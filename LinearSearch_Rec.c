#include <stdio.h>
#include <stdlib.h>

int linearsearch(int[], int, int);

int main() 
{
    int i, a[20], key, n, result, choice;

    printf("Enter the size of the data: ");
    scanf("%d", &n);

    printf("Enter the data: ");
    for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

   printf("Enter the value to be searched: ");
   scanf("%d", &key);

    result = linearsearch(a, key, n);

     if (result != -1) 
    { // Use == for comparison, not =.
        printf("Key is found at position %d", result); // Print the position where key is found.
    } 
    else 
    {
        printf("Key is not found!!..enter a valid one");
    }

    return 0;
}

int linearsearch(int a[], int key, int n)
{
    int i, flag = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }   
    }

    if (flag == 1) // Return the index where the key is found or -1 if not found.
    {
        return i;
    }
    else 
    {
        return -1;
        
    }

}
