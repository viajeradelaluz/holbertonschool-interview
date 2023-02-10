#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed, original;

	original = n;
	for (reversed = 0; n != 0; n /= 10)
		reversed = reversed * 10 + n % 10;

	return (original == reversed);
}
