<h1>Simulador de máquina de pilha</h1>

##  base
++  [X] $R <br>
++  [X] Validar programa soma 4 e 8 <br>
++  [X] Registradores e palavras com 16 bits <br>
++  [X] Pilha possui 128 palavras. <br>
++  [X] PC para o topo da pilha. <br>

##  operações aritméticas trabalhando sobre o topo da pilha e armazenando em $R
++  [X] ADD <br>
++  [X] SUB <br>
++  [X] MUL <br>
++  [X] DIV <br>
++  [X] MOD <br>

##  operações lógicas
++  [X] NOT <br>
++  [X] OR <br>
++  [X] AND <br>
++  [X] MIR <br>

##  operações de controle
++  [X] PUSH <br>
++  [X] POP <br>

##  in/out
++  [X] OUT

##  aplicações
++  [X] Bhaskara --> R1 e R2 na pilha. <br>
++  [X] Raiz quadrada --> uma única resposta na pilha. <br>
++  [X] Cálculo do N-ésimo número primo --> única resposta na pilha. <br>
++  [X] Outra aplicação. <br>

##  erros básicos
++  [X] 000 - Erro de sintaxe - 0 ou 1 operandos (PUSH ou POP). <br>
++  [X] 001 - Instrução inválida. <br>
++  [X] 002 - Argumento inválido. Conferir se o argumento condiz com a instrução. <br>
++  [X] 003 - POP em pilha vazia. <br>
++  [X] 004 - PUSH em pilha cheia. <br>

##  extras
++  --> labels => usado para os jumps <br>
++  --> IF0    => pula se $R = 0 <br>
++  --> IF1    => pula se $R = 1 <br>
++  --> JGE    => pula se M1 >= $R <br>
++  --> INC    => incrementa o valor no topo da pilha <br>
++  --> INCR   => incrementa o registrador dado como operando <br>
++  --> M1     => registrador auxiliar <br>
++  --> M2     => registrador auxiliar <br> 
++  --> SUB2   => subtrai o penúltimo e antepenúltimo elementos da pilha <br>
++  --> MOVM1  => coloca o valor do operando em M1 <br>
++  --> MOVM2  => coloca o valor do operando em M2 <br>
++  --> PUSHR  => coloca o valor do topo da pilha em $R

##  validação de operações
++  [X] ADD <br>
++  [X] SUB <br>
++  [X] MUL <br>
++  [X] DIV <br>
++  [X] MOD <br>
++  [X] POP <br>
++  [X] NOT <br>
++  [X] OR <br>
++  [X] AND <br>
++  [X] MIR

##  validação de erros
++  [X] 000 - Erro de sintaxe - 0 ou 1 operandos (PUSH ou POP). <br>
++  [X] 001 - Instrução inválida. <br>
++  [X] 002 - Argumento inválido. Conferir se o argumento condiz com a instrução. <br>
++  [X] 003 - POP em pilha vazia. <br>
++  [X] 004 - PUSH em pilha cheia.

## To-do...
++  [ ] ...