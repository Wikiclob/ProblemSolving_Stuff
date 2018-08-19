#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

bool compare_key(string a, string b){
    if(a.length()!=b.length()){
        return true;
    }
    else if(a.length()==1){
        return false;
    }
    else{
        int i=1;
        int verif=abs(a.at(0)-'0'-b.at(0)+'0');
        while(i<a.length()){
            if(verif!=(int)abs(a.at(i)-'0'-b.at(i)+'0')){
                return true;
            }
            else
                i++;
        }
        return false;
    }
}

bool verif_vector_key(vector<string> V,string pass){
    for(int i=0;i<V.size();i++){
        if(!compare_key(V[i],pass))
            return false;
    }
    return true;
}

int main()
{
    int N,nbPass;
    vector <string> Passwords;
    string pass;
    cin >> N;
    for(int i=0;i<N;i++){
        Passwords.clear();
        cin >> nbPass;
        cin.ignore();
        for(int j=0;j<nbPass;j++){
            cin >> pass;
            if(verif_vector_key(Passwords,pass))
                Passwords.push_back(pass);
        }
        cout << "Case " << i+1 << ": " << Passwords.size() << endl;
    }
    return 0;
}
