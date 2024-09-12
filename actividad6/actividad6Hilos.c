#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

// Función simple para que el hilo imprima un mensaje
void* thread_function(void* arg) {
    printf("Hilo creado en el proceso con PID: %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;

    // Primer fork
    pid = fork();

    if (pid == 0) { // Proceso hijo
        // Segundo fork dentro del proceso hijo
        fork();

        // Crear un hilo en el proceso hijo
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, NULL);

        // Esperar que el hilo termine
        pthread_join(thread, NULL);
    }

    // Tercer fork que se ejecutará en ambos: proceso padre y procesos hijos
    fork();
    sleep(60);
    // Espera para que los procesos terminen adecuadamente
    wait(NULL);

    return 0;
}
