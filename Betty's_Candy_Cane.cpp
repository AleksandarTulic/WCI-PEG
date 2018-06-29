#include <iostream>

using namespace std;

int m[11][11];
int a1,a2;

void postavi()
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        m[i][j]=1000;

    m[3][3]=-1;
    m[10][1]=-1;
    m[7][2]=-1;
    m[9][3]=-1;
    m[1][4]=-1;

    m[1][6]=-1;
    m[2][6]=-1;
    m[3][6]=-1;
    m[4][6]=-1;
    m[5][6]=-1;
    m[6][6]=-1;
    m[7][6]=-1;

    m[8][7]=-1;
    m[2][8]=-1;
    m[4][9]=-1;
    m[8][9]=-1;
    m[10][10]=-1;
}

void mL(int x, int y, int korak)
{
    if (x<1 || x>10 || y<1 || y>10) return;
    if (m[x][y]==-1) return;
    if (korak>m[x][y]) return;

    m[x][y]=korak;

    mL(x+1,y,korak+1);
    mL(x-1,y,korak+1);
    mL(x,y+1,korak+1);
    mL(x,y-1,korak+1);
}

int main()
{
    cin>>a1>>a2;

    postavi();

    mL(1,1,0);

    cout<<"Betty will sweat "<<m[a1][a2]<<"mL to get to her candy cane"<<endl;
    return 0;
}
