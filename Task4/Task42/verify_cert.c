#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/x509v3.h>

void printCertificateFields(X509 *cert) {
    BIO *bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);

    // Print subject name
    BIO_puts(bio_out, "Subject Name:\n");
    X509_NAME_print_ex(bio_out, X509_get_subject_name(cert), 0, XN_FLAG_MULTILINE);
    BIO_puts(bio_out, "\n");

    // Print issuer name
    BIO_puts(bio_out, "Issuer Name:\n");
    X509_NAME_print_ex(bio_out, X509_get_issuer_name(cert), 0, XN_FLAG_MULTILINE);
    BIO_puts(bio_out, "\n");

    // Print validity period
    BIO_puts(bio_out, "Valid From: ");
    ASN1_TIME_print(bio_out, X509_get_notBefore(cert));
    BIO_puts(bio_out, "\nValid To: ");
    ASN1_TIME_print(bio_out, X509_get_notAfter(cert));
    BIO_puts(bio_out, "\n");

    // Print subject public key
    BIO_puts(bio_out, "Subject Public Key:\n");
    EVP_PKEY *pkey = X509_get_pubkey(cert);
    if (pkey) {
        PEM_write_bio_PUBKEY(bio_out, pkey);
        EVP_PKEY_free(pkey);
    }

    // Print signature algorithm
    BIO_puts(bio_out, "Signature Algorithm: ");
    int sig_nid = X509_get_signature_nid(cert);
    BIO_printf(bio_out, "%s\n", OBJ_nid2ln(sig_nid));

    // Print certificate purposes
    BIO_puts(bio_out, "Purposes:\n");
    for (int i = 0; i < X509_PURPOSE_get_count(); i++) {
        X509_PURPOSE *purp = X509_PURPOSE_get0(i);
        BIO_printf(bio_out, "  %s\n", X509_PURPOSE_get0_sname(purp));
    }

    BIO_free(bio_out);
}

EVP_PKEY* parseAndValidateCertificate(const char *certPath) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Read certificate
    BIO *bio = BIO_new(BIO_s_file());
    if (BIO_read_filename(bio, certPath) <= 0) {
        fprintf(stderr, "Error reading certificate file\n");
        BIO_free(bio);
        return NULL;
    }

    X509 *cert = PEM_read_bio_X509(bio, NULL, 0, NULL);
    if (!cert) {
        // Try reading as DER
        BIO_reset(bio);
        cert = d2i_X509_bio(bio, NULL);
        if (!cert) {
            fprintf(stderr, "Error parsing certificate\n");
            BIO_free(bio);
            return NULL;
        }
    }

    BIO_free(bio);

    // Print certificate fields
    printCertificateFields(cert);

    // Verify the signature
    EVP_PKEY *pkey = X509_get_pubkey(cert);
    if (!pkey) {
        fprintf(stderr, "Error getting public key from certificate\n");
        X509_free(cert);
        return NULL;
    }

    int verifyResult = X509_verify(cert, pkey);

    if (verifyResult == 1) {
        // Signature is valid, return the public key
        return pkey; // Directly return the public key
    } else {
        EVP_PKEY_free(pkey);
        fprintf(stderr, "Certificate signature is invalid\n");
        X509_free(cert);
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <certificate file path>\n", argv[0]);
        return 1;
    }

    const char *certPath = argv[1];
    EVP_PKEY *publicKey = parseAndValidateCertificate(certPath);
    if (publicKey) {
        printf("Certificate signature is valid. Public key:\n");
        PEM_write_PUBKEY(stdout, publicKey);
        EVP_PKEY_free(publicKey);
    } else {
        fprintf(stderr, "Certificate signature is invalid.\n");
    }

    return 0;
}
