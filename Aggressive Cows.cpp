class Solution {
public:
    bool ispossibleSoln(int n,int k,vector<int>&stalls,int mid)
    {
        int c = 1;  //cow Count
        int pos = stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i] - pos >= mid)
            {
                c++;
                pos = stalls[i]; //ab jo pos hai wo bhi update hogi
            }
            if(c == k)
            {
                return true; //means aapne saare cows place kar diye barabar
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) 
    {
     sort(stalls.begin(),stalls.end());
     int ans = -1;
     int start = 0;
     int end = stalls[stalls.size()-1] - stalls[0];
     while(start<=end)
     {
         int mid = start + (end-start)/2;
         if(ispossibleSoln(n,k,stalls,mid))
         {
             ans = mid;
             start = mid + 1;
         }
         else
         {
             end = mid - 1;
         }
     }
     return ans;
    }
};
