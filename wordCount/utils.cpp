#include <iostream>
#include <fstream>
#include <string>
#include "utils.hpp"

static void check_stream(std::ifstream& in) {
    if (!in.is_open()) {
        std::cerr << "\x1B[91mUnable to open file\033[0m\n";
        return;
    }
}

int count_lines(const std::string& file) {
    std::ifstream in(file);
    check_stream(in);

    std::string line;
    int lines_count = 0;

    while (getline(in, line)) {
        lines_count++;
    }

    in.close();
    return lines_count;
}
long count_bytes(const std::string& file) {
    std::ifstream in(file, std::ifstream::ate | std::ifstream::binary);
    check_stream(in);

    long size = in.tellg();
    in.close();

    return size;
}
int count_words(const std::string& file) {
    std::ifstream in(file);
    check_stream(in);

    int words = 0;
    std::string word;

    while (in >> word) {
        words++;
    }

    in.close();
    return words;
}
int count_chars(const std::string& file) {
    std::ifstream in(file);
    check_stream(in);

    int chars = 0;
    char symbol;

    while (in.get(symbol)) {
        chars++;
    }

    in.close();
    return chars;
}