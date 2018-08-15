#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector <int> dp(100001,0);
    int sum = 0;

    for (int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        sum+=2*c;

        dp[b]=dp[a]+c;
    }

    sort(dp.begin(),dp.end());

    cout<<sum-dp[dp.size()-1]<<endl;
    return 0;
}
