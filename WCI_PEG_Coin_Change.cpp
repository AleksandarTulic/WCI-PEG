#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin>>x;

    int n;
    cin>>n;

    vector <int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];

    vector <int> dp(x+1,20000000);

    dp[0]=0;
    for (int i=0;i<n;i++)
        for (int j=1;j<=x;j++)
            if ( j>=a[i] ) dp[j]=min(dp[j],dp[j-a[i]]+1);

    cout<<dp[x]<<endl;
    return 0;
}
