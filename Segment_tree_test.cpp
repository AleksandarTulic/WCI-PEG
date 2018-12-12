#include <iostream>
#include <stdio.h>
#include <map>
#include <iomanip>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n,m;
int len;
int niz[1000001];
int tree[2100000];

int velicina(int d);
void build(int low, int high, int pos);
void update(int index, int delta, int low, int high, int pos);
int minimumquery(int qlow, int qhigh, int low, int high, int pos);

int main()
{
    cin>>n>>m;len = velicina(n);
    for (int i=0;i<n;i++) cin>>niz[i];
    for (int i=0;i<=len;i++) tree[i] = 2e9;

    build(0, n-1, 0);

    char a;
    int b,c;
    for (int i=0;i<m;i++)
    {
        scanf("%c", &a);
        scanf("%c", &a);
        if ( a == 'Q' )
        {
            scanf("%d %d", &b, &c);
            cout<<minimumquery(b, c, 0, n-1, 0)<<endl;
        }
        else if ( a == 'M' )
        {
            scanf("%d %d", &b, &c);
            update(b, c, 0, n-1, 0);
        }
    }
    return 0;
}

int velicina(int d)
{
    for (; !(d && !(d&(d-1))) ;d++);
    return d*2-1;
}

void build(int low, int high, int pos)
{
    if ( low == high )
    {
        tree[pos] = niz[low];
        return;
    }

    int mid = (low+high)/2;
    build(low, mid, 2*pos+1);
    build(mid+1, high, 2*pos+2);

    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int minimumquery(int qlow, int qhigh, int low, int high, int pos)
{
    if ( qlow <= low && qhigh >= high ) return tree[pos];
    if ( qlow > high || qhigh < low ) return 2e9;
    int mid = (low + high)/2;
    return min(minimumquery(qlow, qhigh, low, mid, 2*pos+1), minimumquery(qlow, qhigh, mid+1, high, 2*pos+2));
}

void update(int index, int delta, int low, int high, int pos)
{
    if ( index < low || index > high ) return;

    if ( low == high )
    {
        tree[pos]=delta;
        return;
    }

    int mid = (low+high)/2;
    update(index, delta, low, mid, 2*pos+1);
    update(index, delta, mid+1, high, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}
