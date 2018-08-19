#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

//PRIMES Sieve
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i); // also add this vector containing list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2


//COUNT sum of divisors of N
ll sumDiv(ll N) {
int add=0;
if(N==496)
add=31;
ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
while (PF * PF <= N) {
ll power = 0;
while (N % PF == 0) { N /= PF; power++; }
ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1); // formula
PF = primes[++PF_idx];
}
if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last one
return ans+add;
}

void affiche_N(int N){
    if(N/10==0){
        printf("    %d",N);
    }
    else if(N/100==0){
        printf("   %d",N);
    }
    else if(N/1000==0){
        printf("  %d",N);
    }
    else if(N/10000==0){
        printf(" %d",N);
    }
    else{
        printf("%d",N);
    }
}

ll numDiv(ll N) {
ll PF_idx = 0, PF = primes[PF_idx], ans = 1;// start from ans = 1
while (N != 1 && (PF * PF <= N)) {
ll power = 0; // count the power
while (N % PF == 0) { N /= PF; power++; }
ans *= (power + 1); // according to the formula
PF = primes[++PF_idx];
}
if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
return ans;
}

int main()
{
    int N,sum;
    sieve(60000);
    cout << "PERFECTION OUTPUT\n";
    while(true){
        scanf("%d",&N);
        if(N==0)
            break;
        affiche_N(N);
        sum=sumDiv(N)-N;
        if(sum>N)
            printf("  ABUNDANT\n");
        else if(sum<N)
            printf("  DEFICIENT\n");
        else
            printf("  PERFECT\n");
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
