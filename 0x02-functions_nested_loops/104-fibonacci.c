#include <stdio.h>

void print_fibonacci(int n)
{
	int prev = 1;
	int curr = 2;
	
	printf("%d, %d", prev, curr);
	
	for (int i = 3; i <= n; i++)
	{
        int next = prev + curr;
        printf(", %d", next);
        prev = curr;
        curr = next;
	}
	printf("\n");
}

int main()
{
	print_fibonacci(98);
	return 0;
}
