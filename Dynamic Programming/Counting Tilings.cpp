#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
const int mod=1e9+7;

void check(int n,int i,int curr_mask,int mask,vector<int>&possible)
{
    if(i==n+1)
    {
        possible.push_back(mask);
        return;
    }
    if((curr_mask&(1<<i))!=0)
    {
        //means already placed
        check(n,i+1,curr_mask,mask,possible);
    }
    if((curr_mask&(1<<i))==0)
    {
        //means not placed, so put a horizontal
        check(n,i+1,curr_mask,mask+(1<<i),possible);
    }
    if(i!=n)
    {
        if((curr_mask&(1<<i))==0 && (curr_mask&(1<<(i+1)))==0)
        {
            //place a vertical
            check(n,i+2,curr_mask,mask,possible);
        }
    }
}
ll int dp[1005][1<<12];
ll int way(int col,int m,int n,int curr)
{
    if(col==m+1)
    {
        if(curr==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[col][curr]!=-1)
    {
        return dp[col][curr];
    }
    vector<int>possible;
    check(n,1,curr,0,possible);
    ll int ans=0;
    for(auto x:possible)
    {
        ans=(ans+way(col+1,m,n,x))%mod;
    }
   
    return dp[col][curr]=ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<way(1,m,n,0)<<endl;
    return 0;
}
