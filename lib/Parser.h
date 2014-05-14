#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include "Nonterminal.h"
#include "Token.h"
#include "Node.h"

using namespace std;

#ifndef PARSER_H 
#define PARSER_H

class Parser{
	
	public:
		Parser(char* input_path);
		~Parser();
		void inputGrammar(char* input_path);
		void startParsing(vector<Token*> tokens);

	private:
		vector<Nonterminal*> non_terminals;
		map <string, vector<list<string> > > grammar;
		map <string, Nonterminal*> non_terminals_map;
		map <string, map<string, int> > parsingTable;	
		multimap <int, Node*> parsingTree;

		bool nullable(string non_terminal);
		set<string> first(string non_terminal);
		void follow();
		void createParsingTree(vector<Token*> tokens);

		int findTable(string& non_terminal, Token& token);
		bool isTerminal(string term);
		void outputSet();
		void outputParingTable();
		void outputParingTree();
};

#endif
