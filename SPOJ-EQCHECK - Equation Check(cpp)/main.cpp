#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); };
int main()
{
    int N,A,B,C,i;
    scanf("%d",&N);//fflush(stdin);
    for(i=0;i<N;i++){
        scanf("%dx+%dy=%d",&A,&B,&C);
        if(C%gcd(A,B)==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
