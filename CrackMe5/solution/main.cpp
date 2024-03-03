#include <iostream>
#include <random>
#include <string>
#include <sstream>
int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);
	std::stringstream ss;
	ss << "A";
	for (int i = 0; i < 10; ++i) {
		if (i == 2 || i == 6) {
			ss << "-";
			continue;
		}
		ss << dist(rng);
	}
	std::cout << ss.str();
}