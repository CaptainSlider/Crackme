#include <iostream>
#include <random>
#include <sstream>
#include <string>


int shl_key(std::string s);
int sum_key(std::string s, int first);
bool compation(std::string s, int first1, int first2);
std::string generatePartKey() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist9(0, 9);
    std::stringstream ss;
    for (int i = 0; i < 4; ++i) {
        ss << dist9(rng);
    }
    std::string s = ss.str();
    return s;
}
void GenerateAndCheckKey() {   
    while (true)
    {
        std::string s = generatePartKey() + '-' + generatePartKey() + '-' + generatePartKey() + '-' + generatePartKey();
        if (sum_key(s, 0) != shl_key(s) || sum_key(s, 5) != shl_key(s) || sum_key(s, 10) != shl_key(s) || sum_key(s, 15) != shl_key(s)) {
            std::cout << s << "\tWrong key\n";
            continue;
        }
        if (compation(s, 0, 5) && compation(s, 5, 10) && compation(s, 10, 15)) {
            std::cout << s << "\tRight key\n";
            return;
        }
    }
    
}
int shl_key(std::string s) {
    int part_1 = sum_key(s, 0);
    int part_2 = sum_key(s, 5);
    int part_3 = sum_key(s, 10);
    int part_4 = sum_key(s, 15);
    int sum = part_1 + part_2 + part_3 + part_4;
    return (sum >> 2);
}
bool compation(std::string s, int first1, int first2) {
    for (int i = 0; i < 4; ++i) {
        if (s[first1 + i] == s[first2 + i]) {
            return false;
        }
    }
}
int sum_key(std::string s, int first) {
    return int(s[first]) + int(s[first + 1]) + int(s[first + 2]) + int(s[first + 3]) + int(s[first + 3]) + int(s[first + 3]) + int(s[first + 3]) - 336;
}
int main() {
    GenerateAndCheckKey();
}