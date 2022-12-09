#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int mod=1e9+7;
    int n;
    cin>>n;
    vector<vector<char>>vec(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    int dp[n+1][n+1];
    dp[0][0]=1;
    if(vec[0][0]=='*')
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
            if(i==0 && j==0)
            {
                continue;
            }
            dp[i][j]=0;
            if(vec[i][j]=='*')
            {
                continue;
            }
            if(i>=1)
            {
                dp[i][j]=dp[i-1][j];
            }
            if(j>=1)
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            }
       }
    }

    cout<<dp[n-1][n-1]<<endl;
    
    return 0;
}
