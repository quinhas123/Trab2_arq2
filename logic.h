#include <vector>

using namespace std;

void notLogic(vector<int>& pilha){
    pilha[pilha.size() - 1] = ~pilha[pilha.size() - 1];
}

void mir(vector<int>& pilha){
    int num = pilha[pilha.size() - 1];
    int pos = sizeof(num) - 1;
    int reverse = 0;

    while(pos >= 0 && num) {
        if(num & 1) {
            reverse = reverse | (1 << pos);
        }

        num >>= 1;
        pos--;
    }

    pilha[pilha.size() - 1] = reverse;
}