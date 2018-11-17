#include <iostream>
#include<string.h>
#include <fstream>
#include "parser.h"
using namespace std;

int main(int argc, char* argv[]){

	
	if(argc == 2){ // garantia que será passado o número certo de arguentos

		if(strcmp(argv[1],"--help") == 0){
			//fazer descrição do help
			cout << "uso: ./tradutor [FILE]\n"
				<< "Faz a tradução do conteudo de [FILE] \n"
				<< "o conteúdo do [FILE] deve obedecer as regas de produção da gramatica indicada no trabalho \n"
				<< "a tradução ocorrerar da notação infixa para a pos-fixa \n\n"
				<< "Exit status: \n"
				<< "0 se OK, \n"
				<< "1 se existir algum problemas ao abrir o arquivo indicado, \n"
				<< "2 se existir algum problema de sintaxe. \n\n";

			return 0;	
		}else{// se o argumento é teoricamente o arquivo

			Parser tradutor;
				try
				{
					tradutor.Start(argv[1]);
				}
				catch (SyntaxError)
				{
					cout << "^\n";
					cout << "Erro de Sintaxe";
					return 2;
				}
				cout << endl;

			/*ifstream the_file ( argv[1] );
			if ( !the_file.is_open() ){
				cout<<"Could not open file\n";
				return 1;
			}
			else {// iniciar tradução aqui
				char x;
		
				while ( the_file.get ( x ) )
					cout<< x;

				Parser tradutor;
				try
				{
					tradutor.Start(argv[1]);
				}
				catch (SyntaxError)
				{
					cout << "^\n";
					cout << "Erro de Sintaxe";
				}
				cout << endl;
			}
			the_file.close(); */
		}

	}else{
		cout << "Argumentos invalidos \n";
	}

	return 0;
	
}
