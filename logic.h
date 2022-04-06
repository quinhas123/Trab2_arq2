#include <vector>

using namespace std;

void notLogic(vector<int16_t>& pilha){
    pilha[pilha.size() - 1] = ~pilha[pilha.size() - 1];
}

int16_t andLogic(vector<int16_t>& pilha, int16_t registrador){
    return pilha[pilha.size() - 1] & registrador;
}

int16_t orLogic(vector<int16_t>& pilha, int16_t registrador){
    return pilha[pilha.size() - 1] | registrador;
}

void mir(vector<int16_t>& pilha){
    unsigned int num = pilha[pilha.size() - 1];
    unsigned int numRev = 0;

    while (num > 0)
    {
        numRev <<= 1;
         
        if (num & 1 == 1)
            numRev ^= 1;
         
        num >>= 1;
             
    }
     
    pilha[pilha.size() - 1] = numRev;
}