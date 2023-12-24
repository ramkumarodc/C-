/* selection sort*/

//Time Complexity: O(N^2)
//Space Complexity: O(1)

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

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b =tmp;
}
int main()
{
    int a[] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(a)/sizeof(int);
    print(a,n);

    for(int i=0; i<n; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(a[j]< a[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(a[min], a[i]);
        }
    }
    print (a,n);
    return 0;
}
