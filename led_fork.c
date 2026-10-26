/*
    Autore: Matias Moreno

    Esercizio C:
    Il padre riceve un comando da tastiera.
    In base al comando crea un processo figlio
    che gestisce il lampeggio del LED richiesto.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {

    char comando;
    int i;

    do {

        // Richiesta comando all'utente
        printf("\nComandi disponibili:\n");
        printf("v = LED verde\n");
        printf("r = LED rosso\n");
        printf("g = LED giallo\n");
        printf("q = Esci\n");

        printf("Inserisci comando: ");
        scanf(" %c", &comando);

        // Se viene digitato q il programma termina
        if (comando == 'q') {
            printf("Chiusura programma...\n");
            break;
        }

        // Creazione del processo figlio
        pid_t pid = fork();

        // Codice eseguito dal figlio
        if (pid == 0) {

            // Comando LED verde
            if (comando == 'v') {

                for(i = 0; i < 10; i++) {

                    printf("LED VERDE ACCESO\n");
                    usleep(300000);

                    printf("LED VERDE SPENTO\n");
                    usleep(300000);
                }
            }

            // Comando LED rosso
            else if (comando == 'r') {

                for(i = 0; i < 10; i++) {

                    printf("LED ROSSO ACCESO\n");
                    usleep(700000);

                    printf("LED ROSSO SPENTO\n");
                    usleep(700000);
                }
            }

            // Comando LED giallo
            else if (comando == 'g') {

                for(i = 0; i < 10; i++) {

                    printf("LED GIALLO ACCESO\n");
                    usleep(1200000);

                    printf("LED GIALLO SPENTO\n");
                    usleep(1200000);
                }
            }

            else {

                printf("Comando non valido\n");

            }

            // Termine del processo figlio
            exit(0);
        }

    } while(comando != 'q');

    return 0;
}
