#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    float a,b,c,x;
    cin >> a >> b >> c;
    x=sqrt(pow(b,2)-4*a*c)-b;
    x/=2*a;
    printf("%.6f\n",x);
    return 0;
}
