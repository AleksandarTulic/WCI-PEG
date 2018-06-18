#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

string a;

bool prostiline(int broj)
{
    int prov=true;

    if (broj==1) return false;

    for (int i=2;i<=sqrt(broj);i++)
        if (broj % i == 0) {prov=false;break;}

    if (prov) return true;
    return false;
}

void rjesenje()
{
    if (a[a.size()-1]=='0' || a[a.size()-1]=='5' || a[a.size()-1]=='2') {cout<<"Not possible"<<endl;return;}

    int d;

    if ( a[0]=='_' ) d=1;
    else d=0;

    int p=1;
    for (int kk=0;kk<a.size()-1;kk++) p*=10;

    bool prov=false;

    for (int i=d;i<=9;i++)
    {
        int suma=0;
        for (int j=0;j<a.size();j++)
        {
            int e;

            if (a[j]!='_') e=a[j]-'0';
            else e=i;

            suma+=p*e;

            p1/=10;
        }
        if (prostiline(suma)){prov=true;cout<<i<<" ";}
    }

    if (!prov) cout<<"Not possible"<<endl;
    else cout<<endl;
}

int main()
{
    for (int i=0;i<5;i++)
    {
        cin>>a;

        rjesenje();
    }
    return 0;
}
