#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int, int, int[]);
void SelectionSort(int, int, int[]);

int main() 
{
    int n, a[20], i, j, m, t, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the data: ");

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    while (1)
   {
    printf ("\n 1.Insertion Sort \n 2.Selection Sort \n 3.Exit \n");
    printf ("\n Enter your Choice:\n");
    scanf ("%d",&choice);
    switch(choice)
    {
        case 1: InsertionSort(i, n, a);
        break;

        case 2: SelectionSort(i, n, a);
        break;

        case 3: exit(1);
        break;

        default:
        printf("Invalid choice. Please try again.\n");
    }
   }

}

void InsertionSort(int i, int n, int a[])
{
  int t, c;
  for (i = 1; i < n; i++)
  {
    t = a[i];
    c = i - 1;
    while(c >= 0 && a[c] > t)
    {
      a[c+1] = a[c];
      c = c-1;
    }
    a[c = 1] = t;
  }

  printf("Sorted data is: \n");
    for (i = 0; i < n; i++) 
    {
        printf(" %d \n ", a[i]);
    }

  return ;
}


void SelectionSort(int i, int n, int a[])
{
  int m, j, t;
  for (i = 0; i < n - 1; i++) 
    {
        m = i;

        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < a[m]) 
            {
                m = j;
            }
        }

        if (m != i) 
        {
            t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }

    printf("Sorted data is: \n");
    for (i = 0; i < n; i++) 
    {
        printf(" %d \n", a[i]);
    }

    return ;
}