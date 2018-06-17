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

int main()
{
    int t;
    cin>>t;

    while (t != 0)
    {
        string g;
        cin>>g;

        vector <string> niz;

        string h="";
        bool flag = true;
        for (int i=0;i<g.size();i++)
        {
            h+=g[i];

            if ( ( i + 1 ) % t == 0 )
            {
                if ( flag ) niz.push_back(h);
                else
                {
                    string k="";
                    for (int j=h.size()-1;j>=0;j--) k+=h[j];
                    niz.push_back(k);
                }

                flag=!flag;
                h="";
            }
        }

        string rez="";
        for (int i=0;i<niz[0].size();i++)
            for (int j=0;j<niz.size();j++)
                rez+=niz[j][i];

        cout<<rez<<endl;

        cin>>t;
    }
    return 0;
}
