#include <stdio.h> 	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registo(){ //fun��o respons�vel por cadastrar usu�rios no sistema
	
	//in�cio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: \n"); //coleta informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //copia o valor da string cpf para a string arquivo
	
	FILE *file; //chama a fun��o interna FILE para lidar com arquivos 
	file = fopen(arquivo,"w"); //abre o file "arquivo" e escreva nele
	fprintf(file,cpf); //escreve no arquivo file "arquivo" a string "cpf"
	fclose(file); //fecha o file "arquivo"
	
	file = fopen(arquivo,"a"); //abre novamente o mesmo file "arquivo" para adicionar elementos no final "a". Se fosse adicionar no inicio ceria "p"
	fprintf(file,","); //escreve uma v�rgula no file "arquivo"
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); // abre novamente o mesmo arquivo para atualiz�-lo
	fprintf(file,","); // escreve uma v�rgula nele
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //abre novamente o mesmo arquivo para atualiz�-lo
	fprintf(file,","); //escreve uma v�rgula nele
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){ //fun��o respons�vel por consultar usu�rios no sistema
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // chama a fun��o que consulta arquivos
	file = fopen(cpf,"r"); // abre o arquivo de nome igual ao conte�do de "cpf" e l� o mesmo 
	
	if(file == NULL){ // se o arquivo de nome igual ao conte�do de "cpf" n�o for encontrado
		printf("N�o foi poss�vel abrir o arquivo, usu�rio n�o localizado! \n"); // exibe a mensagem de erro
		printf("\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //fgets vai buscar o conteudo do arquivo
		// salva na variavel "conteudo" os 200 caracteres que est�o dentro do arquivo
		// at� encontrar um caractere nulo
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo); // salva o conteudo que estava dentro da strin
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){ //fun��o respons�vel por deletar usu�rios no sistema
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");	
	}
	
}
				
int main (){ //fun��o principal do programa

	int opcao=0; // Define vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
		
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); // Define o idioma
	
	printf("### Cart�rio da EBAC ### \n \n");	// inicio do menu
	printf("Escolha a op��o desejada no menu: \n \n"); 
	printf("\t 1 - Registrar nomes \n"); 
	printf("\t 2 - Consultar nomes \n");
	printf("\t 3 - Deletar nomes \n \n");
	printf("Op��o:"); // fim do menu
	
	scanf("%d", &opcao); // armazena o valor digitado na vari�vel "opcao"
	
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
		printf("Essa op��o n�o est� dispon�vel.\n");
		system("pause");
		break;		
}
		
}
}


