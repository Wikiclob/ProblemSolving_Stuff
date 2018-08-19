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

struct cmpMapKey {
    bool operator()(const std::string& a, const std::string& b) const {
        //cout << a << " & " << b << endl;
        if(a.length()!=b.length()){
            //cout << "not the same length" << endl;
            return true;
        }
        else if(a.length()==1){
            //cout << "length is 1" << endl;
            return false;
        }
        else{
            int i=1;
            int verif=abs(a.at(0)-'0'-b.at(0)+'0');
            //cout << "diff = " << verif << endl;
            while(i<a.length()){
                if(verif!=(int)abs(a.at(i)-'0'-b.at(i)+'0')){
                    //cout << "verif!=" << (int)abs(a.at(i)-'0'-b.at(i)+'0') << endl;
                    return true;
                }
                else
                    i++;
            }
            //cout << "it's equal" << endl;
            return false;
        }
    }
};

int main()
{
    int N,nbPass;
    map <string,bool,cmpMapKey> Passwords;
    string pass;
    cin >> N;
    for(int i=0;i<N;i++){
        Passwords.clear();
        cin >> nbPass;
        cin.ignore();
        for(int j=0;j<nbPass;j++){
            cin >> pass;
            Passwords.insert(pair<string,bool>(pass,false));
        }
        cout << "Case " << i+1 << ": " << Passwords.size() << endl;
    }
    return 0;
}
