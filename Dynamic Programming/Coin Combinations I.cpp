//Method-1 : Will give TLE for large test cases


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int ways(vector<ll int>&vec,vector<ll int>&dp,ll int x)
{
    if(x==0)
    {
        return 1;//Sucesufully Distributed
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]<=x)
        {
            ans+=ways(vec,dp,x-vec[i])%mod;
        }
        else
        {
            break;
        }
    }
    return dp[x]=ans;
}
int main()
{
    fast;
    ll int n,x;
    cin>>n>>x;
    vector<ll int>vec(n);
    vector<ll int>dp(x+1,-1);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    ll int res=ways(vec,dp,x)%mod;
   
    cout<<max(0LL,res)<<endl;
    
    return 0;
}
