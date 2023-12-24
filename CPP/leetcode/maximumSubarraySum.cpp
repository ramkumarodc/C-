/*2461. Maximum Sum of Distinct Subarrays With Length K
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

long long maximumSubarraySum1(vector<int>& nums, int k)
{
    int n = nums.size();
    int st=0; int ed=0;
    int max = 0;

    unordered_map<int,int> mp;
    int sum =0;
    while(ed<n)
    {
		if(mp[nums[ed]]==0 )
		{
			sum += nums[ed];
			mp[nums[ed]]++;
			
			if(ed-st+1 == k)
			{
				if (max < sum)
					max = sum;

				sum -= nums[st];
				mp[nums[st]]--;
				st++;
			}
			ed++;				
		}
		else
		{
			sum-=nums[st];
			mp[nums[st]]--;
			st++;
		} 
    }
    return max;
}


int main()
{
    vector<int> nums = {1,5,4,2,9,9,9};
    int k=3;
    cout<<maximumSubarraySum(nums,k);
}