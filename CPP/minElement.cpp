#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Function pointer
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> vec= {7,8,2,8,3,2};

    //funtors  or function object
    struct {
        bool operator()(int& a, int& b)
        {
            if(a>b)
            {
                return true;
            }
            return false;
        }
    } func;

    //lambda function
    auto lam = [](int a, int b){return a>b;};

    auto val1 = min_element(vec.begin(), vec.end(), compare );
    auto val2 = min_element(vec.begin(),vec.end(), func );
    auto val3 = min_element(vec.begin(), vec.end(),[](int a, int b){return a>b;} );
    auto val4 = min_element(vec.begin(),vec.end(), lam );
    cout<<*val4;
    
    return 0;
}