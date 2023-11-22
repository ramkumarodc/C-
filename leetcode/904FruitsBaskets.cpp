#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int totalFruit(vector<int>& fruits) 
{
    int n = fruits.size();
    int sum=0;
    int max=0;
    unordered_map<int,int> mp;
    int curr =-1;
    int curridx=-1;
    int prev =-1;
    int previdx=-1;
    for(int i=0; i<n; i++)
    {
        if(mp.size()<2 || (mp.size()==2 && mp.count(fruits[i])>0))
        {
            mp[fruits[i]]++;
            sum++;

            if(curr==-1 || curr == fruits[i])
            {
                curr = fruits[i];
                curridx=i;
            }
            else if(curr != fruits[i])
            {
                prev = curr;
                previdx = curridx;
                curr = fruits[i];
                curridx =i;
            }
        }
        else
        {
            if(max < sum)
            {
                max = sum;
            }
            
            //sum-= mp[prev];
            //mp.erase(prev);

            while(previdx>=0)
            {
                if(mp.count(fruits[previdx]))
                {
                mp[fruits[previdx]]--;
                sum--;
                if(mp[fruits[previdx]]==0)
                    mp.erase(fruits[previdx]);
                }
                previdx--;
            }

            mp[fruits[i]]++;
            sum++;

            prev = curr;
            previdx = curridx;
            curr = fruits[i];
            curridx =i;
        }
    }
    if(max < sum)
    {
        max = sum;
    }
    return max;
}

int main()
{
    //vector<int> fruits ={1,2,3,2,2};
    //vector<int> fruits ={1,0,1,4,1,4,1,2,3};
    //vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> fruits = {1,0,3,4,3};
    cout<<totalFruit(fruits);
    return 0;
}


/*}
read 1, h(1)=1 len=1 sum=1
read 0 h(0)=1 len=2 sum=2
read 1 h(0)=1 h(1)=2 len=2 sum=3
read 4 

*/