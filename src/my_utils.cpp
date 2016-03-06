#include <fstream>

using namespace std; 

extern ifstream& open_file(ifstream &in, char *file) {
	in.close();
	in.clear();
	in.open(file);
	return in;
}

extern string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr == 1) ? word : word + ending;
}
