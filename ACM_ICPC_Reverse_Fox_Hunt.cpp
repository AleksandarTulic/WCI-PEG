#include <iostream>

using namespace std;

int r,c;
char grid[7][7];
int m[7][7];
int x1,y1,x2,y2;

void inf()
{
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        m[i][j]=20000000;
}

void flood(int x, int y, int korak, int r1, int r2, int r3, int r4, int r5, int r6)
{
    if (x>=r || x<0 || y>=c || y<0) return;
    if (korak>m[x][y]) return;
    if (grid[x][y]=='T') return;
    if (x==r1 && y==r2) return;
    if (x==r3 && y==r4) return;
    if (x==r5 && y==r6) return;

    m[x][y]=korak;

    flood(x+1,y,korak+1,r1,r2,r3,r4,r5,r6);
    flood(x-1,y,korak+1,r1,r2,r3,r4,r5,r6);
    flood(x,y+1,korak+1,r1,r2,r3,r4,r5,r6);
    flood(x,y-1,korak+1,r1,r2,r3,r4,r5,r6);
}

bool jedan()
{
    inf();
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if ( (i!=x1 || j!=y1) && (i!=x2|| j!=y2) )
            {
                flood(x1,y1,0,i,j,-1,-1,-1,-1);

                if (m[x2][y2]==20000000) return true;

                inf();
            }
    return false;
}

bool dva()
{
    inf();
    for (int i1=0;i1<r;i1++)
        for (int j1=0;j1<c;j1++)
            for (int i2=0;i2<r;i2++)
                for (int j2=0;j2<c;j2++)
                    if ( (i1!=i1 || j1!=j2) && (i1!=x1 || j1!=y1) && (i1!=x2 || j1!=y2) && (i2!=x1 || j2!=y1) && (i2!=x2 || j2!=y2))
                    {
                        flood(x1,y1,0,i1,j1,i2,j2,-1,-1);

                        if (m[x2][y2]==20000000) return true;

                        inf();
                    }
    return false;
}

bool tri()
{
    inf();
    for (int i1=0;i1<r;i1++)
        for (int j1=0;j1<c;j1++)
            for (int i2=0;i2<r;i2++)
                for (int j2=0;j2<c;j2++)
                    for (int i3=0;i3<r;i3++)
                        for (int j3=0;j3<c;j3++)
                            if ( (i1!=i2 || j1!=j2) && (i1!=i3 || i1!=j3) && (i2!=i3 || j2!=j3) && (i1!=x1 || j1!=y1) && (i1!=x2 || j1!=y2) && (i2!=x1 || j2!=y1) && (i2!=x2 || j2!=y2) && (i3!=x1 || j3!=y1) && (i3!=x2 || j3!=y2))
                            {
                                flood(x1,y1,0,i1,j1,i2,j2,i3,j3);

                                if (m[x2][y2]==20000000) return true;

                                inf();
                            }
    return false;
}

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        cin>>r>>c;

        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
            {
                cin>>grid[i][j];

                if (grid[i][j]=='F') {x1=i;y1=j;}
                else if (grid[i][j]=='H') {x2=i;y2=j;}

                m[i][j]=20000000;
            }
        flood(x1,y1,0,-1,-1,-1,-1,-1,-1);

        if (m[x2][y2]==20000000) cout<<0<<endl;
        else
        {
            if (jedan()) cout<<1<<endl;
            else if (dva()) cout<<2<<endl;
            else if (tri()) cout<<3<<endl;
            else cout<<4<<endl;
        }
    }
    return 0;
}
