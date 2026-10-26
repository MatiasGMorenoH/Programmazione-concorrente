#!/usr/bin/env python3
// Matias Moreno 4CINF - 26/10/2026

"""Hello World: dal programma Python al processo in esecuzione."""
import os

nome = 'Matias'
messaggio = "Hello World sotto controllo versione con Git."

print('Hello, World!')
print(f'Studente: {nome}')
print(messaggio)
# Il sistema operativo assegna un PID al processo che esegue il programma.
print(f'PID del processo: {os.getpid()}')
