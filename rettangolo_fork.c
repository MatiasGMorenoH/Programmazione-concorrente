/*
    Autore: Matias Moreno

    Esercizio B:
    Il processo padre calcola l'area del rettangolo.
    Il processo figlio calcola il perimetro del rettangolo.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    // Dichiarazione e inizializzazione delle variabili
    int base = 10;
    int altezza = 5;
    int risultato;

    // Creazione del processo figlio
    pid_t pid = fork();

    // Controllo di eventuali errori
    if (pid < 0) {

        printf("Errore nella creazione del processo figlio\n");
    }
    // Codice eseguito dal processo figlio
    else if (pid == 0) {

        // Calcolo del perimetro
        risultato = 2 * (base + altezza);

        printf("\n=== PROCESSO FIGLIO ===\n");
        printf("PID Figlio: %d\n", getpid());
        printf("PPID: %d\n", getppid());
        printf("Base = %d\n", base);
        printf("Altezza = %d\n", altezza);
        printf("Perimetro = %d\n", risultato);

    }
    // Codice eseguito dal processo padre
    else {

        // Calcolo dell'area
        risultato = base * altezza;

        printf("\n=== PROCESSO PADRE ===\n");
        printf("PID Padre: %d\n", getpid());
        printf("PID Figlio: %d\n", pid);
        printf("Base = %d\n", base);
        printf("Altezza = %d\n", altezza);
        printf("Area = %d\n", risultato);

    }

    return 0;
}
