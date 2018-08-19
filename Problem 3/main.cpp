#include <bits/stdc++.h>

using namespace std;




string hash_function(string ch){
    string ch1="00000000000000000000000000000000000000000000000000000000000000";
    bool verif=false;
    for(int i=0;i<ch.size();i++){
        if(ch[i]>='A' && ch[i]<='Z'){
            //verif=true;
            ch1[i]='1';
        }
        else
            ch1[i]='0';
    }
    //if(verif)
        return ch1;
    //else
     //   return "";
}

long long sum_arith(int N){
    long long res=N;
    res*=(N-1);
    res/=2;
    return res;
}

int main(){
    int N;
    long long R=0;
    map<string,int> M;
    string ch,ch1;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >> ch;

        ch1=hash_function(ch);
        //if(ch1 != "")
        M[ch1]++;
    }
    for(map<string,int>::iterator it=M.begin();it!=M.end();it++){
        if(it->second >=2)
            R+=sum_arith(it->second);
    }
    cout << R << endl;
    return 0;
}
