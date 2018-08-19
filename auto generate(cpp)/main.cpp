#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#define BIG_INT_MOD (1000000007)
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("resultat.txt");
    myfile << "{2,3";
    int n=2;
    int m=3;
    for(int i=3;i<=1000;i++){
        if(i%15==0)
            myfile << "\n";
        myfile << "," << (n+m)%BIG_INT_MOD;
        int temp=(n+m)%BIG_INT_MOD;
        n=m;
        m=temp;
    }
    myfile << "};";
    myfile.close();
    return 0;
}
