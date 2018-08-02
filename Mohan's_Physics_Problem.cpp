#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,k;
float rez = 1.0;
int br = 0;

float notation()
{
    while ( rez + 0.01 >= 10.0 )
    {
        rez/=10;
        br++;
    }

    return rez;
}

int main()
{
    cin>>n>>k;

    for (int i=0;i<k;i++)
    {
        rez*=n;

        rez = notation();
    }

    cout<<setprecision(2)<<fixed<<rez<<endl;
    cout<<br<<endl;
    return 0;
}
