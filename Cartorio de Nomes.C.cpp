#include <stdio.h> //biblioteca de comunicação  com o usuário
#include <stdlib.h> //biblioteca de alocação de espaco em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h>	//biblioteca responsavel por cuidar dos strings

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//Incio criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criacao das variaves/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informacao do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fechar o arquivo	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!. \n");
		system("pause");	
	}
}




int main ()
	{
	int opcao=0; // Definindo as variaves
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // Responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // E o inicio do menu
		printf("Escolha uma opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes.\n");
		printf("\t2 - Consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n\n"); 
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenamento a escolha do usuario
	
		system("cls"); // Limpar tela
	
	
		switch(opcao) //Incio da selecao do menu
		{
			case 1:
			registro();
			system("pause");
			break;
			
			case 2:
			consulta();
			system("pause");
			break;
			
			case 3:
			deletar();
			system("pause");
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	}
}

