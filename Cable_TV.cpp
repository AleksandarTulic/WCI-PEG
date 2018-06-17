#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector <pair<int, int> > vi(n+1,{2e9,2e9});
    vector <vector <pair<int,int> > > graf(n+1,vi);

    for (int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        graf[a][b]={c,d};
        graf[b][a]={c,d};
    }

    int damage = 0;
    int MST = 0;
    vector <bool> bio(n+1,false);
    vector <pair<int, int> > dist(n+1,{2e9,2e9});
    dist[1]={0,0};

    for (int i=1;i<=n;i++)
    {
        int uda = 2e9;
        int tko;
        int dam = 2e9;

        for (int j=1;j<=n;j++)
            if ( bio[j] == false )
                if ( dam > dist[j].second || ( dam == dist[j].second && uda > dist[j].first ) ) tko=j,dam=dist[j].second,uda=dist[j].first;

        MST+=uda;
        damage+=dam;
        bio[tko]=true;

        for (int j=1;j<=n;j++)
            if ( dist[j].second > graf[tko][j].second || ( dist[j].second == graf[tko][j].second && dist[j].first > graf[tko][j].first ) ) dist[j]=graf[tko][j];
    }

    cout<<damage<<" "<<MST<<endl;
    return 0;
}
