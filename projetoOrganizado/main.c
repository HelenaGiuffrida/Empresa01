#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "gerente.h"
#include "projeto.h"

void escritaDosDados() {
  criadorDeFuncionarios();
  criadorDeProjetos();
  criadorDeGerentes();
}

void leituraDosDados() {
  leitorDeFuncionarios();
  leitorDeProjetos();
  leitorDeGerentes();
}


int main()
{
  int opcao = 100;

   
  while (opcao != 0) {
    printf("Digite 0 para sair \n");
    printf("Digite 1 para entrar com novos dados\n");
    printf("Digite 2 para ler os dados salvos\n");
    printf("Digite 3 para buscar um funcionario por id\n");
    scanf("%d",&opcao);
    if (opcao == 1) {
      escritaDosDados();
    }
    if (opcao == 2) {
      leituraDosDados();
    }
     if (opcao == 3) {
      exibe_funcionario();
      
    }
  }
  return 0;
}
