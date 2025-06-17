#include <stdio.h>
#include <string.h>
#include "prodotto.h"

#define MAX_PRODOTTI 100
Prodotto prodotti[MAX_PRODOTTI];
int contaProdotti = 0;

void creaProdotto()
{
  if (contaProdotti >= MAX_PRODOTTI)
  {
    printf("Numero massimo di prodotti raggiunto.\n");
    return;
  }

  Prodotto pr;
  pr.id = contaProdotti + 1;

  printf("Descrizione prodotto: ");
  getchar();
  fgets(pr.descrizione, sizeof(pr.descrizione), stdin);
  pr.descrizione[strcspn(pr.descrizione, "\n")] = 0;

  printf("Peso (kg): ");
  scanf("%f", &pr.peso_kg);

  printf("Valore (euro): ");
  scanf("%f", &pr.valore_euro);

  printf("Codice TARIC: ");
  getchar();
  fgets(pr.codice_taric, sizeof(pr.codice_taric), stdin);
  pr.codice_taric[strcspn(pr.codice_taric, "\n")] = 0;

  prodotti[contaProdotti++] = pr;
  printf("Prodotto creato con ID %d\n", pr.id);
}

void stampaProdotto()
{
  if (contaProdotti == 0)
  {
    printf("Nessun prodotto disponibile.\n");
    return;
  }

  printf("\n--- Lista Prodotti ---\n");
  for (int i = 0; i < contaProdotti; i++)
  {
    printf("ID: %d\n", prodotti[i].id);
    printf("  Descrizione: %s\n", prodotti[i].descrizione);
    printf("  Peso: %.2f kg\n", prodotti[i].peso_kg);
    printf("  Valore: %.2f euro\n", prodotti[i].valore_euro);
    printf("  Codice TARIC: %s\n\n", prodotti[i].codice_taric);
  }
}

int getNumeroProdotti()
{
  return contaProdotti;
}

Prodotto *getProdotti()
{
  return prodotti;
}