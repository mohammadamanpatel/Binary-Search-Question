#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bs(vector<int>nums,int start,int end,int target)
{
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}
int exponentialSearch(vector<int>nums,int x)
{
    int end = nums.size()-1;
    
    if(nums[0]==x)
    {
        return 0;
    }
    int i = 1;
    while(i<nums.size() and nums[i]<=x)
    {
        i = i*2;
    }
    return bs(nums,i/2,min(i,end),x);
}
int main()
{
    vector<int>nums = {10,11,12,13,56,60,67,80,90,94,98};
    int x = 98;
    int ans = exponentialSearch(nums,x);
    cout<<ans;
    return 0;
}
