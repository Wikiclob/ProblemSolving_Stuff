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
    int N;
    char str[4];
    int nb[3];
    int tmp;
    cin >> N;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&nb[0],&nb[1],&nb[2]);
        sort(nb,nb+3);
        fflush(stdin);
        scanf("%s",str);
        for(int i=0;i<3;i++){
            if(i!=0)
                cout << " ";
            switch(str[i]){
                case 'A': cout << nb[0];break;
                case 'B': cout << nb[1];break;
                case 'C': cout << nb[2];break;
            }
        }
        cout << "\n";
    }
    return 0;
}
