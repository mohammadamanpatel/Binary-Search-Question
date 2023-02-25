class Solution {
public:
    int bs(vector<int>&nums,int target,int start)
    {
        int end = nums.size()-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++)
        {
           if(bs(nums,nums[i]+k,i+1)!=-1)
           {
               ans.insert({nums[i],nums[i]+k});
           }
        }
        return ans.size();
    }
};
