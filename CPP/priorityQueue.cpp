#include<iostream>
#include<queue>
//#include<utility>
using namespace std;

template<typename T>
void print(string_view  name, T const& q)
{
    cout<<name<<": \t";
    for(auto const& n : q)
    {
        cout<<n<<' ';
    }
    cout<<"\n";
}

template<typename Q>
void print_queue(string_view name, Q q)
{
    for(cout<<name<<": \t"; !q.empty(); q.pop())
    {
        cout<<q.top()<< ' ';
    }
    cout<<"\n";
}

int main()
{

    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    print("data", data);

    priority_queue<int> q1;
    for(int n: data)
    {
        q1.push(n);
    }
    print_queue("q1",q1);

    priority_queue<int, vector<int>, greater<int>> minq1(data.begin(), data.end());
    print_queue("minq1",minq1);


    priority_queue minq2(data.begin(), data.end(), greater<int>());
    print_queue("minq2",minq2);

    struct 
    {
        bool operator()(const int left, const int right)
        {
            return left > right;
        }
    }customLess;

    priority_queue minq3(data.begin(), data.end(), customLess);
    print_queue("minq3", minq3);

    auto cmp = [](int left, int right){return left < right; };
    priority_queue<int, vector<int>,    decltype(cmp)> q5(cmp);
    for(int n: data)
        q5.push(n);
    print_queue("q5", q5);

    return 0;
}