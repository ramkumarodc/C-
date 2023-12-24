/*
2653. Sliding Subarray Beauty

Given an integer array nums containing n integers, find the beauty of each subarray of size k.

The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.

Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3. 
The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.
Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
Output: [-1,-2,-3,-4]
Explanation: There are 4 subarrays with size k = 2.
For [-1, -2], the 2nd smallest negative integer is -1.
For [-2, -3], the 2nd smallest negative integer is -2.
For [-3, -4], the 2nd smallest negative integer is -3.
For [-4, -5], the 2nd smallest negative integer is -4. 
Example 3:

Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
Output: [-3,0,-3,-3,-3]
Explanation: There are 5 subarrays with size k = 2.
For [-3, 1], the 1st smallest negative integer is -3.
For [1, 2], there is no negative integer so the beauty is 0.
For [2, -3], the 1st smallest negative integer is -3.
For [-3, 0], the 1st smallest negative integer is -3.
For [0, -3], the 1st smallest negative integer is -3.
 

Constraints:

n == nums.length 
1 <= n <= 105
1 <= k <= n
1 <= x <= k 
-50 <= nums[i] <= 50 */

#include<iostream>
#include<vector>
using namespace std;


vector<int> getSubarrayBeauty1(vector<int>& nums, int k, int x) 
{
	int n=nums.size();
	int st=0;
	int ed=0;
    vector<vector<int>> tmp(101);
    vector<int> op;
    
    while(ed<n)
    {
        tmp[nums[ed]+50].push_back(nums[ed]);
        if(ed-st+1==k)
        {
            int cnt =0; 
            int val =0;
            for(int ti=0; ti<101; ti++)
            {
                cnt += tmp[ti].size();
                if(cnt >= x)
                {
                    val = tmp[ti][0];
                    break;
                }
                
            }
            if(val > 0)
            {
                val =0;
            }
            op.push_back(val);

            tmp[nums[st]+50].pop_back();
            st++;
        }
        ed++;
    }
    return op;
}

vector<int> getSubarrayBeauty2(vector<int>& nums, int k, int x) 
{
	int n=nums.size();
	int st=0;
	int ed=0;
	vector<int> op;
	vector<int> mp(51,0);

	while(ed<n)
	{
		if(nums[ed] < 0)
		{
			mp[nums[ed]+50]++;
		}
		if(ed-st+1 == k)
		{
			int cnt=0; 
			int val=0;
			for(int i=0; i<51; i++)
			{
				cnt+=mp[i];
				if(cnt >= x)
				{
					val = i-50;
					break;
				}
			}
			if(val>0)
			{
				val =0;
			}
			op.push_back(val);
			
			if(nums[st] <0)
			{
				mp[nums[st]+50]--;
			}
			st++;
		}
		ed++;
	}
	return op;
}

int main()
{
    vector<int> nums = {1,-1,-3,-2,3};
    int k = 3;
    int x = 2;
    getSubarrayBeauty2(nums,k,x);
    return 0;
}