#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void main()
{
int a[100],i,j,n;
printf("\nEnter array size");
scanf("%d",&n);
printf("\nEnter array elements:");
for(i=0;i<n;++i)
scanf("%d",&a[i]);
mergeSort(a,0,n-1);
printf("\nSorted array is:");
for(i=0;i<n;++i)
printf("%d ",a[i]);
}
