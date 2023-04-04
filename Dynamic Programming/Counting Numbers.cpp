#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

ll int dp[20][14][2][2];
ll int way(string &curr,int n,int last,bool tight,bool leading)
{
    if(n==0)
    {
        return 1;
    }
    int ub=9;
    if(tight)
    {
        ub=curr[curr.size()-n]-'0';
    }
    if(dp[n][last][tight][leading]!=-1)
    {
        return dp[n][last][tight][leading];
    }
    
    ll int ans=0;
    for(int i=0;i<=ub;i++)
    {
        if(leading==true && i==0)
        {
            //Means we are putting 0 at leading so there can be 00 adjacent.
            ans+=way(curr,n-1,i,tight&(i==ub),true);
            continue;
        }
        if(i==last)
        {
            continue;
        }
       
        ans+=way(curr,n-1,i,tight&(i==ub),false);
    }
    return dp[n][last][tight][leading]=ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int a,b;
    cin>>a>>b;
    string l=to_string(a-1);
    string r=to_string(b);

    memset(dp,-1,sizeof(dp));
    ll int ans=way(r,r.size(),10,true,true);
    //cout<<ans<<endl;
    if(a>=1)
    {
        memset(dp,-1,sizeof(dp));
        ans=ans-way(l,l.size(),10,true,true);
    }
    cout<<ans<<endl;
    return 0;
}
