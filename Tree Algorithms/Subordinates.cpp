#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

vector<int>ans;
void dfs(int node,int par,vector<vector<int>>&vec)
{
    int child=0;
    for(auto x:vec[node])
    {
        if(x!=par)
        {
            dfs(x,node,vec);
            child+=1+ans[x-1];
        }
    }
    ans[node-1]=child;
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>>vec(n+1);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        vec[x].push_back(i);
        vec[i].push_back(x);
    }
    ans.resize(n,0);
    dfs(1,0,vec);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
