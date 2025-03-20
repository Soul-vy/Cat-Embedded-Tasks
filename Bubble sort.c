#include<stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE]= {0};
    int temp;
    for (int i=0; i<SIZE; i++)
    {
        printf("\nthe %i element\n",i);
        scanf("%i",&arr[i]);
    }
    for (int i=0; i<SIZE-1; i++)
    {
        for (int j=0; j<SIZE-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
               temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
            }
        }
    }
    for (int i=0; i<SIZE; i++)
    {
        printf("\nthe %i element\n",i);
        printf("%i",arr[i]);
    }

    return 0;
}