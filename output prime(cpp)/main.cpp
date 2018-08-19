#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

long long from_string(std::string const & s) {
    std::stringstream ss(s);
    long long result;
    ss >> result;    // TODO handle errors
    return result;
}
int main()
{
    long long N=3;
    string line;
    ofstream myfile2;
    while(N>0){
        ifstream myfile("prime.txt");
        bool verif=true;
        while (getline(myfile,line))
        {
            long long ll=from_string(line);
            if(N%ll==0){
                verif=false;
                myfile.close();
                break;
            }
            if(ll*ll>N)
                break;
        }
        if(verif){
            myfile.close();
            myfile2.open("prime.txt",ios::app);
            myfile2 << N << endl;
            myfile2.close();
        }
        N+=2;
    }

    return 0;
}
