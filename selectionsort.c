#include<stdio.h>
void read(int [],int);
void display(int [],int);
void sort(int [],int);
void swap(int *,int *);
void print_array(FILE *ptr, int [], int);
int main()
{
    FILE *ptr;
    ptr=fopen("selection sort.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    int a[100];
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sort(a,n);
    print_array(ptr, a, n);
    fclose(ptr);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void sort(int a[100],int n)
{
    int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (a[j] < a[min_idx])
			min_idx = j;
		if(min_idx != i)
			swap(&a[min_idx], &a[i]);
	}
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void print_array(FILE *ptr, int a[100], int n)
 {
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(ptr, "%d\t", a[i]);
    }
    printf("\nThe result is stored in selection sort file\n");
}
