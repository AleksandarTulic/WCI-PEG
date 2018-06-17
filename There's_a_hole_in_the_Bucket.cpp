#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sum,n;
    cin>>sum>>n;

    while (sum!=0 && n!=0)
    {
        int a[n];
        for (int i=0;i<n;i++) cin>>a[i];

        vector <int> DP(sum+1,20000000);
        DP[0]=0;

        for (int i=0;i<n;i++)
            for (int j=1;j<=sum;j++)
                if (j>=a[i]) DP[j]=min(DP[j],DP[j-a[i]]+1);

        if (DP[sum]!=20000000) cout<<DP[sum]<<endl;
        else cout<<-1<<endl;

        cin>>sum>>n;
    }
    return 0;
}
