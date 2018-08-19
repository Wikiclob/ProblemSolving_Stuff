#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

string S;

int main()
{
    ofstream output("A-large (2).out");
    ifstream input("A-large (2).in");
    int N;
    input >> N;
    string subS;
    for(int i=1;i<=N;i++){
        input >> S;
        subS="";
        for(int j=0;j<S.length();j++){
            if(subS.length()!=0){
                if(S[j]>=subS[0])
                    subS=S[j]+subS;
                else
                    subS=subS+S[j];
            }
            else
                subS=S[j];
        }
        output << "Case #" << i << ": " << subS << "\n";
    }
    return 0;
}
