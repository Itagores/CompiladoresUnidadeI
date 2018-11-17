#include <string>
#include "lexer.h"
using std::string;

class SyntaxError {};
class FileError {};

class Parser
{
private:
	//char lookahead;
	Lexer lexer;
	Token * lookahead;

	void program();
	void block();
	void decls();
	void decl();
	void stmts();
	void stmt();
	void expr();
	void term();
	void factor();
	void match(int tag);
		
	//void Expr();
	//void Term();
	//void Match(char t);

public:
	Parser();
	void Start(string file);
};
