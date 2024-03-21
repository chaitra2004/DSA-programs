#include <stdio.h>
#include <stdlib.h>
void print_array(FILE *output, int [], int);
void insertion(int [],int );
int main()
{
    int a[100];
    int i,n;
    FILE *random_file = fopen("random.txt", "w");
    if (random_file == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    printf("Enter the value of n\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 50 + 1;
        fprintf(random_file, "%d\n", a[i]);
    }
    fclose(random_file);
    random_file = fopen("random.txt", "r");
    if (random_file == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    for ( i = 0; i < n; i++)
    {
        fscanf(random_file, "%d", &a[i]);
    }

    fclose(random_file);
    insertion(a,n);
    FILE *output = fopen("insertion.txt", "w");
    if (output == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    print_array(output, a, n);
    fclose(output);
    return 0;
}
void insertion(int a[100], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void print_array(FILE *output, int a[100], int n)
 {
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(output, "%d\t", a[i]);
    }
    printf("The result is stored in insertionsort file\n");
}
