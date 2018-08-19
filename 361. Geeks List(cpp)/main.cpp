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
#define ll long long
#define MAX_INT (2147483647)

using namespace std;

int main()
{
    string firstN,lastN,geekList;
    cin >> firstN;
    cin >> lastN;
    cin >> geekList;
    if(geekList.find(firstN+lastN)!=-1)
        cout << "Invited" << endl;
    else
        cout << "I don't have time for parties, I have thigs to do." << endl;
    return 0;
}
