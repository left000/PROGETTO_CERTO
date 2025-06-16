#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "certificato.h"

#define MAX 100

Azienda aziende[MAX];
Prodotto prodotti[MAX];
Destinazione destinazioni[MAX];

int contaAziende = 0;
int contaProdotti = 0;
int contaDestinazioni = 0;

void creaAzienda()
{
  Azienda az;
  az.id = contaAziende + 1;

  printf("Ragione sociale: ");
  getchar();
  fgets(az.ragione_sociale, sizeof(az.ragione_sociale), stdin);
  az.ragione_sociale[strcspn(az.ragione_sociale, "\n")] = 0;

  printf("Partita IVA: ");
  fgets(az.partita_iva, sizeof(az.partita_iva), stdin);
  az.partita_iva[strcspn(az.partita_iva, "\n")] = 0;

  printf("Indirizzo: ");
  fgets(az.indirizzo, sizeof(az.indirizzo), stdin);
  az.indirizzo[strcspn(az.indirizzo, "\n")] = 0;

  printf("Nazione: ");
  fgets(az.nazione, sizeof(az.nazione), stdin);
  az.nazione[strcspn(az.nazione, "\n")] = 0;

  aziende[contaAziende++] = az;
  printf("Azienda creata con ID %d\n", az.id);
}

void creaProdotto()
{
  Prodotto pr;
  pr.id = contaProdotti + 1;

  printf("Descrizione: ");
  getchar();
  fgets(pr.descrizione, sizeof(pr.descrizione), stdin);
  pr.descrizione[strcspn(pr.descrizione, "\n")] = 0;

  printf("Peso (kg): ");
  scanf("%f", &pr.peso_kg);

  printf("Valore (euro): ");
  scanf("%f", &pr.valore_euro);

  printf("Codice TARIC: ");
  scanf("%s", pr.codice_taric);

  prodotti[contaProdotti++] = pr;
  printf("Prodotto creato con ID %d\n", pr.id);
}

void inizializzaLista(ListaCertificati *lista)
{
}

void inserisciCertificatoDaTastiera(ListaCertificati *lista)
{
}

void stampaListaCertificati(ListaCertificati lista)
{
}
