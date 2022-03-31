#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream assemblyCode;
    assemblyCode.open("teste-arq.txt");

    int lineCounter = 0;                                    // Para identificar a linha de erro

    if(assemblyCode.is_open()) {
        string codeLine;

        while(getline(assemblyCode, codeLine)) {            // Laço para ir 'pegando' as linhas do arquivo
            string instrucao;
            string operando = "\0";
            bool ehinstrucao = true;                        // Ajuda a identificar quando deve concatenar os caracteres do arquivo a 'instrucao' ou a 'operando'
            bool temOperando;                               // Para gerar erro sobre comandos que deveriam ou não possuir operando

            lineCounter++;
            
            if(codeLine[0] == ';') {                        // Se a linha já começar com comentário já será ignorada
                continue;
            }

            for(int i = 0; i < codeLine.size(); i++) {      // Percorre cada um dos caracteres da linha atual
                if(codeLine[i] == ';') {                    // Se/Quando encontrar comentário já pula para a próxima
                    break;
                }
                
                if(codeLine[i] == ' ') {                    // Quando encontrar espaço passa a concatenar os caracteres a 'operando'
                    ehinstrucao = false;
                }else {
                    if(ehinstrucao) {
                        instrucao += codeLine[i];
                    }else {
                        operando += codeLine[i];
                    }
                }

            }
        
            if(operando == "\0\r") {                        // Atualiza a flag de operando considerando se é apenas a quebra de linha ou não
                temOperando = false;
            }else {
                temOperando = true;
            }

            cout << "\n####";
            cout << "\ninstrucao =" << instrucao;
            cout << "\noperando =" << operando;
            cout << "\ntem operando = " << temOperando;

            if(instrucao == "PUSH" && !temOperando) {
                cout << "\n\nERRO: INSTRUCAO PUSH SEM OPERANDO [linha " << lineCounter << "]";
            }
        }
    }

    return 0;
}