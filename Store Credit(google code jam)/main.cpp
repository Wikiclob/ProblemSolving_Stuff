#include <bits/stdc++.h>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

vi items;
int CREDIT,NB;
int ind1,ind2;

void solve(){
    ind1=-1;
    ind2=-1;
    for(int i=1;i<NB;i++){
        for(int j=0;j<i;j++){
            if(items[i]+items[j]==CREDIT){
                ind1=j+1;
                ind2=i+1;
                break;
            }
        }
        if(ind1!=-1)
            break;
    }
}

int main()
{
    ifstream input("A-large-practice.in");
    ofstream output("A-large-practice.out");
    int N;
    int tmp;
    input >> N;
    for(int i=1;i<=N;i++){
        items.clear();
        input >> CREDIT >> NB;
        for(int j=0;j<NB;j++){
            input >> tmp;
            items.push_back(tmp);
        }
        solve();
        output << "Case #" << i << ": " << ind1 << " " << ind2 << "\n";
    }
    return 0;
}
