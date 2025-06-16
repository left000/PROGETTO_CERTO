#include <stdio.h>
#include "certificato.h"

int main()
{
  ListaCertificati lista;
  inizializzaLista(&lista);

  int scelta;
  do
  {
    printf("\nMENU PRINCIPALE:\n");
    printf("1 - Crea Azienda\n");
    printf("2 - Crea Prodotto\n");
    printf("3 - Crea Destinazione\n");
    printf("4 - Crea Certificato di Origine\n");
    printf("5 - Stampa Certificati\n");
    printf("0 - Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta)
    {
    case 1:
      creaAzienda();
      break;
    case 2:
      creaProdotto();
      break;
    case 3:
      // creaDestinazione();
      printf("Crea Destinazione!");
      break;
    case 4:
      inserisciCertificatoDaTastiera(&lista);
      break;
    case 5:
      stampaListaCertificati(lista);
      break;
    case 0:
      printf("Uscita\n");
      break;
    default:
      printf("Scelta non valida.\n");
    }
  } while (scelta != 0);

  return 0;
}
