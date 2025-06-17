#include "menu.h"
#include "certificato.h"

int main()
{
  ListaCertificati lista;
  inizializzaLista(&lista);
  menuPrincipale(&lista);
  return 0;
}