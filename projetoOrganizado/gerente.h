#ifndef GERENTE
#define GERENTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_GERENTES 3

typedef struct{
    char chave[50];
    char email[100];
    int id;
} Gerente;

Gerente ght[NUM_GERENTES];
FILE *p3;

//função hash
unsigned int hashFuntion(const char* chave){
    unsigned int hash = 0;
    for(int i=0;i<strlen(chave);i++){
        hash+=chave[i];
    }
    return hash % NUM_GERENTES;
}
int inserirGerente(const char* chave, const char* email) {
    unsigned int index = hashFuntion(chave);
    //criar um novo gerente
    Gerente* novoGerente = (Gerente*)malloc(sizeof(Gerente));
    strcpy(novoGerente->chave, chave);
    strcpy(novoGerente->email, email);
    novoGerente->id = index;
    if (strcmp(ght[index].chave, "")) {
      printf("Houve Conflito ao inserir a chave: %s\n", chave);
      return 0;
    }
    //inserir na tabela hash
    ght[index] = *novoGerente;
    return 1;
}

//função para buscar gerente na tabela
Gerente getGerente(Gerente* ght, const char* chave){
    unsigned int index = hashFuntion(chave);
    //busca na tabela hash
    return ght[index];
}

void inicializaGerentes() {
  Gerente* gerenteLido;
  for(int i=0;i<NUM_GERENTES;i++){
    gerenteLido = &ght[i];
    strcpy(gerenteLido->chave, "");
    strcpy(gerenteLido->email, "");
    gerenteLido->id = -1;
    printf("\n");
  };
}

void criadorDeGerentes() {
  p3 = fopen("Gerente","w+");
  printf("Criando Gerentes pre definidos: \n");

  // limpar o array de gerentes para a comparacao de conflito da HashTable
  inicializaGerentes();

  //exemplo de inserção de gerente
  inserirGerente("gerente1", "gerente1@exemplo.com");
  inserirGerente("gerente2", "gerente2@exemplo.com");
  inserirGerente("gerente3", "gerente3@exemplo.com");

  printf("\n\n ---------------- \n\n");
  printf("Salvando Gerentes no arquivo \n\n");
  fwrite(ght,sizeof(Gerente),NUM_GERENTES,p3);
  fclose(p3);
}


void leitorDeGerentes() {
  Gerente* gerenteLido;
  p3 = fopen("Gerente","r+");
  fread(ght,sizeof(Gerente),NUM_GERENTES,p3);
  for(int i=0;i<NUM_GERENTES;i++){
    gerenteLido = &ght[i];
    printf("%s\t",gerenteLido->chave);
    printf("%s",gerenteLido->email);
    printf("\n");
  };
  fclose(p3);
}

#endif
