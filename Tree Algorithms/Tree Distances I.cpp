#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

vector<int>depth;
void dfs(int node,int parent,vector<vector<int>>&graph)
{
    int an=0;
    for(int x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,node,graph);
        an=max(an,1+depth[x]);
    }
    depth[node]=an;
}
vector<int>ans;
void solve(int cur,int parent,int partial,vector<vector<int>>&graph)
{
    vector<int>pm;
    vector<int>sm;

    for(auto x:graph[cur])
    {
        if(x!=parent)
        {
            pm.push_back(depth[x]);
            sm.push_back(depth[x]);
        }
    }

    for(int i=1;i<pm.size();i++)
    {
        pm[i]=max(pm[i],pm[i-1]);
    }
    for(int i=sm.size()-2;i>=0;i--)
    {
        sm[i]=max(sm[i],sm[i+1]);
    }

    int child_no=0;

    for(auto node:graph[cur])
    {
        if(node!=parent)
        {
            int op1=-1;
            int op2=-1;

            if(child_no!=0)
            {
                op1=pm[child_no-1];
            }
            if(child_no!=pm.size()-1)
            {
                op2=sm[child_no+1];
            }

            int partial_ans=1+max(partial,max(op1,op2));

            solve(node,cur,partial_ans,graph);

            child_no++;

        }
    }
    int full_depth=-1;
    if(pm.size()!=0)
    {
        full_depth=pm.back();
    }

    ans[cur]=1+max(partial,full_depth);

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
    depth.resize(n+1);
    ans.resize(n+1);
    dfs(1,-1,graph);
    solve(1,-1,-1,graph);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}
