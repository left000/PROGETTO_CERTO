#include <stdio.h>
#include <string.h>
#include "destinazione.h"

#define MAX_DESTINAZIONI 100

Destinazione destinazioni[MAX_DESTINAZIONI];
int contaDestinazioni = 0;

void creaDestinazione()
{
  if (contaDestinazioni >= MAX_DESTINAZIONI)
  {
    printf("⚠ Numero massimo di destinazioni raggiunto.\n");
    return;
  }

  Destinazione d;
  d.id = contaDestinazioni + 1;

  getchar();
  printf("Paese: ");
  fgets(d.paese, sizeof(d.paese), stdin);
  d.paese[strcspn(d.paese, "\n")] = 0;

  printf("Porto di arrivo: ");
  fgets(d.porto_arrivo, sizeof(d.porto_arrivo), stdin);
  d.porto_arrivo[strcspn(d.porto_arrivo, "\n")] = 0;

  printf("Mezzo di trasporto: ");
  fgets(d.mezzo_trasporto, sizeof(d.mezzo_trasporto), stdin);
  d.mezzo_trasporto[strcspn(d.mezzo_trasporto, "\n")] = 0;

  destinazioni[contaDestinazioni++] = d;

  printf("Destinazione creata con ID %d\n", d.id);
}

void stampaDestinazioni()
{
  if (contaDestinazioni == 0)
  {
    printf("⚠ Nessuna destinazione disponibile.\n");
    return;
  }

  printf("\n Elenco Destinazioni:\n");
  for (int i = 0; i < contaDestinazioni; i++)
  {
    printf("ID: %d | Paese: %s | Porto: %s | Trasporto: %s\n",
           destinazioni[i].id,
           destinazioni[i].paese,
           destinazioni[i].porto_arrivo,
           destinazioni[i].mezzo_trasporto);
  }
}
int getNumeroDestinazioni()
{
  return contaDestinazioni;
}
Destinazione *getDestinazioni()
{
  return destinazioni;
}