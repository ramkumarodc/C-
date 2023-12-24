/*Bubble sort*/

#include<iostream>
using namespace std;

//Time Complexity: O(N^2)
//Space Complexity: O(1)
void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<"\n";
}
void swap1(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp; 
}

int main()
{
    int a[] = {15,16,6,8,5};
    int n = sizeof(a)/sizeof(int);
    print(a, n);

   for(int i=0; i<n-1; i++)
    {
        bool swap = false;
        for(int j=0; j<n-i-1; j++)       
        {
            if (a[j] > a[j+1] )
            {
                swap1(a[j], a[j+1]);
                swap = true;
            }
        }
        if(!swap)
        break;
    }

    print(a,n);
    return 0;
}