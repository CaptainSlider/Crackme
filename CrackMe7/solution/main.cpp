#include <iostream>
#include <random>
#include <string>
#include <sstream>
int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 150);
	char ss[8] = "******\n";
	std::string s = "\"3 \"*,$";
	while (true) {
	loop1:
		int num = dist(rng);
		for (int i = 0; i < 7; ++i) {
			if ((num ^ s[i]) > 96 && (num ^ s[i]) < 122) {
				ss[i] = char((num ^ s[i]));
			}
			else {
				goto loop1;
			}
		}
		std::cout << ss;
		std::cout << "\t" << num << std::endl;
	}
	
}