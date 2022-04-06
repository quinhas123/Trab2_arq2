#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int pilha[128];
    int registrador, teste;

    pilha[0] = 5;
    pilha[1] = 8;
    teste = 4;

    registrador = or(pilha, 1, teste);
    printf("%d", registrador);
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

//Incrementa um ao topo da pilha
void inc(int *pilha, int ultimonum){
    pilha[ultimonum] = pilha[ultimonum]+1;
}

//Empurra topo da pilha para o registrador
int pushr(int *pilha, int ultimonum){
    return pilha[ultimonum];
}

int sub2(int *pilha, int ultimonum){
    return pilha[ultimonum-1]-pilha[ultimonum-2];
}

int and(int *pilha, int ultimonum, int  registrador){
    return pilha[ultimonum] & registrador;
}

int or(int *pilha, int ultimonum, int  registrador){
    return pilha[ultimonum] | registrador;
}
