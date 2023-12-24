#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int getMaxElement(int *a, int n)
{
    int max = -1;
    for( int i=0; i<n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int getNumofPass(int element)
{
    int cnt =0;
    while(element >0)
    {
        element = element/10;
        cnt++;
    }
    return cnt;
}

void print(int *a, int n)
{
    for(int i =0; i<n; i++)
    {
        cout<<a[i]<<' ';    
    }
    cout<<endl;

}

int main()
{
    int a[] = {432, 8, 530, 90, 88,23,11,45,677,199, 33};
    int n = sizeof(a)/sizeof(int);

    print(a,n);
    //Radix and counting sort
    int max_element = getMaxElement(a, n);
    int no_of_pass = getNumofPass(max_element);

    int counting[10] = {};
    int output[n] = {};
    int pass =1;
    for(int i= 0 ; i<no_of_pass; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cnt_idx = (a[j]/pass)%10;
            counting[cnt_idx]++;
        }

        for(int j=1 ; j<10; j++)
        {
            counting[j]+= counting[j-1];
        }

        for(int k = n-1; k>=0; k--)
        {
            int idx = (a[k]/pass)%10;

            int pos = --(counting[idx]);
            output[pos] = a[k];
        }
        memcpy(&a,&output,sizeof(a));
        memset(&counting,0, sizeof(counting));
        pass = pass*10;
    }
    print(output, n);
    return 0;
}