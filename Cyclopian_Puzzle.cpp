#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

void hanoi(int n, char a, char b, char c)
{
    if (n==1) {cout<<a<<b<<endl;;return;}
    hanoi(n-1,a,c,b);
    cout<<a<<b<<endl;
    hanoi(n-1,c,b,a);
}

int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','C','B');
    return 0;
}
