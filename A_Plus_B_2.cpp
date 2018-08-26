#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

string oduzimanje(string a, string b, int koji)
{
    if ( a == b ) return "0";
    string nule = "";
    string rez = "";

    for (int i=0;i<abs((int)a.size() - (int)b.size());i++) nule+='0';

    if ( (int)a.size() > (int)b.size() ) b=nule + b;
    else a=nule + a;

    int poz = 0;
    while ( a[poz] == b[poz] ) { poz++; }

    bool neg = false;
    if ( (a[poz] - '0') < (b[poz] - '0') )
    {
        string r = a;
        a=b;
        b=r;

        if ( koji == 2 ) neg = true;
    }
    else
        if ( koji == 1 ) neg = true;

    int prenos = 0;
    for (int i=(int)a.size()-1;i>=0;i--)
    {
        int sum = ( a[i] - '0' ) - prenos - ( b[i] - '0' );

        if ( sum < 0 )
        {
            prenos = 1;
            sum+=10;
        }
        else prenos=0;

        rez = (char)(sum + '0') + rez;
    }

    poz = 0;
    while ( rez[poz] == '0' ) {poz++;}
    rez = rez.substr(poz,(int)rez.size());

    if ( neg ) rez = '-' + rez;

    return rez;
}

string sabiranje(string a, string b)
{
    string nule = "";
    string rez = "";

    for (int i=0;i<abs((int)a.size() - (int)b.size());i++) nule+='0';

    if ( (int)a.size() > (int)b.size() ) b=nule + b;
    else a=nule + a;

    int prenos = 0;
    for (int i=(int)a.size()-1;i>=0;i--)
    {
        int sum = ( a[i] - '0' ) + ( b[i] - '0' ) + prenos;

        if ( sum >= 10 )
        {
            prenos = 1;
            sum-=10;
        }
        else prenos = 0;

        rez = (char)( sum + '0' ) + rez;
    }

    if ( prenos == 1 ) rez = '1' + rez;

    return rez;
}

int main()
{
    string a,b;
    cin>>a>>b;

    if ( a[0] == '-' && b[0] == '-' )
        cout<<"-"<<sabiranje(a.substr(1,a.size()), b.substr(1,b.size()))<<endl;
    else if ( a[0] == '-' )
        cout<<oduzimanje(a.substr(1,a.size()),b,1)<<endl;
    else if ( b[0] == '-' )
        cout<<oduzimanje(a,b.substr(1,b.size()),2)<<endl;
    else
        cout<<sabiranje(a,b)<<endl;
    return 0;
}
