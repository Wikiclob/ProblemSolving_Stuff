#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
vector <string> V1;
vector <string> V2;
vector <string> V3;
vector <string> V4;
vector <string> V5;

int taille_limit(vector<string> a,vector<string> b,vector<string> c,vector<string> d,vector <string> e){
    return max(a.size(),max(b.size(),max(c.size(),max(d.size(),e.size()))));
}

bool equi_pass_pass(string pass1,string pass2){
    int i=1;
    int verif=(int)abs(pass1.at(0)-pass2.at(0));
    while(i<pass1.length()){
        if((int)abs(pass1.at(i)-pass2.at(i))!=verif)
            return false;
        else
            i++;
    }
    return true;
}

bool verif_equi_pass(string pass){
    switch(pass.length()){
    case 1:
        if(V1.empty())
            return false;
        else
            return true;
        break;
    case 2:
        if(V2.empty())
            return false;
        else{
            int i=0;
            while(i<V2.size()){
                if(equi_pass_pass(pass,V2[i]))
                    return true;
                else
                    i++;
            }
            return false;
        }
        break;
    case 3:
        if(V3.empty())
            return false;
        else{
            int i=0;
            while(i<V3.size()){
                if(equi_pass_pass(pass,V3[i]))
                    return true;
                else
                    i++;
            }
            return false;
        }
        break;
    case 4:
        if(V4.empty())
            return false;
        else{
            int i=0;
            while(i<V4.size()){
                if(equi_pass_pass(pass,V4[i]))
                    return true;
                else
                    i++;
            }
            return false;
        }
        break;
    case 5:
        if(V5.empty())
            return false;
        else{
            int i=0;
            while(i<V5.size()){
                if(equi_pass_pass(pass,V5[i]))
                    return true;
                else
                    i++;
            }
            return false;
        }
        break;
    }
}

void add_vector(string add){
    if(!verif_equi_pass(add)){
        switch(add.length()){
            case 1: V1.push_back(add);break;
            case 2: V2.push_back(add);break;
            case 3: V3.push_back(add);break;
            case 4: V4.push_back(add);break;
            case 5: V5.push_back(add);break;
        }
    }
}

int main()
{
    vector <string> V11;
    vector <string> V22;
    vector <string> V33;
    vector <string> V44;
    vector <string> V55;
    int N,nbPass;
    string pass;
    cin >> N;
    for(int i=0;i<N;i++){
        V1.clear();
        V2.clear();
        V3.clear();
        V4.clear();
        V5.clear();
        V11.clear();
        V22.clear();
        V33.clear();
        V44.clear();
        V55.clear();
        cin >> nbPass;
        //cin.ignore();
        for(int j=0;j<nbPass;j++){
            cin >> pass;
            switch(pass.length()){
                case 1:V11.push_back(pass);break;
                case 2:V22.push_back(pass);break;
                case 3:V33.push_back(pass);break;
                case 4:V44.push_back(pass);break;
                case 5:V55.push_back(pass);break;
            }
        }
        for(int j=0;j<taille_limit(V11,V22,V33,V44,V55);j++){
            if(j<V11.size())
                add_vector(V11[j]);
            if(j<V22.size())
                add_vector(V22[j]);
            if(j<V33.size())
                add_vector(V33[j]);
            if(j<V44.size())
                add_vector(V44[j]);
            if(j<V55.size())
                add_vector(V55[j]);
        }
        int taille=V1.size()+V2.size()+V3.size()+V4.size()+V5.size();
        cout << "Case " << i+1 << ": " << taille << endl;
    }
    return 0;
}
