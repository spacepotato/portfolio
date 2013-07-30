/*A recursive implementation of the insertion sort algorithm */

/* This is a recursive insertion sort program */

#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

void int_swap(int* p1, int* p2);
void insertion(int numbers[], int count);

int main(int argc, char *argv[])
{
    int numbers[MAXVAL];
    int count = 0;
    int i;
    
  while(scanf("%d", &numbers[count])==1){
	    count++;
	}
	
	if(count <= 1){
	    printf("The array is sorted. \n");
	    return 1;
	}
	
	
	for(i = 0; i < count; i++){
	    insertion(numbers, count);
	    printf("%d ", numbers[i]);
	}
	
	return 0;
}

void insertion(int numbers[], int count)
{
    if(count == 0){
        return;
    }
    if(numbers[count] < numbers[count -1]){
        int_swap(&numbers[count], &numbers[count -1]);
    }
    return insertion(numbers, count -1);
}

void int_swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/* Program written by James McLaren as part of the University of Melbourne */
