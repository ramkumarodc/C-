#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum_Brute_force (vector<int>& nums, int target)
     {
        for (int i = 0; i < nums.size(); i++) 
        {
                  for (int j = i + 1; j < nums.size(); j++) 
            {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    vector<int> twoSum_optimized(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
       
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
        return {-1, -1};         
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {-3,4,3,90};
    int target = 0;
    vector<int> result = obj.twoSum_optimized(nums, target);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
}