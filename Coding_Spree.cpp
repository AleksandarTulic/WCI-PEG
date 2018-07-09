#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;

    int a[n],b[n];

    for (int i=0;i<n;i++) cin>>a[i]>>b[i];

    int dp[n][t+1];

    for (int i=0;i<=t;i++)
        if ( i >= b[0] ) dp[0][i]=a[0];
        else dp[0][i]=0;
    for (int i=0;i<n;i++)
        dp[i][0]=0;

    for (int i=1;i<n;i++)
        for (int j=1;j<=t;j++)
            if ( j>=b[i] ) dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i]]+a[i]);
            else dp[i][j]=dp[i-1][j];

    cout<<dp[n-1][t]<<endl;
    return 0;
}
