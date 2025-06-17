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

void inizializzaLista(ListaCertificati *lista);
void inserisciCertificatoDaTastiera(ListaCertificati *lista);
void stampaListaCertificati(ListaCertificati lista);
void saveCertificatiFile(ListaCertificati lista, const char *nomeFile);
void loadCertificatiFile(ListaCertificati *lista, const char *nomeFile);

#endif
