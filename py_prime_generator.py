def is_prime(num):

    i = 2
    while i * i <= num:
        if (num % i == 0):
            return False
        i = i + 1
    return True

def prime_generator(num):
    count = 2
    while True:
        if is_prime(count):
            yield count
        count = count + 1

num = 5
l = prime_generator(num)

for _ in range(num):
    print(next(l))
