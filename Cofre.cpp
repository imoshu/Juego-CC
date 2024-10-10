#include "Cofre.h"
#include <cstdlib>  // uso de rand()

// inicializa el cofre en uns pos exacta
Cofre::Cofre(int fila, int columna) {
    posicion.x = columna;
    posicion.y = fila;
    establecerCofre();  // Establece el tipo y la recompensa del cofre
}

// Método que establece el tipo de cofre y la recompensa que deja
void Cofre::establecerCofre(int tipo) {
    if (tipo == 0) {
        // Si no se especifica un tipo, se genera un tipo aleatorio entre 4 y 7
        tipo = rand() % 4 + 4;
    } else {
        tipo = tipo;  // Se asigna el tipo especificado
    }

    // Se asigna una recompensa aleatoria entre 10 y 39
    recompensa = rand() % 30 + 10;
}

// Método que devuelve la recompensa del cofre
int Cofre::obtenerRecompensa() {
    return recompensa;
}

// Método para desactivar el cofre cambiando su tipo a -1
void Cofre::desactivar() {
    tipo = -1;
}
