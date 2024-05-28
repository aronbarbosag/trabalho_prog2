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
void cadastrarVenda();
void verVendaPorCliente();
void verificarNumeroNegativo(float numero);

//------------------------------------------INICIO MAIN------------------------------------------------------------
int main(void){
  
  int escolha;
  int qtdVendas;
 
do{
    printf("\nMenu Principal\n");
    printf("1. Cadastrar novas vendas\n");
    printf("2. Ver informacoes de uma venda especifica\n");
    printf("3. Ver informacoes de todas as vendas\n");
    printf("4. Encerrar o programa\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      cadastrarVenda();
      
      break;
    case 2:
       verVendaPorCliente();
      break;
    case 3:
      // verTodasVendas();
      break;
    case 4:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Erro. Opção inválida.\n");
    }
   
   system("cls"); // para windows
  //  system("clear"); // para linux e replit
}while (escolha != 4);
  
  
  
  
  
  
  // 
  
  return 0;
}
//---------------------------------------------------------------FIM DA MAIN------------------------------------------------------------------------
void verificarNumeroNegativo(float numero){
  if(numero < 0){
    printf("numero inválido, por favor digite um numero positivo\n ");
  }
}



void limparEnter(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '\n') {
      string[i] = '\0';
    }
  }
}

void cadastrarVenda(){
  int qtdVendas;

  printf("Qual a quantidade de vendas que deseja cadastrar ?");
  scanf("%d",&qtdVendas);
  venda *vendas;
  vendas = (venda *)malloc(qtdVendas*sizeof(venda));
  if(vendas== NULL ){
    printf("Erro na alocação de memoria");
    return ;
  }

  for(int i =0;i<qtdVendas;i++){
    

      printf("nome do cliente ? ");
      scanf("%s",vendas[i].c.nome);
      
      printf("idade do cliente ? ");
      scanf("%d",&vendas[i].c.idade);

      printf("sexo (m) , (f) ou (n) ?");
      scanf(" %c",&vendas[i].c.sexo);

      printf("quantidade de itens ? ");
      scanf("%d",&vendas[i].quantidade_itens);
      
      printf("quantidade de sabores ? ");
      scanf("%d",&vendas[i].quantidade_sabores);

   
    


      printf("valor total ? ");
      scanf("%f",&vendas[i].valor_total);
     


}
// fim do cadastro

 
  
//aqui joga os dados para o arquivo txt
 FILE *arquivo;
 arquivo = fopen("registro.txt","a");
 for(int i =0;i<qtdVendas;i++){
  fprintf(arquivo,"%s\n",vendas[i].c.nome);
  fprintf(arquivo,"%c\n",vendas[i].c.sexo);
  fprintf(arquivo,"%d\n",vendas[i].c.idade);
  fprintf(arquivo,"%d\n",vendas[i].quantidade_itens);
  fprintf(arquivo,"%d\n",vendas[i].quantidade_sabores);
  fprintf(arquivo,"%.2f\n",vendas[i].valor_total);
  fprintf(arquivo,"$\n");

 }
 fclose(arquivo);
 free(vendas);
}

// aqui ver cliente (especifico)
 void verVendaPorCliente(){
  char palavra_pesquisada[30];
  int idade,quantidadeItens,quantidadeSabores;
  float valorTotal;
  char sexo;
  
  int contador =0;
  printf("Nome do cliente a ser pesquisado: ");
  fgets(palavra_pesquisada, 30, stdin);
  
  getchar();
 
    FILE *arquivo;

    arquivo = fopen("registro.txt", "r");

    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.");
      return ;
    }

    
  
    printf("%s",palavra_pesquisada);
   
//------------------------------------ ESSE CODIGO ABAIXO ESTÁ PSICODÉLICO-----------------------------------------------------------------------------------
   while (fscanf(arquivo, "%c %d %f %d %d\n", &sexo, &idade, &valorTotal, &quantidadeItens, &quantidadeSabores) != EOF){
    char nome[30];
    fscanf(arquivo, "%s", nome);

    if (strcmp(nome, palavra_pesquisada) == 0) {
      printf("Sexo: %c\n", sexo);
      printf("Idade: %d\n", idade);
      printf("Valor Total: %.2f\n", valorTotal);
      printf("Quantidade de Itens: %d\n", quantidadeItens);
      printf("Quantidade de Sabores: %d\n", quantidadeSabores);
      contador++;
    }
  }
  printf("Total de vendas para %s: %d\n", palavra_pesquisada, contador);

  
  
   fclose(arquivo);
  }
 
