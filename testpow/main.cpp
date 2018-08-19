#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ll fastExp(ll base, int p) { // O(log p)
if (p == 0) return 1;
else if (p == 1) return base;
else { ll res = fastExp(base, p / 2); res *= res;
if (p % 2 == 1) res *= base;
return res; } }

int main()
{
    cout << (ll)pow(50,20) << endl;
    cout << fastExp(50,20) << endl;
    return 0;
}
