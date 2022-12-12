#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

ll int ways(int n,int req,int i,vector<vector<ll int>>&dp)
{
    
    int mod=2*(1e9+7); //As our final answer is divided by 2
    if(req==0)
    {
        return 1;
    }
    if(i>n || req<0)
    {
        return 0;
    }
    if(dp[i][req]!=-1)
    {
        return dp[i][req];
    }
    ll int pick=ways(n,req-i,i+1,dp);
    ll int not_pick=ways(n,req,i+1,dp);

    return dp[i][req]=(pick+not_pick)%mod;
}
int main()
{
    fast;
    int n;
    cin>>n;
    ll int req=n*(n+1)/2;
    if(req%2!=0)
    {
        cout<<0<<endl;
    }
    else
    {
        req=req>>1;
        vector<vector<ll int>>dp(n+2,vector<ll int>(req+2,-1));
        ll int ans=(ways(n,req,1,dp)/2);
        cout<<ans<<endl;
    }
    return 0;
}
