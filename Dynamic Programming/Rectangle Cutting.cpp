#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int main()
{
    fast;
    int a,b;
    cin>>a>>b;

    int dp[a+1][b+1];//dp[i][j] is minimum cuts for rectangle size a*b

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            int c1=INT_MAX;
            if(j==i)
            {
                dp[i][j]=0;//If side equal then no need of cut
                continue;
            }
            //Cutting horizolally
            for(int k=1;k<j;k++)
            {
                c1=min(c1,1+dp[i][k]+dp[i][j-k]);
            }
            //Cutting vertically
            for(int k=1;k<i;k++)
            {
                c1=min(c1,1+dp[k][j]+dp[i-k][j]);
            }
            dp[i][j]=c1;
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}
