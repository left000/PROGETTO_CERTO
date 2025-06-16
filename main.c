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
    printf("2 - Visualizza Aziende\n");
    printf("3 - Crea Prodotto\n");
    printf("4 - Visualizza Prodotto\n");
    printf("5 - Crea Destinazione\n");
    printf("6 - Visualizza Destinazione\n");
    printf("7 - Creare un Certificato\n");
    printf("8 - Crea Certificato di Origine\n");
    printf("9 - Stampa Certificati\n");
    printf("0 - Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta)
    {
    case 1:
      creaAzienda();
      break;
    case 2:
      stampaAziende();
      break;
    case 3:
      creaProdotto();
      break;
    case 4:
      stampaProdotto();
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
