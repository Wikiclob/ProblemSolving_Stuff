#define MAX 100
#define MAXSTR (MAX+1)
#define TRUE 1
#define FALSE 0
#define init(M,C) memset(M,C,sizeof M)
typedef int boolean;

void remplirMatrice(float M[][MAX],int L,int C){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%f",&M[i][j]);
        }
    }
}

void afficherMatrice(float M[][MAX],int L,int C){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf(" | %.2f",M[i][j]);
        }
        printf(" |\n");
    }
}

void afficherTableau(float T[],int L){
    int i;
    for(i=0;i<L;i++){
        printf(" | %.2f |\n",T[i]);
    }
}

float calculerMoyenne(float M[][MAX], float moyenne[], int L, int C){
    int i,j;
    float result = 0.0f;
    init(moyenne,0);
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            moyenne[i]+=M[i][j];
        }
        moyenne[i] /= C;
        result += moyenne[i];
    }
    result /= L;
    return result;
}

void ex1(){
    float M[MAX][MAX],moyenne[MAX],moyenneT;
    int C,L;
    printf("L C: ");
    scanf("%d%d",&L,&C);
    remplirMatrice(M,L,C);
    printf("notes:\n");
    afficherMatrice(M,L,C);
    moyenneT = calculerMoyenne(M,moyenne,L,C);
    printf("moyennes:\n");
    //afficherMatrice(moyenne,1,C);
    afficherTableau(moyenne,C);
    printf("moyenne Totale: %.2f",moyenneT);
}

int taille(char* s){
    int result = 0;
    while(result!=MAXSTR){
        if(s[result]=='\0')
            break;
        result++;
    }
    return (result==MAXSTR)?-1:result;
}

void ex12(){
    char s[MAXSTR];
    printf("saisir chaine: ");
    scanf("%[^\n]s",s);
    printf("chaine: %s\n",s);
    printf("taille: %d\n",taille(s));
    printf("taille strlen: %d\n",strlen(s));
}

void inverse(char* s){
    int i,len = strlen(s);
    for(i=0;i<len/2;i++){
        s[len-1-i] = s[len-1-i]+s[i];
        s[i] = s[len-1-i]-s[i];
        s[len-1-i] = s[len-1-i]-s[i];
    }
}

void ex13(){
    char s[MAXSTR];
    printf("saisir chaine: ");
    scanf("%[^\n]s",s);
    inverse(s);
    printf("chaine inversee: %s\n",s);
}
