//Method-1 : Without pre compution 3 test will pass

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

int main()
{
    
    fast;
    int t;
    cin>>t;
    while(t--)
    {
       
        int n;
        cin>>n;
        ll int dp[n+1][2];
        //dp[i] denotes ways to make building from i to n
        //dp[i][0] denotes ways if i-1 floor is dlink or 2 tiles of width 1
        //dp[i][1] denotes ways if i-1 floor is link or 1 tiles of width 2
        dp[n][0]=1;
        dp[n][1]=1;
      
        for(int i=n-1;i>=1;i--)
        {
            ll int op1=(dp[i+1][1]+dp[i+1][0])%mod;
            ll int op2=dp[i+1][0];
            ll int op3=(dp[i+1][0]<<1)%mod;
            ll int op4=dp[i+1][1];
            dp[i][0]=(op1+op2+op3)%mod;
            dp[i][1]=(op1+op4)%mod;
        }
        cout<<(dp[1][0]+dp[1][1])%mod<<endl;
    }
    return 0;
}

//Method-2 : All cases passed

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

int maxn=1000005;
ll int dp[1000006][2];
void pre()
{
    dp[1][0]=1;
    dp[1][1]=1;
      
    for(int i=2;i<maxn;i++)
    {
        ll int op1=(dp[i-1][1]+dp[i-1][0])%mod;
        ll int op2=dp[i-1][0];
        ll int op3=(dp[i-1][0]<<1)%mod;
        ll int op4=dp[i-1][1];
        dp[i][0]=(op1+op2+op3)%mod;
        dp[i][1]=(op1+op4)%mod;
    }
}
int main()
{
    
    fast;
    int t;
    cin>>t;
    pre();
    while(t--)
    {
        int n;
        cin>>n;
        //dp[i] denotes ways to make building from i to n
        //dp[i][0] denotes ways if i-1 floor is dlink or 2 tiles of width 1
        //dp[i][1] denotes ways if i-1 floor is link or 1 tiles of width 2
        
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }
    return 0;
}
