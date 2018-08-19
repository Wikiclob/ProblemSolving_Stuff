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

vi numbers;

int BS(){
    int optimal=numbers[numbers.size()-1]/2;
    bool stop=false;
    int res=abs(numbers[0]-optimal);
    int last=abs(numbers[0]-optimal);
    int retour=0;
    for(int i=1;i<numbers.size() && !stop;i++){
        res=abs(numbers[i]-optimal);
        if(res>last){
            stop=true;
            retour = i-1;
        }
        else
            last=res;
    }
    return numbers[retour];
}

int main()
{
    int n,tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    cout << BS() << endl;
    return 0;
}
