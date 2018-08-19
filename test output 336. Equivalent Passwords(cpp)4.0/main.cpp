#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

struct cmpMapKey {
    bool operator()(const std::string& a, const std::string& b) const {
        if(a.length()!=b.length())
            return true;
        else if(a.length()==1)
            return false;
        else{
            int i=1;
            int verif=abs(a.at(0)-'0'-b.at(0)+'0');
            while(i<a.length()){
                if(verif!=(int)abs(a.at(i)-'0'-b.at(i)+'0'))
                    return true;
                else
                    i++;
            }
            return false;
        }
    }
};

int main()
{
    ofstream output;
    ifstream input("input3.in");
    output.open("output3.out");
    int N,nbPass;
    map <string,bool,cmpMapKey> Passwords;
    string pass;
    input >> N;
    for(int i=0;i<N;i++){
        Passwords.clear();
        input >> nbPass;
        for(int j=0;j<nbPass;j++){
            input >> pass;
            Passwords.insert(pair<string,bool>(pass,false));
        }
        output << "Case " << i+1 << ": " << Passwords.size() << endl;
    }
    output.close();
    input.close();
    return 0;
}
