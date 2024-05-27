#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct cliente{
  char nome[30];
  char sexo;
  int idade;
};
typedef struct cliente cliente;

struct venda{
  cliente c;
  int quantidade_itens;
  int quantidade_sabores;
  float valor_total;
};
typedef struct venda venda;
void limparEnter(char *string);
int main(void){
  
  int qtdVendas;
  printf("Qual a quantidade de vendas que deseja cadastrar ?");
  scanf("%d",&qtdVendas);
  venda *vendas;
  vendas = (venda *)malloc(qtdVendas*sizeof(venda));
  for(int i =0;i<qtdVendas;i++){
    // 
  }
  printf("pronto");


 free(vendas);
  return 0;
}

void limparEnter(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '\n') {
      string[i] = '\0';
    }
  }
}