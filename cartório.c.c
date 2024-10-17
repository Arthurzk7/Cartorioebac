#include <stdio.h>//biblioteca de comunicação com o usuario 
#include <stdlib.h>//Biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de testo por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
	//final da criação de variáveis/string

  printf("digite o CPF a ser cadastrado"); //coletando informações do usuário
  scanf("%s", cpf);//%s refere-se a string
  
  strcpy(arquivo, cpf);//Responsavel por copiar os valores dos string
  
  FILE *file;// cria o arquivo
  file = fopen(arquivo, "w");//cria arquivo
  fprintf(file, cpf);//salvo o valor da variavel
  fclose(file);//fecho o arquivo
  
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado");
  scanf("%s", nome);
   
  file = fopen(arquivo, "a");
  fprintf(file, nome);
  fclose(file);
     
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);
  
  file = fopen(arquivo, "a");
  fprintf(file, sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado");
  scanf("%s", cargo);
  
  file = fopen(arquivo, "a");
  fprintf(file, cargo);
  fclose(file);
   

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
   printf("você escolheu consultar os nomes!\n");
   scanf("%s", cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   
{
	printf("Não foi possível abrir o arquivo, não localizado!.\n");
}
   	
   while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
   system("pause");
   
     
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema!.\n");
		system("pause");
			
	}
	
	
}





int main()
    {
	    int opcao=0; //Definindo variaveis
	    int x=1;
	    
	    for(x=1;x=1;)
	
	    {
		system("cls");
		
		
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("###cartório da EBAC###\n\n"); //Inicio do menu 
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - sair do sistema\n");
		printf("Opção:");//fim do menu 
	
	    scanf("%d", &opcao); //Armazenado a escolha do usuario
	    
	    system("cls"); //responsavel por limpar a tela
	    
	    switch (opcao) //início da seleção do menu
	    {
	    	case 1:
	        registro(); //chamada de funções
	        break;
		    
		    case 2:
		   	consulta();
		   break;
		    
		    case 3:	
		    deletar();
		    break;
		 
            case 4:
            printf("obrigado por utilizar o sistema!");
            return 0;
            break;
            
                 
                 
                 
		    default:
			printf("esta opção não está disponível\n"); 
		    system("pause");
		    break;
		    	
		}
	
	    
    }  	
} 
