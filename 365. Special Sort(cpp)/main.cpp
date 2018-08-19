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

bool compare_int_dec(int a,int b){
	return (a>b);
}

bool compare_int_inc(int a,int b){
    return (a<b);
}

int main()
{
    int N,number;
    vector<int> even,odd;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> number;
        if(number%2==0)
            even.push_back(number);
        else
            odd.push_back(number);
    }
    sort(even.begin(),even.end(),compare_int_inc);
    sort(odd.begin(),odd.end(),compare_int_dec);
    for(int i=0;i<even.size();i++)
        cout << even[i] << endl;
    for(int i=0;i<odd.size();i++)
        cout << odd[i] << endl;
    return 0;
}
