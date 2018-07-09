#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if (n==k)
        cout<<m-n;
    else if (n==m)
        cout<<k-n;
    else if (k==m)
        cout<<n-m;
    return 0;
}
