#include <iostream>

int main() {
	std::string s;
	std::cout << "Enter Name";
	std::cin >> s;
	int n = 0;
	for (int i = 0; i < s.length(); ++i) {
		n += (int)s[i];
	}
	std::cout << n;
	
}
