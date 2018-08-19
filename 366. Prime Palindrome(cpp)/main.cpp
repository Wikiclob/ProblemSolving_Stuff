#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>
#define LONG_INT_MAX (4294967296)

using namespace std;

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

bool IsPrime(long long number) {
    if (number <= 3 && number > 1)
        return true;            // as 2 and 3 are prime
    else if (number%2==0 || number%3==0)
        return false;     // check if number is divisible by 2 or 3
    else {
        for (long long i=5; i*i<=number; i+=6) {
            if (number % i == 0 || number%(i + 2) == 0)
                return false;
        }
        //cout << number << endl;
        return 1;
    }
}

bool VerifNine(long long number){
    string test=NumberToString(number);
    for(int i=0;i<test.length();i++)
        if(test.at(i)!='9')
            return false;
    return true;
}

int main()
{
    long long N;
    //ofstream myfile;
    //myfile.open("resultat.txt");
    cin >> N;
    long long limit;
    //cin >> limit;
    if(N%2==0)
        N=N+1;
    string test1="",test2="";
    while(true){
        if(IsPrime(N)){
            test1=NumberToString(N);
            test2=test1;
            reverse(test2.begin(),test2.end());
            if(test1==test2)
            {
                cout << N << endl;
                N+=2;
                if(N<0)
                    break;
                //break;
            }
            else{
                N+=2;
            }
        }
        N+=2;
    }
    myfile.close();
    return 0;
}
