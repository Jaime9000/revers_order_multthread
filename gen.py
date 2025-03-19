import string
import secrets

# Generate a random string of given length
def random_string(length):
    return ''.join(secrets.SystemRandom().choices(string.ascii_letters + string.digits, k=length))

# Generate input.txt with 100 random lines
with open('input.txt', 'w') as file:
    for _ in range(1000000):
        line = random_string(secrets.SystemRandom().randint(10, 50))  # Random line length between 10 and 50 characters
        file.write(line + '\n')
