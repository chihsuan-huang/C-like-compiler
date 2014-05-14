#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#ifndef NONTERMINAL_H
#define NONTERMINAL_H

class Nonterminal{

	public:
		string term;
		bool nullable;
		set<string> first;
		set<string> follow;
		int production_nullable;
		

		Nonterminal(string term);	
		void insertFollow(set<string> const set);
		void insertFirst(set<string> const set);

	private:
};

#endif
