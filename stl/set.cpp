#include<iostream>
#include<unordered_set>
using namespace std;

//testing insert, erase, find, count, clear, size, empty 
// for set, multiset, unordered_set, unordered_multiset

typedef unordered_multiset<int> testset;


void print(testset &st)
{
    for(auto it = st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}
int main()
{
    testset st;
    st.insert(10);
    st.insert(50);
    st.insert(40);
    st.insert(30);
    st.insert(20);
    st.insert(20);

    cout<<"Insert 10, 50, 40, 30, 20, 20"<<endl;

    cout<<"size of set:"<<st.size()<<endl;

    print(st);

    auto val = st.find(40);
    if(val!=st.end())
    {
        cout<<"Erasing: "<<*val<<endl;
        st.erase(val);
        cout<<"Erasing: 20"<<endl;
        st.erase(20);
        print(st);
    }
    else
    {
        cout<<"Not found"<<endl;
    }

    cout<<"Counting: 10:"<<st.count(10)<<endl;
    cout<<"Counting: 20:"<<st.count(20)<<endl;
    print(st);
    cout<<"Checking empty(): "<<st.empty()<<endl;
    cout<<"Clearing the set:"; st.clear();
    cout<<"\nChecking empty(): "<<st.empty()<<endl;
    

    
    return 0;
}