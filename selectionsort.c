#include<stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selection_sort(int [],int);
int main()
{
    int a[50],len;
    printf("Enter the length of the array\n");
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        printf("Enter the element at %d position\n",i+1);
        scanf("%d",&a[i]);
    }
    selection_sort(a,len);
    printf("Sorted array is\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",a[i]);
    } 
    return 0;
}
void selection_sort(int a[50],int len)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < len-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < len; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&a[min_idx], &a[i]);
    }
}
