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
    int cap,N,left,enter,stay,countNb;
    bool verif,stop_count;
    //ifstream input("input.in");
    while(true){
        cin >> cap >> N;
        countNb=0;
        stop_count=false;
        for(int i=1;i<=N;i++){
            cin >> left >> enter >> stay;
            if(!stop_count){
                verif=false;
                if(i==1){
                    if(left==0){
                        if(enter<cap && stay==0){
                            countNb=enter;
                            verif=true;
                        }
                        else if(enter==cap){
                            countNb=enter;
                            verif=true;
                        }
                    }
                }
                else if(i<N){
                    if(left<=countNb){
                        countNb-=left;
                        if(enter<cap-countNb){
                            if(stay==0){
                                countNb+=enter;
                                verif=true;
                            }
                        }
                        else if(enter == cap-countNb){
                            countNb+=enter;
                            verif=true;
                        }
                    }
                }
                else{
                    if(left == countNb){
                        if(enter==0){
                            if(stay==0){
                                verif=true;
                            }
                        }
                    }
                }
                if(verif==false)
                    stop_count=true;
            }
        }
        if(cin.eof())
            break;
        if(!stop_count)
            cout << "possible" << endl;
        else
            cout << "impossible" << endl;
    }
    //input.close();
    return 0;
}
