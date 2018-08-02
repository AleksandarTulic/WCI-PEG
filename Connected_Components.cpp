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

int n;
int graf[1001][1001];
vector <bool> flag(1001,false);
vector <int> ele;

void dfs(int cvor)
{
    ele.push_back(cvor);
    flag[cvor]=true;

    for (int i=0;i<n;i++)
        if ( !flag[i] && graf[cvor][i] == 1 )
            dfs(i);
}

int main()
{
    cin>>n;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>graf[i][j];

    for (int i=0;i<n;i++)
    {
        if ( !flag[i] )
        {
            if (!ele.empty()) ele.erase(ele.begin(),ele.end());

            dfs(i);

            sort(ele.begin(),ele.end());

            for (int j=0;j<ele.size();j++) cout<<ele[j]+1<<" ";
            cout<<endl;
        }
    }
    return 0;
}
