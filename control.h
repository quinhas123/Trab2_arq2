#include <vector>

using namespace std;

void push(vector<int>& pilha, int elemento) {
    pilha.push_back(elemento);
}

int pushr(vector<int>& pilha) {
    return pilha[pilha.size() - 1];
}

void pop(vector<int>& pilha) {
    pilha.pop_back();
}