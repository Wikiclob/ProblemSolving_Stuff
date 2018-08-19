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

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

long long from_string(std::string const & s) {
    std::stringstream ss(s);
    long long result;
    ss >> result;    // TODO handle errors
    return result;
}
int main()
{
    string line;
    ofstream myfile2;
    ifstream myfile("prime.txt");
    myfile2.open("PrimeAndPal.txt");
    string test1,test2;
    while (getline(myfile,line))
    {
        test1=line;
        test2=test1;
        reverse(test2.begin(),test2.end());
        if(test1==test2){
            myfile2 << line << endl;
        }
    }
    myfile.close();
    myfile2.close();
    return 0;
}
