#include <vector>

using namespace std;

int add(vector<int>& pilha){
    return pilha[pilha.size() - 1] + pilha[pilha.size() - 2];
}

void inc(vector<int>& pilha){
    pilha[pilha.size() - 1] += 1;
}

int sub(vector<int>& pilha){
    return pilha[pilha.size() - 1] - pilha[pilha.size() - 2];
}

int mul(vector<int>& pilha){
    return pilha[pilha.size() - 1] * pilha[pilha.size() - 2];
}

int divis(vector<int>& pilha){
    return pilha[pilha.size() - 1] / pilha[pilha.size() - 2];
}

int mod(vector<int>& pilha){
    return pilha[pilha.size() - 1] % pilha[pilha.size() - 2];
}

int sub2(vector<int>& pilha){
    return pilha[pilha.size() - 2] - pilha[pilha.size() - 3];
}