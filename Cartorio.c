#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar da string

int registro() //Função responsável por cadastrar os usuários no sistema 
{
	//Início da criação de variáveis/string
	char arquivo[40];	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //Escreve na tela e pede ao usuário que digite o CPF a ser cadastrado coletando essa informação  
    scanf("%s", cpf); //%s refere-se a string e armazena dentro da variável os dados coletado do usuário 
    
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salva o valor da variável
    fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//Abre o arquivo e "a" atualiza o conteúdo
	fprintf(file,",");//Adiciona uma vírgula entre as informações do usuário
	fclose(file);//Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," "); //Nesse caso o espaço entre nome e sobrenome fica mais visual que a vírgula nas informações do usuário 
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
	
    system("pause");//Adiciona uma pausa na tela, facilitando o a leitura do usuário e espera a ação dele
	
}

int consulta() //Função responsável por consultar os usuário no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	//Início da criação das variáveis dessa função
	char cpf[40];
	char conteudo[200];
	//Termino da criação das variáveis
	
	printf("Digite o CPF a ser consultado:");//Escreve na tela e pede ao usuário que digite o CPF a ser consultado e coleta essa informação 
	scanf("%s", cpf);//Escaneia as informações que o usuário digitou 
	
	FILE *file;
	file = fopen(cpf,"r");//Abre o arquivo e o "r" lê as informações contidas no arquivo 
	
	if(file == NULL)// Função condicional caso o usuário digite uma informção inexistente 
	{
		printf("Não foi possível abrir o arquivo, CPF não cadastrado! \n ");//Escreve na tela para o usuário saber que ele digitou um CPF inválido
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Buscará informações enquanto tiver conteúdo dentro da variável armazanado
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);//Armazena dentro da variável os dados coletado do usuário 
		printf("\n\n");
		//Escreve na tela e informa ao usuário a informações encontradas dentro da variaável	
	
	system("pause");
	
    }
}

int deletar() //Função responsável por deletar usuários do sistema 
{
	
	char cpf[40];//Criação da variável 
	
	printf("Digite o CPF do usuário a ser deletado : ");//escreve na tela e pede ao usuário que digite o CPF a ser deletado e coleta essa informação 
	scanf("%s",cpf);//Armazena dentro da variável os dados coletado do usuário 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//Se o usuário for inexistente 
	{
		printf("O usuáio não se encontra no sistema!\n");//Escreve na tela e informa ao usuário que ele digitou uma informção inexistente
		system("pause");
	}

	
	
}

int main() //Função responsável por dar interação ao menu
{

	int opcao=0; //Definindo as variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");//Responsável por limpar a tela 
	    
		setlocale(LC_ALL, "Portuguese"); 
	
	    printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n"); 
	    printf("Opção: ");//Fim do menu
	
	    scanf("%d", &opcao); //Armazenamento e escolha do usuário
	
	    system("cls"); 
	    
	    switch(opcao)//Início da seleção do menu
	    {   
		    case 1://Caso o usuário selecione a primeira opção ao usuário 
	    	    registro();//Chamada de funções
	    	    break; // fechamento da primeira opção 
	    	 
	    	case 2:
	    		consulta();
	    		break;
	        
	        case 3:
	        	deletar();
	        	break;
	        	
	        case 4:
	        	printf("Obrigado por utilizar o sistema! ");
	        	return 0;
	        	
	        default://Caso o usuário selecione uma opção não disponível 
	        	printf("Esta opção não está disponível!\n");//Escreve na tela e informa ao usuário que ele digitou uma opção inválida 
	        	system("pause");
	        	break;
	        
			
		}
	}
}

	
	
	

