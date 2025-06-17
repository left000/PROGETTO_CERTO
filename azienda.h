#ifndef AZIENDA_H
#define AZIENDA_H

typedef struct
{
  int id;
  char ragione_sociale[100];
  char partita_iva[20];
  char indirizzo[100];
  char nazione[50];
} Azienda;

void creaAzienda();
void stampaAziende();
Azienda *getAziende();
int getNumeroAziende();

#endif
