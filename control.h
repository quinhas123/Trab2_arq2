#include <vector>

using namespace std;

void push(vector<int>& pilha, int elemento) {
    pilha.push_back(elemento);
}

void pop(vector<int> pilha) {
    pilha.pop_back();
}