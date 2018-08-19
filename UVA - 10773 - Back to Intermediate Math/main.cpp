#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

double to_rad(double x){
    return x*PI/180;
}

double to_deg(double x){
    return x*180/PI;
}

int main()
{
    int N;
    int DISTANCE,V_RIVER,V_BOAT;
    double time_mdist,time_mtime;
    double v_search,angleBeta;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d%d",&DISTANCE,&V_RIVER,&V_BOAT);
        if(V_BOAT>V_RIVER && V_RIVER!=0 && V_BOAT!=0){
            time_mtime=(double)DISTANCE/V_BOAT;
            angleBeta=to_deg(asin(((double)V_RIVER/V_BOAT)*sin(to_rad(90.0))));
            v_search=((double)V_BOAT*sin(to_rad(90-angleBeta)))/sin(to_rad(90.0));
            time_mdist=(double)DISTANCE/v_search;
            printf("Case %d: %.3f\n",i,abs(time_mdist-time_mtime));
        }
        else{
            printf("Case %d: can't determine\n",i);
        }
    }
    return 0;
}
