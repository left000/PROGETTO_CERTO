#ifndef PRODOTTO_H
#define PRODOTTO_H

typedef struct
{
  int id;
  char descrizione[100];
  float peso_kg;
  float valore_euro;
  char codice_taric[15];
} Prodotto;

void creaProdotto();
void stampaProdotto();
int getNumeroProdotti();
Prodotto *getProdotti();
#endif
