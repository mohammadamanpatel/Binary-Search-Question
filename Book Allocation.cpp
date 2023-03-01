class Solution 
{
    public:
    bool isPossibleSoln(int A[],int N,int M,int sol)
    {
        int pageSum = 0;
        int c = 1;
        for(int i=0;i<N;i++)
        {
            if(A[i]>sol)
            {
                return false;
            }
            if(pageSum+A[i]>sol)
            {
                c++;
                pageSum = 0;
                pageSum = A[i];
                if(c>M)
                {
                    return false;
                }
            }
            else
            {
                pageSum+=A[i];
            }
            
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
      int start = 0;
      int end = accumulate(A,A+N,0);
      int Ans = -1;
      if(M>N)
      {
          return -1;
      }
      while(start<=end)
      {
          int mid = start+(end-start)/2;
          if(isPossibleSoln(A,N,M,mid))
          {
              Ans = mid;
              end = mid-1;
          }
          else
          {
              start = mid+1;
          }
      }
      return Ans;
    }
};
