/*
 * [Source] http://www.lintcode.com/en/problem/gfs-client/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class BaseGFSClient {
private: map<string, string> chunk_list;
public:
    string readChunk(string& filename, int chunkIndex) {
        cout << "ReadChunk " << filename << " idx " << chunkIndex << endl;
        return "readChunk" + filename;
    }
    void writeChunk(string& filename, int chunkIndex,
                    string& content) {
        cout << "writeChunk " << filename << " idx " << chunkIndex << " content " << content << endl;
    }
 };

// [Corner Case]:
// [Solution]:
class GFSClient : public BaseGFSClient {
public:
    GFSClient(int chunkSize): chunkSize_(chunkSize) {
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string& filename) {
        if (fileSizes_.find(filename) == fileSizes_.end())
            return "";
        int size = fileSizes_[filename];
        string file = "";
        for (int i = 0; i < size; ++i) {
            file += readChunk(filename, i);
        }
        return file;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string& filename, string& content) {
        int len = content.length();
        int size = len / chunkSize_ + (len % chunkSize_ == 0 ? 0 : 1);
        for (int i = 0; i < size; ++i) {
            int st = i * chunkSize_;
            int partialLen = min(chunkSize_, len - st);
            string partialContent = content.substr(st, partialLen);
            writeChunk(filename, i, partialContent);
        }
    }

private:
    int chunkSize_;
    map<string, int> fileSizes_;
};

// [Solution]:

int main() {

    return 0;
}
