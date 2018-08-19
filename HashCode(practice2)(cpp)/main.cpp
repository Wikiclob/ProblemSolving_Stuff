#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ii,ii> iiii;
typedef vector<iiii> viiii;

int N,M;
char In[1000][1000];
char test_mat[1000][1000];

string itos(int a){
    ostringstream convert;
    convert << a;
    return convert.str();
}

bool verif_clear(char mat[][1000]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mat[i][j]=='#')
                return false;
        }
    }
    return true;
}

vector<string> count_line_vert(ii A,ii B,char Inn[][1000]){
    vector<string> res;
    ii BEGIN;
    bool END;
    for(int j=A.second;j<=B.second;j++){
        BEGIN.first=-1;
        BEGIN.second=-1;
        END=false;
        for(int i=A.first;i<=B.first;i++){
            if(BEGIN.first==-1){
                if(Inn[i][j]=='#'){
                    END=false;
                    BEGIN.first=i;
                    BEGIN.second=j;
                }
            }
            else{
                if(Inn[i][j]!='#' && BEGIN.first!=-1 && !END){
                    END=true;
                    //string tmp="PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(i)+" "+itos(j);
                    res.push_back("PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(i-1)+" "+itos(j));
                    BEGIN.first=-1;
                    BEGIN.second=-1;
                }
            }
        }
        if(!END && BEGIN.first!=-1){
            res.push_back("PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(B.first)+" "+itos(j));
        }
    }
    return res;
}

vector<string> count_line_horiz(ii A,ii B, char Inn[][1000]){
vector<string> res;
    ii BEGIN;
    bool END;
    for(int i=A.first;i<=B.first;i++){
        BEGIN.first=-1;
        BEGIN.second=-1;
        END=false;
        for(int j=A.second;j<=B.second;j++){
            if(BEGIN.first==-1){
                if(Inn[i][j]=='#'){
                    END=false;
                    BEGIN.first=i;
                    BEGIN.second=j;
                }
            }
            else{
                if(Inn[i][j]!='#' && BEGIN.first!=-1 && !END){
                    END=true;
                    //string tmp="PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(i)+" "+itos(j);
                    res.push_back("PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(i)+" "+itos(j-1));
                    BEGIN.first=-1;
                    BEGIN.second=-1;
                }
            }
        }
        if(!END && BEGIN.first!=-1){
            res.push_back("PAINT_LINE "+itos(BEGIN.first)+" "+itos(BEGIN.second)+" "+itos(i)+" "+itos(B.second));
        }
    }
    return res;
}

void copie_shape(ii A,char mat[][1000], bool visited[][1000],char remplir[][1000]){
    if(A.first>0){
        if(mat[A.first-1][A.second]=='#' && !visited[A.first-1][A.second]){
            remplir[A.first-1][A.second]='#';
            visited[A.first-1][A.second]=true;
            copie_shape(ii(A.first-1,A.second),mat,visited,remplir);
        }
    }
    if(A.second>0){
        if(mat[A.first][A.second-1]=='#' && !visited[A.first][A.second-1]){
            remplir[A.first][A.second-1]='#';
            visited[A.first][A.second-1]=true;
            copie_shape(ii(A.first,A.second-1),mat,visited,remplir);
        }
    }
    if(A.second>0 && A.first>0){
        if(mat[A.first-1][A.second-1]=='#' && !visited[A.first-1][A.second-1]){
            remplir[A.first-1][A.second-1]='#';
            visited[A.first-1][A.second-1]=true;
            copie_shape(ii(A.first-1,A.second-1),mat,visited,remplir);
        }
    }
    if(A.first>0 && A.second<M-1){
        if(mat[A.first-1][A.second+1]=='#' && !visited[A.first-1][A.second+1]){
            remplir[A.first-1][A.second+1]='#';
            visited[A.first-1][A.second+1]=true;
            copie_shape(ii(A.first-1,A.second+1),mat,visited,remplir);
        }
    }
    if(A.second<M-1){
        if(mat[A.first][A.second+1]=='#' && !visited[A.first][A.second+1]){
            remplir[A.first][A.second+1]='#';
            visited[A.first][A.second+1]=true;
            copie_shape(ii(A.first,A.second+1),mat,visited,remplir);
        }
    }
    if(A.first<N-1 && A.second<M-1){
        if(mat[A.first+1][A.second+1]=='#' && !visited[A.first+1][A.second+1]){
            remplir[A.first+1][A.second+1]='#';
            visited[A.first+1][A.second+1]=true;
            copie_shape(ii(A.first+1,A.second+1),mat,visited,remplir);
        }
    }
    if(A.first<N-1){
        if(mat[A.first+1][A.second]=='#' && !visited[A.first+1][A.second]){
            remplir[A.first+1][A.second]='#';
            visited[A.first+1][A.second]=true;
            copie_shape(ii(A.first+1,A.second),mat,visited,remplir);
        }
    }
    if(A.first<N-1 && A.second>0){
        if(mat[A.first+1][A.second-1]=='#' && !visited[A.first+1][A.second-1]){
            remplir[A.first+1][A.second-1]='#';
            visited[A.first+1][A.second-1]=true;
            copie_shape(ii(A.first+1,A.second-1),mat,visited,remplir);
        }
    }
}

vector<string> count_perfect_line2(ii minP,ii maxP,char mat[][1000]){
    vector<string> res;
    char test[1000][1000];
    memcpy(test,mat,sizeof(char)*1000*1000);
    ii deb,fin;
    ii maxD,maxF;
    int nbS,nbR;
    int maxT=0;
    while(!verif_clear(test)){
        maxT=0;
        /*for(int l=0;l<N;l++){
            for(int o=0;o<M;o++){
                cout << test[l][o];
            }
            cout << "\n";
        }*/
        //cout << maxT << endl;
        for(int i=minP.first;i<=maxP.first;i++){
            deb.first=i;
            fin.first=i;
            for(int j=minP.second;j<=maxP.second;j++){
                if(test[i][j]=='#'){
                    nbS=0;
                    for(int k=j;k>=minP.second;k--){
                        if(test[i][k]=='#'){
                            nbS++;
                            deb.second=k;
                        }
                        else
                            break;
                    }
                    nbR=0;
                    for(int k=j;k<=maxP.second;k++){
                        if(test[i][k]=='#'){
                            nbR++;
                            fin.second=k;
                        }
                        else
                            break;
                    }
                    if(maxT<nbR+nbS-1){
                        maxT=nbR+nbS-1;
                        maxD.first=deb.first;
                        maxD.second=deb.second;
                        maxF.first=fin.first;
                        maxF.second=fin.second;
                    }
                }
            }
        }
        for(int j=minP.second;j<=maxP.second;j++){
            deb.second=j;
            fin.second=j;
            for(int i=minP.first;i<=maxP.first;i++){
                if(test[i][j]=='#'){
                    nbS=0;
                    for(int k=i;k>=minP.first;k--){
                        if(test[k][j]=='#'){
                            nbS++;
                            deb.first=k;
                        }
                        else
                            break;
                    }
                    nbR=0;
                    for(int k=i;k<=maxP.first;k++){
                        if(test[k][j]=='#'){
                            nbR++;
                            fin.first=k;
                        }
                        else
                            break;
                    }
                    if(maxT<nbR+nbS-1){
                        maxT=nbR+nbS-1;
                        maxD.first=deb.first;
                        maxD.second=deb.second;
                        maxF.first=fin.first;
                        maxF.second=fin.second;
                    }
                }
            }
        }
        //cout << maxT << "\n";
        if(maxD.first==maxF.first){
            for(int j=maxD.second;j<=maxF.second;j++){
                test[maxD.first][j]='.';
            }
            //cout << "ligne\n";
        }
        else{
            for(int i=maxD.first;i<=maxF.first;i++){
                test[i][maxD.second]='.';
            }
            //cout << "colonne\n";
        }
        res.push_back("PAINT_LINE "+itos(maxD.first)+" "+itos(maxD.second)+" "+itos(maxF.first)+" "+itos(maxF.second));
    }
    return res;
}

vector<string> count_perfect_line(ii A, ii B,char mat[][1000]){
    vector<string> R1=count_line_vert(A,B,mat);
    vector<string> R2=count_line_horiz(A,B,mat);
    return (R1.size()<R2.size())?R1:R2;
}

void clear_mat(ii minP,ii maxP,char mat[][1000]){
    for(int i=minP.first;i<=maxP.first;i++)
        for(int j=minP.second;j<=maxP.second;j++)
            mat[i][j]='.';
}



vector<vector<string> > V;
/**from here**/
/*
vector<string> recursive_solution(int maxC,char test[][1000]){
    vector< vector<string> > save;
    int tailleB;
    ii minP(1000,1000),maxP(-1,-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(test[i][j]=='#'){
                if(i<minP.first)
                    minP.first=i;
                if(j<minP.second)
                    minP.second=j;
                if(i>maxP.first)
                    maxP.first=i;
                if(j>maxP.second)
                    maxP.second=j;
            }
        }
    }
    vector<string> tmp_res=count_perfect_line(ii(minP.first,minP.second),ii(maxP.first,maxP.second),test);
    int limitT=(maxC<tmp_res.size())?maxC:tmp_res.size();
    if(min(maxP.first-minP.first,maxP.second-minP.second)%2==0)
        tailleB--;
    for(int m=tailleB;m>0;m-=2){
        for(int k=minP.first;k<maxP.first-m+1;k++){
            for(int l=minP.second;l<maxP.second-m+1;l++){
                int nbDot=0;
                for(int o=k;o<=k+m;o++){
                    for(int p=l;p<=l+m;p++){
                        if(test[o][p]=='.')
                            nbDot++;
                    }
                }
                if(nbDot+1<limitT){
                    char tmp_mat[1000][1000];
                    memcpy(tmp_mat,test,sizeof(char)*1000*1000);
                    clear_mat(ii(k,l),ii(k+m,l+m),tmp_mat);
                    if(verif_clear(tmp_mat)){
                        vector<string> Sv;
                        for(int i=k;i<=k+m;i++){
                            for(int j=l;j<=l+m;j++){
                                if(test[i][j]=='.')
                                    Sv.push_back("ERASE_CELL "+itos(i)+" "+itos(j));
                            }
                            Sv.push_back("PAINT_SQUARE "+itos(k+m/2)+" "+itos(l+m/2)+" "+itos(m/2));
                        }
                        save.push_back(Sv);
                    }//else if not clear separer traitement object
                    else{
                        bool visited[1000][1000];
                        char temp[1000][1000];
                        vector<string> Sv;
                        vector<string> poss;
                        memset(temp,'.',sizeof(char)*1000*1000);
                        memset(visited,false,sizeof(bool)*1000*1000);
                        while(!clear_mat(ii(0,0),ii(N-1,M-1),temp)){
                            char tmp[1000][1000];
                            for(int i=0;i<N;i++){
                                for(int j=0;j<M;j++){
                                    if(temp[i][j]=='#' && !visited[i][j]){
                                        copie_shape(ii(i,j),temp,visited,tmp);
                                        poss=recursive_solution(limitT-nbDot-1,tmp_mat);
                                        if(poss.size()!=0)
                                    }
                                }
                            }

                        }
                        //memcpy(temp,tmp_mat,sizeof(char)*1000*1000);
                        vector<string>
                        vector<string> poss=recursive_solution(limitT-nbDot-1,tmp_mat);
                        vector<string> Sv;
                        for(int i=k;i<=k+m;i++){
                            for(int j=l;j<=l+m;j++){
                                if(test[i][j]=='.')
                                    Sv.push_back("ERASE_CELL "+itos(i)+" "+itos(j));
                            }
                            Sv.push_back("PAINT_SQUARE "+itos(k+m/2)+" "+itos(l+m/2)+" "+itos(m/2));
                        }
                        save.push_back(Sv);
                    }
                    if(m<tailleB){
                        char test_mat2[1000][1000];
                        memcpy(test_mat2,test_mat,sizeof(char)*1000*1000);
                        for(int o=k;o<=k+m;o++){
                            for(int p=l;p<=l+m;p++){
                                if(test_mat2[o][p]=='#')
                                    test_mat2[o][p]='.';
                            }
                        }
                        //cout << "test" << endl;
                        vector<string> hor=count_line_horiz(ii(0,0),ii(N-1,M-1),test_mat2);
                        vector<string> ver=count_line_vert(ii(0,0),ii(N-1,M-1),test_mat2);
                        if(min(hor.size(),ver.size())+nbDot+1<min(horiz.size(),vert.size())){
                            res.push_back("PAINT_SQUARE "+itos(k+m/2)+" "+itos(l+m/2)+" "+itos(m/2));
                            cout << "opti m!=tailleB" << endl;
                            if(min(hor.size(),ver.size())==hor.size()){
                                for(int o=0;o<hor.size();o++)
                                    res.push_back(hor[o]);
                            }
                            else{
                                for(int o=0;o<ver.size();o++)
                                    res.push_back(ver[o]);
                            }
                        }
                    }
                    else{
                        res.push_back("PAINT_SQUARE "+itos(k+m/2)+" "+itos(l+m/2)+" "+itos(m/2));
                        cout << "opti m==tailleB" << endl;
                    }
                }
            }
        }
    }
    if(resSize==res.size()){
        if(min(horiz.size(),vert.size())==horiz.size()){
            for(int o=0;o<horiz.size();o++){
                res.push_back(horiz[o]);
            }
        }
        else{
            for(int o=0;o<vert.size();o++){
                res.push_back(vert[o]);
            }
        }
    }
    //mettre le carré a . si nbDots<nblignes
    //puis essayer avec recur(ind+1,maxC=maxC-(nbDots+1))
    //si
}
*/
/**to here**/
/*
vector<string> search_opt(){
    memset(visited,false,sizeof(bool)*1000*1000);
    vector<string> res;
    int resSize=0;
    bool no_touch_yet=true;
    while(no_touch_yet){
        no_touch_yet=false;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(In[i][j]=='#' && !visited[i][j]){
                    no_touch_yet=true;
                    memset(test_mat,'.',sizeof(char)*1000*1000);
                    test_mat[i][j]='#';
                    visited[i][j]=true;
                    copie_shape(ii(i,j));
                    vector<string> horiz=count_line_horiz(ii(0,0),ii(N-1,M-1),test_mat);
                    vector<string> vert=count_line_vert(ii(0,0),ii(N-1,M-1),test_mat);

                    resSize=res.size();



                }

            }
        }

    }
    return res;
}
*/
int main()
{
    ofstream output("output1.out");
    ifstream input("input1.in");
    input >> N >> M;
    memset(In,'.',sizeof(char)*1000*1000);
    //memset(visited,false,sizeof(bool)*1000*1000);
    string in;
    for(int i=0;i<N;i++){
        input >> in;
        for(int j=0;j<M;j++){
            In[i][j]=in[j];
            //cout << In[i][j];
        }
    }
    vector<string> re;
    bool visited[1000][1000];
    memset(visited,false,sizeof(bool)*1000*1000);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(In[i][j]=='#' && !visited[i][j]){
                memset(test_mat,'.',sizeof(char)*1000*1000);
                copie_shape(ii(i,j),In,visited,test_mat);
                vector<string> tmp=count_perfect_line2(ii(0,0),ii(N-1,M-1),test_mat);
                //memset(test_mat,'.',sizeof(char)*1000*1000);
                for(int k=0;k<tmp.size();k++){
                    re.push_back(tmp[k]);
                }
            }
        }
    }
    output << re.size() << endl;
    for(int i=0;i<re.size();i++)
        output << re[i] << "\n";
    re.clear();

    output.close();
    input.close();
    return 0;
}
