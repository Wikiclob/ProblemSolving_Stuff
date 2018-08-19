#include <iostream>

using namespace std;

int main()
{
    int a,b,c,great,notGreat,res;
    cin >> a >> b >> c;
    great=max(max(a,b),c);
    if(great==a)
        notGreat=b+c;
    else if(great==b)
        notGreat=a+c;
    else
        notGreat=a+b;
    if(great>notGreat)
        res=great;
    else
        res=notGreat;
    cout << res << endl;
    return 0;
}
