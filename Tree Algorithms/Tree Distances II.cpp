#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

vector<ll int>subtree;
vector<ll int>ans;
vector<ll int>no_node;
ll int N;
void dfs(ll int node,ll int parent,vector<vector<ll int>>&graph)
{
    ll int an=0;
    ll int nd=1;
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,node,graph);
        an+=subtree[x]+no_node[x];
        nd+=no_node[x];
    }
    subtree[node]=an;
    no_node[node]=nd;
}
void calculate(ll int node,ll int parent,ll int partial,vector<vector<ll int>>&graph)
{
    ans[node]=subtree[node]+partial+N-no_node[node];
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        ll int p=ans[node]-subtree[x]-no_node[x];
        calculate(x,node,p,graph);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int n;
    cin>>n;
    vector<vector<ll int>>graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        ll int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    subtree.resize(n+1,0);
    ans.resize(n+1,0);
    no_node.resize(n+1,0);
    dfs(1,-1,graph);
    N=no_node[1];
    ans[1]=subtree[1];
    calculate(1,-1,0,graph);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
