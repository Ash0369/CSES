#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int mod=1e9+7;
    int n,m;
    cin>>n>>m;
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    int dp[n+1][m+1];//No of valid array till nth index if at ith index we have m
    for(int i=0;i<n;i++)
    {
        //Base case
        if(i==0)
        {
            //if first element is 0 then it can be anything from 1 to m
            if(x[i]==0)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[0][j]=1;
                }
            }
            else
            {
                //If first elemnt is not zero then only when 1st elemnt ends with x[0] then 1
                for(int j=0;j<=m;j++)
                {
                    dp[0][j]=0;
                }
                dp[0][x[0]]=1;
            }
            continue;
        }
        
        for(int j=1;j<=m;j++)
        {
            //If we already have anything on that place and we are asking anything such that its should not end with that then it will be zero
            if(x[i]!=0 && x[i]!=j)
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(j>1)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
            if(j<m)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
        }
        
    }

    ll int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=(ans+dp[n-1][i])%mod;
    }

    cout<<ans<<endl;
    
    return 0;
}
