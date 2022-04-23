// Should use a map and "hash" it, but ...
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        tb.push_back(longUrl);
        return to_string(tb.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tb[stoi(shortUrl)];
    }
    
private:
    vector<string> tb;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
