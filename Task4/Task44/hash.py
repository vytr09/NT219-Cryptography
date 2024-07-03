import hashlib

secret_key = b'secret_key_16byt'
orginal_message = b'original_message'
original_data = secret_key + orginal_message
original_sha1_hash = hashlib.sha1(original_data).hexdigest()
original_sha256_hash = hashlib.sha256(original_data).hexdigest()
original_sha512_hash = hashlib.sha512(original_data).hexdigest()

print(f'Original SHA-1 hash: {original_sha1_hash}')
print(f'Original SHA-256 hash: {original_sha256_hash}')
print(f'Original SHA-512 hash: {original_sha512_hash}')