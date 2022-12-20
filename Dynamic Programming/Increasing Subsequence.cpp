#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int get_best_candidates(map<int,int>&candidates,int v)
{
    auto it=candidates.lower_bound(v);//smallest value greater then or equal to v
    if(it==candidates.begin())
        return 0;
    it--;//smallest value strictly less then v
    return it->second;
}
void check_and_insert(map<int,int>&candidates,int v,int adv)
{
    if(candidates[v]>=adv)
    {
        return;
    }
    else
    {
        candidates[v]=adv;
        auto it=candidates.find(v);
        it++;
        while(it!=candidates.end() && it->second<=adv)
        {
            auto temp=it;
            it++;
            candidates.erase(temp);
        }
    }
}

int main()
{
    fast;
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>dp(n+1,0);
    map<int,int>candidates;
    dp[0]=1;
    candidates[nums[0]]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1+get_best_candidates(candidates,nums[i]);
        check_and_insert(candidates,nums[i],dp[i]);
    }

    cout<<*max_element(dp.begin(),dp.end());  
    return 0;
}
