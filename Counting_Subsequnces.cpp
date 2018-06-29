#include <iostream>

using namespace std;

int main()
{
    string slova;

    cin>>slova;

    int duzina=slova.length();

    int DP[duzina+1];

    DP[0]=1;

    int provjera[260];

    for (int i=0;i<260;i++)
        provjera[i]=-100;

    for (int i=1;i<=duzina;i++)
    {

        DP[i]=2*(DP[i-1]%10007);

        if (provjera[slova[i-1]]!=-100)
            DP[i]=(DP[i]-DP[provjera[slova[i-1]]])%10007;

        provjera[slova[i-1]]=i-1;
    }

    cout<<DP[duzina]-1<<endl;
    return 0;
}
