#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool compareString(string a,string b){
    return(a.length()<b.length());
}

int main()
{
    int N,nbPass;
    int Taille[5];
    int nbTaille[5];
    string pass;
    vector <string> V;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nbPass;
        cin.ignore();
        V.clear();
        memset(Taille,-1,sizeof(int)*5);
        memset(nbTaille,0,sizeof(int)*5);
        for(int j=0;j<nbPass;j++){
            cin >> pass;
            bool test=true;
            if(nbTaille[pass.length()-1]!=0){
                int fin=Taille[pass.length()-1]+nbTaille[pass.length()-1];
                for(int k=Taille[pass.length()-1];k<fin;k++){
                    bool diff=false;
                    int verif;
                    int len=pass.length(),cc=1;
                    verif=abs(pass.at(0)-V[k].at(0));
                    while(!diff && cc<len){
                        if((int)abs(pass.at(cc)-V[k].at(cc))!=verif)
                            diff=true;
                        else
                            cc++;
                    }

                    test&=diff;
                    if(!test)
                        break;
                }
            }
            else{
                switch(pass.length()-1){
                    case 0: Taille[0]=0;break;
                    case 1: Taille[1]=(Taille[1]!=-1)?Taille[1]+1:nbTaille[0];break;
                    case 2: Taille[2]=(Taille[2]!=-1)?Taille[2]+1:nbTaille[0]+nbTaille[1];break;
                    case 3: Taille[3]=(Taille[3]!=-1)?Taille[3]+1:nbTaille[0]+nbTaille[1]+nbTaille[2];break;
                    case 4: Taille[4]=(Taille[4]!=-1)?Taille[4]+1:nbTaille[0]+nbTaille[1]+nbTaille[2]+nbTaille[3];break;
                }
            }
            if(test){
                V.push_back(pass);
                nbTaille[pass.length()-1]++;
                sort(V.begin(),V.end(),compareString);
                switch(pass.length()-1){
                    case 0: Taille[1]=(Taille[1]!=-1)?Taille[1]+1:-1;
                            Taille[2]=(Taille[2]!=-1)?Taille[2]+1:-1;
                            Taille[3]=(Taille[3]!=-1)?Taille[3]+1:-1;
                            Taille[4]=(Taille[4]!=-1)?Taille[4]+1:-1;
                            break;
                    case 1: Taille[2]=(Taille[2]!=-1)?Taille[2]+1:-1;
                            Taille[3]=(Taille[3]!=-1)?Taille[3]+1:-1;
                            Taille[4]=(Taille[4]!=-1)?Taille[4]+1:-1;
                            break;
                    case 2: Taille[3]=(Taille[3]!=-1)?Taille[3]+1:-1;
                            Taille[4]=(Taille[4]!=-1)?Taille[4]+1:-1;
                            break;
                    case 3: Taille[4]=(Taille[4]!=-1)?Taille[4]+1:-1;
                            break;
                }
            }
        }
        cout << "Case " << i+1 << ": " << V.size() << endl;
    }
    return 0;
}
