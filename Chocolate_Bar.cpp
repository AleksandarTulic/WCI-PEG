#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        int a,b;
        cin>>a>>b;

        cout<<a*b-1<<endl;
    }
    return 0;
}
