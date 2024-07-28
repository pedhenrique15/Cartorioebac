#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o  de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar da string

int registro() // funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao = 0;
	int laco = 1;
	//final da criacao de variaveis 
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string (para salvar a string)
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // Acessar a fun�ao FILE que vai receber file
	file = fopen(arquivo, "w"); // cria o arquivo e "w" � pra criar uma nova
	fprintf(file, cpf);// salvo o valor da variavel 
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" � pra atualizar 
	fprintf(file, ",");
	fclose(file);
	
	printf("Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
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
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
	while (laco == 1) 
	{
        system("cls");
        
        printf("Deseja fazer um novo registro?\n\n");
        printf("1- Fazer novo registro\n");
        printf("2- Voltar ao menu principal\n\n");
        scanf("%d", &opcao);
        
        
        switch (opcao) 
		{
            case 1:
                registro();
                break;
            case 2:
                return 0;
                break;
            default:
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
        }
    }
    
    return 0;
	

}

int consulta()
{
	setlocale(LC_ALL,"Portuguese_Brazil.1252"); // definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abre o arquivo e "r" � para ler o arquivo
	
	if(file == NULL) // verificando se o cpf digitado existe no banco de dados 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fgets(buscar no arquivo) enquanto o conteudo no file nao for NULL, vai continuar procurando.
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
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
		

}


int main()
{
	int opcao = 0; // definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL,"Portuguese_Brazil.1252"); // definindo a linguagem 
	
		printf("### Cart�rio da EBAC ### \n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls"); // responsavel por limpar a tela
		
		
		switch(opcao) //inicio da selecao
		{
			case 1:
			registro(); // chamada de funcoes
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} //fim da selecao 
		
	}
	
}
