#include "parser.h"
#include "string.h"
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

/*void Parser::Expr()
{
	// expr -> term oper
	Term();
	while (true)
	{
		// oper -> + term { print(+) } oper
		if (lookahead == '+')
		{
			Match('+');
			Term();
			cout << '+';
		}
		// oper -> - term { print(-) } oper
		else if (lookahead == '-')
		{
			Match('-');
			Term();
			cout << '-';
		}
		// produção vazia
		else return; 
	}
}

void Parser::Term()
{
	if (isdigit(lookahead))
	{
		cout << lookahead;
		Match(lookahead);
	}
	else
		throw SyntaxError{};
}*/

void Parser::match(char t)
{
	if (t == lookahead->tag)
		lookahead = lexer.Scan();
		//lookahead = cin.get();
	else
		throw SyntaxError{};
}

Parser::Parser()
{
	lookahead = nullptr; 
} 

void Parser::program(){
	lookahead = lexer.Scan();
	Id * id = (Id*)lookahead;
	cout << "(" << id->tag << "," << id->name << ")";
	lookahead = lexer.Scan();
	block();

}
void Parser::block(){
	//lookahead = lexer.Scan();
	//match '{'
	if (lookahead->tag == '{'){
		cout << '{';
		decls();
		stmts();

		lookahead = lexer.Scan();
		//match '}'
		if (lookahead->tag == '}'){
			cout << '}';
		}else throw SyntaxError{};
	}	
}

void Parser::decls(){
	lookahead = lexer.Scan();
	while(lookahead->tag == Tag::INT || lookahead->tag == Tag::FLOAT)
		decl();

}
void Parser::decl(){
	Id * id = (Id*)lookahead;
	cout << "(" << id->tag << "," << id->name << ")";
	lookahead = lexer.Scan();

}
void Parser::stmts(){
	stmt();
}
void Parser::stmt(){
	// se não houver {} o função block não fará nada
	block();
	cout << "aqui!";
	expr();
}
void Parser::expr(){
	term();
	while (true)
	{
		// oper -> + term { print(+) } oper
		if (lookahead->tag == '+')
		{
			match('+');
			term();
			cout << '+';
		}
		// oper -> - term { print(-) } oper
		else if (lookahead->tag == '-')
		{
			match('-');
			term();
			cout << '-';
		}
		// produção vazia
		else return; 
	}
}
void Parser::term(){
	factor();
	while (true)
	{
		// oper -> + term { print(+) } oper
		if (lookahead->tag == '*')
		{
			match('*');
			factor();
			cout << '*';
		}
		// oper -> - term { print(-) } oper
		else if (lookahead->tag == '/')
		{
			match('/');
			factor();
			cout << '/';
		}
		// produção vazia
		else return; 
	}
}
void Parser::factor(){
	//Token * lookahead = lexer.Scan();
	
	switch (lookahead->tag)
	{
		case Tag::FLOAT:{
			Num * n  = (Num *) lookahead;
			cout << "(" << n->tag << ',' << n->value << ")";
			break;
		}
		case Tag::INT:{
			Num * n  = (Num *) lookahead;
			cout << "(" << n->tag << ',' << n->value << ")";
			break;
		}
			
		default:
			cout << lookahead->tag;
			break;
	}
}
void Parser::match(int tag){
	/*if (tag == lookahead)
		lookahead = cin.get();
	else
		throw SyntaxError{};*/
}

void Parser::Start(string file)
{
	//abrir o arquivo
	lexer.Start(file);

	program();

}