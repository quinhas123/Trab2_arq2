#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "arithmetic.h"                                     // importações dos arquivos externos '.h' contendo as funções criadas
#include "control.h"

using namespace std;

int main() {
    cout << "########################################################";
    cout << "\n\t\tSIMULADOR MAQUINA DE PILHA";
    cout << "\n########################################################";
// ####################### Para fins de teste #######################
    vector<int> stack;
    int registrador;
// ##################################################################

    std::ifstream assemblyCode;
    assemblyCode.open("teste-arq.txt");                     // Mudar o nome para o arquivo desejado

    int lineCounter = 0;                                    // Para identificar a linha de erro

    if(assemblyCode.is_open()) {
        string codeLine;

        while(getline(assemblyCode, codeLine)) {            // Laço para ir 'pegando' as linhas do arquivo
            string instrucao;
            string operando = "\0";
            bool ehinstrucao = true;                        // Ajuda a identificar quando deve concatenar os caracteres do arquivo a 'instrucao' ou a 'operando'
            bool temOperando;                               // Para gerar erro sobre comandos que deveriam ou não possuir operando
            bool operandoEhRegistrador;                     // Flag para identificar se o operando passado foi um número ou o próprio registrador. Ex: PUSH 8 ou PUSH $R
            int numOperando;                                // Guarda o valor do operando após ele ser convertido de string para int
            int i = 0;

            lineCounter++;
            
            while(codeLine[i] == ' ' || codeLine[i] == '\t'){	// Ignora espaços no começo da linha
                i++;
            }

            if(codeLine[i] == ';') {                            // Se a linha já começar com comentário será ignorada
                continue;
            }

            while(i < codeLine.size() && codeLine[i] != ';'){   // Percorre cada um dos caracteres da linha atual
                if(codeLine[i] == ' '){                         // Quando encontrar espaço passa a concatenar os caracteres a 'operando'
                    ehinstrucao = false;
                }
                else if(ehinstrucao){
                    instrucao += codeLine[i];
                }
                else{
                    operando += codeLine[i];
                }

                i++;
            }
        
            if(operando == "\0\r") {                        // Atualiza a flag de operando considerando se é apenas a quebra de linha ou não
                temOperando = false;
            }else {
                temOperando = true;
            }

// ####################### Para fins de teste #######################
            // cout << "\n";
            // cout << "\ninstrucao = " << instrucao;
            // cout << "\noperando = " << operando;
            // cout << "\ntem operando = " << temOperando;
// ##################################################################

            if(temOperando) {
                if(operando == "$R") {                      // Atualiza a flag do tipo do operando
                    operandoEhRegistrador = true;
                }else {
                    operandoEhRegistrador = false;
                }

                if(operandoEhRegistrador) {
                    numOperando = registrador;              // Se operando == $R, então o valor de $R é passado para numOperando
                }else {
                    numOperando = stoi(operando);           // Se operando tiver sido algum número, converte de string para int (stoi)
                }
            }

            if(instrucao == "PUSH" && !temOperando) {       // Dispara erro caso PUSH tenha sido passada sem operando
                cout << "[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;
            }else if(instrucao == "POP" && temOperando) {   // Dispara erro caso POP tenha sido passada com algum operando
                cout << "[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;         
            }else if((instrucao == "CLEAR" || instrucao == "ADD" || instrucao == "SUB" || instrucao == "MUL" || instrucao == "DIV" || instrucao == "MOD") && temOperando) {
                // Dispara erro caso alguma das instruções aritméticas tenham sido passadas com operando
                cout << "[002] - Argumento inválido -> [Linha " << lineCounter << "]";
                break;
            }

            if(instrucao == "CLEAR") {

            }else if(instrucao == "ADD") {
                registrador = add(stack, stack.size() - 1);
            }else if(instrucao == "SUB") {

            }else if(instrucao == "MUL") {

            }else if(instrucao == "DIV") {

            }else if(instrucao == "MOD") {

            }else if(instrucao == "NOT") {

            }else if(instrucao == "OR") {
                
            }else if(instrucao == "AND") {

            }else if(instrucao == "MIR") {

            }else if(instrucao == "PUSH") {
                if(stack.size() == 128) {
                    cout << "[004] - PUSH em stack cheia -> [Linha " << lineCounter << "]";
                    break; 
                }else {
                    push(stack, numOperando);
                }
            }else if(instrucao == "POP") {
                if(stack.size() == 0) {
                    cout << "[003] - POP em stack vazia -> [Linha " << lineCounter << "]";
                    break; 
                }else {
                    pop(stack);
                }
            }else if(instrucao == "OUT") {
                cout << "\n\nTopo da pilha: " << stack[stack.size() - 1];
                cout << "\n\nFim do programa.";
            }else {
                cout << "[001] - Instrucao invalida. Ex. POOP em vez de POP. -> [Linha " << lineCounter << "]";
                break; 
            }
        }
    }

    return 0;
}