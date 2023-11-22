/*shell sort*/
#include<iostream>
using namespace std;

void print(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<*(a++)<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};
    int n = sizeof(a)/sizeof(int);
    print(a,n);

    for(int g = n/2; g>0 ; g=g/2)
    {
        for(int j=g; j<n; j++)
        {
            for(int i=j-g; i>=0; i=i-g )
            {
                if(a[i] < a[i+g])
                {
                    break;
                }
                else{
                    swap(a[i], a[i+g]);
                }
            }
        }
    }
    print(a,n);
    return 0;
}