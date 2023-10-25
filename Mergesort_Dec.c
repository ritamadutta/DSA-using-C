#include <stdio.h>
#include <stdlib.h>

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() 
{
    int a[20], i, n, beg = 0, end;
    printf("Enter the size of the data: ");
    scanf("%d", &n);

    printf("Enter your data:");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("The sorted elements in descending order are:\n");
    for (i = 0; i < n; i++) 
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void mergesort(int a[], int beg, int end) 
{
    int mid;
    if (beg < end) 
    {
        mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void merge(int a[], int top, int size, int bottom) 
{
    int f, t, s, temp[20], i;
    f = top;
    s = size + 1;
    t = top;
    while ((f <= size) && (s <= bottom)) 
    {
        if (a[f] >= a[s]) 
        {  // Modified condition for descending order
            temp[t] = a[f];
            f++;
        } 
        else 
        {
            temp[t] = a[s];
            s++;
        }
        t++;
    }
    if (f <= size) 
    {
        for (i = f; i <= size; i++) 
        {
            temp[t] = a[i];
            t++;
        }
    } 
    else 
    {
        for (i = s; i <= bottom; i++) 
        {
            temp[t] = a[i];
            t++;
        }
    }
    for (i = top; i <= bottom; i++) 
    {
        a[i] = temp[i];
    }
}
