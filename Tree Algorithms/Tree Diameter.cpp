#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

vector<vector<int>>dp;
int ans=0;
void adj(int &mx1,int &mx2,int dist)
{
    if(dist>=mx1)
    {
        swap(mx1,mx2);
        mx1=dist;
    }
    else if(dist>=mx2)
    {
        mx2=dist;
    }
}
int dfs(int node,int parent,vector<vector<int>>&graph)
{
    int mx1=0;
    int mx2=0;

    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        int dist=1+dfs(x,node,graph);
        adj(mx1,mx2,dist);
    }
    ans=max(ans,mx1+mx2);
    return mx1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    int n;
    cin>>n;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,0,graph);
    cout<<ans<<endl;


    return 0;
}
