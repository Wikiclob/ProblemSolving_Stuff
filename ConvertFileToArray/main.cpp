#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)

using namespace std;

int main()
{
    ofstream output;
    string s;
    ifstream input("input.in");
    output.open("output.out");
    int i=1;
    while(!input.eof()){
        input >> s;
        output << s << ",";
        if(i%20==0)
            output << "\n";
        i++;
    }
    input.close();
    output.close();
    return 0;
}
