#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

int main()
{
    int n;
    vector<string> save;
    string row;
    bool found=false;
    cin >> n;
    while(n--){
        cin >> row;
        if(!found && row[0]==row[1] && row[0]=='O'){
            row[0]=row[1]='+';
            found=true;
        }
        if(!found && row[3]==row[4] && row[3]=='O'){
            row[3]=row[4]='+';
            found=true;
        }
        save.push_back(row);
    }
    if(found){
        cout << "YES" << endl;
        for(int i=0;i<save.size();i++)
            cout << save[i] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
