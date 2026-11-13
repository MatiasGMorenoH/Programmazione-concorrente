/* es03a_exit.c - Matias Moreno
* Test della terminazione volontaria del processo.
*/
#include <stdlib.h> // exit

int main() {
    // Termina il processo restituendo lo stato 42 al padre (la shell)
    exit(42);
}
