#include <stdio.h > // Biblioteca de comunica��o
#include <stdlib.h> // Biblioteca de aloca��o de espa�os 
#include <locale.h> // Biblioteca de texto com acento
#include <string.h> // Biblioteca responsavel pelas strings
int registra()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int retornos = 0;
	
	printf("Qual o CPF sera cadastrado: ");
	scanf("%s",cpf); // vai coletar o CPF e guardar na variavel cpf
	
	strcpy(arquivo, cpf); // Copia os dados da variavel cpf e cola na variavel arquivo
	
	FILE *file; // Cria o arquivo na pasta do programa
	file = fopen(arquivo, "w"); // Cria o arquivo 
	fprintf(file,cpf); // Salvo o valor da variavel cpf no arquivo criado
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o 
	fprintf(file, " Nome: "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o 
	fprintf(file,nome); // Escreve no arquivo o nome 
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o 
	fprintf(file, " "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o 
	fprintf(file,sobrenome); // Escreve no arquivo o sobrenomenome 
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o 
	fprintf(file, " Cargo: "); // Escreve no arquivo 
	fclose(file); // Fecha o arquivo 
	
	printf("Qual o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o
	fprintf(file,cargo); // Escreve no arquivo o sobrenome 
	fclose(file); // Fecha o arquivo
	
	printf("\n\nDeseja retornar para o menu?\n");
	printf("\t1 para sim\n");
	printf("\t2 para nao\n");
	scanf("%d",&retornos); // coleta a informa��o se o usuario deseja retorna para o menu
	
	switch(retornos) // executa de acordo com a vontade do cliente o retorno para o menu ou iniciar novamente a fun��o
	{
		case 1: //  retorna ao menu
		main();
		break;
		
		case 2: // limpa a tela e retorna para a funa��o
		system("cls"); //  Limpa a tela apos a escolha para evitar polui��o visual 
		registra();
	}
	
	main();
}
int consultar()
{
	setlocale(LC_ALL, "portuguese"); // Colocar em portugues o texto escrito
	
	char cpf[40]; // Cria o conjunto de variavel responsavel por guardar o cpf 
	char conteudo[400]; // Cria o conjunto de variavel responsavel por guardar as informa�o0es do cpf digitado
	int retornos = 0; // Variavel para retorno ao menu
	
	printf("Qual o CPF sera consultado: ");
	scanf("%s", cpf);
	printf("\n\n");
	
	FILE *file; // Chama o arquivo
	file = fopen(cpf,"r"); // Abre o arquivo do cpf digitado
	
	if(file == NULL) // Informa caso um cpf n�o registrado seja informado
	{
		printf("Esse cpf n�o foi identificado em sistema, tente novamente!\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL); // Ira guarda as informa�oes no conteudo e ira printar em tela para o usuario
	{
		printf("Os dados do usuario s�o: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		printf("\n\nDeseja retornar para o menu?\n");
	printf("\t1 para sim\n");
	printf("\t2 para nao\n");
	scanf("%d",&retornos); // coleta a informa��o se o usuario deseja retorna para o menu
	
	switch(retornos) // executa de acordo com a vontade do cliente o retorno para o menu ou iniciar novamente a fun��o
	{
		case 1: //  retorna ao menu
		main();
		break;
		
		case 2: // limpa a tela e retorna para a funa��o
		system("cls"); //  Limpa a tela apos a escolha para evitar polui��o visual 
		consultar();
	}
	
	
}
int deletar()
{
	char cpf[40]; // Cria o conjunto de variaveis que ira guardar o cpf
	int retornos = 0; // Variavel para retorno no menu
	
	printf("Qual o CPF do usuario sera deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Exclui o arquivo com de acrodo com o cpf informado
	
	FILE *file;
	file = fopen(cpf, "r"); // Le o arquivo do cpf informado
	
	if(file == NULL)  // Infroma que o arquivo foi deletadoo
	{
		printf("O usuario n�o existe mais em sistema\n\n");
	}
	
		printf("\n\nDeseja retornar para o menu?\n");
	printf("\t1 para sim\n");
	printf("\t2 para nao\n");
	scanf("%d",&retornos); // coleta a informa��o se o usuario deseja retorna para o menu
	
	switch(retornos) // executa de acordo com a vontade do cliente o retorno para o menu ou iniciar novamente a fun��o
	{
		case 1: //  retorna ao menu
		main();
		break;
		
		case 2: // limpa a tela e retorna para a funa��o
		system("cls"); //  Limpa a tela apos a escolha para evitar polui��o visual 
		deletar();
	}
}
	
int main()
{
	int opcao = 0;
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //  Limpa a tela apos a escolha para evitar polui��o visual 
		
		setlocale(LC_ALL, "portuguese"); // Colocar em portugues o texto escrito
	
		printf("** Cart�rio da EBAC **\n\n"); // Apresenta o nome do projeto
		printf("Qual a fun��o desejada?\n\n"); // Solicita que o cliente escolha a oop��o desejada que sera apresentada logo abaixo 
		printf("\t1 - Registrar Usuario\n");
		printf("\t2 - Consultar Usuario\n");
		printf("\t3 - Excluir Usuario\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");
	
		scanf("%d", &opcao); // Ira guarada a informa��o de qual menu vo�e escolheu 
	
		system("cls"); //  Limpa a tela apos a escolha para evitar polui��o visual 
		
		switch(opcao)
		{
			case 1: // faz a fun��o caso a op��o escolhida for a 1
			registra();
			break;
			
			case 2: // faz a fun��o caso a op��o escolhida for a 2
			consultar();
			break;
			
			case 3: // faz a fun��o caso a op��o escolhida for a 3
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o cartorio da ebac\n");
			printf("Projeto desenvolvido por Anderson Costa");
			return 0;
			
			default: // caso uma op��o inexistente seja selecionada 
			printf("Essa op��o n�o existe\n\n");
			system("pause");
			break;
		}
		printf("Esse softare e de uso livre do aluno Anderson Costa\n\n"); // Creditos do projeto 
	}
}
