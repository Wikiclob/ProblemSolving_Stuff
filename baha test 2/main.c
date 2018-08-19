#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define L 12
#define C 31
//                                                                 Un projet réalisé par :
//                                                                   Debbabi Mohamed
//                                                                                &
//                                                                Messaoudi Bahaeddine
//                                                                          (Ti105)


//prototype des foncions
int anneebi(int a);
int Mike_Keith(int j,int m,int a);
int jourmois();
int firstsem(int j,int m,int a,int j1,int m1,int a1);
int secondsem(int j2,int m2,int a2,int j3,int m3,int a3);
int etablissement(int a,int a3);
void SetColorAndBackground(int ForgC, int BackC);

//programme principale
int main(void)
{
    int i,k,m,a,a3,j,j1,j2,j3,m1,m2,m3,a2,a1,w;
    int f,s,e;
    int o;
    int t[L][C];
    int true;
    system ("mode con cols=200 lines=500");
    system("color F1");
    FILE *imprim;

    printf("\t\t\t****Institut Superieur des Etudes Technologiques de Charguia****");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t**2016/2017** \n\n");
    printf("\t\t\t\t**Messaoudi Bahaeddine & Debbabi Mohamed** \n\n");
//Menu
    do
    {
        printf("1-Parametrage du modele. \n");
        printf("2-Creation du calendrier. \n");
        printf("3-Affichage du calendrier. \n");
        printf("4-Impression du calendrier. \n");
        scanf("%d",&o);
        switch(o)
        {
        case 1:
            printf("Voulez-vous modifier les paramétres initiale ? \n");
            printf("Entrez les nouvelles dates \n");
            firstsem(j,m,a,j1,m1,a1);
            secondsem(j2,m2,a2,j3,m3,a3);
            printf("Voulez-vous retourner au menu principale ? \n");
            printf("1-Pour oui. \n");
            printf("0-Pour quitter. \n");
            scanf("%d",&true);
            break;
        case 2:
            firstsem(j,m,a,j1,m1,a1);
            secondsem(j2,m2,a2,j3,m3,a3);
            printf("Voulez-vous retourner au menu principale ? \n");
            printf("1-Pour oui. \n");
            printf("0-Pour quitter. \n");
            scanf("%d",&true);
            break;
        case 3:
            //Nous avons pas appris le passage par adresse , donc je ne peux pas faire appel a une seule variable d'une fonction qui fais le return de plusieurs variables.
            do
            {
                printf("Entrez la date du debut du 1er semestre sous la forme jj/mm/aaaa \n");
                scanf("%d/%d/%d",&j,&m,&a);

                printf("%d/%d/%d \n",j,m,a);
            }
            while(m<1 && m>12 && j>31 && a<2010 && a>2030 && Mike_Keith(j,m,a)!=1);
            do
            {
                printf("Entrez la date de fin du 1er semestre sous la forme jj/mm/aaaa \n");
                scanf("%d/%d/%d",&j1,&m1,&a1);

                printf("%d/%d/%d \n",j1,m1,a1);
                Mike_Keith(j,m,a);
            }
            while(m1<1 && m1>12 && j1>31 && a1<2010 && a1>2030 && Mike_Keith(j1,m1,a1)!=6 );
            do
            {
                printf("Entrez la date du debut du 2eme semestre sous la forme jj/mm/aaaa \n");
                scanf("%d/%d/%d",&j2,&m2,&a2);
            }
            while(m2<1 && m2>12 && j2>31 && a2<2010 && a2>2030 && Mike_Keith(j2,m2,a2)!=1);
            do
            {
                printf("%d/%d/%d \n",j2,m2,a2);
                printf("Entrez la date de fin du 2eme semestre sous la forme jj/mm/aaaa \n");
                scanf("%d/%d/%d",&j3,&m3,&a3);

                printf("%d/%d/%d \n",j3,m3,a3);

            }
            while(m3<1 && m3>12 && j3>31 && a3<2010 && a3>2030 && Mike_Keith(j3,m3,a3)!=1);
            etablissement(a,a3);
            k=0;

            //Ecrire Mois/jours
            jourmois(k);
            for(j=0; j<C; j++)
            {
                printf("|%d|",j+1);

            }
            //printf("\n%i ?= %i",m,m3);
            //printf("\n%i ?= %i",a,a3);
            if(a==a3){
                for(k=m; k<=m3; k++)
                {
                    jourmois(k);
                    for(j=0;j<31;j++)
                    {
                        if((j+1)%7==0){
                            SetColorAndBackground(1,2);
                            //_textbackground(2);
                            //_cprintf("D");
                            if(j<=9)
                                printf("|D|");
                            else
                                printf("|D |");
                            SetColorAndBackground(1,15);
                            //_textbackground(15);
                        }
                        else{
                            if(j<=9)
                                printf("| |");
                            else
                                printf("|  |");
                        }
                    }
                }
            }
            else{
                for(k=-m; k<=m3; k++)
                {
                    if(k<0)
                        jourmois(2*m+k);
                    else if(k!=0)
                        jourmois(k);
                    if(k!=0){
                        for(j=0;j<31;j++)
                        {
                            if((j+1)%7==0){
                                SetColorAndBackground(1,2);
                                //_textbackground(2);
                                //_cprintf("D");
                                if(j<9)
                                    printf("|D|");
                                else
                                    printf("|D |");
                                SetColorAndBackground(1,15);
                                //_textbackground(15);
                            }
                            else{
                                if(j<9)
                                    printf("| |");
                                else
                                    printf("|  |");
                            }
                        }
                    }
                }
            }
            if(Mike_Keith(j1,m1,a1)==1)
            {
                for(j=0; j<C; j+7)
                {
                    printf("%d",w);
                    w++;
                }
            }

            for(k=m2; k<=m3+1; k++)
            {
                jourmois(k);
                /*if(Mike_Keith(j2,m2,a2)==1)
                {
                   for(j=0;j<C;j+6)
                   {
                     printf("%d",w);
                     w++;
                   }
                }*/
                if(Mike_Keith(j3,m3,a3)==1)
                {
                    for(j=0; j<C; j+7)
                    {
                        printf("%d",w);
                        w++;
                    }
                }
            }
            printf("\n\n\nCouleur verte : Dimanche \n");
            printf("Couleur grise : Periode qui separe les deux semestres \n");
            printf("Dates importantes : \n");
            printf("Arret de cours le 3 decembre \n");
            printf("Periode d'examen : Du 12 au 17 decembre \n");
            printf("Periode de stage :Du 2 janvier jusqu'au 28 \n ");
            printf("\nVoulez-vous retourner au menu principale ? \n");
            printf("1-Pour oui. \n");
            printf("0-Pour quitter. \n");
            scanf("%d",&true);
            break;
        case 4:
            printf("Voulez-vous imprimer le calendrier ? \n");
            printf("Choisir le nombre de page : \n");

            imprim=fopen("Lastone","wt");
            fprintf(imprim,"Imprimer mon fichier C.\n");
            fclose(imprim);
            printf("Voulez-vous retourner au menu principale ? \n");
            printf("1-Pour oui. \n");
            printf("0-Pour quitter. \n");
            scanf("%d",&true);
            break;
        }
    }
    while(true==1);
    return true;
}

//fonction bissextile
int anneebi(int a)
{
    if ( a%400 == 0 || a%4 == 0)
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

//fonction mike keith
int Mike_Keith(int jour,int mois,int annee)
{
    int j,m,a,c;
    c=(14-mois)/12;
    a=annee-c;
    m=mois+(12*c)-2;
    j=(jour+a+a/4-a/100+a/400+(31*m)/12)%7;
    return j;
}

//fonction affichage jours et mois
int jourmois (int k)
{
    switch(k)
    {
    case 0:
        printf("Mois/Jours \t");
        break;
    case 1:
        printf("\nJanvier\t\t");

        break;
    case 2:
        printf("\nFevrier\t\t");

        break;
    case 3:
        printf("\nMars\t\t");
        break;
    case 4:
        printf("\nAvril\t\t");
        break;
    case 5:
        printf("\nMai\t\t");
        break;
    case 6:
        printf("\nJuin\t\t");
        break;
    case 7:
        printf("\nJuillet\t\t");
        break;
    case 8:
        printf("\nAout\t\t");
        break;
    case 9:
        printf("\nSeptembre\t");
        break;
    case 10:
        printf("\nOctobre\t\t");
        break;
    case 11:
        printf("\nNovembre\t");
        break;
    case 12:
        printf("\nDecembre\t");
        break;
    default:
        return 0;
    }
}

//premier semestre
int firstsem(int j,int m,int a,int j1,int m1,int a1)
{
    do
    {
        printf("Entrez la date du debut du 1er semestre sous la forme jj/mm/aaaa \n");
        scanf("%d/%d/%d",&j,&m,&a);

        printf("%d/%d/%d \n",j,m,a);
    }
    while(m<1 && m>12 && j>31 && a<2010 && a>2030 && Mike_Keith(j,m,a)!=1);
    do
    {
        printf("Entrez la date de fin du 1er semestre sous la forme jj/mm/aaaa \n");
        scanf("%d/%d/%d",&j1,&m1,&a1);

        printf("%d/%d/%d \n",j1,m1,a1);
        Mike_Keith(j,m,a);
    }
    while(m1<1 && m1>12 && j1>31 && a1<2010 && a1>2030 && m1<m && j<0 && Mike_Keith(j1,m1,a1)!=6 );
    return a,m,j,m1,a1,j1;
}

//deuxieme semestre
int secondsem(int j2,int m2,int a2,int j3,int m3,int a3)
{

    do
    {
        printf("Entrez la date du debut du 2eme semestre sous la forme jj/mm/aaa \n");
        scanf("%d/%d/%d",&j2,&m2,&a2);
    }
    while(m2<1 && m2>12 && j2>31 && a2<2010 && a2>2030 && Mike_Keith(j2,m2,a2)!=1);
    do
    {
        printf("%d/%d/%d \n",j2,m2,a2);
        printf("Entrez la date de fin du 2eme semestre sous la forme jj/mm/aaa \n");
        scanf("%d/%d/%d",&j3,&m3,&a3);

        printf("%d/%d/%d \n",j3,m3,a3);

    }
    while(m3<1 && m3>12 && j3>31 &&j3<0 && m3<m2 && a3<2010 && a3>2030 && Mike_Keith(j3,m3,a3)!=1);
    return a3,a2,m3,m2,j3,j2;

}

//etablissement
int etablissement(int a,int a3)
{
    char ch[30]= {0};
    printf("Entrez le nom de l'etablissement\n");
    scanf("%s",ch);
    printf("\t\t\t\t\tETAB:%s",ch);
    printf("\n\t\t\t\t\tCalendrier de l'annee universitaire %d / %d\n\n",a,a3);
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
