#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

typedef unsigned long long ull;

struct Primes
{
    public: ull num;

    ull mnozenje(ull a, ull b)
    {
        ull x = 0, y = a % num;

        while ( b > 0 )
        {
            if ( b % 2 == 1 ) x = ( x + y ) % num;
            y = ( y + y ) % num;

            b/=2;
        }

        return x % num;
    }

    ull exponent(ull base, ull expo)
    {
        ull x = 1;
        ull y = base;

        while (expo > 0)
        {
            if ( expo % 2 == 1 ) x = mnozenje(x, y) % num;
            y = mnozenje(y, y) % num;
            expo/=2;
        }

        return x;
    }

    void Miller_Rabin()
    {
        if ( num == 2 || num == 3 ) { cout<<"PRIME"<<endl; return; }
        if ( num % 2 == 0 || num == 1 ) { cout<<"NOT"<<endl; return; }

        ull d = num - 1;
        while ( d % 2 == 0 ) d/=2;

        for (int i=1;i<=10;i++)
        {
            ull a = rand() % ( num - 1 ) + 1;
            ull temp = d;
            ull mod = exponent(a, temp);

            while (temp != num -1 && mod != 1 && mod != num - 1 )
            {
                mod = mnozenje(mod, mod);
                temp*=2;
            }

            if ( mod != num - 1 && temp % 2 == 0 )
            {
                cout<<"NOT"<<endl;
                return;
            }
        }

        cout<<"PRIME"<<endl;
    }
};

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        ull num;
        cin>>num;

        Primes prost;
        prost.num = num;

        prost.Miller_Rabin();
    }
    return 0;
}
