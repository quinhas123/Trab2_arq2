#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int pilha[128];
    int registrador;

    pilha[0] = 5;
    pilha[1] = 7;

    registrador = out(pilha, 1);
}

int add(int *pilha, int ultimonum){
    return pilha[ultimonum] + pilha[ultimonum-1];
}

int sub(int *pilha, int ultimonum){
    return pilha[ultimonum] - pilha[ultimonum-1];
}

int mul(int *pilha, int ultimonum){
    return pilha[ultimonum] * pilha[ultimonum-1];
}

int divis(int *pilha, int ultimonum){
    return pilha[ultimonum] / pilha[ultimonum-1];
}

int mod(int *pilha, int ultimonum){
    return pilha[ultimonum] % pilha[ultimonum-1];
}

void not(int *pilha, int ultimonum){
    pilha[ultimonum] = ~pilha[ultimonum];
}

void out(int *pilha, int ultimonum){
    printf("Topo da pilha = %d", pilha[ultimonum]);
}
