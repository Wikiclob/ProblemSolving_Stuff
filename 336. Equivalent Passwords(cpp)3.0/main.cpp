#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
//#include <unordered_map>

using namespace std;

struct cmpMapKey {
    bool operator()(const std::string& a, const std::string& b) const {
        if(a.length()!=b.length())
            return true;
        else if(a.length()==2)
            return false;
        else{
            int i=0;
            while(true){
                if(i*4>a.length()-2)
                    break;
                //cout << a.substr(i*6,3) << " " << a.substr(i*6+3,3) << endl;
                //cout << b.substr(i*6,3) << " " << b.substr(i*6+3,3) << endl;
                if(a.substr(i*4,2)==b.substr(i*4,2) || a.substr(i*4+2,2)==b.substr(i*4+2,2))
                    i++;
                else
                    return true;
            }
            return false;
        }
    }
};

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

string generate_hash_pass(string pass){
    string retour="",addA,addB;
    int a,b;
    if(pass.length()==1)
        return "00";
    for(int i=0;i<pass.length()-1;i++){
        for(int j=i+1;j<pass.length();j++){
            //cout << (int)pass.at(i)-'0' << " & " << (int)pass.at(j)-'0' << endl;
            a=pass.at(i)-'0';
            b=pass.at(j)-'0';
            addA=NumberToString(a+b);
            if(addA.length()==1)
                addA="0"+addA;
            addB=NumberToString(a-b);
            if(addB.length()==1)
                addB="0"+addB;
            retour+=addA+addB;
        }
    }
    return retour;
}

int main()
{
    int N,nbPass;
    map <string,bool,cmpMapKey> Passwords;
    string pass;
    cin >> N;
    for(int i=0;i<N;i++){
        Passwords.clear();
        cin >> nbPass;
        for(int j=0;j<nbPass;j++){
            cin >> pass;
            //cout << generate_hash_pass(pass) << endl;
            Passwords.insert(pair<string,bool>(generate_hash_pass(pass),false));
        }
        cout << "Case " << i+1 << ": " << Passwords.size() << endl;
    }
    return 0;
}
