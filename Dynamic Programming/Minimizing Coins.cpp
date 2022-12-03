#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long

ll int distrbute(vector<ll int>&vec, vector<ll int>&dp,ll int x)
{
    if(x==0)
    {
        return 0;//Sucesufully Distributed
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll int ans=INT_MAX;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]<=x)
        {
            ans=min(ans,1+distrbute(vec,dp,x-vec[i]));
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
    ll int res=distrbute(vec,dp,x);
    if(res==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<res<<endl;
    }
    return 0;
}
