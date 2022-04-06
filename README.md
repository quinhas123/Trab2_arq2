[[ simulador de máquina de pilha ]]

##  base
++  [X] $R
++  [X] Validar programa soma 4 e 8
++  [ ] Registradores e palavras com 16 bits
++  [ ] Pilha possui 128 palavras.
++  [ ] PC para o topo da pilha.

##  operações aritméticas trabalhando sobre o topo da pilha e armazenando em $R
++  [X] ADD
++  [X] SUB
++  [X] MUL
++  [X] DIV
++  [X] MOD

##  operações lógicas (devem armazenar em $R ou não ?)
++  [ ] NOT
++  [ ] OR
++  [ ] AND
++  [ ] MIR

##  operações de controle
++  [X] PUSH
++  [X] POP

##  in/out
++  [X] OUT

##  aplicações
++  [X] Bhaskara --> R1 e R2 na pilha.
++  [X] Raiz quadrada --> uma única resposta na pilha.
++  [X] Cálculo do N-ésimo número primo --> única resposta na pilha.
++  [ ] Outra aplicação.

##  erros básicos
++  [X] 000 - Erro de sintaxe - 0 ou 1 operandos (PUSH ou POP).
++  [X] 001 - Instrução inválida.
++  [X] 002 - Argumento inválido. Conferir se o argumento condiz com a instrução.
++  [X] 003 - POP em pilha vazia.
++  [X] 004 - PUSH em pilha cheia.

##  extras
++  --> labels => usado para os jumps
++  --> IF0    => pula se $R = 0
++  --> IF1    => pula se $R = 1
++  --> JGE    => pula se M1 >= $R
++  --> INC    => incrementa o valor no topo da pilha
++  --> INCR   => incrementa o registrador dado como operando
++  --> M1     => registrador auxiliar
++  --> M2     => registrador auxiliar
++  --> SUB2   => subtrai o penúltimo e antepenúltimo elementos da pilha
++  --> MOVM1  => coloca o valor do operando em M1
++  --> MOVM2  => coloca o valor do operando em M2
++  --> PUSHR  => coloca o valor do topo da pilha em $R

##  validação de operações
++  [X] ADD
++  [X] SUB
++  [X] MUL
++  [X] DIV
++  [X] MOD
++  [X] POP
++  [ ] NOT
++  [ ] OR
++  [ ] AND
++  [X] MIR

##  validação de erros
++  [X] 000 - Erro de sintaxe - 0 ou 1 operandos (PUSH ou POP).
++  [X] 001 - Instrução inválida.
++  [X] 002 - Argumento inválido. Conferir se o argumento condiz com a instrução.
++  [X] 003 - POP em pilha vazia.
++  [X] 004 - PUSH em pilha cheia.

## To-do...
++  [ ] ...