/*Counting sort*/
#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[] = {1,0,2,1,0,1,1,5,6,7,5,4,2,2,0,0,1};
    int n = sizeof(a)/sizeof(int);

    print(a,n);

    int count[10] = {};
    for(int i=0; i<n; i++)
    {
        count[a[i]]++;
    }

    for(int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    int na[n] = {};
    for(int i=n-1; i>=0; i--)
    {
        int val = a[i];
        int idx = --count[val];
        na[idx] = a[i];
    }
    print(na,n);


    return 0;
}