#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int sum1,sum2;
    char ch[150];
    scanf("%d",&N);fflush(stdin);
    for(int i=0;i<N;i++){
        sum1=0;
        sum2=0;
        bool passed=false;
        strcpy(ch,"");
        scanf("%s",ch);
        for(int j=0;j<strlen(ch);j++){
            if(!passed){
                if(ch[j]!='.'){
                    if(ch[j]>=97)
                        sum1+=(ch[j]-97+1);
                    else
                        sum1+=(ch[j]-65+1);
                }
                else{
                    passed=true;
                }
            }
            else{
                if(ch[j]>=97)
                        sum2+=(ch[j]-97+1);
                    else
                        sum2+=(ch[j]-65+1);
            }
        }
        //printf("%s %d %d\n",ch,sum1,sum2);
        if(sum1!=sum2){
            printf("%s\n",ch);
        }
    }
    return 0;
}
