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
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int N,age;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&age);
        cout << "Case " << i << ":\n";
        if(age<=5)
            cout << "Languages\n";
        else if(age<=7)
            cout << "Read and Write\n";
        else if(age<=12)
            cout << "Robotics\n";
        else if(age<=19)
            cout << "Programming and Robotics\n";
        else
            cout << "Read about everything\n";

    }
    return 0;
}
