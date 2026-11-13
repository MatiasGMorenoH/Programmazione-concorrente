/* es03a_wait.c - Matias Moreno
* Test della system call wait con un processo figlio.
* Basato sull'esempio forkwait02.c delle slide.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Necessario per la wait()

int main() {
    pid_t pid;
    int status;

    printf("[INIZIO] - Prima della fork - pid processo=%d\n", getpid());

    pid = fork(); // Creazione del processo figlio

    if (pid == 0) {
        // Codice del processo figlio
        printf("[Figlio] - pid=%d, pid padre=%d\n", getpid(), getppid());
        // Il figlio termina volontariamente con stato 3
        exit(3);
    } else if (pid > 0) {
        // Codice del processo padre
        printf("[Padre] - pid=%d, pid padre=%d, pid figlio=%d\n", getpid(), getppid(), pid);

        // Il padre si sospende e aspetta la terminazione del figlio
        int ret_val = wait(&status);

        printf("[Padre] - wait_retvalue=%d, wait_status=%d\n", ret_val, status);
        printf("[FINE] - Termine del processo con pid=%d\n", getpid());
    } else {
        printf("Errore nella creazione della fork\n");
    }
    return 0;
}
