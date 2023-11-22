//#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

void initialize2DArray()
{
    int arr[10][10] = {};
    memset(arr, -1, sizeof(arr));
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void toLowerCase()
{
    string str = "Hello World";
    for(int i=0;i<str.size(); i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]-'A'+'a';
        }
    }
    cout<<str;
}

void reverseStr()
{
    string s= "abcdefg";
    int k=8;
    
    int start =0;
    while(start<s.size())
    {
        string word = s.substr(start, (2*k));
        std::string::iterator end = word.begin()+k;
        if(end > word.end())
            end = word.end();
        std::reverse(word.begin(), end);
        cout<<word<<endl;
        start += (2*k);
    }
}


void reverseParentheses() 
{
    string s="(abcd)";        
        int i=0;
        int j= s.size();
        int st =0;
        int ed =0;
        while(i<j)
        {
            if(s[i]=='(')
            {
                st = i;
            }
            else if(s[i]==')')
            {
                ed = i;
            }

            if(st<ed)
            {
                reverse(s.begin()+st, s.begin()+ed+1);
                s.erase(st,1);
                s.erase(ed-1,1);
                i = 0;
                j=s.size();
                st = ed =0;
            }
            i++;
        }
        cout<<s;
    }   

void test()
{
    string str;
    string str2 = "Hello ";
    string str3 = "world";
    str.append(str2);
    str2.append(str3, 2);
    cout<<str<<"\n";
    cout<<str2<<"\n";
}


void isPalindrome() 
{
    string s="A man, a plan, a canal: Panama";
    unordered_map<char,int> map;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'a' && s[i]<='z' )
            map[s[i]]++;
        else if(s[i]>='A' && s[i]<='Z')
        {
            char c = s[i];
            c-='A';
            c+='a';

            map[c]++;
        }
    }

    for(unordered_map<char,int>::iterator it = map.begin();
            it!=map.end(); it++)
    {
        if((it->second%2)!=0)
        cout<< false;
        return;
    }
    cout<< true;
}

int main()
{
    //initialize2DArray();
    //toLowerCase();
    reverseStr();
    //reverseParentheses();
    //test();
    //isPalindrome();
    return  0;
}