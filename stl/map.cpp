#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

struct
{
    bool operator()(const string &a, const string &b) const
    {
        return a < b;
    };
}cmp;

auto cmp1=[](const string &a, const string &b) 
{
    return a < b;
};


typedef std::unordered_multimap<std::string, int> testmp;
//typedef std::multimap<std::string, int> testmp;


void print(testmp &mp)
{
    for(auto it = mp.begin(); it!=mp.end(); it++)
    {
        cout<<"Key:"<<it->first<<"\t"<<"value:"<<it->second<<endl;
    }
}
int main()
{

    testmp mp;
    cout<<"Insert...."<<endl;
    mp.insert(pair<string,int>("Ram",5));
    mp.insert(pair<string,int>("Dhi",6));
    mp.insert(pair<string,int>("Kav",7));
    mp.insert(pair<string,int>("yas",8));
    mp.insert(pair<string,int>("bal",9));
    mp.insert(pair<string,int>("bal",10));
    print(mp);

    

    return 0;
}