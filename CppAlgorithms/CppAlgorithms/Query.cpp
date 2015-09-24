#include "TextQuery.h"
#include "Query.h"
#include <set>
using std::set; 
#include <algorithm>
using std::set_intersection; 
#include <iterator>
using std::inserter;

std::set<TextQuery::line_no> OrQuery::eval(const TextQuery &file) const {
	set<line_no> right = rhs.eval(file), ret_lines = lhs.eval(file); 
	ret_lines.insert(right.begin(), right.end()); 
	return ret_lines;
}

std::set<TextQuery::line_no> AndQuery::eval(const TextQuery &file) const {
	set<line_no> left = lhs.eval(file), right = rhs.eval(file);
	set<line_no> ret_lines; 
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(ret_lines, ret_lines.begin())); 
	ret_lines.insert(right.begin(), right.end());
	return ret_lines;
}

std::set<TextQuery::line_no> NotQuery::eval(const TextQuery &file) const {
	set<line_no> has_val = query.eval(file); 
	set<line_no> ret_lines;
	for (line_no n = 0; n != file.size(); ++n) {
		if (has_val.find(n) == has_val.end())
			ret_lines.insert(n); 
	}
	return ret_lines;
}
