#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,p=0;
    cin>>n;
    int k[n];
    for (int i=0;i<n;i++)
    {
        cin>>k[i];
        p=p+abs(k[i]);
    }
    cout<<p;
    return 0;
}
