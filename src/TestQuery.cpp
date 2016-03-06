#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "TextQuery.h"

using namespace std; 

ifstream& open_file(ifstream &in, char *file);
void print_results(const set<TextQuery::line_no>&, const string&, const TextQuery&); 

int textQuery(int argc, char **argv)
//int main(int argc, char **argv)
{
	ifstream infile;
	cout << argc << endl;
	cout << argv[1] << endl;
	if (argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file! " << endl;
		return EXIT_FAILURE;
	}

	TextQuery tq;
	tq.read_file(infile);
	while (true) {
		cout << "Enter word to look for, or q to exit: " << endl;
		string s;
		cin >> s;
		if (!cin || s == "q") break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}

	return 0;
}
