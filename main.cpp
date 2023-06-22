#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

int main() {
    vector<string> words = { "ring", "sleeping", "farmer", "true", "like", "another" };

    const char* path = R"(..\words.txt)";
    std::ifstream in;
    in.open(path);

    printf("%-10s: %s\n", "word", "count");
    printf("-------------------\n");

    for (const auto &word : words) {
        int numberOfFound = 0;

        while (!in.eof()) {
            string currentFromFile;

            // Считываем из файла по слову
            in >> currentFromFile;
            int result = word.compare(currentFromFile);
            if (result == 0) {
                ++numberOfFound;
            }
        }

        printf("%-10s: %s\n", word.c_str(), (numberOfFound ? std::to_string(numberOfFound).c_str() : "not found"));

        // Сбросить состояние потока и переместиться в начало файла
        in.clear();
        in.seekg(0, std::ios_base::beg);
    }

    in.close();
}
