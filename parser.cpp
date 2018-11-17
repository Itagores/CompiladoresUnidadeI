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
}

void Parser::Match(char t)
{
	if (t == lookahead)
		lookahead = cin.get();
	else
		throw SyntaxError{};
}*/

Parser::Parser()
{
	lookahead = nullptr; 
} 

void Parser::program(){
	lookahead = lexer.Scan();
	//cout << "(" << lookahead->tag << ")";

}
void Parser::block(){

}

void Parser::decls(){

}
void Parser::decl(){

}
void Parser::stmts(){

}
void Parser::stmt(){

}
void Parser::expr(){

}
void Parser::term(){

}
void Parser::factor(){

}
void Parser::match(int tag){
	
}

void Parser::Start(string file)
{
	//abrir o arquivo
	lexer.Start(file);

	program();

}