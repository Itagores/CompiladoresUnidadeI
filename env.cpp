#include "env.h"
#include <unordered_map>
using std::unordered_map;

Env::Env(Env p) {
    prev = p; 
}

void Env::put(string s, Symbol sym){
    table.put(s, sym);
}

Symbol Env::get(string s) 
{
    for (Env e = this; e != nullptr; e = e.prev) 
    {
        Symbol found = e.table.get(s);
        if (found != null) return found;
    }
    return null;
}