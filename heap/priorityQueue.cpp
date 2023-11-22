#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    vector<int> data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    priority_queue<int> q;
    cout<<"data:";
    for(int i=0; i<data.size(); i++)
    {
        cout<<data[i]<<' ';
        q.push(data[i]);
    }
    cout<<endl;
    cout<<"q:";
    for(int i=0; i<data.size(); i++)
    {
        cout<<q.top()<<' ';
        q.pop();
    }
    cout<<endl;

    priority_queue<int> q1(data.begin(), data.end());
    cout<<"q1:";
    for(int i=0; i<data.size(); i++)
    {
        cout<<q1.top()<<' ';
        q1.pop();
    }
    cout<<endl;

    priority_queue q2(data.begin(), data.end(), greater<int>());
    cout<<"q2:";
    for(int i=0; i<data.size(); i++)
    {
        cout<<q2.top()<<' ';
        q2.pop();
    }
    cout<<endl;

    struct {
        bool operator() (const int a, const int b)
        {
            return a>b;
        }
    } customless;
    priority_queue q3(data.begin(), data.end(), customless);
    cout<<"q3:";
    for(int i=0; i<data.size(); i++)
    {
        cout<<q3.top()<<' ';
        q3.pop();
    }
    cout<<endl;

    auto cmp= [](int a , int b)
    {
        return a>b;
    };
    priority_queue<int, vector<int>, decltype(cmp)> q4(cmp);
    priority_queue<int, vector<int>, decltype(customless)> q5(customless);
    return 0;
}