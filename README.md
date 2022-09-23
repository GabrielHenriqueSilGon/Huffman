# Huffman
 
Nesse código, uma àrvore de Huffman é utilizada para transformar um arquivo de texto em um código binário. Dada a string de teste "frase" no main como exemplo, esta é levada para a função "contas", que separa tokeniza a string em palavras e as guarda como chave numa hash <string, float> (esta é a struct "seiva" no código, para facilitar na implementação, pois escrever unordered_map<string, float> várias vezes deixa o código mais embaralhado do que apenas a palavra "seiva". Além da Hash, a struct seiva possui a recorrência de palavra (RP) máxima e mínima, e a quantidade de palavras na hash), além de guardar a recorrência de cada palavra como seu valor.

Essa hash então é passada para a função MinMax que acha o maior e menor RP das palavras, e então a função HuffmanRP normaliza os valores com a fórmula:

RP / (max(RP) - min(RP))

E substitui os valores na hash pelo valor normalizado. 

Por fim, essa Hash é enviada para o HuffmanCodes, que constroi a árvore de Huffman e devolve a codificação de cada palavra na Hash.

# Makefile

Como executar:

  make clean - Apaga a última compilação realizada contida na pasta build
  
  make - Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build
  
  make run - Executa o programa da pasta build após a realização da compilação
