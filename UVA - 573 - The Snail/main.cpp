#include <bits/stdc++.h>

using namespace std;

int main()
{
    int height,dayDist,nightDist,fatigue,day;
    bool failure=false;
    bool never=false;
    double distNow,reduce,dayD;
    while(true){
        cin >> height >> dayDist >> nightDist >> fatigue;
        if (height==0){
            break;
        }
        distNow=0;
        day=0;
        failure=false;
        never=false;
        reduce=0;
        dayD=dayDist;
        reduce=(dayDist*fatigue)/100.0;
        while(distNow<height){
            if(day!=0 && !never){
                dayD-=reduce;
                if(dayD<0){
                    dayD=0;
                    never=true;
                }
                distNow+=dayD;
            }
            else
                distNow+=dayD;
            day++;
            //cout << "day: " << distNow << endl;
            if(distNow>0){
                if(distNow>height)
                    break;
                else{
                    distNow-=nightDist;
                    //cout << "night: " << distNow << endl;
                    //getchar();
                    if(distNow<0){
                        failure=true;
                        break;
                    }
                }
            }
            else{
                failure=true;
                break;
            }
        }
        if(failure){
            cout << "failure on day " << day << endl;
        }
        else
            cout << "success on day " << day << endl;
    }
    return 0;
}
