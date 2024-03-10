#include <iostream>

char encrypt(char input, int shift) {
    if (input >= 'a' && input <= 'z')
        return ((input - 'a' + shift) % 26) + 'a';
    if (input >= 'A' && input <= 'Z')
        return ((input - 'A' + shift) % 26) + 'A';
    return input;
}

int main()
{
    char message[256];
    int shift;
    std::cin >> message;
    std::cin >> shift;
    int i;
    for (i = 0; i < strlen(message); i++) {
        std::cout << encrypt(message[i], shift);
    }
    std::cout << std::endl;
    return 0;
}