# Palindrome integer

## Tasks

### 0. Palindrome unsigned integer

Write a function that checks whether or not a given unsigned integer is a palindrome.

- Prototype: `int is_palindrome(unsigned long n)`;
- Where `n` is the number to be checked
- Your function must return `1` if `n` is a palindrome, and `0` otherwise
- You are not allowed to allocate memory dynamically (malloc, calloc, …)

```sh
alex@~/0x08-palindrome_integer$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
alex@~/0x08-palindrome_integer$ ./palindrome 1
1 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 11
11 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 112
112 is not a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 121
121 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
alex@~/0x08-palindrome_integer$
```
