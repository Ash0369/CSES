#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

void count(set<int>&st,int index,int sum,int n, vector<int>&vec,vector<vector<int>>&dp)
{
    if(dp[index][sum]!=-1)
    {
        return;
    }
    if(sum!=0)
       st.insert(sum);
    if(index==n)
    {
        return;
    }

    count(st,index+1,sum+vec[index],n,vec,dp);
    count(st,index+1,sum,n,vec,dp);
    dp[index][sum]=1;
}
int main()
{
    fast;
    int n;
    cin>>n;

    vector<int>vec(n);
    vector<vector<int>>dp(n+1,vector<int>(100001,-1));
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    set<int>ans;
    count(ans,0,0,n,vec,dp);
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
