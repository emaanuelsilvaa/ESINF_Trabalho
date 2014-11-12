# Trabalho da cadeira Estruturas de Informação do 2º ano de Licenciatura de Engenharia Informática. #

Equipa de Desenvolvimento:

Luís Ferreira, 1130647

Paulo Barbosa, 1130648

## Aplicação: ##
   Pretende-se com este trabalho desenhar e implementar um simulador de armazém disponibilizando
diversas funcionalidades, desde a criação automática do armazém até ao armazenamento e expedição de
produtos no armazém.

## Matéria Abordada: ##
   Polimorfismo
   Hierarquia
   Biblioteca STL (vetores, stacks...)
   Manipulação de Ficheiros

## Projeto: ##
   Encontra-se dividida em 2 Partes.
    ### 1ª Parte: (40%) ### 
        Aproveitando as facilidades oferecidas pelo paradigma orientado a objetos, o trabalho deverá ser
realizado de forma incremental — começando com as classes mais simples até se chegar ao sistema final.
É importante testarem as diferentes classes à medida que as desenvolvem. Serão assim estabelecidos os
seguintes objetivos intermédios a alcançar.

1. Apresente o diagrama de classes

2. Desenvolva as classes necessárias ao simulador de armazém acima especificado.

3. Para cada classe, para além dos construtores, destrutor, métodos para atualização/acesso aos
membros de dados privados e sobrecarga dos operadores necessários ao bom funcionamento da
classe, deverão também ser implementados os métodos específicos da classe.

4. Para os métodos específicos das classes devem apresentar o diagrama de sequências.

###    2ª Parte: (60%) ###
        A distância entre os depósitos de armazenamento é muito importante na gestão de um armazém, pelo
que pretende-se que implementem o armazém, gerado e guardado em ficheiro de texto com o sistema
anteriormente desenvolvido, através de um grafo usando a classe graphStl e na qual a gestão do grafo
ocorra indistintamente ao nível dos depósitos frescos e dos depósitos normais.
A classe para além dos construtores e destrutor deverá disponibilizar funcionalidades para:
1. Construir o grafo
2. Apresentar todos os percursos possíveis entre dois depósitos
3. Apresentar um percurso entre dois depósitos que envolva apenas um tipo de depósito (fresco/normal)
4. Calcular o percurso mais curto entre dois depósitos