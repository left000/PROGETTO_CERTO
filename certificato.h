#ifndef CERTIFICATO_H
#define CERTIFICATO_H

typedef struct
{
  int giorno;
  int mese;
  int anno;
} Data;

typedef struct
{
  int id;
  char ragione_sociale[100];
  char partita_iva[20];
  char indirizzo[100];
  char nazione[50];
} Azienda;

typedef struct
{
  int id;
  char descrizione[100];
  float peso_kg;
  float valore_euro;
  char codice_taric[15];
} Prodotto;

typedef struct
{
  int id;
  char paese[50];
  char porto_arrivo[50];
  char mezzo_trasporto[30];
} Destinazione;

typedef struct
{
  int id_certificato;
  int id_azienda;
  int id_prodotto;
  int id_destinazione;
  Data data_emissione;
  char numero_seriale[30];
  char stato[15];
  char camera_commercio[100];
} CertificatoOrigine;

typedef struct NodoCertificato
{
  CertificatoOrigine dato;
  struct NodoCertificato *next;
} NodoCertificato;

typedef NodoCertificato *ListaCertificati;

void creaAzienda();
void stampaAziende();
void creaProdotto();
void stampaProdotto();
void creaDestinazione();
void stampaDestinazioni();

void inizializzaLista(ListaCertificati *lista);
void inserisciCertificatoDaTastiera(ListaCertificati *lista);
void stampaListaCertificati(ListaCertificati lista);
void saveCertificatiFile(ListaCertificati lista, const char *nomeFile);
void loadCertificatiFile(ListaCertificati *lista, const char *nomeFile);

#endif
