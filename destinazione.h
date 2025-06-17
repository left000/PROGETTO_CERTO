#ifndef DESTINAZIONE_H
#define DESTINAZIONE_H

typedef struct
{
  int id;
  char paese[50];
  char porto_arrivo[50];
  char mezzo_trasporto[30];
} Destinazione;

void creaDestinazione();
void stampaDestinazioni();
int getNumeroDestinazioni();
Destinazione *getDestinazioni();

#endif
