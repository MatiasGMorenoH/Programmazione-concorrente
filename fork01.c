// Esercizio con l'utilizzo del Fork per l'avvio del processo
// Autore: Matias Moreno

#include <stdio.h>   // printf
#include <unistd.h>  // getpid

int main() {

  printf("\nAvvio del processo con pid=%d\n", getpid());
}
