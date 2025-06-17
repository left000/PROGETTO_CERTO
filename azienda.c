#include <stdio.h>
#include <string.h>
#include "azienda.h"

#define MAX_AZIENDE 100

static Azienda aziende[MAX_AZIENDE];
static int contaAziende = 0;

void creaAzienda()
{
  if (contaAziende >= MAX_AZIENDE)
  {
    printf("Limite massimo aziende raggiunto!\n");
    return;
  }

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

void stampaAziende()
{
  printf("\nElenco Aziende:\n");
  for (int i = 0; i < contaAziende; i++)
  {
    printf("ID: %d\n", aziende[i].id);
    printf("  Ragione sociale: %s\n", aziende[i].ragione_sociale);
    printf("  Partita IVA: %s\n", aziende[i].partita_iva);
    printf("  Indirizzo: %s\n", aziende[i].indirizzo);
    printf("  Nazione: %s\n\n", aziende[i].nazione);
  }
  if (contaAziende == 0)
  {
    printf("Nessuna azienda presente.\n");
  }
}

Azienda *getAziende()
{
  return aziende;
}

int getNumeroAziende()
{
  return contaAziende;
}
