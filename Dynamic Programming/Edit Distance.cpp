#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    string a;
    string b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];

    //dp[i][j] denotes operation needed to match
    //a[i....n] and b[j....m]

    dp[n][m]=0;//If we reached end of both then no operation needed
    for(int i=0;i<m;i++)
    {
        dp[n][i]=m-i;//If we reached end of 1 string so now 
        //just we have to keep removing
    }
    for(int i=0;i<n;i++)
    {
        dp[i][m]=n-i;
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i+1][j+1];//If equal then no operation
            }
            else
            {
                //1
                ll int c1=INT_MAX;
                ll int c2=INT_MAX;
                ll int c3=INT_MAX;
                c1=dp[i][j+1]+1;//Insterting at ith and matched
                c2=dp[i+1][j]+1;//Removing ith
                c3=dp[i+1][j+1]+1;//Changed ith to jth

                dp[i][j]=min(c1,min(c2,c3));//Take minimum
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
