#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

class segment_tree
{
    public:
    vector<ll int>seg;
    segment_tree(int n)
    {
        seg.resize(4*n+1);
    }
    void build(int index,int low,int high,vector<int>&arr)
    {
        if(low==high)
        {
            seg[index]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index]=seg[2*index+1]^seg[2*index+2];
    }

    ll int query(int index,int low,int high,int l,int r)
    {
        if(r<low || high<l)
        {
            return 0;
        }
        if(low>=l && high<=r)
        {
            return seg[index];
        }

        int mid=(low+high)/2;
        ll int left=query(2*index+1,low,mid,l,r);
        ll int right=query(2*index+2,mid+1,high,l,r);
        return left^right;
    }
    
    void update(int index,int low,int high,int i,int val)
    {
        if(low==high)
        {
            seg[index]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid)
        {
            update(2*index+1,low,mid,i,val);
        }
        else
        {
            update(2*index+2,mid+1,high,i,val);
        }

        seg[index]=seg[2*index+1]+seg[2*index+2];

    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    int n,q;
    cin>>n>>q;

    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    segment_tree sg(n);
    sg.build(0,0,n-1,vec);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cout<<sg.query(0,0,n-1,a,b)<<endl;
    }
    return 0;
}
