#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int n1,n2;
vector <int> c,p;

int main()
{
    scanf("%d",&n1);

    for (int i=0;i<n1;i++) {int a;scanf("%d",&a);c.push_back(a);}

    scanf("%d",&n2);

    for (int i=0;i<n2;i++) {int a;scanf("%d",&a);p.push_back(a);}

    sort(c.begin(),c.begin()+c.size());
    sort(p.begin(),p.begin()+p.size());

    long long suma=0;
    int prov=c.size();
    int poz=p.size()-1;

    for (int i=c.size()-1;i>=0;i--)
        for (int j=poz;j>=0;j--)
            if (c[i]>=p[j])
            {
                suma+=c[i]-p[j];
                poz=j-1;
                prov--;
                break;
            }

    if (prov==0) cout<<suma<<endl;
    else cout<<-1<<endl;
    return 0;
}
