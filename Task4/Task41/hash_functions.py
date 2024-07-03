import hashlib
import argparse
import timeit
import platform

# Conditional import based on the operating system
if platform.system() == 'Windows':
    from Crypto.Hash import SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256
else:
    from Cryptodome.Hash import SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256

def hash_data(data, algorithm, digest_length=None):
    try:
        if algorithm == 'sha224':
            hasher = hashlib.sha224()
        elif algorithm == 'sha256':
            hasher = hashlib.sha256()
        elif algorithm == 'sha384':
            hasher = hashlib.sha384()
        elif algorithm == 'sha512':
            hasher = hashlib.sha512()
        elif algorithm == 'sha3_224':
            hasher = SHA3_224.new()
        elif algorithm == 'sha3_256':
            hasher = SHA3_256.new()
        elif algorithm == 'sha3_384':
            hasher = SHA3_384.new()
        elif algorithm == 'sha3_512':
            hasher = SHA3_512.new()
        elif algorithm == 'shake128':
            if digest_length is None:
                raise ValueError("digest_length is required for shake128")
            hasher = SHAKE128.new()
            hasher.update(data.encode('utf-8'))
            return hasher.read(digest_length).hex()
        elif algorithm == 'shake256':
            if digest_length is None:
                raise ValueError("digest_length is required for shake256")
            hasher = SHAKE256.new()
            hasher.update(data.encode('utf-8'))
            return hasher.read(digest_length).hex()
        else:
            raise ValueError("Unsupported algorithm")

        hasher.update(data.encode('utf-8'))
        return hasher.hexdigest()
    except Exception as e:
        print(f"Error: {e}")
        return None

def main():
    parser = argparse.ArgumentParser(description='Hash Function Implementation')
    parser.add_argument('input', type=str, nargs='?', help='Input text or file path')
    parser.add_argument('--file', action='store_true', help='Indicates that input is a file path')
    parser.add_argument('--algorithm', type=str, default='sha256', help='Hash algorithm')
    parser.add_argument('--digest_length', type=int, help='Digest length for SHAKE algorithms')
    parser.add_argument('--output', type=str, help='Output file to save the hash')
    parser.add_argument('--benchmark', action='store_true', help='Run performance benchmark')
    args = parser.parse_args()

    if args.benchmark:
        run_benchmark()
        return

    if not args.input:
        parser.error("the following arguments are required: input")

    # Validate algorithm argument
    valid_algorithms = ['sha224', 'sha256', 'sha384', 'sha512', 'sha3_224', 'sha3_256', 'sha3_384', 'sha3_512', 'shake128', 'shake256']
    if args.algorithm not in valid_algorithms:
        parser.error(f"Unsupported algorithm '{args.algorithm}'. Supported algorithms are: {', '.join(valid_algorithms)}")

    if args.file:
        try:
            with open(args.input, 'r', encoding='utf-8') as f:
                input_data = f.read()
        except FileNotFoundError:
            print(f"Error: File '{args.input}' not found.")
            return
    else:
        input_data = args.input

    result = hash_data(input_data, args.algorithm, args.digest_length)

    if result:
        if args.output:
            with open(args.output, 'w', encoding='utf-8') as f:
                f.write(result)
        else:
            print(f'Hash result: {result}')

def run_benchmark():
    input_sizes = [10**6, 2*(10**6), 10**7, 10**8, 10**9]
    algorithms = ['sha224', 'sha256', 'sha384', 'sha512', 'sha3_224', 'sha3_256', 'sha3_384', 'sha3_512', 'shake128', 'shake256']
    results = []

    for size in input_sizes:
        input_data = 'a' * size
        for algorithm in algorithms:
            if 'shake' in algorithm:
                total_time = timeit.timeit(lambda: hash_data(input_data, algorithm, digest_length=256), number=1000)
            else:
                total_time = timeit.timeit(lambda: hash_data(input_data, algorithm), number=1000)
            average_time = total_time / 1000
            results.append((algorithm, size, average_time))
            print(f'Algorithm: {algorithm}, Input Size: {size}, Average Time: {average_time}')

    with open('performance_results.txt', 'w', encoding='utf-8') as f:
        for result in results:
            f.write(f'Algorithm: {result[0]}, Input Size: {result[1]}, Average Time: {result[2]}\n')

if __name__ == '__main__':
    main()
