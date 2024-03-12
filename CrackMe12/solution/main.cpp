#include <iostream>
#include <random>
#include <string>
#include <sstream>
int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);
	std::stringstream ss;
	for (int i = 0; i < 10; ++i) {
		if (i < 4) {
			ss << dist(rng);
		}
		else if(i > 4 && i < 9) {
			while(true)
			{
				int n = dist(rng);
				if ((n & 1) == 0) {
					ss << n;
					break;
				}
			}	
		}
		else if (i == 4 || i == 9) {
			ss << "-";
			continue;
		}
	}
	ss << "R3KT";
	std::cout << ss.str();
}