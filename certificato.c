#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "certificato.h"

#define MAX 100
#define MAX_AZIENDE 100

Azienda aziende[MAX_AZIENDE];
Azienda aziende[MAX];
Prodotto prodotti[MAX];
Destinazione destinazioni[MAX];

int contaAziende = 0;
int contaProdotti = 0;
int contaDestinazioni = 0;

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
  *lista = NULL;
}

void inserisciCertificatoDaTastiera(ListaCertificati *lista)
{
  CertificatoOrigine cert;
  static int nextCertificatoId = 1;

  cert.id_certificato = nextCertificatoId++;

  printf("\n--- Seleziona Azienda per il certificato ---\n");
  for (int i = 0; i < contaAziende; i++)
  {
    printf("ID: %d - %s\n", aziende[i].id, aziende[i].ragione_sociale);
  }
  int id_az;
  printf("Inserisci ID azienda: ");
  scanf("%d", &id_az);

  int aziendaTrovata = 0;
  for (int i = 0; i < contaAziende; i++)
  {
    if (aziende[i].id == id_az)
    {
      aziendaTrovata = 1;
      break;
    }
  }

  if (!aziendaTrovata)
  {
    printf("ID azienda non valido. Operazione annullata.\n");
    return;
  }

  cert.id_azienda = id_az;

  printf("Numero seriale: ");
  getchar();
  fgets(cert.numero_seriale, sizeof(cert.numero_seriale), stdin);
  cert.numero_seriale[strcspn(cert.numero_seriale, "\n")] = 0;

  printf("Stato certificato: ");
  fgets(cert.stato, sizeof(cert.stato), stdin);
  cert.stato[strcspn(cert.stato, "\n")] = 0;

  printf("Camera di commercio: ");
  fgets(cert.camera_commercio, sizeof(cert.camera_commercio), stdin);
  cert.camera_commercio[strcspn(cert.camera_commercio, "\n")] = 0;

  printf("Data emissione (gg mm aaaa): ");
  scanf("%d %d %d", &cert.data_emissione.giorno, &cert.data_emissione.mese, &cert.data_emissione.anno);

  cert.id_prodotto = 0;
  cert.id_destinazione = 0;

  NodoCertificato *nuovo = (NodoCertificato *)malloc(sizeof(NodoCertificato));
  nuovo->dato = cert;
  nuovo->next = *lista;
  *lista = nuovo;

  printf("\nCertificato creato con ID %d associato all'azienda ID %d\n", cert.id_certificato, cert.id_azienda);
}

void stampaListaCertificati(ListaCertificati lista)
{
}
