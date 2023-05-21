#ifndef PROJETO
#define PROJETO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PROJETOS 2

typedef struct {
    char nome[51];
    int data_inicial[3];
    int data_termino[3];
    int tempo_estimado;
    float valor_estimado;
    int f_id;
} Projeto;

void criadorDeProjetos() {
  Projeto p[NUM_PROJETOS];
  FILE *p2;
  p2 = fopen("Projeto","wb");

  printf("Criando Projetos: \n");

  for(int i=0;i<NUM_PROJETOS;i++){
     printf("Nome do Projeto\n");
     fgets(p[i].nome, 51, stdin);
     printf("dia de inicio do projeto\n");
     scanf("%d",&p[i].data_inicial[0]);
     printf("mes de inicio do projeto\n");
     scanf("%d",&p[i].data_inicial[1]);
     printf("ano de inicio do projeto\n");
     scanf("%d",&p[i].data_inicial[2]);
     printf("dia estimado para finalizar o projeto\n");
     scanf("%d",&p[i].data_termino[0]);
     printf("mes estimado para finalizar o projeto\n");
     scanf("%d",&p[i].data_termino[1]);
     printf("ano estimado para finalizar o projeto\n");
     scanf("%d",&p[i].data_termino[2]);
     printf("tempo(dias) total para realizar o projeto\n");
     scanf("%d",&p[i].tempo_estimado);
     printf("Valor total disponibilizado para o projeto\n");
     scanf("%f",&p[i].valor_estimado);
     printf("ID do responsavel\n");
     scanf("%d",&p[i].f_id);
     getchar();
     printf("\n");
 }

 printf("\n\n ---------------- \n\n");
 printf("Salvando Projetos no arquivo \n\n");
 fwrite(p,sizeof(Projeto),NUM_PROJETOS,p2);
 fclose(p2);
}


void leitorDeProjetos() {
  Projeto p[NUM_PROJETOS];
  FILE *p2;
  p2 = fopen("Projeto","rb");

  //---Leitor De Projetos---
  fread(p,sizeof(Projeto),NUM_PROJETOS,p2);
  for(int i=0;i<NUM_PROJETOS;i++){
    printf("P:%s",p[i].nome);
    printf("i:%d",p[i].data_inicial[0]);
    printf("/%d",p[i].data_inicial[1]);
    printf("/%d\n",p[i].data_inicial[2]);
    printf("f:%d",p[i].data_termino[0]);
    printf("/%d",p[i].data_termino[1]);
    printf("/%d\n",p[i].data_termino[2]);
    printf("%d",p[i].tempo_estimado);
    printf("\n%.2f ",p[i].valor_estimado);
    printf("\n%d",p[i].f_id);
    printf("\n");
    printf("\n");
  }
  fclose(p2);
}

#endif
