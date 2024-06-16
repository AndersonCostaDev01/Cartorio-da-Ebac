#include <stdio.h > // Biblioteca de comunicação
#include <stdlib.h> // Biblioteca de alocação de espaços 
#include <locale.h> // Biblioteca de texto com acento
#include <string.h> // Biblioteca responsavel pelas strings
int registra()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Qual o CPF sera cadastrado: ");
	scanf("%s",cpf); // vai coletar o CPF e guardar na variavel cpf
	
	strcpy(arquivo, cpf); // Copia os dados da variavel cpf e cola na variavel arquivo
	
	FILE *file; // Cria o arquivo na pasta do programa
	file = fopen(arquivo, "w"); // Cria o arquivo 
	fprintf(file,cpf); // Salvo o valor da variavel cpf no arquivo criado
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização 
	fprintf(file, " Nome: "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização 
	fprintf(file,nome); // Escreve no arquivo o nome 
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização 
	fprintf(file, " "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização 
	fprintf(file,sobrenome); // Escreve no arquivo o sobrenomenome 
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização 
	fprintf(file, " Cargo: "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização
	fprintf(file,cargo); // Escreve no arquivo o sobrenome 
	fclose(file); // Fecha o arquivo
	
	system("pause");
}
int consultar()
{
	setlocale(LC_ALL, "portuguese"); // Colocar em portugues o texto escrito
	
	char cpf[40]; // Cria o conjunto de variavel responsavel por guardar o cpf 
	char conteudo[400]; // Cria o conjunto de variavel responsavel por guardar as informaço0es do cpf digitado
	
	printf("Qual o CPF sera consultado: ");
	scanf("%s", cpf);
	printf("\n\n");
	
	FILE *file; // Chama o arquivo
	file = fopen(cpf,"r"); // Abre o arquivo do cpf digitado
	
	if(file == NULL) // Informa caso um cpf não registrado seja informado
	{
		printf("Esse cpf não foi identificado em sistema, tente novamente!\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL); // Ira guarda as informaçoes no conteudo e ira printar em tela para o usuario
	{
		printf("Os dados do usuario são: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Pausa o sistema 
}
int deletar()
{
	char cpf[40]; // Cria o conjunto de variaveis que ira guardar o cpf
	
	printf("Qual o CPF do usuario sera deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Exclui o arquivo com de acrodo com o cpf informado
	
	FILE *file;
	file = fopen(cpf, "r"); // Le o arquivo do cpf informado
	
	if(file == NULL)  // Infroma que o arquivo foi deletadoo
	{
		printf("O usuario não existe mais em sistema\n\n");
	}
	
	system("pause"); // Pausa o sistema 
}
	
int main()
{
	int opcao = 0;
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //  Limpa a tela apos a escolha para evitar poluição visual 
		
		setlocale(LC_ALL, "portuguese"); // Colocar em portugues o texto escrito
	
		printf("** Cartório da EBAC **\n\n"); // Apresenta o nome do projeto
		printf("Qual a função desejada?\n\n"); // Solicita que o cliente escolha a oopção desejada que sera apresentada logo abaixo 
		printf("\t1 - Registrar Usuario\n");
		printf("\t2 - Consultar Usuario\n");
		printf("\t3 - Excluir Usuario\n\n");
		printf("Opção:");
	
		scanf("%d", &opcao); // Ira guarada a informação de qual menu voçe escolheu 
	
		system("cls"); //  Limpa a tela apos a escolha para evitar poluição visual 
		
		switch(opcao)
		{
			case 1: // faz a função caso a opção escolhida for a 1
			registra();
			break;
			
			case 2: // faz a função caso a opção escolhida for a 2
			consultar();
			break;
			
			case 3: // faz a função caso a opção escolhida for a 3
			deletar();
			break;
			
			default: // caso uma opção inexistente seja selecionada 
			printf("Essa opção não existe\n\n");
			system("pause");
			break;
		}
		printf("Esse softare e de uso livre do aluno Anderson Costa\n\n"); // Creditos do projeto 
	}
}
