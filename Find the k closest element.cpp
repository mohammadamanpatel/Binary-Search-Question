class Solution {
public:
    vector<int> twoPtrMethod(vector<int>arr,int k,int x)
    {
        int a = 0;
        int b = arr.size()-1;
        vector<int>brr;
        while(abs(a-b)>=k)
        {
            if(abs(arr[a]-x)>abs(arr[b]-x))
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        for(int i=a;i<=b;i++)
        {
            brr.push_back(arr[i]);
        }
        return brr;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPtrMethod(arr,k,x);
    }
};
