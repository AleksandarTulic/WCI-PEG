#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    int suma=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        suma+=a[i];
    }
    
    int minn=20000000;
    for (int i=0;i<(1<<n);i++)
    {
        int br=0;
        for (int j=0;j<n;j++)
            if ( (1<<j) & i ) br+=a[j];

        minn=min(minn,abs(suma-2*br));
    }
    cout<<minn<<endl;
    return 0;
}
