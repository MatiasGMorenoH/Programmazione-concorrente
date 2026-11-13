/* es03b.c - Matias Moreno
* Programma che utilizza fork, exit e wait per far calcolare
* una somma o una moltiplicazione al processo figlio.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Inizializzazione delle variabili
    int num1 = 10;
    int num2 = 5;
    int ris = 0;
    int operazione = 1; // 1 = somma, 2 = moltiplicazione
    int status;
    pid_t pid;

    printf("[Padre] - Variabili inizializzate: num1=%d, num2=%d, operazione=%d\n", num1, num2, operazione);

    pid = fork(); // Creazione del processo figlio

    if (pid == 0) {
        // Siamo nel processo figlio
        if (operazione == 1) {
            ris = num1 + num2;
        } else if (operazione == 2) {
            ris = num1 * num2;
        } else {
            ris = 0; // Caso di errore
        }

        printf("[Figlio] - Calcolo eseguito. Esco con status: %d\n", ris);
        // Il figlio termina e restituisce il risultato come exit status
        exit(ris);

    } else if (pid > 0) {
        // Siamo nel processo padre
        printf("[Padre] - Attendo la terminazione del figlio...\n");

        // Il padre si sospende in attesa del figlio
        wait(&status);

        // Estrazione dell'exit status dal valore di status
        int exit_status = WEXITSTATUS(status);

        printf("[Padre] - Il figlio è terminato.\n");
        printf("[Padre] - L'exit status restituito dal figlio è: %d\n", exit_status);

        if (operazione == 1) {
            printf("[Padre] - Il risultato della SOMMA è: %d\n", exit_status);
        } else if (operazione == 2) {
            printf("[Padre] - Il risultato della MOLTIPLICAZIONE è: %d\n", exit_status);
        }
    } else {
        printf("Errore nella creazione del processo figlio.\n");
        return 1;
    }

    return 0;
}
