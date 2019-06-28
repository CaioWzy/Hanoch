# Hanoch
> Hanoch é uma ferramenta, escrita em C++, que gera a solução para a Torre de Hanoi com o mínimo de movimentos possíveis através do método iterativo. Também foram utilizados ponteiros e pilhas como parte do desafio proposto.
  
## Compilação
```bash
make
```
  
## Execução
```bash
./Hanoch [num_discos]
```

## Visualização  
É possível visualizar, durante a solução, a resolução para o problema com o script 'HanochViewer.py'.
  
1. Instale a biblioteca pygame:
```bash
pip3 install -r requirements.txt
```
2. Execute o ./Hanoch piperizando a saída do comando para o script:
```bash
./Hanoch [num_discos] | python3 HanochViewer.py
```

## Referências  
1. [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)
2. [How to solve Tower of Hanoi iteratively?](https://cs.stackexchange.com/questions/96624/how-to-solve-tower-of-hanoi-iteratively)
3. [Como resolver a Torre de Hanói de qualquer tamanho](https://www.youtube.com/watch?v=GUjr_qLXf-k)
4. [Binary, Hanoi and Sierpinski, part 1](https://www.youtube.com/watch?v=2SUvWfNJSsM)
5. [Binary, Hanoi and Sierpinski, part 2](https://www.youtube.com/watch?v=bdMfjfT0lKk)

