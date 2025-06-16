#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "certificato.h"

#define MAX 100
#define MAX_AZIENDE 100
#define MAX_PRODOTTI 100
#define MAX_DESTINAZIONI 100

Azienda aziende[MAX_AZIENDE];
Prodotto prodotti[MAX_PRODOTTI];
Destinazione destinazioni[MAX_DESTINAZIONI];

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

void inizializzaLista(ListaCertificati *lista)
{
  *lista = NULL;
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

void inserisciCertificatoDaTastiera(ListaCertificati *lista)
{
  CertificatoOrigine c;

  static int idCertificatoProgressivo = 1;
  c.id_certificato = idCertificatoProgressivo++;

  if (contaAziende == 0)
  {
    printf("Nessuna azienda disponibile. Creane una prima.\n");
    return;
  }
  stampaAziende();
  printf("Inserisci ID dell'azienda: ");
  scanf("%d", &c.id_azienda);

  if (contaProdotti == 0)
  {
    printf("Nessun prodotto disponibile. Creane uno prima.\n");
    return;
  }
  stampaProdotto();
  printf("Inserisci ID del prodotto: ");
  scanf("%d", &c.id_prodotto);

  if (contaDestinazioni == 0)
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
}
