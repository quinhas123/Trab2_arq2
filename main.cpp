#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream assemblyCode;
    assemblyCode.open("teste-arq.txt");

    int lineCounter = 0;                                    // Para identificar a linha de erro

    if(assemblyCode.is_open()) {
        string linha;

        while(getline(assemblyCode, linha)) {               // Laço para ir 'pegando' as linhas do arquivo
            string instrucao;
            string operando = "\0";
            bool ehinstrucao = true;                        // Ajuda a identificar quando deve concatenar os caracteres do arquivo a 'instrucao' ou a 'operando'
            bool temOperando;                               // Para gerar erro sobre comandos que deveriam ou não possuir operando

            lineCounter++;
            
            if(linha[0] == ';') {                           // Se a linha já começar com comentário já será ignorada
                continue;
            }

            for(int i = 0; i < linha.size(); i++) {         // Percorre cada um dos caracteres da linha atual
                if(linha[i] == ';') {                       // Se/Quando encontrar comentário já pula para a próxima
                    break;
                }
                
                if(linha[i] == ' ') {                       // Quando encontrar espaço passa a concatenar os caracteres a 'operando'
                    ehinstrucao = false;
                }else {
                    if(ehinstrucao) {
                        instrucao += linha[i];
                    }else {
                        operando += linha[i];
                    }
                }
            }
        
            if(operando == "\0\r") {                        // Atualiza a flag de operando considerando se é apenas a quebra de linha ou não
                temOperando = false;
            }else {
                temOperando = true;
            }

            // cout << "\n####";
            // cout << "\ninstrucao =" << instrucao;
            // cout << "\noperando =" << operando;
            // cout << "\ntem operando = " << temOperando;

            if(instrucao == "PUSH" && !temOperando) {
                cout << "[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;
            }else if(instrucao == "POP" && temOperando) {
                cout << "[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;         
            }else if((instrucao == "CLEAR" || instrucao == "ADD" || instrucao == "SUB" || instrucao == "MUL" || instrucao == "DIV" || instrucao == "MOD") && temOperando) {
                cout << "[002] - Argumento inválido -> [Linha " << lineCounter << "]";
                break;
            }

            if(instrucao == "CLEAR") {

            }else if(instrucao == "ADD") {

            }else if(instrucao == "SUB") {

            }else if(instrucao == "MUL") {

            }else if(instrucao == "DIV") {

            }else if(instrucao == "MOD") {

            }else if(instrucao == "NOT") {

            }else if(instrucao == "OR") {
                
            }else if(instrucao == "AND") {

            }else if(instrucao == "MIR") {

            }else if(instrucao == "PUSH") {

                // se stack estiver cheia, retornar erro:
                // cout << "[004] - PUSH em stack vazia -> [Linha " << lineCounter << "]";
                // break; 
            }else if(instrucao == "POP") {

                // se stack estiver vazia, retornar erro:
                // cout << "[003] - POP em stack vazia -> [Linha " << lineCounter << "]";
                // break; 
            }else if(instrucao == "OUT") {

            }else {
                cout << "[001] - Instrucao invalida. Ex. POOP em vez de POP. -> [Linha " << lineCounter << "]";
                break; 
            }
        }
    }

    return 0;
}