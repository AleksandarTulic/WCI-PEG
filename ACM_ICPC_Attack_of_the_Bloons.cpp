#include <iostream>

using namespace std;

int l,n,m;
int r[1001],c[1001],h[1001],d[1001];
int L[1001];

void staza()
{
    for (int i=0;i<1000;i++) L[i]=0;

    for (int i=0;i<n;i++)
    {
        int poz=c[i]-1;
        if (r[i]==0) L[poz]+=d[i];
        else
        {
            L[poz]+=d[i];

            for (int j=poz-1;j>(poz-1-r[i]);j--) if (j>=0) L[j]+=d[i];
            for (int j=poz+1;j<(poz+1+r[i]);j++) if (j<l) L[j]+=d[i];
        }
    }
}

int main()
{
    int t;

    cin>>t;

    for (int tests=0;tests<t;tests++)
    {
        cin>>l>>n;

        for (int i=0;i<n;i++) cin>>c[i]>>r[i]>>d[i];

        cin>>m;

        for (int i=0;i<m;i++) cin>>h[i];

        staza();

        for (int i=0;i<m;i++)
        {
            int hp=h[i];

            for (int j=0;j<l;j++)
            {
                hp-=L[j];
                if (hp<=0){cout<<j+1<<endl;break;}
            }

            if (hp>=1) cout<<"Bloon leakage"<<endl;
        }
    }
    return 0;
}
