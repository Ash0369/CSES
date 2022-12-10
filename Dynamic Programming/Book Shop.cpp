#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int n,x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int dp[n+1][x+1];//Max no of pages if i have selecte till nth book and spend x ruppes
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<=x;j++)
       {
           if(i>=1)
           {
                dp[i][j]=dp[i-1][j];//Not taken ith book
           }
           if(i>=1 && j>=h[i])
           {
                //Taken ith book
                dp[i][j]=max(dp[i][j],s[i]+dp[i-1][j-h[i]]);
           }

           //For 0th book we can take it if we have amount more then require for it 
           if(i==0 && j<h[0])
           {
                dp[i][j]=0;
           }
           else if(i==0 && j>=h[0])
           {
                dp[i][j]=s[0];
           }
       }
    }

    cout<<dp[n-1][x]<<endl;
    
    return 0;
}
