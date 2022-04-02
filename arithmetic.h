#include <vector>

using namespace std;

int add(vector<int>& pilha, int ultimonum){
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