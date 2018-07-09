#include <iostream>

using namespace std;

int main()
{
    int n,b=0;
    cin>>n;
    
    while (n!=1)
    {
        if (n % 2 == 0)
        {
            n=n/2;
            b++;
        }
        else if (n % 2 != 0)
        {
            n=(3*n)+1;
            b++;
        }
    }
    
    cout<<b;
    return 0;
}
