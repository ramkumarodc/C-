#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

bool containsDuplicate_HashTable()
{
    vector<int> nums = {0,4,5,0,3,6};
    unordered_map<int, int> umap;
    bool ret= false;
    int count = 0;
    for(auto val : nums)
    {
        count = ++umap[val];
        if(count > 1)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

bool containsDuplicate_Set()
{
    vector<int> nums = {0,4,5,0,3,6,9};
    return nums.size() > set<int>(nums.begin(),nums.end()).size();
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int max(int a, int b, int c)
{
    cout<<"l:"<<a<<" r:"<<b<<" sum:"<<c<<endl;
    if(a>b && a>c)
        return a;
    if(b>a && b>c)
        return b;
    else
        return c;

}
int maxSubArray_BruteForce()
{
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    int max = nums[0];
    int sum =0;
    for(int i=0; i<nums.size(); i++)
    {
        sum=0;
        for(int j=i; j<nums.size(); j++)
        {
            sum += nums[j];
            if(max < sum)
                max = sum;
        }
    }
    return max;
}

int maxSubArray_Kadanes()
{
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    int max = nums[0];
    int sum =0;
    for(int i=0; i<nums.size(); i++)
    {
        sum =(sum+nums[i] > nums[i])? sum+nums[i] : nums[i];
        max = sum > max ? sum : max;
    }
    return max;
}

int maxCrossingSum(vector<int>&nums, int low, int mid, int high)
{
    int leftsum =INT_MIN;
    int sum =0;
    for(int i=mid; i>=low; i--)
    {
        sum = sum+nums[i];
        leftsum =max(leftsum, sum);
    }

    int rightsum = INT_MIN;
    sum=0;
    for(int i=mid+1; i<=high; i++)
    {
        sum = sum+nums[i];
        rightsum = max(rightsum, sum);
    }

    int css = leftsum+rightsum;
    return max(leftsum, rightsum, css);
}

int maxSubArraySum(vector<int>&nums,  int low, int high)
{
    //if(low > high)
     //   return 0;
    int maxSum =0;
    int mid = (low+high)/2;

    if(low==high)
    {
        cout<<"["<<nums[low]<<"] ";
        return nums[low];
    }

    //cout<<"low:"<<low<<" mid:"<<mid<<" high:"<<high<<endl;
    int leftmaxsum = maxSubArraySum(nums, low, mid); 
    int rightmaxsum = maxSubArraySum(nums, mid+1, high);
    int crossSum = maxCrossingSum(nums, low, mid, high);
    return max(leftmaxsum, rightmaxsum, crossSum);
}

int maxSubArray_DivideAndConquer()
{
    //vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums ={-2,1};//,-3,4,-1,2,1,-5,4};
    int max_index = nums.size()-1;
    int val = maxSubArraySum(nums, 0, max_index);
    cout<<"max: "<<val<<endl;
    return val;
}

void twoSum_BruteForece()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(target-nums[i] ==nums[j])
            {
                cout<<"["<<i<<","<<j<<"]"<<endl;
                break;
            }
        }
    }
}

void twoSum_Hash()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    unordered_map<int, int> hash;
    int key =0;
    for(int i=0; i<nums.size(); i++)
    {
        key = target-nums[i];
        if(hash.find(key) != hash.end())
            cout<<"["<<i<<","<<hash[key]<<"]"<<endl;
        else
            hash[nums[i]] = i;
    } 
}

int main()
{
    int choice =0;
    cout<<"1. containsDuplicate_HashTable 2.containsDuplicate_Set 3.maxSubArray_BruteForce "<<endl;
    cout<<"4. maxSubArray_Kadanes 5.maxSubArray_DivideAndConquer 6.twoSum_BruteForece"<<endl;
    cout<<"7. twoSum_Hash"<<endl;
    cout<<"Enter the choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<containsDuplicate_HashTable();
            break;
        }
        case 2:
        {
            cout<<containsDuplicate_Set();
            break;
        }
        case 3:            
            cout<<maxSubArray_BruteForce();
            break;
        case 4:
            cout<<maxSubArray_Kadanes();
            break;
        case 5:
            maxSubArray_DivideAndConquer();
            break;
        case 6:
            twoSum_BruteForece();
            break;
        case 7:
            twoSum_Hash();
            break;
        case 0:
        default:
            return 0; 
    }
    return 0;
}