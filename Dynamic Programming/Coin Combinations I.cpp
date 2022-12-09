#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    int mod=1e9+7;
    fast;
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    int dp[x+1];
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        dp[i]=0;
        for(auto c:vec)
        {
            if((i-c)>=0)
            {
                dp[i]=(dp[i]+dp[i-c])%mod;
            }
            
        }
    }
    cout<<dp[x]<<endl;
    
    return 0;
}
