#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007


vector<vector<int>>dp;

void binary_lifting(int curr,int parent,vector<vector<int>>&graph)
{
    dp[curr][0]=parent;

    for(int i=1;i<20;i++)
    {
        if(dp[curr][i-1]!=-1)
        {
            int a=dp[curr][i-1];
            dp[curr][i]=dp[a][i-1];
        }
        else
        {
            dp[curr][i]=-1;
        }
    }

    for(auto x:graph[curr])
    {
        if(x!=parent)
        {
            binary_lifting(x,curr,graph);
        }
    }
}

int query(int node,int jump)
{
    if(node==-1 || jump==0)
    {
        return node;
    }
    for(int i=19;i>=0;i--)
    {
        if(jump>=(1<<i))
        {
            return query(dp[node][i],jump-(1<<i));
        }
    }
    return -1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int n,q;
    cin>>n>>q;
    vector<vector<int>>graph(n+1);
    for(int i=2;i<=n;i++)
    {
        ll int a;
        cin>>a;
        graph[a].push_back(i);
    }
    dp.resize(n+1,vector<int>(20,0));
    binary_lifting(1,-1,graph);
    for(int i=0;i<q;i++)
    {
        int x,k;
        cin>>x>>k;

        cout<<query(x,k)<<endl;
    }

    return 0;
}
