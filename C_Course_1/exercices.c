#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef unsigned long long ull;
typedef long long ll;
typedef int boolean;

ull itFact(ull n){
    ull i, fact = 1;
    for(i=2;i<=n;i++){
        fact *= i;
    }
    return fact;
}

ull recFact(ull n){
    if(n==0 || n==1) return 1;
    return n*recFact(n-1);
}

ull pow(ull x, ull n){
    if(n==0) return 1;
    if(n==1) return x;
    return x*pow(x,n-1);
}

void printDec(int n){
    if(n==0) return;
    printf("%d\n",1+2*(n-1));
    printDec(n-1);
}

int recurDiv2(int n){
    if(n%2 || !n) return 0;
    return 1+recurDiv2(n/2);
}

int recurMul(int n,int m){
    if(!n || !m) return 0;
    if(m==1) return n;
    if(n==1) return m;
    return n+recurMul(n,m-1);
}

boolean isPrime(int n) {
    if (n == 2) return TRUE;
    else if (n < 2 || n % 2 == 0) return FALSE;
    int i;
    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)  return FALSE;
    return TRUE;
}

int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }

boolean mulSum(int n){
    int i,sum=0;
    for(i=1;i<n/2+1;i++){
        if(!(n%i)) sum+=i;
    }
    return ((sum==n)?TRUE:FALSE);
}

void dali(){
    int i,n,somme = 0;

    scanf("%d", &n);

    for(i=1 ; i<(n/2)+1 ; i++){

        if(n%i==0){
            somme += i;
        }
    }

    if(somme==n){
        printf("\n %d est parfait.", n);
    }else{
        printf("\n %d n est pas parfait.", n);
    }
}

ll sumGeo(int q,int n){
    return (1-(int)pow(q,n))/(1-q);
}

int* search(int T[], int n, int val){
    while(n--)
        if(*T==val) return T;
        else T++;
    return T;
}

int removeT(int T[],int n,int pos){
    if(pos<n && pos>=0){
        int i;
        for(i=pos+1;i<n;i++){
            T[i-1]=T[i];
        }
        return n-1;
    }
    return n;
}

int insertT(int T[],int n,int pos,int val){
    int i;
    for(i=n;i>pos;i--){
        T[i] = T[i-1];
    }
    T[pos] = val;
    return n+1;
}

void ex2(){
    ull n;
    printf("n: ");
    scanf("%lld",&n);
    printf("recursive factoriel: %lld\n",recFact(n));
    printf("iterative factoriel: %lld\n",itFact(n));
}

void ex3(){
    ull n=0,x=0;
    while(!x && !n){
        printf("x n: ");
        scanf("%lld%lld",&x,&n);
    }
    printf("%lld^%lld = %lld",x,n,pow(x,n));
}

void ex31(){
    float neg=0,pos=0,tmp;
    int i=20,n=0,p=0;
    while(i){
        printf("(%d): ",20-i--+1);
        scanf("%f",&tmp);
        if(tmp>0){ pos+=tmp,p++;}
        else{ neg+=tmp,n++;}
    }
    printf("moyenne (+): %.2f\nmoyenne (-): %.2f\n",pos/(!p?1:p),neg/(!n?1:n));
}

void ex4(){
    int n;
    printf("n: ");
    scanf("%d",&n);
    printDec(n);
}

void ex5(){
    char noms[35][255];
    float moyennes[35];
    float moyenne = 0;
    float n1,n2,n3;
    int i,j;
    for(i=0;i<35;i++){
        printf("saisir nom: ");
        scanf("%s",noms[i]);
        printf("saisir note prog: ");
        scanf("%f",&n1);
        printf("saisir note elect: ");
        scanf("%f",&n2);
        printf("saisir note ang: ");
        scanf("%f",&n3);
        moyennes[i] = (n1+n2+n3)/3.0;
        moyenne += moyennes[i];
    }
    moyenne/=35.0;

    printf("les moyennes:\n");
    for(i=0;i<35;i++){
        printf("%s: %.2f\n",noms[i],moyennes[i]);
    }
    printf("moyenne de la classe: %.2f\n",moyenne);
}

void ex6(){
    int n;
    printf("n: ");
    scanf("%d",&n);
    printf("%d est divisible %d fois par 2\n",n,recurDiv2(n));
}

void ex7(){
    int n,m;
    printf("n m: ");
    scanf("%d%d",&n,&m);
    printf("%d*%d = %d\n",n,m,recurMul(n,m));
}

void ex8(){
    int n;
    printf("n: ");
    scanf("%d",&n);
    printf("%d is %sprime\n",n,(isPrime(n)?"":"not "));
}

void ex9(){
    int n,m;
    printf("n m: ");
    scanf("%d%d",&n,&m);
    printf("pgcd(%d,%d) = %d",n,m,gcd(n,m));
}

void ex10(){
    int n;
    scanf("%d",&n);
    printf("%d is%s perfect",n,((mulSum(n))?"":"nt"));
}

void ex11(){
    int x,n;
    printf("x n: ");
    scanf("%d%d",&x,&n);
    printf("sum: %lld",sumGeo(x,n));
}

void exSearch(){
    int T[8]={5,10,31,21,-5,32,42,56},
        n=8,val,pos;
    printf("val: ");
    scanf("%d",&val);
    pos = search(T,n,val)-T;
    printf("position of %d: %d\n",val,(pos==n)?-1:pos);
}

void exRemove(){
    int T[8]={5,10,31,21,-5,32,42,56},
        n=8,pos,i;
    printf("pos: ");
    scanf("%d",&pos);
    n=removeT(T,n,pos);
    printf("size: %d\n|",n);

    for(i=0;i<n;i++){
        printf("%d|",T[i]);
    }
}

void exInsert(){
    int T[9]={5,10,31,21,-5,32,42,56},
        n=8,pos,i,val;
    printf("|");
    for(i=0;i<n;i++){
        printf("%d|",T[i]);
    }
    printf("\npos val: ");
    scanf("%d%d",&pos,&val);
    n=insertT(T,n,pos,val);
    printf("size: %d\n|",n);

    for(i=0;i<n;i++){
        printf("%d|",T[i]);
    }
}

void ex12(){

}
