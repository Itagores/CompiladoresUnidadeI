#include <unordered_map>
#include <string>
#include <fstream>
using std::unordered_map;
using std::string;
using std::ifstream;

// cada token deve possuir uma tag (número a partir de 256)
// a tag dos caracteres individuais é seu código ASCII
enum Tag { NUM = 256, ID, EXPRESSION,TRUE, FALSE };

// classes para representar tokens
struct Token
{
	int tag;
	Token(int t) : tag(t) {}
};

struct Num : public Token
{
	int value;
	Num(int v) : Token(Tag::NUM), value(v) {}
};

struct Id : public Token
{
	string name;
	Id(): Token(0) {}
	Id(int t, string s) : Token(t), name(s) {}
};


// analisador léxico
class Lexer
{
private:
	ifstream the_file;
	int  line = 1;
	char peek = ' ';
	unordered_map<string, Id> id_table;

public:
	Lexer();
	Token* Scan();
	void ignore();
	Num* isNum();
	Id* isId();
	void Start(string file);
};
