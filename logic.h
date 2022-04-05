#include <vector>

using namespace std;

void notLogic(vector<int>& pilha){
    pilha[pilha.size() - 1] = ~pilha[pilha.size() - 1];
}