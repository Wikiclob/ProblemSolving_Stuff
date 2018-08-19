#include <bits/stdc++.h>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

bool T[10];

bool verif_finish(){
    for(int i=0;i<10;i++){
        if(T[i]==false)
            return false;
    }
    return true;
}
int NB;
ll solve(){
    ll n=0;
    int i=1;
    string s="";
    if(NB==0)
        return -1;
    else{
        //cout << "begin" << endl;
        while(!verif_finish()){
            n=i*NB;
            i++;
            s=NumberToString(n);
            //cout << s << endl;
            for(int j=0;j<s.length();j++)
                T[s[j]-48]=true;
        }
        //cout << "end" << endl;
        return n;
    }
}

int main()
{
    ifstream input("A-large.in");
    ofstream output("A-large.out");
    int N;
    ll res;
    input >> N;
    for(int i=1;i<=N;i++){
        memset(T,false,sizeof(bool)*10);
        input >> NB;
        output << "Case #" << i << ": ";
        if((res=solve())==-1){
            output << "INSOMNIA\n";
        }
        else
            output << res << "\n";
    }
    return 0;
}
