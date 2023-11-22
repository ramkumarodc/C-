/*Sliding Window Maximum (Maximum of all subarrays of size K)*/

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void printKMax_naive(int arr[], int n, int k)
{
    vector<int> ans;
    for(int i=0; i<n-k+1; i++)
    {
        int max = arr[i];
        for(int j=1;j<k; j++)
        {
            if(max < arr[i+j])
            {
                max = arr[i+j];
            }
        }
        ans.push_back(max);
    }

    for(int i=0;i<ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

void printKMax_deque(int arr[], int n, int k)
{
    deque<int> qi;
    
    int i;
    for(i=0; i<k; i++)
    {
        while((!qi.empty()) && arr[i] >= arr[qi.back()])
        {
            qi.pop_back();
        }
        qi.push_back(i);
    }

    for(; i<n; i++)
    {
        cout<<arr[qi.front()] <<' ';

        while(!qi.empty() && qi.front()<=i-k)
        {
            qi.pop_front();
        }

        while ((!qi.empty()) && arr[i] >= arr[qi.back()])
        {
            qi.pop_back();
        }
        qi.push_back(i);
    }
    cout << arr[qi.front()];
}

int main()
{
    //int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };    int k=3;
    //int arr[] = {12, 78, 1, 90, 57, 89, 56 };   int k=3;
    int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 }; int k = 4;
    int n=sizeof(arr)/sizeof(int);
    
    return 0;
}