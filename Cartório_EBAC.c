#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o por cadastrar os usu�rios no sistema
{
	//Inicio das cria��es das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das cria��es das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coleta de informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo, "w"); //cria o arqivo e "w" de "Write" para escrever o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, ","); //Logo ap�s a resposta do usuario ele adicionar� uma ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abrir o arquivo e atualiza-lo com nova instru��o
	fprintf(file,nome); //Escrever o que foi escrito da vari�vel do nome dentro do arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo e atualiza-lo com nova instru��o
	fprintf(file, ","); //Colocar "," na �ltima letra 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Ler arquivo
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel encontrar esses dados.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
	
	if (file == NULL)
	{
		printf("Usu�rio apagado ou inexistente. \n");
		system("pause");
	}
	
	
}

int main() 
{
	int opcao=0; //Variaveis
	int laco=1;
	
	for(laco=1;laco=1;) //Repeti��o
	{
	
	system("cls"); //Limpa a tela ap�s ser executado
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
	
	printf("S2 S2 Cart�rio da EBAC S2 S2 \n\n"); //Inicio do menu
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nome\n");
	printf("\t2 - Consultar nome\n");
	printf("\t3 - Excluir nome\n\n"); //final do menu
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o: ");
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls"); //limpar tela ap�s selecionar a op��o
	
	switch(opcao) //Sele��o de op��o
	{
		case 1:
		registro(); //Chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("Essa op��o n�o est� disponivel.\n");
		system("pause");
		break;
		} //Fim da sele��o
	
	}
	
}
