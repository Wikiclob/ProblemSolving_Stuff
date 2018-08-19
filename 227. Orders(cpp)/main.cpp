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

vector<string> res;
int len;
int cc=0;

void all_possible(string ch,int fixed){
    cc++;
    cout << cc << endl;
    cout << "test: " << ch << endl;
    if(fixed+1==len)
        return;
    all_possible(ch,fixed+1);
    for(int i=fixed+1;i<len;i++){
        if(ch[fixed]!=ch[i]){
            swap(ch[fixed],ch[i]);
            if(ch==res[res.size()-1])
                return;
            else
                res.push_back(ch);
            all_possible(ch,fixed+1);
            swap(ch[fixed],ch[i]);
        }
    }
}

int main()
{
    int N,i;
    string S;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        cin >> S;
        res.clear();
        len=S.length();
        res.push_back(S);
        all_possible(S,0);
        sort(res.begin(),res.end());
        for(int j=0;j<res.size();j++){
            cout << res[j] << endl;
        }
    }
    return 0;
}
