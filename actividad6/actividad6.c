#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error al hacer fork
        perror("Error al crear proceso hijo");
        return 1;
    }

    if (pid == 0) {
        // Este es el proceso hijo
        printf("Soy el proceso hijo con PID: %d\n", getpid());
        exit(0);  // El proceso hijo termina inmediatamente
    } else {
        // Este es el proceso padre
        printf("Soy el proceso padre con PID: %d\n", getpid());
        printf("El proceso hijo con PID %d se convertirá en un zombie por 60 segundos...\n", pid);

        // Espera 60 segundos antes de recolectar al proceso hijo
        sleep(60);

        // Recolecta al proceso hijo, eliminando el estado zombie
        wait(NULL);

        printf("Proceso zombie recolectado\n");
    }

    return 0;
}
