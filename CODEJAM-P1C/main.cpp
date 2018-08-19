#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ifstream input("A-small-attempt3.in");
ofstream output("A-small-attempt3.out");

bool compare_int_dec(pair<int,char> a,pair<int,char> b){
	return (a.first>b.first);
}

int main()
{
    int N,nb;
    input >> N;
    int number=0;
    string out="";
    pair<int,char> SEN[26];
    for(int i=1;i<=N;i++){
        out="";
        input >> nb;
        int nbp=nb;
        for(int j=0;j<nb;j++){
            input >> SEN[j].first;
            number+=SEN[j].first;
            SEN[j].second=j+65;
        }
        bool first=true;
        while(number>0){
            sort(SEN,SEN+nb,compare_int_dec);
            nb=nbp;
            if(number>1){
                if(nb>2){
                    if(SEN[0].first>SEN[1].first+1){
                        if(SEN[0].first!=1){
                            if(first){
                                out=out+SEN[0].second+SEN[0].second;
                                first=false;
                            }
                            else{
                                out=out+" "+SEN[0].second+SEN[0].second;
                            }
                            SEN[0].first-=2;
                            if(SEN[0].first==0)
                                nbp-=2;
                        }
                        else{
                            if(first){
                                out=out+SEN[0].second+SEN[1].second;
                                first=false;
                            }
                            else
                                out=out+" "+SEN[0].second+SEN[1].second;
                            SEN[0].first--;
                            SEN[1].first--;
                            if(SEN[0].first==0)
                                nbp--;
                            if(SEN[1].first==0)
                                nbp--;
                        }
                    }
                    else{
                        if(first){
                            out=out+SEN[0].second+SEN[1].second;
                            first=false;
                        }
                        else
                            out=out+" "+SEN[0].second+SEN[1].second;
                        SEN[0].first--;
                        SEN[1].first--;
                        if(SEN[0].first==0)
                            nbp--;
                        if(SEN[1].first==0)
                            nbp--;
                    }
                }
                else if(nb==2){
                    if(SEN[0].first>SEN[1].first){
                        if(first){
                            out=out+SEN[0].second;
                            first=false;
                        }
                        else{
                            out=out+" "+SEN[0].second;
                        }
                        SEN[0].first--;
                        if(SEN[0].first==0)
                            nbp--;
                    }
                    else{
                        if(first){
                            out=out+SEN[0].second+SEN[1].second;
                            first=false;
                        }
                        else
                            out=out+" "+SEN[0].second+SEN[1].second;
                        SEN[0].first--;
                        SEN[1].first--;
                        if(SEN[0].first==0)
                            nbp--;
                        if(SEN[1].first==0)
                            nbp--;
                    }
                }
                else{
                    if(first){
                        out=out+SEN[0].second+SEN[0].second;
                        first=false;
                    }
                    else
                        out=out+" "+SEN[0].second+SEN[0].second;
                    SEN[0].first-=2;
                    if(SEN[0].first==0)
                        nbp--;
                }
                number-=2;
            }
            else{
                if(first){
                    out=out+SEN[0].second;
                    first=false;
                }
                else
                    out=out+" "+SEN[0].second;
                SEN[0].first--;
                if(SEN[0].first==0)
                    nbp--;
                number--;
            }
        }
        output << "Case #" << i << ": ";
        output << out << endl;
    }
    return 0;
}
