#include <iostream>
#include <fstream>
#include <string>

int countCharacterSequence(const std::string& filename, const std::string& sequence) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return 0;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(sequence);
        while (pos != std::string::npos) {
            ++count;
            pos = line.find(sequence, pos + sequence.length());
        }
    }

    file.close();
    return count;
}

int main() {
    std::string filename = "README-pl.md";
    std::string sequence = "- [ ]";
    int count = countCharacterSequence(filename, sequence);

    std::cout << "Number of occurrences of '" << sequence << "' in " << filename << ": " << count << std::endl;
    return 0;
}
