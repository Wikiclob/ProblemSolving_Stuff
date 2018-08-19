#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define ull unsigned long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int LSD_FirstDigit_ORI(ll a, ll b) {
    ll sum = 0;
    for(ll i = a; i <= b; i++)
        sum += (i * i);
    return sum % 10; // '%' is the operator for getting remainder of division.
}

int LSD_FirstDigit(ull a, ull b) {
    if(a>b)
        return 0;
    if(a==b)
        return a%10;
    ull x=(a-1);
    ull y=a;
    ull z=(2*(a-1)+1);
    ull P1=(x*y*z)/6;
    x=b;
    y=(b+1);
    z=(2*b+1);
    ull P2=(x*y*z)/6;
    ull P3=(P2-P1);
    return P3%10;
}

int main()
{

    int N;
    ll A,B;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A >> B;
        //cout << "ori: " << LSD_FirstDigit_ORI(A,B) << endl;
        //cout << sizeof(long long ) << endl;
        cout << "Case " << i << ": " << LSD_FirstDigit(A,B) << endl;
    }
    return 0;
}
