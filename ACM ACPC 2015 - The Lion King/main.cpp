#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define MOD (1000000007)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

vii points;

bool compare_pint_inc(pair<int,int> a,pair<int,int> b){
    return (a.first<b.first);
}

int count_etoiles(){
    int nb=0;
    for(int i=0;i<points.size()-4;i++){//P5 => i
        for(int j=points.size()-1;j>=i+4;j--){//P2 => j
            if(points[i].second==points[j].second && points[i].first!=points[j].first){
                for(int k=i+1;k<j-2;k++){//P4 => k
                    if(points[i].first!=points[k].first && points[j].first!=points[k].first){
                        for(int l=k+1;l<j-1;l++){//P1 => l
                            if(points[i].first!=points[l].first && points[j].first!=points[l].first && points[k].first!=points[l].first && points[l].second>points[k].second && points[l].second>points[i].second){
                                for(int m=l+1;m<j;m++){//P3 => m
                                    if(points[i].first!=points[m].first && points[j].first!=points[m].first && points[k].first!=points[m].first && points[l].first!=points[m].first && points[l].second>points[m].second && points[m].second==points[k].second){
                                        nb=(nb+1)%MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return nb;
}

int main()
{
    ifstream input("input.in");
    ofstream output("output.out");
    int N,nb,tmp1,tmp2,etoiles;
    //scanf("%d",&N);
    input >> N;
    for(int i=0;i<N;i++){
        points.clear();
        //scanf("%d",&nb);
        input >> nb;
        for(int j=0;j<nb;j++){
            //scanf("%d%d",&tmp1,&tmp2);
            input >> tmp1 >> tmp2;
            points.push_back({tmp1,tmp2});
        }
        sort(points.begin(),points.end(),compare_pint_inc);
        etoiles=count_etoiles();
        output << etoiles << endl;
        //cout << etoiles << endl;
    }
    return 0;
}
