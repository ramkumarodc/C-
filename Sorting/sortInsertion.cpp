/*insertion sort*/

//Time Complexity: O(N^2)
//Space Complexity: O(1)
#include<iostream>
using namespace std;
void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[] = { 5, 4, 10, 1, 6, 2};
    int n = sizeof(a)/sizeof(int);

    print(a,n);
    for(int i=1; i<n; i++)
    {
        int tmp = a[i];
        int j=i-1;
        while( j>=0 && a[j]>tmp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=tmp;
    }
    print(a,n);
    return 0;
}