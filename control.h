#include <vector>

using namespace std;

void push(vector<int16_t>& pilha, int elemento) {
    pilha.push_back(elemento);
}

int16_t pushr(vector<int16_t>& pilha) {
    return pilha[pilha.size() - 1];
}

int16_t pushm1(vector<int16_t>& pilha) {
    return pilha[pilha.size() - 1];
}

int16_t pushm2(vector<int16_t>& pilha) {
    return pilha[pilha.size() - 1];
}

void pop(vector<int16_t>& pilha) {
    pilha.pop_back();
}