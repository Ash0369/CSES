#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int n;
    cin>>n;
    int dp[n+1];
    //dp[i] minimum stepes to change i to 0.
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1e9;
        int d=i;
        while(d>0)
        {
            int last=d%10;
            d=d/10;
            if(i>=last)
            {
                dp[i]=min(dp[i],1+dp[i-last]);
            }
            
        }
    }

    cout<<dp[n]<<endl;
    
    return 0;
}
