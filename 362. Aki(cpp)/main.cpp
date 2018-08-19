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

bool verif_pal(string word){
    string rev="";
    string w="";
    for(int i=0;i<word.length();i++)
        w+=tolower(word.at(i));
    rev=w;
    reverse(rev.begin(),rev.end());
    return rev==w;
}

int main()
{
    string word;
    cin >> word;
    if(verif_pal(word))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
    return 0;
}
