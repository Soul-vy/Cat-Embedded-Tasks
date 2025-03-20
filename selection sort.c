#include<stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE]= {0};
    int temp;
    int min;
    for (int i=0; i<SIZE; i++)
    {
        printf("\nthe %i element\n",i);
        scanf("%i",&arr[i]);
    }
    for (int i = 0; i < SIZE - 1; i++) {
        min = i;  
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min]) {
                min = j;  
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i=0; i<SIZE; i++)
    {
        printf("\nthe %i element\n",i);
        printf("%i",arr[i]);
    }

    return 0;
}