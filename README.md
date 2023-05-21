# Empresa01
Projeto de Estrutura de Dados
Projeto do curso de Engenharia da Computação - IFSP - 2023

Descrição do Sistema
Uma empresa mantém cadastrados seus funcionários e dos diversos projetos
desenvolvidos. Diversas informações são armazenadas sobre os empregados, sendo
as principais, número funcional (único), nome e salário. Já sobre os projetos armazenase o nome (único), data_inicio, data_termino, tempo_estimado_projeto(meses),
valor_estimado, e funcionário responsável (número funcional).

Os empregados e os projetos são mantidos em vetores de tamanho fixo pela chave de
ordenação, sendo que para o vetor de funcionários é o número funcional e para o vetor
de projetos é o nome. Vamos supor que a empresa não tenha mais de 500 funcionários
e não mais de 2000 projetos ao longo de sua existência.
Os sistemas da empresa necessitam realizar algumas funcionalidades usando os dados
dos empregados e dos projetos, sendo essas funcionalidades focadas em buscas e
ordenações.

Proposta de implementação

Faça um programa que tenha as seguintes funcionalidades mínimas:
• Faça uma interface que permita ao usuário ter acesso a todas as
funcionalidades implementadas. A chave de ordenação dos registros dos
vetores pode ser definida automaticamente pelo sistema ou pelo usuário.

• O sistema deve permitir inserir, remover e alterar dados nos vetores,
sempre mantendo a ordenação dos dados pela chave de ordenação
definida para cada um deles. Não deve ser permitido que o usuário
modifique essa chave, pois não pode haver repetição nos valores dessas
chaves.

• Buscas e ordenações a serem implementadas:
o Faça a busca de um funcionário a partir do número funcional,
retornando os dados do empregado caso esse número seja de um
empregado válido. Para essa solução utilize um algoritmo de busca
que seja melhor que O(n).

o Os funcionários que tenham os maiores salários não irão receber
o bônus. Dessa forma, liste, os nomes e salários maiores que
R$10.000,00 em ordem decrescente de salário. Para essa solução
utilize um algoritmo de ordenação de O(n2).

o A empresa precisa controlar informações sobre os projetos que
estão em andamento. Dessa forma, busque e liste os projetos que
não estão terminados e tenham valor estimado acima de
R$500.000,00. Imprima a lista ordenada pelo valor dos projetos
usando um algoritmo que tenha a ordem O <=n.log2n. 

 A empresa teve problemas com alguns projetos, o que acarretou
atraso no término. Dessa forma, é necessário buscar e obter uma
listagem dos projetos estejam ainda em andamento e já passaram
do prazo estimado de entrega, e os que já terminaram e foi com
atraso. A listagem deve indicar junto com o projeto se o projeto está
terminado (finalizado) ou em andamento (em aberto) e tempo de
atraso. Ordene a resposta pelo tempo de atraso, usando um
algoritmo a sua escolha.

o A empresa concederá um bônus para empregados que estão como
responsáveis por projetos. Dessa forma, busque e liste em ordem
alfabética os nomes dos funcionários que estejam trabalhando
como responsáveis de projetos em andamento. Para busca use
uma solução que seja o otimizada possível para os dados
utilizados e uma ordenação de sua escolha.

• Usando o conceito de tabelas Hash implementar:
o Como é preciso sempre marcar reuniões entre a direção e os
gerentes de projeto é preciso obter rapidamente os e-mails dos
gerentes, dessa forma, guarde(insira) os e-mails (trate como string)
desses gerentes de projeto numa tabela hash estática, usando a
implementação de sua escolha.

• Regras de Implementação
o O programa pode ser desenvolvido em qualquer linguagem de
programação de sua escolha.

o Os algoritmos de ordenação e busca usados na implementação
das funcionalidades devem ser explicitamente implementados no
programa. Não é permitido o uso de funções prontas de ordenação
e busca já implementada na linguagem de programação escolhida.
o Caso o programa faça a inserção inicial de uma certa quantidade
de dados, é preciso garantir:

§ a ordenação inicial dos dados cadastrados dos funcionários
pelo número funcional.

§ a ordenação inicial dos dados cadastrados para os projetos
pelo nome.
