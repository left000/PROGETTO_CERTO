#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "certificato.h"
#include "azienda.h"
#include "prodotto.h"
#include "destinazione.h"

#define MAX 100

void inizializzaLista(ListaCertificati *lista)
{
  *lista = NULL;
}

void inserisciCertificatoDaTastiera(ListaCertificati *lista)
{
  CertificatoOrigine c;

  static int idCertificatoProgressivo = 1;
  c.id_certificato = idCertificatoProgressivo++;

  if (getNumeroAziende() == 0)
  {
    printf("Nessuna azienda disponibile. Creane una prima.\n");
    return;
  }
  stampaAziende();
  printf("Inserisci ID dell'azienda: ");
  scanf("%d", &c.id_azienda);

  if (getNumeroProdotti() == 0)
  {
    printf("Nessun prodotto disponibile. Creane uno prima.\n");
    return;
  }
  stampaProdotto();
  printf("Inserisci ID del prodotto: ");
  scanf("%d", &c.id_prodotto);

  if (getNumeroDestinazioni() == 0)
  {
    printf("Nessuna destinazione disponibile. Creane una prima.\n");
    return;
  }
  stampaDestinazioni();

  printf("Inserisci ID della destinazione: ");
  scanf("%d", &c.id_destinazione);

  printf("Inserisci data emissione (gg mm aaaa): ");
  scanf("%d %d %d", &c.data_emissione.giorno, &c.data_emissione.mese, &c.data_emissione.anno);

  getchar();
  printf("Numero seriale: ");
  fgets(c.numero_seriale, sizeof(c.numero_seriale), stdin);
  c.numero_seriale[strcspn(c.numero_seriale, "\n")] = 0;

  printf("Stato: ");
  fgets(c.stato, sizeof(c.stato), stdin);
  c.stato[strcspn(c.stato, "\n")] = 0;

  printf("Camera di Commercio: ");
  fgets(c.camera_commercio, sizeof(c.camera_commercio), stdin);
  c.camera_commercio[strcspn(c.camera_commercio, "\n")] = 0;

  NodoCertificato *nuovoNodo = malloc(sizeof(NodoCertificato));
  if (nuovoNodo == NULL)
  {
    printf("Errore allocazione memoria.\n");
    return;
  }

  nuovoNodo->dato = c;
  nuovoNodo->next = *lista;
  *lista = nuovoNodo;

  printf("Certificato inserito con ID %d\n", c.id_certificato);
}

void stampaListaCertificati(ListaCertificati lista)
{
  if (lista == NULL)
  {
    printf("Nessun certificato presente.\n");
    return;
  }

  NodoCertificato *corrente = lista;

  while (corrente != NULL)
  {
    CertificatoOrigine c = corrente->dato;

    Azienda *az = NULL;
    Azienda *aziende = getAziende();
    int nAz = getNumeroAziende();
    for (int i = 0; i < nAz; i++)
    {
      if (aziende[i].id == c.id_azienda)
      {
        az = &aziende[i];
        break;
      }
    }

    Prodotto *pr = NULL;
    Prodotto *prodotti = getProdotti();
    int nPr = getNumeroProdotti();
    for (int i = 0; i < nPr; i++)
    {
      if (prodotti[i].id == c.id_prodotto)
      {
        pr = &prodotti[i];
        break;
      }
    }

    Destinazione *dest = NULL;
    Destinazione *destinazioni = getDestinazioni();
    int nDest = getNumeroDestinazioni();
    for (int i = 0; i < nDest; i++)
    {
      if (destinazioni[i].id == c.id_destinazione)
      {
        dest = &destinazioni[i];
        break;
      }
    }

    printf("\n📄 Certificato ID: %d\n", c.id_certificato);
    printf("Numero seriale: %s\n", c.numero_seriale);
    printf("Data emissione: %02d/%02d/%04d\n",
           c.data_emissione.giorno, c.data_emissione.mese, c.data_emissione.anno);
    printf("Stato: %s\n", c.stato);
    printf("Camera commercio: %s\n", c.camera_commercio);

    // Stampa azienda
    if (az != NULL)
    {
      printf("🏢 Azienda: %s (P.IVA: %s) | %s, %s\n",
             az->ragione_sociale, az->partita_iva, az->indirizzo, az->nazione);
    }
    else
    {
      printf("🏢 Azienda: NON TROVATA\n");
    }

    // Stampa prodotto
    if (pr != NULL)
    {
      printf("📦 Prodotto: %s | Peso: %.2f kg | Valore: %.2f € | Codice TARIC: %s\n",
             pr->descrizione, pr->peso_kg, pr->valore_euro, pr->codice_taric);
    }
    else
    {
      printf("📦 Prodotto: NON TROVATO\n");
    }

    // Stampa destinazione
    if (dest != NULL)
    {
      printf("🌍 Destinazione: %s | Porto: %s | Mezzo: %s\n",
             dest->paese, dest->porto_arrivo, dest->mezzo_trasporto);
    }
    else
    {
      printf("🌍 Destinazione: NON TROVATA\n");
    }

    printf("-------------------------------------------------\n");

    corrente = corrente->next;
  }
}
void saveCertificatiFile(ListaCertificati lista, const char *nomeFile)
{
  FILE *fp = fopen(nomeFile, "w");
  if (fp == NULL)
  {
    printf("Errore nell'apertura del file per la scrittura.\n");
    return;
  }

  NodoCertificato *corrente = lista;
  while (corrente != NULL)
  {
    CertificatoOrigine c = corrente->dato;
    fprintf(fp, "%d;%d;%d;%d;%02d/%02d/%04d;%s;%s;%s\n",
            c.id_certificato,
            c.id_azienda,
            c.id_prodotto,
            c.id_destinazione,
            c.data_emissione.giorno,
            c.data_emissione.mese,
            c.data_emissione.anno,
            c.numero_seriale,
            c.stato,
            c.camera_commercio);
    corrente = corrente->next;
  }

  fclose(fp);
  printf("📁 Certificati salvati correttamente su '%s'.\n", nomeFile);
}
void loadCertificatiFile(ListaCertificati *lista, const char *nomeFile)
{
  FILE *fp = fopen(nomeFile, "r");
  if (fp == NULL)
  {
    printf("⚠ File '%s' non trovato o impossibile da aprire.\n", nomeFile);
    return;
  }

  CertificatoOrigine c;
  while (fscanf(fp, "%d;%d;%d;%d;%d/%d/%d;%29[^;];%14[^;];%99[^\n]\n",
                &c.id_certificato,
                &c.id_azienda,
                &c.id_prodotto,
                &c.id_destinazione,
                &c.data_emissione.giorno,
                &c.data_emissione.mese,
                &c.data_emissione.anno,
                c.numero_seriale,
                c.stato,
                c.camera_commercio) == 10)
  {
    NodoCertificato *nuovo = malloc(sizeof(NodoCertificato));
    if (!nuovo)
    {
      printf("❌ Errore allocazione memoria.\n");
      fclose(fp);
      return;
    }

    nuovo->dato = c;
    nuovo->next = *lista;
    *lista = nuovo;
  }

  fclose(fp);
  printf("📂 Certificati caricati da '%s'.\n", nomeFile);
}