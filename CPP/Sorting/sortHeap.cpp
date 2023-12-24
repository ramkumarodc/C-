/*Heap Sort*/
#include<iostream>
using namespace std;

void print(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

void maxHeapify(int *a, int n, int idx)
{
    int max = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;

    if(left < n && a[max] < a[left])
    {
        max = left;
    }
    else if(right < n && a[max] < a[right])
    {
        max = right;
    }
    if(idx!=max)
    {
        swap(a[max], a[idx]);
        maxHeapify(a, n, max);
    }
}


void heapSort(int a[], int n)
{

}

int main()
{
    int a[] = {15,20,7,9,30};
    int n =sizeof(a)/sizeof(int);

    print(a, n);

    for(int i=n/2; i>=0; i--)
    {
        maxHeapify(a, n, i);
    }

    for(int i=n-1; i>=0; i--)
    {
        swap(a[i], a[0]);
        maxHeapify(a,i,0);
    }

    print(a, n);
    
    return 0;
}