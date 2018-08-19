#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    ifstream input("D-large.in");
    ofstream output("D-large.out");
    int N,SIZE,DEPTH,TILES;
    input >> N;
    for(int i=1;i<=N;i++){
        input >> SIZE >> DEPTH >> TILES;
        output << "Case #" << i << ":";
        if(TILES < SIZE-1)
            output << " IMPOSSIBLE";
        else if(SIZE==1){
            output << " 1";
        }
        else if(DEPTH>1){
            for(int j=2;j<=SIZE;j++)
                output << " " << j;
        }
        else if(TILES>=SIZE){
            for(int j=1;j<=SIZE;j++)
                output << " " << j;
        }
        else{
            output << " IMPOSSIBLE";
        }
        output << "\n";
    }
    return 0;
}
