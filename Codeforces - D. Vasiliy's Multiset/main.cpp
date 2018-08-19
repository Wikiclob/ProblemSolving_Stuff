#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int oo=1e9;
const int MAX=1010;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

set<int> mset;
void operation(char op,int n){
    if(op=='+')
        mset.insert(n);
    else if(op=='-')
        mset.erase(mset.find(n));
    else{
        int maxi=-oo;
        int tmp;
        for(set<int>::iterator it=mset.begin();it!=mset.end();++it){
            tmp=(*it)^n;
            if(tmp>maxi)
                maxi=tmp;
        }
        cout << maxi << endl;
    }


}

int main()
{
    int q;
    char op;
    int n;
    mset.insert(0);
    cin >> q;
    while(q--){
        cin >> op >> n;
        operation(op,n);
    }
    return 0;
}
