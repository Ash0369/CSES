#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

int n;
int dp[200005][30];

void binary_lifting()
{
    for(int i=1;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a=dp[j][i-1];
            dp[j][i]=dp[a][i-1];
        } 
    }
}
int lift_node(int node,int jump)
{
    for(int i=29;i>=0;i--)
    {
        if(jump==0)
        {
            break;
        }
        if(jump>=(1<<i))
        {
            jump-=1<<i;
            node=dp[node][i];
        }
    }
    return node;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int q;
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        dp[i][0]=a;
    }
   
    binary_lifting();
    
    for(int i=0;i<q;i++)
    {
        int x,k;
        cin>>x>>k;
        cout<<lift_node(x,k)<<endl;
    }

    return 0;
}
