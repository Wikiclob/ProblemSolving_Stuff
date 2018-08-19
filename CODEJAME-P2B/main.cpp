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
    ifstream input("B-small-attempt0 (2).in");
    ofstream output("B-small-attempt0 (2).out");
    int N;
    string nb1,nb2;
    //bool firstZERO=true;
    int bigger=0;
    bool firstEntry=true;
    input >> N;
    //input.ignore();
    for(int i=1;i<=N;i++){
        input >> nb1 >> nb2;
        //firstZERO=true;
        firstEntry=true;
        for(int j=0;j<nb1.size();j++){
            if(nb1[j]=='?' && nb1[j]!=nb2[j] && firstEntry){
               //firstZERO=false;
                nb1[j]=nb2[j];
            }
            else if(nb2[j]=='?' && nb1[j]!=nb2[j] && firstEntry){
               //firstZERO=false;
                nb2[j]=nb1[j];
            }
            else if(nb1[j]=='?' && nb2[j]=='?' && firstEntry){
                nb1[j]='0';
                nb2[j]='0';
            }
            else{
                if(firstEntry){
                    if(nb1[j]>nb2[j]){
                        bigger=1;
                        firstEntry=false;
                    }
                    else if(nb1[j]<nb2[j]){
                        bigger=-1;
                        firstEntry=false;
                    }
                }
                else{
                    if(nb1[j]=='?' && nb1[j]!=nb2[j]){
                        if(bigger>0){
                            nb1[j]='0';
                        }
                        else{
                            nb1[j]='9';
                        }
                    }
                    else if(nb2[j]=='?' && nb1[j]!=nb2[j]){
                        if(bigger>0){
                            nb2[j]='9';
                        }
                        else{
                            nb2[j]='0';
                        }
                    }
                    else if(nb1[j]=='?' && nb2[j]=='?'){
                        if(bigger>0){
                            nb1[j]='0';
                            nb2[j]='9';
                        }
                        else{
                            nb1[j]='9';
                            nb2[j]='0';
                        }
                    }
                }
            }
        }
        output << "Case #" << i << ": ";
        output << nb1 << " " << nb2 << "\n";
    }
    return 0;
}
