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
    int N;
    string ch;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> ch;
        bool found=false;
        for(int i=0;i<ch.length()&&!found;i++){
            if(ch.at(i)=='n'){
                for(int j=i+1;j<ch.length()&&!found;j++){
                    if(ch.at(j)=='a'){
                        for(int k=j+1;k<ch.length()&&!found;k++){
                            if(ch.at(k)=='d'){
                                for(int l=k+1;l<ch.length()&&!found;l++){
                                    if(ch.at(l)=='i'){
                                        for(int m=l+1;m<ch.length()&&!found;m++){
                                            if(ch.at(m)=='a')
                                                found=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
