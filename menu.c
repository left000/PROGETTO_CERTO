#include <stdio.h>
#include "menu.h"
#include "certificato.h"
#include "azienda.h"
#include "prodotto.h"
#include "destinazione.h"

void menuPrincipale(ListaCertificati *lista)
{
  int scelta;
  do
  {
    printf("\nMENU PRINCIPALE:\n");
    printf("1 - Crea Azienda\n");
    printf("2 - Stampa Aziende\n");
    printf("3 - Crea Prodotto\n");
    printf("4 - Stampa Prodotti\n");
    printf("5 - Crea Destinatario\n");
    printf("6 - Stampa Destinatari\n");
    printf("7 - Crea Certificato\n");
    printf("8 - Stampa Certificati\n");
    printf("9 - Salva certificati su file\n");
    printf("10 - Carica certificati da file\n");
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
      creaDestinazione();
      break;
    case 6:
      stampaDestinazioni();
      break;
    case 7:
      inserisciCertificatoDaTastiera(lista);
      break;
    case 8:
      stampaListaCertificati(*lista);
      break;
    case 9:
      saveCertificatiFile(*lista, "certificati.txt");
      break;
    case 10:
      loadCertificatiFile(lista, "certificati.txt");
      break;
    case 0:
      printf("Uscita\n");
      break;
    default:
      printf("Scelta non valida.\n");
      break;
    }

  } while (scelta != 0);
}
