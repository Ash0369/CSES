#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long

ll int mod=1e9+7;
ll int count(ll int n,vector<int>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    ll int ans=0;
    for(int i=1;i<=6;i++)
    {
        if(n>=i)
        {
            ans=(ans+count(n-i,dp))%mod;
        }
    }
    return dp[n]=ans;
}
int main()
{
    fast;
    ll int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<count(n,dp)<<endl;
    return 0;
}
