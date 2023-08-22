//Author : silenttkillerr
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
#define pii pair<ll int,ll int>
#define piii pair<ll int,pair<ll int,ll int>>
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
void yn(bool res){if(res==true){yes;}else{no;}}
ll mod=1000000007;
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

ll int pwr(ll int a,ll int b,ll int &m)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2,m);ll int ans2=(ans1*ans1)%m;return ans2;}
    ll int ans1=pwr(a,b/2,m);ll int ans2=(ans1*ans1)%m;
    ans2=(ans2*a)%m;
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
    if(v1[3]>v2[3])
    {
        return true;
    }
    return false;
}

bool cmp2(vector<ll int>&v1,vector<ll int>&v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    return false;
}
//Code starts here

class segment_tree
{
    public:
    struct data
    {
        ll int value=0;
    };
    vector<data>sg;
    vector<data>lazy;
    segment_tree(int n)
    {
        data d;
        d.value=0;
        sg.resize(4*(n+1));
        lazy.resize(4*(n+1),d);
    }
    data make(ll int val)
    {
        data res;
        res.value=val;
        return res;
    }
    data combine(data a,data b)
    {
        if(a.value!=-1) return a;
        return b;
    }
    void push(int index)
    {
        sg[(2*index)+1].value+=lazy[index].value;
        lazy[(2*index)+1].value+=lazy[index].value;

        sg[(2*index)+2].value+=lazy[index].value;
        lazy[(2*index)+2].value+=lazy[index].value;

        lazy[index].value=0;
    }
    void build(int low,int high,vector<ll int>&arr,int index=0)
    {
        if(low>high)
        {
            return;
        }
        if(low==high)
        {
            sg[index]=make(arr[low]);
            return;
        }
        int mid=(low+high)/2;
        build(low,mid,arr,(2*index)+1);
        build(mid+1,high,arr,(2*index)+2);

        sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
    }
    data query(int low,int high,int lq,int rq,int index=0)
    {
        if(lq>rq)
        {
            return make(-1);
        }
        if(low==lq && high==rq)
        {
            return sg[index];
        }
        push(index);
        int mid=(low+high)/2;
        data left=query(low,mid,lq,min(rq,mid),(2*index)+1);
        data right=query(mid+1,high,max(lq,mid+1),rq,(2*index)+2);
        return combine(left,right);
    }
    /*void update(int low,int high,int pos,ll int val,int index=0)
    {
        if(low==high)
        {
            sg[index]=make(val);
        }
        else
        {
            int mid=(low+high)/2;
            if(pos<=mid)
            {
                update(low,mid,pos,val,(2*index)+1);
            }
            else
            {
                update(mid+1,high,pos,val,(2*index)+2);
            }
            sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
        }
    }*/
    void lazy_update(int low,int high,int left,int right,ll int val,int index=0)
    {
        if(left>right)
        {
            return;
        }
        else if(left==low && right==high)
        {
            lazy[index].value+=val;
            sg[index].value+=val;
        }
        else
        {
            push(index);
            int mid=(low+high)/2;
            lazy_update(low,mid,left,min(right,mid),val,(2*index)+1);
            lazy_update(mid+1,high,max(left,mid+1),right,val,(2*index)+2);
            sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
        }
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
        int n,q;
        cin>>n>>q;
        vector<ll int>vec(n);
        read(vec);

        segment_tree st(n);
        st.build(0,n-1,vec);
       
        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int a,b,u;
                cin>>a>>b>>u;
                a--;
                b--;
                st.lazy_update(0,n-1,a,b,u);
            }
            else
            {
                int k;
                cin>>k;
                k--;
                cout<<st.query(0,n-1,k,k).value<<endl;
            }
        }
    }
    //stop_execution
    //execution_time
    return 0; 
}
