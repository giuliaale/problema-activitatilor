#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "util.h"
int n=SIZE;


void generate_activities()
{

    srand(time(NULL));
    int i;
    for(i = 0; i < n; i++)
    {
        ordin[i].nr = i+1;
        ordin[i].inceput.ora = rand() % 24;// se genereaza random valori intre 0 si 24
        ordin[i].durata.ora= rand() % 12;
        ordin[i].inceput.min= rand() % 60;
        ordin[i].durata.min= rand() % 60;//se genereaza random valori intre 0 si 60
    }

}
void scrie()
{
    int i;
    printf("Numarul de activitati: %d \n",n);

    for(i = 0; i <n; i++)
    {
        printf("Ora de inceput (h m) a activitatii %d: %d %d \n", i + 1,ordin[i].inceput.ora,ordin[i].inceput.min);

        printf("Durata activitatii %d: %d %d\n ",i + 1,ordin[i].durata.ora,ordin[i].durata.min);

    }
}
void citeste()
{
    int i;
    printf("Numarul de activitati: ");
    scanf("%d",&n);
    for(i = 0; i <n; i++)
    {
        printf("Ora de inceput (h m) a activitatii %d: ",i+1);
               scanf("%d %d",&ordin[i].inceput.ora,&ordin[i].inceput.min);
        printf("Durata activitatii %d: ",i+1);
                       scanf("%d %d",&ordin[i].durata.ora,&ordin[i].durata.min);
        ordin[i].nr=i+1;
        //pentru fiecare spectacol transformam ora de sfarsit in minute

    }
}
int conv_into_min(int *h, int *m)
{
    int d=*h*60+*m;
    return d;
}
void selection_sort()
{
    struct activitate aux;
    int i,j;
    for(i=0; i<n-1; i++)
       {
        for(j=i+1; j<n; j++)
            if(ordin[i].sfarsit.min>ordin[j].sfarsit.min)///ora de sfarsit a fost convertatita in minute, ordonarea se face in functie de numarul de minute
               {aux=ordin[j];
                ordin[j]=ordin[i];
                ordin[i]=aux;

               }
            }


}

void conv_ora()
{
    int i;
    for(i=0; i<n; i++)
    {
        ordin[i].sfarsit.ora=ordin[i].sfarsit.min/60;
        if(ordin[i].sfarsit.ora>24)
            ordin[i].sfarsit.ora=ordin[i].sfarsit.ora-24;
        ordin[i].sfarsit.min=ordin[i].sfarsit.min%60;

    }
}
void greedy_selector()
{

    int i;
    int counter=1;//avem o activitate selectata, prima activitate
    int ora_sf=ordin[0].sfarsit.ora;
    int min_sf=ordin[0].sfarsit.min;
    printf("Activitatile compatibile si ordinea acestora: ");
    printf("%d ",ordin[0].nr);//afisam prima activitate
    for(i=1; i<n; i++)
        if((ora_sf<ordin[i].inceput.ora)  )
        {ora_sf=ordin[i].sfarsit.ora;
            min_sf=ordin[i].sfarsit.min;
            printf("%d ",ordin[i].nr);
            counter++;

        }
        else if((ora_sf<ordin[i].inceput.ora)&&(min_sf<=ordin[i].inceput.min))
        {ora_sf=ordin[i].sfarsit.ora;
            min_sf=ordin[i].sfarsit.min;
            printf("%d ",ordin[i].nr);
            counter++;
        }
    printf("\nNumarul maxim de activitati compatibile este: ");
    printf("%d ",counter);

}
