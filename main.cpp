#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

int main() {
    vector<string> list = { "ring", "sleeping", "farmer", "true", "like", "another" };

    const char* path = R"(..\lexicon.txt)";
    std::ifstream glossary;
    glossary.open(path);

    printf("%-10s: %s\n", "string", "count");
    printf("-------------------\n");

    for (const auto &item : list) {
        int numberOfFound = 0;

        while (!glossary.eof()) {
            string currentFromFile;

            // Считываем из файла по слову
            glossary >> currentFromFile;
            int result = item.compare(currentFromFile);
            if (result == 0) {
                ++numberOfFound;
            }
        }

        printf("%-10s: %s\n", item.c_str(), (numberOfFound ? std::to_string(numberOfFound).c_str() : "not found"));

        // Сбросить состояние потока и переместиться в начало файла
        glossary.clear();
        glossary.seekg(0, std::ios::beg);
    }

    glossary.close();
}
