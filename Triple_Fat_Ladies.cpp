#include <iostream>

using namespace std;

int main()
{
    int t,k;
    cin>>t;
    while (t--)
    {
        cin>>k;
        for (long long i=k;i>0;i++)
        {
            if ((i*i*i)%1000==888)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
