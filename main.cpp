#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // para uso do find, encontrar string específica no vector
#include "arithmetic.h"                                     // importações dos arquivos externos '.h' contendo as funções criadas
#include "control.h"
#include "logic.h"

using namespace std;

int main() {
    cout << "########################################################";
    cout << "\n\t\tSIMULADOR MAQUINA DE PILHA";
    cout << "\n########################################################";

// ####################### Para fins de teste #######################
    vector<int> pilha;
    int registrador;
    int m1;
    int m2;
// ##################################################################

    std::ifstream assemblyCode;
    assemblyCode.open("bhaskara.txt");                     // Mudar o nome para o arquivo desejado

    vector<string> labels;
    vector<int> labelsLinhas;

    if(assemblyCode.is_open()) {
        string codeLine;
        bool flagJump = false;                                  // flag para pular linhas quando procurando pela linha de um label específico
        int linhaLabel;                                         // indica a linha do label a ser procurado após um jump
        int lineCounter = 0;                                    // variável para apontar para a linha atual do arquivo

        // percorre todo o arquivo para salvar os labels e suas respectivas linhas
        while(getline(assemblyCode, codeLine)) {
            string instrucao;
            string operando = "\0";
            bool ehinstrucao = true;
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

            if(instrucao.back() == ':') {
                instrucao.pop_back();                       // remove os : do label
                labels.push_back(instrucao);                // adiciona o label ao vetor de labels
                labelsLinhas.push_back(lineCounter + 1);     // adiciona a linha + 1 do label ao vetor de linhas de labels. + 1 para pular para a região logo após label
            }
        }

        lineCounter = 0;
        // limpa as flags do arquivo para percorre-lo novamente e agora compilar o código
        assemblyCode.clear();
        assemblyCode.seekg(0);
        
        while(getline(assemblyCode, codeLine)) {            // Laço para ir 'pegando' as linhas do arquivo
            string instrucao;
            string operando = "\0";
            bool ehinstrucao = true;                        // Ajuda a identificar quando deve concatenar os caracteres do arquivo a 'instrucao' ou a 'operando'
            bool temOperando;                               // Para gerar erro sobre comandos que deveriam ou não possuir operando
            bool operandoEhRegistrador;                     // Flag para identificar se o operando passado foi um número ou o próprio registrador. Ex: PUSH 8 ou PUSH $R
            bool operandoEhM1;
            bool operandoEhM2;
            bool operandoEhLabel = false;
            int numOperando;                                // Guarda o valor do operando após ele ser convertido de string para int
            int i = 0;

            lineCounter++;

            if(flagJump) {
                if(lineCounter != linhaLabel) {             // se a flag de jump estiver ligada, percorre todas as linhas até chegar na desejada
                    continue;
                }
            }
            
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
                // else if(codeLine[i] == '\t') {
                //     continue;
                // }
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
                }
                else if(operando == "M1") {
                    // cout << operando;
                    operandoEhM1 = true;
                }
                else if(operando == "M2") {
                    // cout << operando;
                    operandoEhM2 = true;
                }
                else if(find(labels.begin(), labels.end(), operando) != labels.end()){
                    operandoEhLabel = true;
                }
                else {
                    operandoEhRegistrador = false;
                    operandoEhM1 = false;
                    operandoEhM2 = false;
                }

                if(operandoEhRegistrador) {
                    numOperando = registrador;              // Se operando == $R, então o valor de $R é passado para numOperando
                }
                else if(operandoEhM1) {
                    numOperando = m1;
                }
                else if(operandoEhM2) {
                    numOperando = m2;
                }
                else if(!operandoEhLabel) {
                    numOperando = stoi(operando);           // Se operando tiver sido algum número, converte de string para int (stoi)
                }
            }

            if(instrucao.back() == ':') {
                continue;
            }

            if(instrucao == "JMP" || instrucao == "IF0" || instrucao == "IF1" || instrucao == "JGE") {
                if(instrucao == "IF0" && registrador != 0) {
                    continue;
                }
                if(instrucao == "IF1" && registrador != 1) {
                    continue;
                }
                if(instrucao == "JGE" && m1 < registrador) {
                    continue;
                }

                int indiceLabel;

                for(int i = 0; i < labels.size(); i++) {
                    if(labels[i] == operando) {
                        indiceLabel = i;
                    }
                }

                linhaLabel = labelsLinhas[indiceLabel];
                lineCounter = 0;
                flagJump = true;

                assemblyCode.clear();
                assemblyCode.seekg(0);
                continue;
            }else {
                flagJump = false;
            }

            if(instrucao == "PUSH" && !temOperando) {       // Dispara erro caso PUSH tenha sido passada sem operando
                cout << "\n[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;
            }
            else if(instrucao == "POP" && temOperando) {   // Dispara erro caso POP tenha sido passada com algum operando
                cout << "\n[000] - Erro de sintaxe. Eh esperado que as instrucoes possuam zero (POP) ou um operandos (PUSH $R). -> [linha " << lineCounter << "]";
                break;         
            }
            else if((instrucao == "CLEAR" || instrucao == "ADD" || instrucao == "SUB" || instrucao == "MUL" || instrucao == "DIV" || instrucao == "MOD") && temOperando) {
                // Dispara erro caso alguma das instruções aritméticas tenham sido passadas com operando
                cout << "\n[002] - Argumento inválido -> [Linha " << lineCounter << "]";
                break;
            }

            if(instrucao == "CLEAR") {

            }
            else if(instrucao == "ADD") {
                registrador = add(pilha);
            }
            else if(instrucao == "INC") {
                inc(pilha);
            }else if(instrucao == "INCR") {
                if(operando == "M1") {
                    m1++;
                }
                else if(operando == "M2") {
                    m2++;
                }
                else if(operando == "$R") {
                    registrador++;
                }
            }
            else if(instrucao == "SUB") {
                registrador = sub(pilha);
            }
            else if(instrucao == "SUB2") {
                sub2(pilha);
            }
            else if(instrucao == "MUL") {
                registrador = mul(pilha);
            }
            else if(instrucao == "DIV") {
                registrador = divis(pilha);
            }
            else if(instrucao == "MOD") {
                registrador = mod(pilha);
                // cout << "\n" << registrador;
            }
            else if(instrucao == "NOT") {

            }
            else if(instrucao == "OR") {
                
            }
            else if(instrucao == "AND") {

            }
            else if(instrucao == "MIR") {

            }
            else if(instrucao == "MOVM1") {
                m1 = numOperando;
            }
            else if(instrucao == "MOVM2") {
                m2 = numOperando;
            }
            else if(instrucao == "PUSH") {
                if(pilha.size() == 128) {
                    // cout << "\n" << pilha.size();
                    cout << "\n[004] - PUSH em pilha cheia -> [Linha " << lineCounter << "]";
                    break; 
                }else {
                    push(pilha, numOperando);
                }
            }
            else if(instrucao == "PUSHR") {
                registrador = pushr(pilha);
            }
            else if(instrucao == "PUSHM1") {
                m1 = pushm1(pilha);
            }
            else if(instrucao == "POP") {
                if(pilha.size() == 0) {
                    cout << "[003] - POP em pilha vazia -> [Linha " << lineCounter << "]";
                    break; 
                }else {
                    pop(pilha);
                }
            }
            else if(instrucao == "OUT") {
                cout << "\n\nTopo da pilha: " << pilha[pilha.size() - 1];
                cout << "\n\nFim do programa.";
            }
            else {
                cout << "\n\n" << instrucao;
                cout << "\n\n" << instrucao.length();
                cout << "\n[001] - Instrucao invalida. Ex. POOP em vez de POP. -> [Linha " << lineCounter << "]";
                break; 
            }

            // for(int i = 0; i < pilha.size(); i++) {
            //     cout << pilha[i] << " ";
            // }
            // cout << "\n\n";
        }
    }

    return 0;
}