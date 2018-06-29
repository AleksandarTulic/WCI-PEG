#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

bool awesome(int broj)
{
    bool prov=true;

    for (int i=2;i<=sqrt(broj);i++)
        if (broj % (i*i) == 0) return false;

    return prov;
}

bool special(int broj)
{
    bool prov=true;
    int brojn=broj%10;
    broj/=10;

    int brojnep=0;

    if (brojn%2!=0) brojnep++;

    while (broj!=0)
    {
        int e=broj%10;
        if (e%2!=0) brojnep++;
        if (brojn<=e) {return false;}
        brojn=e;
        broj/=10;
    }

    if (brojnep%2!=0) return false;

    return prov;
}

int main()
{
    int tests=5;

    int l,u;

    while (tests--)
    {
        cin>>l>>u;

        int brojac=0;

        for (int i=l;i<=u;i++)
            if (special(i) && awesome(i)) brojac++;

        cout<<brojac<<endl;
    }
    return 0;
}
