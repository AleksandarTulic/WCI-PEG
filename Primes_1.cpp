#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector <int> prost;

    for (int i=2;i<=10000000;i++)
    {
        if ( prost.size() == n ) break;

        bool flag = true;
        for (int j=2;j<=sqrt(i);j++)
            if ( i % j == 0 ) { flag=false; break; }

        if ( flag ) prost.push_back(i);
    }

    for (int i=0;i<prost.size();i++) cout<<prost[i]<<endl;
    return 0;
}
