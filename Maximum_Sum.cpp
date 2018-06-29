#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    int b[n];
    b[0]=a[0];
    b[1]=max(b[0],a[1]);

    for (int i=2;i<n;i++)
        b[i]=max(b[i-1],b[i-2]+a[i]);

    cout<<b[n-1]<<endl;
    return 0;
}
