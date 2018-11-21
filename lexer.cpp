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
	id_table["expression"] = Id{ Tag::EXPRESSION, "expression"};
	id_table["float"] = Id{Tag::FLOAT, "expression"};
	id_table["int"] = Id{Tag::INT, "int"};
}

// retorna tokens para o analisador sintático
Token * Lexer::Scan()
{
	//se final do arquivo
	if(the_file.eof())
		return nullptr; 

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
		TRepository.n = Num{v};
		return & TRepository.n;
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
			//cout << pos->second.name;
			TRepository.i = pos->second;
			return & TRepository.i;
		}

		// se o lexema ainda não está na tabela
		stringstream name;
		//ignora espaços ate encontrar o nome da variável
		while(isspace(peek))
			the_file.get(peek);
		
		//pega o nome da variável
		while(!isspace(peek) && peek != ';'){
			name << peek;
			the_file.get(peek);
		}
		string sname = name.str();
		//cout << "S: "<<sname;

		// retorna o token ID
		if(s.compare("int")){
			Id new_id {Tag::INT, sname};
			id_table[sname] = new_id;
			TRepository.i = new_id;
			return & TRepository.i;
		}else if(s.compare("float")){
			Id new_id {Tag::FLOAT, sname};
			id_table[sname] = new_id;
			TRepository.i = new_id;
			return & TRepository.i;
		}

		
	}
	
	// operadores (e caracteres não alphanuméricos isolados)
	//cout << '('<< peek << ')';
	Token t {peek};
	TRepository.t = t;
	peek = ' ';

	// retorna o token para o caractere isolado
	return & TRepository.t;
	
	
}

void Lexer::Start(string file)
{
	//abrir o arquivo
	the_file.open(file);

	if ( !the_file.is_open() )
		cout<<"Could not open file\n";
			
}

void Lexer::ignore(){

	
	while(isspace(peek)){
		the_file.get(peek);
	}

	while(true){

		if(peek == '{')
			return;

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


