#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi shop;

int main()
{
    int n,tmp;
    cin >> n;
    while(n--){
        cin >> tmp;
        shop.push_back(tmp);
    }
    sort(shop.begin(),shop.end());
    vector<int>::iterator start=shop.begin();
    vector<int>::iterator found;
    cin >> n;
    while(n--){
        cin >> tmp;
        found=upper_bound(shop.begin(),shop.end(),tmp);
        cout << found-start << endl;
    }
    return 0;
}
