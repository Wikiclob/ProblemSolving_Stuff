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
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i); // also add this vector containing list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

vi primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
vi factors;
ll PF_idx = 0, PF = primes[PF_idx]; // using PF = 2, then 3,5,7,... is also ok
while (N != 1 && (PF * PF <= N)) { // stop at sqrt(N), but N can get smaller
while (N % PF == 0) { N /= PF; factors.push_back(PF); } // remove this PF
PF = primes[++PF_idx]; // only consider primes!
}
if (N != 1) factors.push_back(N); // special case if N is actually a prime
return factors; // if N does not fit in 32-bit integer and is a prime number
} // then ‘factors’ will have to be changed to vector<ll>

stringstream ss;
vi primeF;

int main(){
    int nb;
    int pow_nb;
    int len,k;
    int last;
    int count_pow;
    ll number;
    sieve(1000001);
    char s[1000];
    while(gets(s)){
        len = strlen(s);
        k = 0;
        if (len==1 && s[0]=='0') break;
        number=0;
        while (k<len) {
            while (k<len && s[k]==' ') k++;
            if (k<len) {
                sscanf(s+k, "%d", &nb);
                while (k<len && s[k]!=' ') k++;
                while (k<len && s[k]==' ') k++;
                if (k<len) {
                    sscanf(s+k, "%d", &pow_nb);
                    number+=pow(nb,pow_nb);
                    while (k<len && s[k]!=' ') k++;
                }
            }
        }
        number--;
        primeF.clear();
        cout << number << endl;
        primeF=primeFactors(number);
        last=0;
        for(int i=0;i<primeF.size();i++){
            if(primeF[i]!=last){
                if(i!=0)
                    cout << " " << count_pow;
                last=primeF[i];
                count_pow=1;
                if(i!=0)
                    cout << " " << primeF[i];
                else
                    cout << primeF[i];
            }
            else{
                count_pow++;
            }
        }
        cout << " " << count_pow << endl;
    }

        //cout << number << endl;




    return 0;
}
