#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

int n,m,k;
int vr=0;
vector <int> niz(30001,2e9);
vector <vector <int> > graf(1e5+1);
queue <int> q;

int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    cin>>k;
    for (int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        niz[a]=0;
        q.push(a);
    }

    int sad;
    int koliko;

    while (q.empty() == false)
    {
        sad=q.front();
        koliko=niz[sad]+1;
        q.pop();

        for (int i=0;i<graf[sad].size();i++)
            if ( koliko < niz[graf[sad][i]] )
            {
                niz[graf[sad][i]]=koliko;
                q.push(graf[sad][i]);
            }
    }

    for (int i=1;i<=n;i++) vr=max(vr,niz[i]);
    cout<<vr<<endl;
    return 0;
}
