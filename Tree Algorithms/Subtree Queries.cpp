#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string>
#include<bitset>
#include<stdio.h>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<iterator>
#include<list>
#include<iomanip>
#include<chrono>
#include<unordered_set>
#include<string>
#include<cmath>
#include<cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define cout std::cout
#define cin std::cin
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
#define pb push_back
#define vll vector<long long int>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)
//less , less_equal , greater , greater_equal -> rule for insertion
#define start_execution auto start = std::chrono::high_resolution_clock::now();
#define stop_execution auto stop = std::chrono::high_resolution_clock::now();
#define execution_time auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); cerr<<"Time taken : "<<((long double)duration.count())/((long double)1e9) <<"s"<<endl; 
#define nline "\n"
#define all(v) (v).begin(),(v).end()
#define pii pair<int,int>
#define mem(a,k) memset(a,k,sizeof(a));
// void print_with_precision(double val,int n)
// {
//     cout << fixed << setprecision(n) <<val<<endl;
// }
void debug(int x)
{
    cout<<"Value Debugged is "<<x<<endl;
}
void debug(vector<int>x)
{
    cout<<"Value Debugged is "<<endl;
    for(auto y:x)
    {
        cout<<y<<" ";
    }
    cout<<endl;
}
const ll mod=1000000007;
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll mod_div(ll a,ll b){return (a*inv(b))%mod;}
ll int ceil_div(ll int a,ll int b)
{
    ll int k=a%b;
    if(k>0) return (a/b)+1;
    return a/b;
}
ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
ll int lcm(ll int a,ll int b)
{
    ll int g=__gcd(a,b);
    return (1LL*a*b)/g;
}
ll int pwr(ll int a,ll int b)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;return ans2;}
    ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
ll int fact(ll int n)
{
    if(n<0)
    {return 0;}
    ll int ans=1;
    if(n==0) return 1;
    for(int i=1;i<=n;i++){ans=(ans*i)%mod;}return ans;
}
vector<ll> sieve(int n)
{
    int*arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
    if (arr[i] == 0)
    {
        vect.push_back(i);
        for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
    return vect;
}
/*ll int Combination(ll int n,ll int r)
{
    void pre()
    {
        for(int i=1;i<=100003;i++)
        {
            dp[i]=(1LL*dp[i-1]*i)%mod;
        }
    }
    if(r==0)
    {
        return 1;
    }
    ll int ans1=dp[n];ll int ans2=dp[r];
    ll int ans3=dp[n-r];ll int ans=(ans1*inv(ans2))%mod;
    ans=(ans*inv(ans3))%mod;return ans;
}*/
 
template<class ForwardIterator>
void read(ForwardIterator first,ForwardIterator last) 
{
    while (first != last) 
    {
        cin >> (*first);
        ++first;
    }
}
template<class T>
void read(vector<T> &v) 
{
    read(v.begin(), v.end());
}
vector<vector<int>>tree_input(int n)
{
    vector<vector<int>>tree(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    return tree;
}
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]>v2[0])
    {
        return true;
    }
    return false;
}
//Code starts here


int n;
int intime[200005];
int outime[200005];
int tx=0;
vector<ll int>euler;
void dfs(int index,int parent,vector<vector<int>>&tree)
{
    euler.push_back(index);
    intime[index]=tx;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        tx++;
        dfs(x,index,tree);
    }
    tx++;
    euler.push_back(index);
    outime[index]=tx;
}


class segment_tree
{
    public:
    struct data
    {
        ll int data=0;
    };
    vector<data>seg;
    vector<ll int>lazy;
    segment_tree(ll int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void push(int index)
    {
        seg[2*index+1].data+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        seg[2*index+2].data+=lazy[index];
        lazy[2*index+2]+=lazy[index];
        lazy[index]=0;
    }
    data make(int val)
    {
        data res;
        res.data=val;
        return res;
    }
    data combine(data a,data b)
    {
        data res;
        res.data=a.data+b.data;
        return res;
    }
    void build(ll int index,ll int low,ll int high,vector<ll int>&arr)
    {
        if(low>high)
        {
            return;
        }
        if(low==high)
        {
            seg[index]=make(arr[low]);
            return;
        }
        ll int mid=(low+high)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index]=combine(seg[2*index+1],seg[2*index+2]);
    }
    data query(ll int index,ll int low,ll int high,ll int l,ll int r)
    {
        if(r<low || high<l || l>r)
        {
            return make(0);
        }
        if(low==l && high==r)
        {
            return seg[index];
        }
        push(index);
        ll int mid=(low+high)/2;
        data left=query(2*index+1,low,mid,l,min(r,mid));
        data right=query(2*index+2,mid+1,high,max(l,mid+1),r);
        return combine(left,right);
    }
    void update(ll int index,ll int low,ll int high,ll int l,ll int r,ll int val)
    {
        if(r<low || high<l || low>high)
        {
            return;
        }
        if(low==l && high==r)
        {
            seg[index]=make(val);
            lazy[index]+=val;
            return;
        }
        push(index);
        ll int mid=(low+high)/2;
        update(2*index+1,low,mid,l,min(r,mid),val);
        update(2*index+2,mid+1,high,max(l,mid+1),r,val);
        seg[index]=combine(seg[2*index+1],seg[2*index+2]);
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    //start_execution
    int tt=1;
    //cin>>tt;
    for(int tc=0;tc<tt;tc++)
    {
        int m;
        cin>>n>>m;
        tx=0;
        vector<int>val(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>val[i];
        }
        vector<vector<int>>tree(n+1);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        euler.clear();
        dfs(1,-1,tree);
        int len=2*n;
        segment_tree sg(len);
        vector<ll int>value;
        for(auto x:euler)
        {
            value.push_back(val[x]);
        }
        sg.build(0,0,(2*n)-1,value);
        while(m--)
        {
            int type;
            cin>>type;
            if(type==2)
            {
                int node;
                cin>>node;
                int l=intime[node];
                int r=outime[node];
                cout<<sg.query(0,0,len-1,l,r).data/2<<endl;
            }
            else
            {
                int s,x;
                cin>>s>>x;
                sg.update(0,0,len-1,intime[s],intime[s],x);
                sg.update(0,0,len-1,outime[s],outime[s],x);
            }
        }

    }
    //stop_execution
    //execution_time
    return 0; 
}
