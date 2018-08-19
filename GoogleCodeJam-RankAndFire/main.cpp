#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
#define INF (999999)

using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    ifstream input("B-small-attempt1.in");
    ofstream output("B-small-attempt1.out");
    int N;
    int SIZE;
    input >> N;
    for(int i=1;i<=N;i++){
        input >> SIZE;
        int M[SIZE*2][SIZE];
        for(int j=0;j<SIZE*2-1;j++){
            for(int k=0;k<SIZE;k++){
                input >> M[j][k];
            }
        }
        /*for(int j=0;j<SIZE*2-1;j++){
            for(int k=0;k<SIZE;k++){
                cout << M[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
        int MAT[SIZE][SIZE];
        memset(MAT,0,sizeof(int)*SIZE*SIZE);
        bool visited[SIZE*2];
        memset(visited,false,sizeof(bool)*SIZE*2);
        bool changed=true;
        int whereI=0,whereJ=0;
        int minInd=INF;
        int ind=0;
        while(changed){
            changed=false;
            minInd=INF;
            ind=0;
            for(int j=0;j<SIZE*2-1;j++){
                if(!visited[j] && M[j][0]<=minInd){
                    changed=true;
                    minInd=M[j][0];
                    ind=j;
                }
            }
            //cout << "minIND: " << minInd << endl;
            //cout << "ind: " << ind << endl;
            //cout << "changed: " << changed << endl;
            if(!changed)
                break;
            visited[ind]=true;
            if(whereI!=0 || whereJ!=0){
                if(MAT[whereI][0]==M[ind][0]){
                    //cout << "MAT:" << MAT[whereI][0] << " M: " << M[ind][0] << endl;
                    bool verif=false;
                    for(int j=0;j<SIZE;j++){
                        if(MAT[whereI][j]!=0 && MAT[whereI][j]!=M[ind][j]){
                            verif=true;
                            break;
                        }
                    }
                    if(!verif){
                        for(int j=0;j<SIZE;j++){
                            MAT[whereI][j]=M[ind][j];
                        }
                        whereI++;
                    }
                    else{
                        verif=false;
                        for(int j=0;j<SIZE;j++){
                            if(MAT[j][whereJ]!=0 && MAT[j][whereJ]!=M[ind][j]){
                                verif=true;
                                break;
                            }
                            if(!verif){
                                for(int j=0;j<SIZE;j++){
                                    MAT[j][whereJ]=M[ind][j];
                                }
                                whereJ++;
                            }
                        }
                    }
                }
                else if(MAT[0][whereJ]==M[ind][0]){
                    bool verif=false;
                    for(int j=0;j<SIZE;j++){
                        if(MAT[j][whereJ]!=0 && MAT[j][whereJ]!=M[ind][j]){
                            verif=true;
                            break;
                        }
                    }
                    if(!verif){
                        for(int j=0;j<SIZE;j++){
                            MAT[j][whereJ]=M[ind][j];
                        }
                        whereJ++;
                    }
                }
                else if(MAT[whereI][0]==0){
                    bool verif=false;
                    for(int j=0;j<SIZE;j++){
                        if(MAT[whereI][j]!=0 && MAT[whereI][j]!=M[ind][j]){
                            verif=true;
                            break;
                        }
                    }
                    if(!verif){
                        for(int j=0;j<SIZE;j++){
                            MAT[whereI][j]=M[ind][j];
                        }
                        whereI++;
                    }
                }
                else if(MAT[0][whereJ]==0){
                    bool verif=false;
                    for(int j=0;j<SIZE;j++){
                        if(MAT[j][whereJ]!=0 && MAT[j][whereJ]!=M[ind][j]){
                            verif=true;
                            break;
                        }
                        if(!verif){
                            for(int j=0;j<SIZE;j++){
                                MAT[j][whereJ]=M[ind][j];
                            }
                            whereJ++;
                        }
                    }
                }
            }
            else{
                for(int j=0;j<SIZE;j++){
                        MAT[j][whereJ]=M[ind][j];
                    }
                    whereJ++;
            }
        }
        if(i==9){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                cout << MAT[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        }
        if(whereI!=SIZE){
            output << "Case #" << i << ":";
            //cout << "whereI: " << whereI << endl;
            for(int j=0;j<SIZE;j++){
                output << " " << MAT[whereI][j];
            }
            output << "\n";
        }
        else{
            output << "Case #" << i << ":";
            //cout << "whereJ: " << whereJ << endl;
            for(int j=0;j<SIZE;j++){
                output << " " << MAT[j][whereJ];
            }
            output << "\n";
        }
    }
    return 0;
}
