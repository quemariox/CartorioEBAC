#include <stdio.h> 	//biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registo(){ //função responsável por cadastrar usuários no sistema
	
	//início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: \n"); //coleta informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //copia o valor da string cpf para a string arquivo
	
	FILE *file; //chama a função interna FILE para lidar com arquivos 
	file = fopen(arquivo,"w"); //abre o file "arquivo" e escreva nele
	fprintf(file,cpf); //escreve no arquivo file "arquivo" a string "cpf"
	fclose(file); //fecha o file "arquivo"
	
	file = fopen(arquivo,"a"); //abre novamente o mesmo file "arquivo" para adicionar elementos no final "a". Se fosse adicionar no inicio ceria "p"
	fprintf(file,","); //escreve uma vírgula no file "arquivo"
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); // abre novamente o mesmo arquivo para atualizá-lo
	fprintf(file,","); // escreve uma vírgula nele
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //abre novamente o mesmo arquivo para atualizá-lo
	fprintf(file,","); //escreve uma vírgula nele
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){ //função responsável por consultar usuários no sistema
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // chama a função que consulta arquivos
	file = fopen(cpf,"r"); // abre o arquivo de nome igual ao conteúdo de "cpf" e lê o mesmo 
	
	if(file == NULL){ // se o arquivo de nome igual ao conteúdo de "cpf" não for encontrado
		printf("Não foi possível abrir o arquivo, usuário não localizado! \n"); // exibe a mensagem de erro
		printf("\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //fgets vai buscar o conteudo do arquivo
		// salva na variavel "conteudo" os 200 caracteres que estão dentro do arquivo
		// até encontrar um caractere nulo
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo); // salva o conteudo que estava dentro da strin
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){ //função responsável por deletar usuários no sistema
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("O usuário não se encontra no sistema! \n");
		system("pause");	
	}
	
}
				
int main (){ //função principal do programa

	int opcao=0; // Define variáveis
	int laco=1;
	
	for(laco=1;laco=1;){
		
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); // Define o idioma
	
	printf("### Cartório da EBAC ### \n \n");	// inicio do menu
	printf("Escolha a opção desejada no menu: \n \n"); 
	printf("\t 1 - Registrar nomes \n"); 
	printf("\t 2 - Consultar nomes \n");
	printf("\t 3 - Deletar nomes \n \n");
	printf("Opção:"); // fim do menu
	
	scanf("%d", &opcao); // armazena o valor digitado na variável "opcao"
	
	system("cls"); // faz o sistema para limpar a tela
	
	switch (opcao){
	
		case 1:
		registo();
		break;
		
		case 2:
		consulta();
		break; 
		
		case 3:
		deletar(); 
		break;
		
		default:
		printf("Essa opção não está disponível.\n");
		system("pause");
		break;		
}
		
}
}


