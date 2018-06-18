#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int graf[m][3];
    vector <int> dist(n+1,2000000);

    for (int i=0;i<m;i++) cin>>graf[i][0]>>graf[i][1]>>graf[i][2];

    dist[1]=0;
    for (int i=1;i<n;i++)
        for (int j=0;j<m;j++)
            if ( dist[graf[j][1]] > dist[graf[j][0]] + graf[j][2] ) dist[graf[j][1]] = dist[graf[j][0]] + graf[j][2];

    cout<<dist[n]<<endl;
    return 0;
}
