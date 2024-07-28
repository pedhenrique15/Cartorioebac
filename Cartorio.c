#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação  de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por região
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
	
	FILE *file; // Acessar a funçao FILE que vai receber file
	file = fopen(arquivo, "w"); // cria o arquivo e "w" é pra criar uma nova
	fprintf(file, cpf);// salvo o valor da variavel 
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" é pra atualizar 
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
                printf("Esta opção não está disponível!\n\n");
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
	file = fopen(cpf, "r"); // abre o arquivo e "r" é para ler o arquivo
	
	if(file == NULL) // verificando se o cpf digitado existe no banco de dados 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fgets(buscar no arquivo) enquanto o conteudo no file nao for NULL, vai continuar procurando.
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
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
	
		printf("### Cartório da EBAC ### \n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // fim do menu
	
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		} //fim da selecao 
		
	}
	
}
