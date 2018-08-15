#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <utility>

using namespace std;

int xor2(int a)
{
    if ( (a+1) % 4 == 0 ) return 1;
    else if ( (a+1) % 4 == 1 ) return a+1;
    else if ( (a+1) % 4 == 2 ) return 0;
    else return a;
}

int xor1(int a, int b)
{
    return xor2(b) ^ xor2(a-1);
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;

        cout<<xor1(a,b)<<endl;
    }
    return 0;
}
