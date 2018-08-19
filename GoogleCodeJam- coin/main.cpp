#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ll divisor;
ll divisors[9];

/*
//PRIMES Sieve
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<536870799> bs; // 10^7 should be enough for most cases
vector<ll> primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back(i); // also add this vector containing list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (ll i = 0; i < primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2
*/

bool isPrime(ll n) {
    if (n == 2) return true ;
    else if (n < 2 || n % 2 == 0) return false ;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)  return false;

    return true;
    }

ll divisor_of(ll n){
    //cout << "\n" << n << " ";
    if(n%2==0)
        return 2;
    for(ll i=3;i*i<=n;i+=2){
        //cout << n << endl;
        if((n%i)==0){
            //cout << "test" << endl;
            //cout << i << "\n";
            return i;
        }
    }
}

//debut verif prime
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
//fin verif prime

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

ll pow_n(ll number,int exp){
    if(exp==0)
        return 1;
    ll res=number;
    while(exp>1){
        res=res*number;
    }
    return res;
}

ll from_base(string number_binary,int base){
    ll result=0;
    int power=0;
    ll res_power=1;
    for(int i=number_binary.length()-1;i>=0;i--){
        result+=((number_binary[i]=='1')?( res_power ) : 0);
        res_power*=base;
        power++;
    }
    //cout << number_binary << " => " << result << "(base " << base << ")" << endl;
    return result;
}

string add_on_string_base_2(string s){
    if(s[s.length()-1]=='0'){
        s[s.length()-1]='1';
        return s;
    }
    else{
        s[s.length()-1]='0';
    }
    bool pass=true;
    for(int i=s.length()-2;i>=0;i--){
        if(s[i]=='1'){
            s[i]='0';
        }
        else{
            s[i]='1';
            pass=false;
            break;
        }
    }
    if(pass)
        return "1"+s;
    else
        return s;
}

string regulate_length(string s,int len){
    while(s.length()!=len)
        s="0"+s;
    return s;
}

string next_number(string s,int len){
    ll number;
    bool first_time=true;
    bool ending=false;
    while(!ending){
        cout << "verif_long boucle\n";
        if(s=="0" && first_time)
            first_time=false;
        else
            s=add_on_string_base_2(s);
        s=regulate_length(s,len);
        //cout << s << endl;
        for(int i=2;i<=10;i++){
            number=from_base("1"+s+"1",i);
            if(Miller(number,20)){
                cout << "Miller\n";
                break;
            }
            else{
                divisors[i-2]=divisor_of(number);
                //cout << number << " divisible par " << divisors[i-2] << endl;
                if(i==10)
                    ending=true;
            }
        }
        if(ending)
            cout << "next\n";
    }
    return s;
}

int main()
{
    ifstream input("C-large.in");
    ofstream output("C-large.out");
    int N;
    int NB,J;
    int limit;
    //sieve(9999999);
    //cout << "test" << endl;
    string res="0";
    input >> N;
    for(int i=1;i<=N;i++){
        input >> NB >> J;
        limit=NB-2;
        output << "Case #" << i << ":\n";
        if(J==1 && NB==1){
            output << "1 1 1 1 1 1 1 1 1 1\n";
        }
        else{
            for(int j=0;j<J;j++){
                res=next_number(res,limit);
                output << "1"+res+"1";
                for(int k=0;k<9;k++)
                    output << " " << divisors[k];
                output << "\n";
            }
        }
    }
    return 0;
}
