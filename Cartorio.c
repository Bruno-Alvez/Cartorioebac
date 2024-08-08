#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //Escreve na tela e pede ao usu�rio que digite o CPF a ser cadastrado coletando essa informa��o  
    scanf("%s", cpf); //%s refere-se a string e armazena dentro da vari�vel os dados coletado do usu�rio 
    
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//Abre o arquivo e "a" atualiza o conte�do
	fprintf(file,",");//Adiciona uma v�rgula entre as informa��es do usu�rio
	fclose(file);//Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," "); //Nesse caso o espa�o entre nome e sobrenome fica mais visual que a v�rgula nas informa��es do usu�rio 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
    system("pause");//Adiciona uma pausa na tela, facilitando o a leitura do usu�rio e espera a a��o dele
	
}

int consulta() //Fun��o respons�vel por consultar os usu�rio no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	//In�cio da cria��o das vari�veis dessa fun��o
	char cpf[40];
	char conteudo[200];
	//Termino da cria��o das vari�veis
	
	printf("Digite o CPF a ser consultado:");//Escreve na tela e pede ao usu�rio que digite o CPF a ser consultado e coleta essa informa��o 
	scanf("%s", cpf);//Escaneia as informa��es que o usu�rio digitou 
	
	FILE *file;
	file = fopen(cpf,"r");//Abre o arquivo e o "r" l� as informa��es contidas no arquivo 
	
	if(file == NULL)// Fun��o condicional caso o usu�rio digite uma inform��o inexistente 
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o cadastrado! \n ");//Escreve na tela para o usu�rio saber que ele digitou um CPF inv�lido
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Buscar� informa��es enquanto tiver conte�do dentro da vari�vel armazanado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);//Armazena dentro da vari�vel os dados coletado do usu�rio 
		printf("\n\n");
		//Escreve na tela e informa ao usu�rio a informa��es encontradas dentro da varia�vel	
	
	system("pause");
	
    }
}

int deletar() //Fun��o respons�vel por deletar usu�rios do sistema 
{
	
	char cpf[40];//Cria��o da vari�vel 
	
	printf("Digite o CPF do usu�rio a ser deletado : ");//escreve na tela e pede ao usu�rio que digite o CPF a ser deletado e coleta essa informa��o 
	scanf("%s",cpf);//Armazena dentro da vari�vel os dados coletado do usu�rio 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//Se o usu�rio for inexistente 
	{
		printf("O usu�io n�o se encontra no sistema!\n");//Escreve na tela e informa ao usu�rio que ele digitou uma inform��o inexistente
		system("pause");
	}

	
	
}

int main() //Fun��o respons�vel por dar intera��o ao menu
{

	int opcao=0; //Definindo as vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");//Respons�vel por limpar a tela 
	    
		setlocale(LC_ALL, "Portuguese"); 
	
	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n"); 
	    printf("Op��o: ");//Fim do menu
	
	    scanf("%d", &opcao); //Armazenamento e escolha do usu�rio
	
	    system("cls"); 
	    
	    switch(opcao)//In�cio da sele��o do menu
	    {   
		    case 1://Caso o usu�rio selecione a primeira op��o ao usu�rio 
	    	    registro();//Chamada de fun��es
	    	    break; // fechamento da primeira op��o 
	    	 
	    	case 2:
	    		consulta();
	    		break;
	        
	        case 3:
	        	deletar();
	        	break;
	        	
	        case 4:
	        	printf("Obrigado por utilizar o sistema! ");
	        	return 0;
	        	
	        default://Caso o usu�rio selecione uma op��o n�o dispon�vel 
	        	printf("Esta op��o n�o est� dispon�vel!\n");//Escreve na tela e informa ao usu�rio que ele digitou uma op��o inv�lida 
	        	system("pause");
	        	break;
	        
			
		}
	}
}

	
	
	

