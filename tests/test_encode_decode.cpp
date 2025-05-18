#include <cassert>
#include <string>

int decodeSquare(const std::string& square) {
    char letter = square[0];
    char digit = square[1];
    int one = letter - 'a' + 1;
    int ten = digit - '1' + 1;
    int index = 10 * ten + one;
    return index;
}

std::string encodeSquare(int square) {
    int ten = square / 10;
    int one = square - ten * 10;
    char letter = 'a' + one - 1;
    char number = '1' + ten - 1;
    std::string retVal;
    retVal += letter;
    retVal += number;
    return retVal;
}

int main() {
    assert(encodeSquare(decodeSquare("e2")) == "e2");
    return 0;
}
