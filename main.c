#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
int n;

int main()
{ generate_activities();
    scrie();
//citeste(); //daca citirea se vrea de la tastatura
for(int i=0;i<n;i++)
   {ordin[i].sfarsit.min=conv_into_min(&ordin[i].inceput.ora,&ordin[i].inceput.min)+conv_into_min(&ordin[i].durata.ora,&ordin[i].durata.min);


   }
selection_sort();
conv_ora();
printf("==Orele de sfarsit ale activitatilor, in ordine crescatoare==\n");
for(int i=0;i<n;i++)
    {printf("Ora de sfarsit a activitatii %d(h m): ",ordin[i].nr);
        printf("%d %d", ordin[i].sfarsit.ora, ordin[i].sfarsit.min);
    printf("\n");}
    greedy_selector();


    return 0;
}
