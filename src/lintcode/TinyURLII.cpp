/*
 * [Source] http://www.lintcode.com/en/problem/tiny-url-ii/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace {
    const string serials("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const int base = serials.size();
    const string prefix("http://tiny.url/");
    const int offset = prefix.length();
}

// [Corner Case]:
// [Solution]: Use id-longURL pair to store mapping. id use 62 base to convert to short URL
class TinyUrl2 {
public:
    /**
     * @param long_url a long url
     * @param a short key
     * @return a short url starts with http://tiny.url/
     */
    string createCustom(string long_url, string short_key) {
        long long existId = findLongURLId_(long_url);
        long long id = shortURLToId_(short_key);

        if (existId != -1 && existId != id) // long_url already exist but map to another shortURL
            return "error";

        if (urlMap_.find(id) != urlMap_.end()) {
            if (urlMap_[id] == long_url)
                return prefix + short_key;
            else
                return "error";
        }

        urlMap_[id] = long_url;
        return prefix + short_key;
    }

    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string long_url) {
        long long id = findLongURLId_(long_url);

        if (id == -1) { // not exist
            while (urlMap_.find(lastId_) != urlMap_.end())
                ++lastId_;

            id = lastId_;
            urlMap_[lastId_++] = long_url;
        }

        return prefix + idToShortURL_(id);
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(string short_url) {
        string shortURL = short_url.substr(offset);
        long long id = shortURLToId_(shortURL);
        if (urlMap_.find(id) == urlMap_.end())
            return "";
        return urlMap_[id];
    }

private:
    string idToShortURL_(long long id) {
        vector<char> shortURLArr;
        while (id > 0) {
            char cur = serials[id % base];
            shortURLArr.push_back(cur);
            id /= base;
        }
        while (shortURLArr.size() < 6) {
            shortURLArr.push_back(serials[0]);
        }

        return string(shortURLArr.rbegin(), shortURLArr.rend());
    }

    long long shortURLToId_(const string& shortURL) {
        long long id = 0;
        for (const char& c : shortURL) {
            id = base * id + serials.find(c);
        }
        return id;
    }

    long long findLongURLId_(const string& long_url) {
        long long id = -1;
        for (auto it = urlMap_.begin(); it != urlMap_.end(); ++it) {
            if (it->second == long_url) {
                id = it->first;
                break;
            }
        }
        return id;
    }

private:
    long long lastId_ = 1000;
    unordered_map<long long, string> urlMap_;
};

// [Solution]:

int main() {

    TinyUrl2 ty;

    
    vector<string> urls = {"http://www.lintcode.com/faq/?id=10"};
    for (string& url : urls) {
        string shortUrl = ty.longToShort(url);
        string longUrl = ty.shortToLong(shortUrl);
        cout << longUrl << " " << shortUrl << endl;
        if (longUrl != url)
            cout << "FAIL" << endl;
    }
    string long_url("http://www.lintcode.com/"), short_key("lccode");
    string shortUrl = ty.createCustom(long_url, short_key);
    string longUrl = ty.shortToLong(shortUrl);
    cout << longUrl << " " << shortUrl << endl;
    if (longUrl != long_url)
        cout << "FAIL" << endl;
    string shortUrl2 = ty.longToShort(long_url);
    cout << longUrl << " " << shortUrl2 << endl;
    if (shortUrl2 != shortUrl)
        cout << "FAIL" << endl;
    

    cout << ty.createCustom("http://www.lintcode.com/p1", "000001") << endl;
    ty.createCustom("http://www.lintcode.com/p2", "000002");
    ty.createCustom("http://www.lintcode.com/p3", "000003");
    ty.createCustom("http://www.lintcode.com/p4", "000004");
    ty.longToShort("http://www.lintcode.com/problem/");
    ty.shortToLong("http://tiny.url/000002");
    ty.shortToLong("http://tiny.url/000004");
    ty.createCustom("http://www.facebook.com", "facebook");
    ty.createCustom("http://www.facebook.com", "facebook");
    ty.createCustom("http://www.google.com", "google");
    ty.createCustom("http://www.lintcode.com", "lc");
    ty.shortToLong("http://tiny.url/lc");
    ty.shortToLong("http://tiny.url/google");
    ty.createCustom("http://www.google.com", "google");
    ty.shortToLong("http://tiny.url/facebook");
    ty.longToShort("http://www.lintcode.com");
    ty.longToShort("http://www.google.com");
    ty.longToShort("http://www.facebook.com");
    return 0;
}
