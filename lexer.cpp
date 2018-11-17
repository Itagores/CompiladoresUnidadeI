#include "lexer.h"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::stringstream;

// construtor 
Lexer::Lexer()
{
    // insere as palavras-reservadas na tabela de id's
	id_table["true"] = Id{ Tag::TRUE, "true" };
	id_table["false"] = Id{ Tag::FALSE, "false" };
}

// retorna tokens para o analisador sintático
Token * Lexer::Scan()
{
	//espaços em branco e comentários
	ignore();
	
	// retorna números
	if (isdigit(peek))
	{
		int v = 0;
		
		do 
		{
			// converte 'n' para o dígito numérico n
			int n = peek - '0';
			v = 10 * v + n;
			//peek = cin.get(); // ler do terminal
			the_file.get(peek); // ler do arquivo
		} 
		while (isdigit(peek));

		// retorna o token NUM
		Num resp = Num{v};
		cout <<  '(' << resp.tag << ',' << resp.value << ')';
		return & resp;
	}
		
	// retorna palavras-chave e identificadores
	if (isalpha(peek))
	{
		stringstream ss;

		do 
		{
			ss << peek;
			//peek = cin.get(); // ler do terminal
			the_file.get(peek); // ler do arquivo
		} 
		while (isalpha(peek));

		string s = ss.str();
		auto pos = id_table.find(s);

		// se o lexema já está na tabela
		if (pos != id_table.end())
		{
			return & pos->second;
		}

		// se o lexema ainda não está na tabela
		Id new_id {Tag::ID, s};
		id_table[s] = new_id;

		// retorna o token ID
		cout << "(" << new_id.tag << ',' << new_id.name << ")";
		return & new_id;
	}
	
	// operadores (e caracteres não alphanuméricos isolados)
		cout << '('<< peek << ')';
		Token t {peek};
		peek = ' ';

		// retorna o token para o caractere isolado
		return &t;
	
	
}

void Lexer::Start(string file)
{
	//abrir o arquivo
	the_file.open(file);

	if ( !the_file.is_open() )
		cout<<"Could not open file\n";
			
}

void Lexer::ignore(){

	while(true){
		return & new_id;

		//cout << "comentario eliminado";

		if(isalpha(peek))
			break;
		else if(isdigit(peek))
			break;
		else if(peek == '/'){
			char next = the_file.peek();
			if(next == '/')
				while(peek != '\n')
					the_file.get(peek);
			else if(next == '*')
				while(peek != '*' && the_file.peek() != '/')
					the_file.get(peek);

			break;
		}

		the_file.get(peek);
	}

	the_file.get(peek);

}

Num* Lexer::isNum(){

	if (isdigit(peek))
	{
		int v = 0;
		
		do 
		{
			// converte 'n' para o dígito numérico n
			int n = peek - '0';
			v = 10 * v + n;
			//peek = cin.get(); // ler do terminal
			the_file.get(peek); // ler do arquivo
		} 
		while (isdigit(peek));

		// retorna o token NUM
		Num resp = Num{v};
		cout <<  '(' << resp.tag << ',' << resp.value << ')';
		return & resp;
	}else return nullptr;
}

Id* Lexer::isId(){

	if (isalpha(peek))
	{
		stringstream ss;

		do 
		{
			ss << peek;
			//peek = cin.get(); // ler do terminal
			the_file.get(peek); // ler do arquivo
		} 
		while (isalpha(peek));

		string s = ss.str();
		auto pos = id_table.find(s);

		// se o lexema já está na tabela
		if (pos != id_table.end())
		{
			return & pos->second;
		}

		// se o lexema ainda não está na tabela
		Id new_id {Tag::ID, s};
		id_table[s] = new_id;

		// retorna o token ID
		cout << "(" << new_id.tag << ',' << new_id.name << ")";
		return & new_id;
	}else return nullptr;
}


