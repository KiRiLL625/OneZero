#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void sequences(std::string input_filename,
                     std::string output_filename) {
    std::fstream input_file(input_filename, std::ios::in);
    std::vector<int> numbers;
    int number;
    while (input_file >> number) {
        numbers.push_back(number);
    }
    input_file.close();
    auto it = std::unique(numbers.begin(), numbers.end());
    /*
    for (auto i = numbers.begin(); i != it; ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    */
    int count_one = std::count(numbers.begin(), it, 1);
    int count_zero = std::count(numbers.begin(), it, 0);
    std::fstream output_file(output_filename, std::ios::out);
    output_file << count_one << " " << count_zero << std::endl;
}
int main(int argc, char** argv) {
    sequences(argv[1], argv[2]);
    return 0;
}
