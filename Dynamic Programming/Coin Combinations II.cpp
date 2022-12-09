#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int mod=1e9+7;
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    int dp[n][x+1];
    //dp[i][x] is to form sum x with i coins.
    for(int i=0;i<n;i++)
    {
        for(int sum=0;sum<=x;sum++)
        {
            dp[i][sum]=0;
            if(sum==0)
            {
                dp[i][sum]=1;
                continue;
            }
            if(i>=1)
            {
                //Not took ith coin
                dp[i][sum]=dp[i-1][sum];
            }
            if(sum>=vec[i])
            {
                //Took ith coin
                dp[i][sum]=(dp[i][sum]+dp[i][sum-vec[i]])%mod;
            }
            
        }
    }

    cout<<dp[n-1][x]<<endl;
    
    return 0;
}
