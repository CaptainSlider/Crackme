#include <iostream>
#include <random>
#include <string>
#include <sstream>
int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1500);
	char ss[13] = "***********\n";
	std::string s = "Nkrru&Ngiqkxy";
	while (true) {
	loop1:
		int num = dist(rng);
		for (int i = 0; i < 12; ++i) {
			if ((s[i] - num) > 31 && (s[i] - num) < 122 ) {
				ss[i] = char(s[i] - num);
			}
			else {
				goto loop1;
			}
		}
		std::cout << ss;
		std::cout << "\t" << num << std::endl;
	}

}