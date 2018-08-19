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

string itos(int a){
    ostringstream convert;
    convert << a;
    return convert.str();
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

char test_mat[1000][1000];
bool visited[1000][1000];
void copie_shape(ii A){
    if(A.first>0){
        if(In[A.first-1][A.second]=='#' && !visited[A.first-1][A.second]){
            test_mat[A.first-1][A.second]='#';
            visited[A.first-1][A.second]=true;
            copie_shape(ii(A.first-1,A.second));
        }
    }
    if(A.second>0){
        if(In[A.first][A.second-1]=='#' && !visited[A.first][A.second-1]){
            test_mat[A.first][A.second-1]='#';
            visited[A.first][A.second-1]=true;
            copie_shape(ii(A.first,A.second-1));
        }
    }
    if(A.second>0 && A.first>0){
        if(In[A.first-1][A.second-1]=='#' && !visited[A.first-1][A.second-1]){
            test_mat[A.first-1][A.second-1]='#';
            visited[A.first-1][A.second-1]=true;
            copie_shape(ii(A.first-1,A.second-1));
        }
    }
    if(A.first>0 && A.second<M-1){
        if(In[A.first-1][A.second+1]=='#' && !visited[A.first-1][A.second+1]){
            test_mat[A.first-1][A.second+1]='#';
            visited[A.first-1][A.second+1]=true;
            copie_shape(ii(A.first-1,A.second+1));
        }
    }
    if(A.second<M-1){
        if(In[A.first][A.second+1]=='#' && !visited[A.first][A.second+1]){
            test_mat[A.first][A.second+1]='#';
            visited[A.first][A.second+1]=true;
            copie_shape(ii(A.first,A.second+1));
        }
    }
    if(A.first<N-1 && A.second<M-1){
        if(In[A.first+1][A.second+1]=='#' && !visited[A.first+1][A.second+1]){
            test_mat[A.first+1][A.second+1]='#';
            visited[A.first+1][A.second+1]=true;
            copie_shape(ii(A.first+1,A.second+1));
        }
    }
    if(A.first<N-1){
        if(In[A.first+1][A.second]=='#' && !visited[A.first+1][A.second]){
            test_mat[A.first+1][A.second]='#';
            visited[A.first+1][A.second]=true;
            copie_shape(ii(A.first+1,A.second));
        }
    }
    if(A.first<N-1 && A.second>0){
        if(In[A.first+1][A.second-1]=='#' && !visited[A.first+1][A.second-1]){
            test_mat[A.first+1][A.second-1]='#';
            visited[A.first+1][A.second-1]=true;
            copie_shape(ii(A.first+1,A.second-1));
        }
    }
}

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
                    int tailleB;
                    if(min(N,M)%2==1)
                        tailleB=min(N,M);
                    else
                        tailleB=min(N,M)-1;
                    resSize=res.size();

                    for(int m=tailleB;m>0;m-=2){
                        for(int k=0;k<N-m+1;k++){
                            for(int l=0;l<M-m+1;l++){
                                int nbDot=0;
                                for(int o=k;o<=k+m;o++){
                                    for(int p=l;p<=l+m;p++){
                                        if(test_mat[o][p]=='.')
                                            nbDot++;
                                    }
                                }
                                if(nbDot+1<min(horiz.size(),vert.size())){

                                    if(m<tailleB){
                                            /**bug from here**/
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
                                        /**bug to here**/
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
                }

            }
        }

    }
    return res;
}

int main()
{

    ofstream output("output.out");
    ifstream input("input3.in");
    input >> N >> M;
    memset(In,'.',sizeof(char)*1000*1000);
    string in;
    for(int i=0;i<N;i++){
        input >> in;
        for(int j=0;j<M;j++){
            In[i][j]=in[j];
            //cout << In[i][j];
        }
    }
    vector<string> re=search_opt();
    output << re.size() << endl;
    for(int i=0;i<re.size();i++)
        output << re[i] << "\n";
    re.clear();

    output.close();
    input.close();
    return 0;
}
