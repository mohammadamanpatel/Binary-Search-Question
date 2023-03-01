
class Solution
{
  public:
    bool isPossibleSoln(int arr[],int n,int k,long long int soln)
    {
        int c = 1;
        long long int timeSum = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>soln)
            {
                return false;
            }
            if(timeSum+arr[i]>soln)
            {
                c++;
                timeSum = arr[i];
                if(c>k)
                {
                    return false;
                }
            }
            else
            {
                timeSum = timeSum + arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
      long long int start = 0;
      long long int end = 0;
      for(int i=0;i<n;i++)
      {
          end+=arr[i];
      }
      long long ans = -1;
      while(start<=end)
      {
          long long int mid = start + (end-start)/2;
          if(isPossibleSoln(arr,n,k,mid))
          {
              ans = mid;
              end = mid - 1;
          }
          else
          {
              start = mid + 1;
          }
          
      }
      return ans;
    }
};

