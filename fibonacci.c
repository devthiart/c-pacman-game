#include <stdio.h>

// Recursive function example
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;

	printf("Enter a positive integer: ");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("Please, only positive numbers :)");
		return 0;
	}

	printf("The %d-th fibonacci number: %d \n", n, fib(n));

	return 0;
}