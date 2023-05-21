#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FUNCIONARIOS 5

typedef struct
{
  char nome[51];
  int id;
  float salario;
} Funcionario;

void ordenarAlfabeticamente(Funcionario f[], int tam)
{
  int i, j;
  Funcionario s;
  for (i = 0; i < tam; i++)
  {
    for (j = i + 1; j < tam; j++)
    {
      if (strcmp(f[i].nome, f[j].nome) > 0)
      {
        s = f[i];
        f[i] = f[j];
        f[j] = s;
      }
    }
  }
}

void ordenarPorId(Funcionario f[], int tam)
{
  int i, j;
  Funcionario s;
  for (i = 0; i < tam; i++)
  {
    for (j = i + 1; j < tam; j++)
    {
      if (f[i].id > f[j].id)
      {
        s = f[i];
        f[i] = f[j];
        f[j] = s;
      }
    }
  }
}



//---Busca Binária---
int busca_id(Funcionario f[], int id)
{
  int inicio = 0, meio, fim = NUM_FUNCIONARIOS - 1;
  while (inicio <= fim)
  {
    meio = (inicio + fim) / 2;
    if (id < f[meio].id)
      fim = meio - 1;
    else if (id > f[meio].id)
      inicio = meio + 1;
    else
      return meio;
  }
  return -1;
}


void exibe_funcionario()
{
  Funcionario f[NUM_FUNCIONARIOS];
  FILE *p1;
  p1 = fopen("Funcionario", "rb");
  fread(f, sizeof(Funcionario), NUM_FUNCIONARIOS, p1);
  fclose(p1);
  int id;
  int idFuncionarioEncontrado;

  printf("Digite o Id do funcionario que quer buscar\n");
  scanf("%d", &id);

  idFuncionarioEncontrado = busca_id(f, id);
  if (idFuncionarioEncontrado == -1)
  {
    printf("\nId não existe\n");
    return;
  }
  
  printf("%d", idFuncionarioEncontrado);

  
  printf("%s\t", f[idFuncionarioEncontrado].nome);
  printf("%d\t", f[idFuncionarioEncontrado].id);
  printf("%.2f\n", f[idFuncionarioEncontrado].salario);

}

void criadorDeFuncionarios()
{
  Funcionario f[NUM_FUNCIONARIOS];
  FILE *p1;
  p1 = fopen("Funcionario", "wb");
  printf("\n\nCriando Funcionarios: \n");
  getchar();
  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("%d-nome:", i + 1);
    fgets(f[i].nome, 51, stdin);

    // remove o ultimo caracter \n para nao quebrar a exibicao
    int size = strlen(f[i].nome);
    if (f[i].nome[size - 1] == '\n')
    {
      f[i].nome[size - 1] = '\0';
    }

    printf("id ");
    scanf("%d", &f[i].id);

    printf("salario ");
    scanf("%f", &f[i].salario);
    getchar();
    printf("\n");
  }
  // Devemos ordenar por ID ou nao?
  ordenarPorId(f, NUM_FUNCIONARIOS);

  printf("\n\n --------Funcionarios Criados: -------- \n\n");
  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("%s\t", f[i].nome);
    printf("%d\t", f[i].id);
    printf("%.2f\n", f[i].salario);
  }
  printf("\n\n ---------------- \n\n");
  printf("Salvando Funcionarios no arquivo \n\n");
  fwrite(f, sizeof(Funcionario), NUM_FUNCIONARIOS, p1);
  fclose(p1);
}

/**
void listar_funcionarios(Funcionario f[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("Nome:%s ",f[i].nome);
        printf("id:%d ",f[i].id);
        printf("Salario:%.2f",f[i].salario);
        printf("\n\n");
    };
}*/

// listar_funcionarios(f,N);

void leitorDeFuncionarios()
{
  Funcionario f[NUM_FUNCIONARIOS];
  FILE *p1;
  p1 = fopen("Funcionario", "rb");

  printf("\n\n ---------- Funcionarios cadastrados ---------------\n\n");
  //---Leitor De Funcionario---
  fread(f, sizeof(Funcionario), NUM_FUNCIONARIOS, p1);
  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("%d: %s \t", f[i].id, f[i].nome);
    printf("%.2f", f[i].salario);
    printf("\n\n");
  };
  printf("\n\n ------------------------\n\n");
  fclose(p1);
}

#endif
