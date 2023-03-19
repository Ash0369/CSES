//Method-1 : Segment Tree

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
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }

    ll int query(int index,int low,int high,int l,int r)
    {
        if(r<low || high<l)
        {
            return 1e10;
        }
        if(low>=l && high<=r)
        {
            return seg[index];
        }

        int mid=(low+high)/2;
        ll int left=query(2*index+1,low,mid,l,r);
        ll int right=query(2*index+2,mid+1,high,l,r);
        return min(left,right);
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

        seg[index]=min(seg[2*index+1],seg[2*index+2]);

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
        int type;
        cin>>type;
        int a,b;
        cin>>a>>b;
        if(type==1)
        {
            sg.update(0,0,n-1,a-1,b);
            continue;
        }
        a--;
        b--;
        cout<<sg.query(0,0,n-1,a,b)<<endl;
    }
    return 0;
}


//Method-2 : Square root decompostion

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
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
void print_with_precision(double val,int n)
{
    cout << fixed << setprecision(n) <<val<<endl;
}
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
ll int mod=1e9+7;
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
int ceil_div(ll int a,ll int b)
{
    int k=a%b;
    if(k>0) return (a/b)+1;
    return a/b;
}
ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
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
ll int Combination(ll int n,ll int r)
{
    ll int ans1=fact(n);ll int ans2=fact(r);
    ll int ans3=fact(n-r);ll int ans=(ans1*inv(ans2))%mod;
    ans=(ans*inv(ans3))%mod;return ans;
}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
double multiply(int n,double num){
    double ans=1.0;
    for(int i=0;i<n;i++)
    {ans*=num;}
    return ans;
}
double root(ll int num,int n,double precision)
{
    double low=1;
    double high=num;
    while((high-low)>precision){
        double mid=(high+low)/2.0;
        if(multiply(n,mid)<num){
            low=mid;}
        else{
            high=mid;}
    }
    return low;
}
vector<vector<ll int>> multiply(vector<vector<ll int>>&vec1,vector<vector<ll int>>&vec2)
{
    int n=vec1.size();
    vector<vector<ll int>>ans(n,vector<ll int>(n,0LL));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=(ans[i][j]+(vec1[i][k]*vec2[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll int>>matrix_exponent(vector<vector<ll int>>&vec,ll int k)
{
    int n=vec.size();
    vector<vector<ll int>>ans(n,vector<ll int>(n,0));
    for(int i=0;i<n;i++)
    {
        ans[i][i]=1LL;
    }
    while(k>0)
    {
        if(k%2==1)
        {
            ans=multiply(ans,vec);
        }
        vec=multiply(vec,vec);
        k=k/2;
    }
    return ans;

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
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]>=v2[0])
    {
        return true;
    }
    return false;
}

class square_root_decompostion
{
    public:
    vector<ll int>dp;
    int size;
    square_root_decompostion(ll int n)
    {
        ll int sz=sqrtl(n);
        sz++;
        dp.resize(sz,1e17);
        size=sz;
    }
    void build(vector<ll int>&vec)
    {
        for(int i=0;i<vec.size();i++)
        {
            dp[i/size]=min(dp[i/size],vec[i]);
        }
    }
    ll int query(vector<ll int>&vec,int left,int right)
    {
        ll int ans=1e17;
        while(left<=right && left%size!=0)
        {
            ans=min(ans,vec[left]);
            left++;
        }
        while(left+size-1<=right)
        {
            ans=min(ans,dp[left/size]);
            left=left+size;
        }
        while(left<=right)
        {
            ans=min(ans,vec[left]);
            left++;
        }
        return ans;
    }
    void update(vector<ll int>&vec,ll int u,ll int v)
    {
        vec[u]=v;
        int block=u/size;
        int start=block*size;
        int end=start+size;
        dp[block]=1e17;
        for(int i=start;i<end;i++)
        {
            dp[block]=min(dp[block],vec[i]);
        }
    }
};
//Code starts here
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
    while(tt--)
    {
        int n;
        cin>>n;
        int q;
        vector<ll int>vec(n);
        cin>>q;
        read(vec);
        square_root_decompostion srd(n);
        srd.build(vec);
        while(q--)
        {
            int c;
            cin>>c;
            ll int i,j;
            cin>>i>>j;
            if(c==2)
            {
                i--;
                j--;
                cout<<srd.query(vec,i,j)<<endl;
            }
            else
            {
                i--;
                srd.update(vec,i,j);
            }
            
        }
    } 
   // stop_execution
    //execution_time
    return 0;
}
