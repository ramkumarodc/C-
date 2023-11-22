#include<iostream>
#include<cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

void defangIPaddr1()
{
    string str = "1.1.1.1";
    string::size_type pos = str.find('.');
    while(pos != std::string::npos)
    {
        str.replace(pos,1,"[.]");
        pos = str.find('.', pos+2);
    }
    cout<<str<<endl;
}

void defangIPaddr2()
{
    string str = "1.1.1.1";
    string ans;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '.')
        {
            ans+="[.]";
        }
        else
        {
            ans.push_back(str[i]);
        }
    }
    cout<<ans<<endl;
}

void finalValueAfterOperations()
{
    vector<string> operations;
    operations.push_back("--X");
    operations.push_back("X++");
    operations.push_back("X++");
// The plus character (+) is equal to 43, and the minus character (-) is equal to 45.
// Therefore, x += 44 - middle operation character; if it's plus, it will be x += 44 - 43 (1);
// if it's minus, it will be x += 44 - 45 (-1)
    int x=0;
    for(int i=0; i<operations.size(); i++)
    {
        string &str = operations[i];
        x+=44-str[1];
    }
    cout<<x;
}

void numJewelsInStones1() 
{
    int result = 0;
    string jewels = "aA";
    string stones = "aAAbbbb";
    unordered_map<char,int> umap;
    for(int i=0; i<stones.size(); i++)
    {
        umap[stones[i]]++;
    }
    
    for(int i=0;i<jewels.size(); i++)
    {
        result+=umap[jewels[i]];
    }
    cout<<result;
}

void numJewelsInStones2()
{
    string jewels = "aA";
    string stones = "aAAbbbb";
    int result =0;
    set<char> cset;
    for(int i=0; i<jewels.size(); i++)
    {
        cset.insert(jewels[i]);
    }

    for(int i=0; i<stones.size(); i++)
    {
        if(cset.count(stones[i])>0)
        result++;
    }
    cout<<result;
}

void mostWordsFound()
{
    string cstr = "alice and bob love leetcode";
    int count =0;
    for(int i=0; i<cstr.size(); i++)
    {
        if(cstr[i]==' ')
        count++;
    }
    cout<<count;
}

void interpret() 
{
    string command ="G()(al)";
    string cstr;
    for(int i=0; i<command.size(); i++)
    {
        if((command[i]>='a' && command[i]<='z' )||
           (command[i]>='A' && command[i]<='Z'))
        {
            cstr.push_back(command[i]);
        }
        else if(command[i]=='(' && command[i+1]==')' )
        {
            cstr.push_back('o');
        }
    }
    cout<<cstr;   
}

void restoreString1() 
{
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    string cstr(s);
    for(int i=0; i<s.size(); i++)
    {
        cstr[indices[i]] = s[i];
    }
    cout<< cstr;
}

string restoreString2() 
{
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    map<int,char> smap;
    for(int i=0; i<s.size(); i++)
    {
        smap.insert(std::pair<int, char>(indices[i],s[i]));
    }

    string str;
    for(map<int,char>::iterator it= smap.begin(); it!= smap.end(); it++)
    {
        str.push_back(it->second);
    }
    return str;
}

void balancedStringSplit()
{
	string s = "RLRRLLRLRL";
    int r=0;
    int res =0;
    for(int i=0; i<s.size(); i++)
    {
       if(s[i]=='R') r++;
       if(s[i]=='L') r--;
       if(r==0)
        res++;
    }
    cout<<res;
}

void cellsInRange()
{
    string s = "A1:B2";
    char cs = s[0];
    char rs = s[1];
    char ce = s[3];
    char re = s[4];

    char col = cs;
    char row = rs;
    vector<string> vec;
    while(col<=ce)
    {
        char row = rs;
        while(row<=re)
        {
            string rowcol;
            rowcol.push_back(col);
            rowcol.push_back(row);
            row++;
            vec.push_back(rowcol);
        }
         col++;
    }

    for(auto str: vec)
    {
        cout<<str<<endl;
    }
}

void checkPrime()
{
    int n=11;
    bool isPrime = true;

    if(n==0|| n==1)
    isPrime = false;

    for (int i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            isPrime = false;
            break;
        }

    }

    if(isPrime)
    {
        cout<<n<<" is a Prime Number";
    }
    else
    {
        cout<<n<<" is not a Prime Number";
    }
}

bool ispalindromestring(string s)
{
    int i=0;
    int j= s.size()-1;

    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool ispalindromeNum(int num)
{
    int rev = 0, rem=0, quo=num;

    while(quo>0)
    {
        rem = quo%10;
        rev = (rev*10)+rem;
        quo = quo/10;
    }
    if(num==rev)
    {
        return true;
    }
    return false;
}

int main()
{
    //defangIPaddr1();
    //defangIPaddr2();
    //finalValueAfterOperations();
    //numJewelsInStones2();
    //mostWordsFound();
    //interpret();
    //restoreString1();
    //restoreString1();
    //balancedStringSplit();
    //cellsInRange();
    //checkPrime();
    //cout<<"ispalindromestring: "<<ispalindromestring("sass")<<endl;
    cout<<"ispalindromeNum: "<<ispalindromeNum(1211)<<endl;
    return 0;
}