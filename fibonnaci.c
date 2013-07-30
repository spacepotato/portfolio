/* A simple program for calculating the nth number of the fibonnaci sequence */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int main(int argc, char *argv[])
{
  int i, n;
	scanf("%d", &n);
	int sequence[MAXN] = {1, 1};
	for(i = 2; i < n; i++)
	{
	    sequence[i] = sequence[i - 1] + sequence[i - 2];
	}
	
	printf("The fibonnaci number is %d\n", sequence[n - 1]);
	return 0;
}


