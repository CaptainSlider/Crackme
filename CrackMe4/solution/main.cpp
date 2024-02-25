#include <iostream>
#include <random>
#include <sstream>
#include <string>

int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);
	std::stringstream ss;
	ss << "t";
	for (int i = 1; i < 9; ++i) {
		if (i == 4) {
			ss << "-";
			continue;
		}
		ss << dist(rng);
	}
	std::cout << "Key: " << ss.str();
}