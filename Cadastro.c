#include<stdio.h>
//constante do tamanho da matriz
#define SIZE 200

//Criar as matrizes
char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];

//criar opção para sair ou continuar
int op;

//iniciar função
void cadastro();
void pesquisa();
void lista();

int main (void){

 //chamando a função
 cadastro();
 lista();
 pesquisa();

}

//função para cadastrar nome, email e cpf e opção de continuar ou sair
void cadastro(){
    static int linha;

    do{
        printf("\nDigite um Nome: ");
        scanf("%199[^\n]s", nome[linha]);
        fflush(stdin);
        printf("\nDigite o Email: ");
        scanf("%s", email[linha]);
        fflush(stdin);
        printf("\nDigite seu CPF: ");
        scanf("%d", &cpf[linha]);
        fflush(stdin);
        printf("\nDigite 1 para continuar ou outro valor para sair: ");
        scanf("%d", &op);
        linha++;

    }while (op==1);    
}
void pesquisa(){
    int cpfPesquisa;
    char emailPesquisa[50];
    int i;
    do
    {
        printf("\nDigite 1 para pesquisar o CPF ou 2 para pesquisar por Email: ");
        scanf("%d", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            printf("\nDigite o CPF: ");
            scanf("%d", &cpfPesquisa);
            fflush(stdin);
            for ( i = 0; i < SIZE; i++)
            {
                if (cpf[i]==cpfPesquisa){
                    printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
                }           
            }
            
            break;
         case 2:
                  printf("\nDigite o Email: ");
                  scanf("%s", emailPesquisa);
                  fflush(stdin);
                  for ( i = 0; i < SIZE; i++)
                  {
                    if (strcmp(email[i], emailPesquisa)==0)
                    {
                        printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
                    }
                    
                  }
            break;    
        
        default:

            printf("\n Opção invalida");

            break;
        }
        printf("\nDigite 1 para continuar pesquisando: ");
        scanf("%d", &op);
        fflush(stdin);
    } while (op==1);
    
}
void lista(){
    int i;
    for ( i = 0; i < SIZE; i++)
    {
        if(cpf[i]>0){
         printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
         }else{
            break;
         }
    }
    
}