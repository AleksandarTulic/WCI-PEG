#include <iostream>

using namespace std;

int main()
{
    int x,y,x1,x2,y1,y2;
    cin>>x>>y;
    cin>>x1>>y1>>x2>>y2;
    if ((x2>x)&&(x>x1)&&(y2>y)&&(y>y1))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
