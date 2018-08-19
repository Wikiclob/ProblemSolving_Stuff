#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#define LONG_LONG_BIG (999999999)
#define ll long long

using namespace std;

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/*
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

long long next_pal(long long n){
    char *s;
    long long i,l,f,mid,fp;
    f=1;
    s=&NumberToString(n)[0u];
    l=strlen(s);
    fp=0;
    for(i=0;i<l;i++){
        if(s[i]!='9'){
            f=0;
            break;
        }
    }
    if(f==1){
        s[0]='1';
        for(i=1;i<l;i++)
            s[i]='0';
        s[l]='1';
        s[l+1]='\0';
        fp=1;
    }
    f=0;
    if(fp!=1){
        for(i=0;i<l/2;i++){
            if(s[i]<s[l-i-1])
                f=-1;
            else if(s[i]>s[l-i-1])
                f=1;
            s[l-i-1]=s[i];
        }
        if(l%2==0)
            mid=l/2-1;
        else
            mid=l/2;
        if(f==-1||f==0){
            i=0;
            while(s[mid-i]=='9'){
                s[mid-i] = '0';
                s[l-1-mid+i] = '0';
                i++;
            }
            s[mid-i]++;
            s[l-1-mid+i] = s[mid-i];
        }
    }
    return atoll(s);
}

int main()
{
    long long N;
    string test1,Ns;
    cin >> N;

    Ns=NumberToString(N);
    test1=Ns;
    reverse(test1.begin(),test1.end());
    while(true){
        if(Ns==test1 && Miller(N,20)){
            cout << N << endl;
            break;
        }
        else{
            N=next_pal(N);
            Ns=NumberToString(N);
            if(Ns.length()%2==0 && N!=11){
                N=(long long)pow(10,Ns.length());
                N=next_pal(N);
                Ns=NumberToString(N);
            }
            if(Ns.at(0)!='1' && Ns.at(0)!='3' && Ns.at(0)!='7' && Ns.at(0)!='9' && Ns.length()>2){
                switch(N%10){
                case 2: N=(long long)pow(10,Ns.length()-1)*3;N+=3;Ns=NumberToString(N);break;
                case 4:case 5: case 6: N=(long long)pow(10,Ns.length()-1)*7;N+=7;Ns=NumberToString(N);break;
                case 8: N=(long long)pow(10,Ns.length()-1)*9;N+=9;Ns=NumberToString(N);break;
                }
            }
            test1=Ns;
            reverse(test1.begin(),test1.end());
        }
    }
    return 0;
}
