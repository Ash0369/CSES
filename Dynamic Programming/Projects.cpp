//Method-1 : 

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int n;
//2 projects not have same starting or same ending point
int getindex(vector<ll int>&sti,int val)
{
    auto it=upper_bound(sti.begin(),sti.end(),val);
    if(it==sti.end())
    {
        return -1;
    }
    else
    {
        return distance(sti.begin(),it); 
    }
}
ll int profit(int index,vector<pair<ll int,pair<ll int,ll int>>>&vec,vector<ll int>&sti,vector<ll int>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    ll int choose=vec[index].second.second;
    int j=getindex(sti,vec[index].second.first);//Finding 1st index whose starting point is greater then ending point of current project
    if(j!=-1)
    {
        choose+=profit(j,vec,sti,dp);
    }
    ll int not_choose=profit(index+1,vec,sti,dp);

    return dp[index]=max(choose,not_choose);
}

bool cmp(pair<ll int,pair<ll int,ll int>>&p1,pair<ll int,pair<ll int,ll int>>&p2)
{
    if(p1.first<p2.first)
    {
        return true;
    }
    return false;
}
int main()
{
    fast;
    cin>>n;
    vector<pair<ll int,pair<ll int,ll int>>>vec;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vec.push_back({a,{b,c}});
    }  

    sort(vec.begin(),vec.end(),cmp);//Sorting based on starting point
    vector<ll int>sti;
    for(auto x:vec)
    {
        sti.push_back(x.first);
    }
    vector<ll int>dp(n+1,-1);
    cout<<profit(0,vec,sti,dp)<<endl;
    return 0;
}
