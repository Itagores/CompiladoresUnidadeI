#include <string>
#include <unordered_map>
using std::unordered_map;
using std :: string;

struct Symbol
{
    string name;
    string type;

};

class Env
{
private: 
   unordered_map<string, Symbol> table;
   Env prev;

public:
   Env(Env p);
   void put(string s, Symbol sym);
   Symbol get(string s);
};
