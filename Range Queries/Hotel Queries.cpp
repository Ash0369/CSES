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
void entry_check(){cout<<"Entered"<<endl;}
void _debugger_printer(int x)
{
    cerr<<"[ "<<x<<" ]";
}
void _debugger_printer(ll int x)
{
    cerr<<"[ "<<x<<" ]";
}
void _debugger_printer(string x)
{
    cerr<<"[ "<<x<<" ]";
}
void _debugger_printer(char x)
{
    cerr<<"[ "<<x<<" ]";
}
template<class T>void _debugger_printer(vector<T>x)
{
    cerr<<"[ ";
    for(T y:x)
    {
        _debugger_printer(y);
    }
    cerr<<"]";
}
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_debugger_printer(x);cerr<<endl;
#else 
#define debug(x)
#endif

void yn(bool res){if(res==true){yes;}else{no;}}
//const ll mod=1000000007;
const ll mod=998244353;
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
template<class T>
void read1(vector<T>&v) 
{
    for(int i=1;i<v.size();i++)
    {
        cin>>v[i];
    }
}
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]>=v2[0])
    {
        return true;
    }
    return false;
}
//code starts here

class segment_tree
{
    public:
    vector<int>data;
    segment_tree(int n)
    {
        data.resize((4*n)+5,0);
    }
    void build(int index,int left,int right,vector<int>&vec)
    {
        if(left==right)
        {
            data[index]=vec[left];
            return;
        }
        int mid=(left+right)/2;

        build((2*index)+1,left,mid,vec);
        build((2*index)+2,mid+1,right,vec);

        data[index]=max(data[(2*index)+1],data[(2*index)+2]);
    }
    void update(int index,int left,int right,int pos,int value)
    {
        if(left==right)
        {
            data[index]=value;
            return;
        }
        int mid=(left+right)/2;

        if(pos<=mid)
        {
            update((2*index)+1,left,mid,pos,value);
        }
        else
        {
            update((2*index)+2,mid+1,right,pos,value);
        }
        data[index]=max(data[(2*index)+1],data[(2*index)+2]);
    }
    int query(int index,int left,int right,int val)
    {
        if(left==right)
        {
            if(data[index]>=val)
            {
                return left;
            }
            return 1000000;
        }
        int mid=(left+right)/2;
        if(data[(2*index)+1]>=val)
        {
            return query((2*index)+1,left,mid,val);
        }
        if(data[(2*index)+2]>=val)
        {
            return query((2*index)+2,mid+1,right,val);
        }
        return 1000000;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    fast;
    //start_execution
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;

        vector<int>vec(n);
        vector<int>v(q);
        read(vec);
        read(v);

        segment_tree sg(n);
        sg.build(0,0,n-1,vec);

        for(auto x:v)
        {
            int pos=sg.query(0,0,n-1,x);
            if(pos==1000000)
            {
                cout<<0<<" ";
                continue;
            }
            cout<<pos+1<<" ";
            vec[pos]=vec[pos]-x;
            sg.update(0,0,n-1,pos,vec[pos]);
        }
        cout<<endl;
    } 
    //stop_execution
    //execution_time
    return 0;
}
