/*quick sort*/
#include<iostream>
using namespace std;

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while(start < end)
    {
        while(a[start] <= pivot )
        {
            start++;
        }
        while(a[end] > pivot)
        {
            end--;
        }

        if(start < end)
        {
            swap(a[start], a[end]); 
        }
    }
    swap(a[lb], a[end]);
    return end;

}
void quicksort(int a[], int lb, int ub)
{
    if(lb<ub)
    {
        int pos = partition(a, lb, ub);
        quicksort(a, lb, pos-1);
        quicksort(a, pos+1, ub);
    }
}
void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main()
{
    //int a[] = {10, 15, 1, 2, 9, 16, 11};
    int a[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(a)/sizeof(int);
    print(a,n);

    quicksort(a, 0, n-1);

    print(a,n);
    return 0;
}