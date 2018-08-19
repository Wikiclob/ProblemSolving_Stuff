#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char ch[101];
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++){
        if(!(ch[i]=='A' || ch[i]=='E' || ch[i]=='Y' || ch[i]=='U' || ch[i]=='I' || ch[i]=='O' || ch[i]=='a' || ch[i]=='e' || ch[i]=='y' || ch[i]=='u' || ch[i]=='i' || ch[i]=='o')){
            if(ch[i]<=90 && ch[i]>=65)
                printf(".%c",ch[i]+32);
            else
                printf(".%c",ch[i]);
        }

    }
    putchar('\n');
    return 0;
}
