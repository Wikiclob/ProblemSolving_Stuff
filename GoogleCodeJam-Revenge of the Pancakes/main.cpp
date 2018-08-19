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
    ifstream input("B-large.in");
    ofstream output("B-large.out");
    int N;
    input >> N;
    string PANCAKES;
    int res;
    bool parity=true;
    for(int i=1;i<=N;i++){
        input >> PANCAKES;
        parity=true;
        res=0;
        for(int j=PANCAKES.length()-1;j>=0;j--){
            if(parity){
                if(PANCAKES[j]=='-'){
                    res++;
                    parity=false;
                }
            }
            else{
                if(PANCAKES[j]=='+'){
                    res++;
                    parity=true;
                }
            }
        }
        output << "Case #" << i << ": " << res << "\n";
    }
    return 0;
}
