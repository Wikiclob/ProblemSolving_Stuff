#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>

void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
	// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i)
bs[j] = 0; primes.push_back((int)i); // also add this vector containing list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

pair<int,int> complete_search(int nb){
    int first=0,last=primes.size()-1;
    last=lower_bound(primes.begin(),primes.end(),nb)-primes.begin();
    for(int i=last;i>0;i--){
        if(primes[i]<nb){
            first=i;
            for(int j=1;j<=first;j++){
                if(primes[j]+primes[i]==nb)
                    return {primes[j],primes[i]};
                else if(primes[j]+primes[i]>nb)
                    break;
            }
        }
    }
    return {-1,-1};
}


int main()
{
    int nb;
    pair<int,int> p;
    sieve(1000000);
    primes[0]=1;
    while(true){
        scanf("%d",&nb);
        if(nb==0)
            break;
        p=complete_search(nb);
        if(p.first!=-1 && p.second!=-1){
            printf("%d = %d + %d\n",nb,p.first,p.second);
        }
        else{
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
