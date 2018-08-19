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

const int taille=400;
int last=1065;
int T[taille]={28,39,46,48,57,64,68,69,75,78,82,84,86,87,91,93,95,96,118,129,
136,138,145,147,154,156,158,159,165,168,169,172,174,176,177,178,183,185,186,187,
189,190,192,194,195,196,198,208,217,219,226,228,235,237,244,246,248,249,253,255,
258,259,264,266,267,268,273,275,276,279,280,284,285,286,288,291,294,295,297,299,
309,316,318,325,327,329,334,336,338,339,345,348,352,354,356,357,358,361,365,366,
369,370,372,374,375,376,378,381,384,385,387,390,392,394,396,398,399,406,408,415,
417,426,428,429,435,437,438,442,446,447,448,451,453,455,456,459,460,462,465,466,
468,471,473,475,477,480,482,483,486,488,489,492,493,495,497,498,507,514,516,518,
519,527,528,529,532,534,536,537,538,543,546,549,550,552,554,556,558,561,564,567,
570,572,573,574,576,578,579,581,582,583,588,590,591,592,594,596,597,604,608,609,
615,618,622,624,627,628,633,635,637,639,640,642,644,645,648,651,654,655,657,660,
662,663,664,668,669,671,672,675,678,680,681,682,684,687,690,693,695,699,703,705,
708,712,714,716,718,721,723,725,726,729,730,732,734,735,736,738,741,744,745,749,
750,752,753,754,756,758,759,762,763,765,768,770,771,772,774,776,780,781,783,785,
786,789,790,792,794,795,798,799,802,804,806,807,813,815,816,817,819,820,822,824,
825,826,831,833,834,835,837,840,842,843,844,846,849,851,852,855,860,861,862,864,
866,867,870,871,873,875,876,879,880,882,884,885,889,891,893,894,897,899,901,903,
905,906,910,912,914,915,916,918,921,923,924,925,927,930,932,933,934,936,938,942,
943,945,948,950,951,952,954,956,957,960,961,963,965,966,970,972,974,975,978,981,
984,987,988,990,992,993,996,998,1018,1027,1029,1036,1038,1045,1047,1054,1056,1058,1059,1065};

bool verif_pal(int n){
    int pal=0;
    int tmp=n;
    while(n>0){
        pal*=10;
        pal+=(n%10);
        n/=10;
    }
    return tmp==pal;
}

int sum_digit(int n){
    int retour=0;
    while(n>0){
        retour+=n%10;
        n/=10;
    }
    return retour;
}

bool isPrime(int n) {
    if (n == 2) return true ;
    else if (n < 2 || n % 2 == 0) return false ;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)  return false;

    return true;
    }

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


int main()
{
    int N,x,sum;
    //ofstream output;
    stringstream output;
    //output.open("output55.out");
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        printf("Case %d:\n",i);
        if(x<=last){
            for(int j=0;j<taille;j++){
                if(T[j]>x)
                    break;
                output << T[j] << "\n";
                //printf("%d\n",T[j]);
            }
        }
        else{
            for(int j=0;j<taille;j++)
                output << T[j] << "\n";
                //printf("%d\n",T[j]);
        }
        for(int j=last+1;j<=x;j++){
            sum=sum_digit(j);
            if(!isPrime(sum)){
                 if(!verif_pal(sum)){
                    if(!verif_pal(j)){
                        if(!isPrime(j)){
                            output << j << "\n";
                            //printf("%d\n",j);
                        }
                    }
                }
            }
        }
        output << flush;
        cout << output.rdbuf();
    }
    return 0;
}
