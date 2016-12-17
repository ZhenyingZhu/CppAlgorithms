/*
 * [Source] https://leetcode.com/problems/read-n-characters-given-read4/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

vector<char> buff;

int read4(char *buf) {
    int cnt = 0;
    for (; cnt < 4; ++cnt) {
        if (buf[cnt] == '\0')
            break; // Mock an EOF

        buff.push_back(buf[cnt]);
    }
    return cnt;
}

// [Solution]: The question is asking how many times we should call the read4 func to load chars into a buff. The return value is to split the buff with the right length.
// [Corner Case]:
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int readCnt = 0;
        while (readCnt < n) {
            int chars = min(read4(buf), n - readCnt);
            readCnt += chars;
            buf += chars;
            if (chars < 4)
                break;
        }
        return readCnt;
    }
};

int main() {
    Solution sol;

    char stream[] = "abcdef";
    int len = sol.read(stream, 5);
    cout << string(buff.begin(), buff.begin() + len) << endl;

    return 0;
}
