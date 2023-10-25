#include <stdio.h>
#include <stdlib.h>

void selectionsort(int[], int);
void insertionsort(int[], int);

int main()
{
    int i, n, a[20], choice;
    while (1)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        printf("Enter the data: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        printf("\n 1. Selection Sort \n 2. Insertion Sort \n 3. Exit");
        printf("\n Enter your Choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            selectionsort(a, n);
            break;

        case 2:
            insertionsort(a, n);
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong Choice...!!!\n");
            break;
        }
    }
}

void selectionsort(int a[], int n)
{
    int i, j, max, m, t;
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        max = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > max)
            {
                max = a[j];
                m = j;
            }
        }
        if (m != i)
        {
            t = a[m];
            a[m] = a[i];
            a[i] = t;
        }
    }
    printf("After sorting data are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionsort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    printf("After sorting data are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
