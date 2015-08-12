#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout; 
using std::endl; 
using std::vector;
using std::string; 
using std::find; 

int collectionErase()
{
	string str_arr[] = {"a", "b", "c", "d"}; 
	vector<string> svec(str_arr, str_arr + sizeof str_arr / sizeof *str_arr); 

	string delStart("b"), delEnd("c");
	vector<string>::iterator b = find(svec.begin(), svec.end(), delStart); 
	vector<string>::iterator e = find(svec.begin(), svec.end(), delEnd);

	cout << *svec.erase(b, e) << endl; 

	for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end(); ++iter) {
		cout << *iter << endl; 
	}

	return 0; 
}
