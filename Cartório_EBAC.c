#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Função por cadastrar os usuários no sistema
{
	//Inicio das criações das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das criações das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coleta de informações do usuário
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo, "w"); //cria o arqivo e "w" de "Write" para escrever o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, ","); //Logo após a resposta do usuario ele adicionará uma ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abrir o arquivo e atualiza-lo com nova instrução
	fprintf(file,nome); //Escrever o que foi escrito da variável do nome dentro do arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo e atualiza-lo com nova instrução
	fprintf(file, ","); //Colocar "," na última letra 
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
		printf("\nNão foi possível encontrar esses dados.\n\n");
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
	
	if (file == NULL)
	{
		printf("Usuário apagado ou inexistente. \n");
		system("pause");
	}
	
	
}

int main() 
{
	int opcao=0; //Variaveis
	int laco=1;
	
	for(laco=1;laco=1;) //Repetição
	{
	
	system("cls"); //Limpa a tela após ser executado
	
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
	printf("S2 S2 Cartório da EBAC S2 S2 \n\n"); //Inicio do menu
	printf("Escolha a opção desejada no menu:\n\n");
	printf("\t1 - Registrar nome\n");
	printf("\t2 - Consultar nome\n");
	printf("\t3 - Excluir nome\n\n"); //final do menu
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: ");
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls"); //limpar tela após selecionar a opção
	
	switch(opcao) //Seleção de opção
	{
		case 1:
		registro(); //Chamada de funções
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
		printf("Essa opção não está disponivel.\n");
		system("pause");
		break;
		} //Fim da seleção
	
	}
	
}
