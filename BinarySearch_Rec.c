#include <stdio.h>
#include <stdlib.h>

int binarysearch(int, int, int[], int);

int main() 
{
    int flag = 0, n, i, a[20], key, l = 0, u, result;

    printf("Enter the size of the data: ");
    scanf("%d", &n);

    printf("Enter the data: ");
    for(i=0;i<n;i++)
  {
    
    scanf("%d",&a[i]);
    
    if(a[i]<a[i-1]&&i!=0)
    {
      printf("wrong input...elements must be inserted into acsecnding order!!");
      exit(1);
    }
  }
    printf("Enter the value to be searched: ");
    scanf("%d", &key);

    u = n - 1; // Set upper bound correctly.

    result = binarysearch(l, u, a, key);

    if (result != -1) {
        printf("Key is found at position %d.\n", result);
    } else {
        printf("Key is not found.\n");
    }

    return 0;
}

int binarysearch(int l, int u, int a[], int key) {
    int mid;
    
    while (l <= u) 
    {
        mid = l + (u - l) / 2; // Calculate the middle index correctly.

        if (a[mid] == key) 
        {
            return mid; // Return the index where the key is found.
        } else if (a[mid] < key) 
        {
            l = mid + 1;
        } else {
            u = mid - 1;
        }
    }

    return -1; // Return -1 to indicate that the key is not found.
}
