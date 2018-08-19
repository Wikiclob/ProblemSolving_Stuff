#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int money,garment;

int main()
{
    int N,cc,tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&money,&garment);
        bool price[garment][money+1];
        memset(price,false,sizeof(bool)*garment*(money+1));
        for(int j=0;j<garment;j++){
            scanf("%d",&cc);
            int T[cc];
            for(int k=0;k<cc;k++){
               scanf("%d",&T[k]);
            }
            if(j>0){
                for(int l=0;l<cc;l++){
                    for(int k=T[l];k<=money;k++){
                        if(price[j-1][k])
                            price[j][k-T[l]]=true;
                    }
                }
            }else{
                for(int l=0;l<cc;l++){
                    price[0][money-T[l]]=true;
                }
            }
        }
        /** TEST CODE**/
        /*for(int j=0;j<garment;j++){
            for(int k=0;k<=money;k++){
                cout << (price[j][k])?"1 ":"0 ";
            }
            cout << "\n";
        }*/

        bool verif=false;
        for(int j=0;j<=money;j++){
            if(price[garment-1][j]){
                cout << money-j << "\n";
                verif=true;
                break;
            }
        }
        if(!verif)
            cout << "no solution\n";
    }
    return 0;
}
