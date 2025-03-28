#include<stdio.h>

int main()
{
    int x,thenum,i;
    printf("enter the size of array\n");
    scanf("%i",&x);
    int arr[x];
    printf("enter the array\n");
    for ( i=0; i<x; i++)
        scanf("%i",&arr[i]);
    printf("enter the number you want to search\n");
    scanf("%i",&thenum);
    for ( i=0; i<x; i++)
    {
        if (thenum==arr[i])
        {
            printf("the index is %i\n",i);
            printf("the number of comparisons made is %i\n",i+1);
            break;
        }
    }
    if (i==x)
    {
    printf("sorry number not found");
    printf("the number of comparisons made is %i\n",i);
    }
    return 0;
}