#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool IsPossSoln(long long int soln,vector<long long int>tree,long long int m,long long int n)
{
    long long int sum = 0;
    for(long long int i = 0;i<tree.size();i++)
    {
       if(tree[i]>soln){
       sum += tree[i]-soln;
       }
    }
    return sum>=m;
}
int binarySearch(vector<long long int>tree,long long int m,long long int n)
{
    long long int start = 0;
    long long int end = *max_element(tree.begin(),tree.end());
    long long int soln = -1;
    while(start<=end)
    {
        long long int mid = start + (end-start)/2;
        if(IsPossSoln(mid,tree,m,n))
        {
            soln = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return soln;
}
int main()
{
    long long int m,n;
    cin>>m>>n;
    vector<long long int>tree;
    while(n--)
    {
        long long int height;
        cin>>height;
        tree.push_back(height);
    }
    cout<<binarySearch(tree,m,n)<<endl;
}
