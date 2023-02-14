#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;

    ll int n;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }

    cout<<st.size()<<endl;

    return 0;
}
