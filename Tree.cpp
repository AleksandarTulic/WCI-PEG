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

int graf[1001][1001];
int n;
vector <bool> flag(1001,false);

void dfs(int cvor)
{
    flag[cvor]=true;

    for (int i=0;i<n;i++)
        if ( graf[cvor][i] == 1 && !flag[i] ) dfs(i);
}

int main()
{
    cin>>n;

    int broj_puteva = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin>>graf[i][j];

            if ( graf[i][j] == 1 ) broj_puteva++;
        }

    int br = 0;

    for (int i=0;i<n;i++)
        if ( !flag[i] )
        {
            dfs(i);
            br++;
        }

    cout<<broj_puteva/2-(n-br)<<endl;
    return 0;
}
