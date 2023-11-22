/*Merge Sort*/
#include<iostream>
using namespace std;

void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

void merge(int a[], int lb, int mid, int ub)
{
    int n =ub+1;
    int tmp[n]={0};

    int i= lb;
    int j = mid+1;
    int k=lb;
    while((i < mid+1) &&  (j <ub+1))
    {
        if(a[i]<a[j])
        {
            tmp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            tmp[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<= mid)
    {
        tmp[k]=a[i];
        i++;
        k++;
    }
    while(j<=ub)
    {
        tmp[k]=a[j];
        j++;
        k++;
    }
    for(int i=lb; i<=ub; i++)
    {
        a[i] = tmp[i];
    }
}

void mergesort(int a[], int lb, int ub)
{
    cout<<"lb:"<<lb<<"\t"<<"ub:"<<ub<<endl;
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        mergesort(a, lb, mid);
        mergesort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int a[] = {15,5,24,8,1,3,16,10,20};
    int n = sizeof(a)/sizeof(int);
    print(a,n);

    mergesort(a, 0, n-1);

    print(a,n);

    return 0;
}