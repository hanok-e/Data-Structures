#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    std::vector<ull> tHash(t.size());
    std::vector<ull> pv(t.size());
    ull p = 53;
    ull currPow = p;
    ull mod = 1000000007;
    ull sHash = s[0] - 'A' + 1;
    for (int i = 1; i < s.size(); i++) {
        sHash = (sHash + (s[i] - 'A' + 1)*currPow) % mod;
        currPow = (currPow * p) % mod;
    }
    tHash[0] = t[0] - 'A' + 1;
    currPow = p;
    pv[0] = 1;
    for (int i = 1;i < t.size(); i++) {
        tHash[i] = (tHash[i-1] + (t[i] - 'A' + 1)*currPow) % mod;
        pv[i] = currPow;
        currPow = (currPow * p) % mod;
    }
    int i = 0;
    int j = s.size()-1;
    ull currHash;
    while (j < t.size()) {
        currHash = tHash[j];
        if (i > 0) {
            currHash = (currHash - tHash[i-1] + mod) % mod;
        }
        if (currHash == (sHash * pv[i]) % mod) {
            ans.push_back(i);
        }
        i++;
        j++;
    }
    /*
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)

            ans.push_back(i);
            */
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
