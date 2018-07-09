#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int A[n];

    for (int i=0;i<n;i++) cin>>A[i];

    sort(A,A+n);

    int q;
    cin>>q;
    int t;
    for (int i=0;i<q;i++) {cin>>t;cout<<A[t-1]<<endl;}
    return 0;
}
