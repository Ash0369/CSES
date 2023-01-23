#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

vector<vector<int>>dp;
//dp[i][0] not selecting any edge connected to i'th node
//dp[i][1] selecting an edge connected to i'th node

void dfs(int node,int parent,vector<vector<int>>&graph)
{
    vector<int>prefix;
    vector<int>suffix;
    dp[node][0]=0;
    dp[node][1]=0;
    bool leaf=true;
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        leaf=false;
        dfs(x,node,graph);
    }
    if(leaf)
    {
        return;
    }
    for(auto x:graph[node])
    {
        if(x!=parent)
        {
            prefix.push_back(max(dp[x][0],dp[x][1]));
            suffix.push_back(max(dp[x][0],dp[x][1]));
        }
    }
    for(int i=1;i<prefix.size();i++)
    {
        prefix[i]+=prefix[i-1];
    }
    for(int i=suffix.size()-2;i>=0;i--)
    {
        suffix[i]+=suffix[i+1];
    }

    dp[node][0]=suffix[0];//Not selecting parent then take sum of all children
    int child=0;
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        //Taking edge betwwen parent at x.
        int left=0;
        int right=0;

        if(child!=0)
        {
            left=prefix[child-1];
        }
        if(child!=suffix.size()-1)
        {
            right=suffix[child+1];
        }
        dp[node][1]=max(dp[node][1],1+left+right+dp[x][0]);
        child++;
    }
}
int main()
{
    
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
    dp.resize(n+1,vector<int>(2,0));
    dfs(1,-1,graph);
    cout<<max(dp[1][0],dp[1][1])<<endl;
    
    return 0;
}
