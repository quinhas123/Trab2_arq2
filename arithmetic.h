#include <vector>

using namespace std;

int16_t add(vector<int16_t>& pilha){
    return pilha[pilha.size() - 1] + pilha[pilha.size() - 2];
}

void inc(vector<int16_t>& pilha){
    pilha[pilha.size() - 1] += 1;
}

int16_t sub(vector<int16_t>& pilha){
    return pilha[pilha.size() - 1] - pilha[pilha.size() - 2];
}

int16_t mul(vector<int16_t>& pilha){
    return pilha[pilha.size() - 1] * pilha[pilha.size() - 2];
}

int16_t divis(vector<int16_t>& pilha){
    return pilha[pilha.size() - 1] / pilha[pilha.size() - 2];
}

int16_t mod(vector<int16_t>& pilha){
    return pilha[pilha.size() - 1] % pilha[pilha.size() - 2];
}

int16_t sub2(vector<int16_t>& pilha){
    return pilha[pilha.size() - 2] - pilha[pilha.size() - 3];
}