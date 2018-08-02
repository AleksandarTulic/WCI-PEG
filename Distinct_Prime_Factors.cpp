#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    vector <bool> prost(b+1,true);
    vector <int> broj(b+1,0);

    for (int i=2;i<=b;i++)
        if ( prost[i] )
            for (int j=i*2;j<=b;j+=i)
            {
                prost[j]=false;
                broj[j]++;
            }

    for (int i=a;i<=b;i++)
        if ( broj[i] == 0 ) cout<<1<<endl;
        else cout<<broj[i]<<endl;
    return 0;
}
