#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#define SIZE 5;

struct timp{ int ora,min;
};
struct activitate
{
struct timp inceput;
struct timp durata;
struct timp sfarsit;
int nr;
};
struct activitate ordin[100];

void citeste();
int conv_into_min(int *h, int *d);
void selection_sort();
void conv_ora();
void greedy_selector();
void generate_activities();
void scrie();

#endif // UTIL_H_INCLUDED
