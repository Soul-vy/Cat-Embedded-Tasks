#include<stdio.h>

void sort(int SIZE,int *arr)
{
    int temp;
    int min;
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
    printf("the sorted array\n");
    for (int i=0; i<SIZE; i++)
        printf("%i\n",arr[i]);
}
    
int main()
{
    int x,thenum,found=1,comp=0;
    printf("enter the size of array\n");
    scanf("%i",&x);
    int arr[x];
    printf("enter the array\n");
    for (int i=0; i<x; i++)
        scanf("%i",&arr[i]);
    sort(x,&arr);    
    int mid;
    int low=0;
    int high=x-1;
    printf("enter the number you want to search\n");
    scanf("%i",&thenum);
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==thenum)
        {
          comp++;
          printf("the index is %i\n",mid);
          found=0;
          break;
        }
        else if (thenum>arr[mid])
        {
            low=mid+1;
            comp++;
        }
        else
        {
            high=mid-1;
            comp++;
        }
    }
    if (found)
    printf("didn't find the num\n");
    else
    printf("the num of comparisons is %i\n",comp);
    return 0;
}