//Method-1 : Recurssive

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


//Method-2 : Iterative

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long


int main()
{
    fast;
    ll int mod=2*(1e9+7);
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
        ll int dp[n+1][req+1];//dp[i][j]
        //No of ways such that we make sum j till ith index
        dp[0][0]=1;
        for(int index=0;index<=n;index++)
        {
            for(int sum=0;sum<=req;sum++)
            {
                //Base case when index==0
                if(index==0)
                {
                    //so whatever sum is we cannot choose 
                    //but if sum==0 then 1 way
                    if(sum==0)
                    {
                        continue;
                    }
                    dp[index][sum]=0;
                    continue;
                }
                ll int pick=0;
                ll int nt_pick=0;

                
                nt_pick=dp[index-1][sum];
                if(sum>=index)
                {
                    pick=dp[index-1][sum-index];
                }
                dp[index][sum]=(pick+nt_pick)%mod;
            }
        }

        cout<<dp[n][req]/2<<endl;

    }
    return 0;
}
