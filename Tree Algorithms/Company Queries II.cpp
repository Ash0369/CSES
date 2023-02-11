#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007


vector<vector<int>>dp;
vector<int>level;
void dfs(int src,int par,int lvl,vector<vector<int>>&graph)
{
    level[src]=lvl;
    for(auto child:graph[src])
    {
        if(child!=par)
        {
            dfs(child,src,lvl+1,graph);
        }
    }
}

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


int lift_node(int node,int jump)
{
    for(int i=19;i>=0;i--)
    {
        if(jump==0 || node==-1)
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


//log(n)*log(n)
int lca_binary_search(int u,int v)
{
    if(level[u]<level[v])
    {
        swap(u,v);
    }
    u=lift_node(u,level[u]-level[v]);
    int low=0;
    int high=level[u];
    int ans=high;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int x1=lift_node(u,mid);
        int x2=lift_node(v,mid);

        if(x1==x2)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return lift_node(u,ans);
}


//without binary search
//logn

int lca(int u,int v)
{
    if(level[u]<level[v])
    {
        swap(u,v);
    }
    u=lift_node(u,level[u]-level[v]);

    if(u==v)
    {
        return u;
    }

    for(int i=19;i>=0;i--)
    {
        if(dp[u][i]!=dp[v][i])
        {
            u=dp[u][i];
            v=dp[v][i];
        }
    }

    //return lift_node(u,1);
    //or
    return dp[u][0];
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
    level.resize(n+1,0);
    dfs(1,-1,0,graph);
    binary_lifting(1,-1,graph);
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }

    return 0;
}
