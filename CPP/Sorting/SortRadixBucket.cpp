/*Radix sort or bucket sort*/
#include<iostream>
#include<list>

using namespace std;

int getMax(int* a, int n)
{
    int max = -1;
    for(int i=0; i<n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int getPassCount(int max)
{
    int i=0;
    while(max)
    {
        max = max/10;
        i++;
    }
    return i;
}

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
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n= sizeof(arr)/sizeof(n);

    print(arr, n);
    int max = getMax(arr, n);
    int passCnt = getPassCount(max);

    int bucket[10] = {0};

    
    int pass =1;
    list<int> tmp[10];
    for(int j =1 ; j <= passCnt; j++)
    {
        for(int i=0; i<n; i++)
        {
            int quo = arr[i]/pass;
            int rem = quo%10;
            tmp[rem].push_back(arr[i]);
        }

        int k=0;
        for(int i=0; i<10; i++)
        {
            for(auto it = tmp[i].begin(); it!=tmp[i].end(); it++)
            {
                arr[k++] = *it;
            }
            tmp[i].clear();
        }
        pass*=10;
    }
    print(arr, n);
}
