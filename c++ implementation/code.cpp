#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void pigeonholeSort(std::vector<int> &arr) {
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    int range = max - min + 1;
    std::vector<int> holes(range, 0);
    for (int i = 0; i < arr.size(); ++i) {
        holes[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;
        }
    }
}

std::vector<int> readInputFromFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        exit(1);
    }
    std::vector<int> arr;
    int num;
    while (file >> num) {
        arr.push_back(num);
    }
    file.close();
    return arr;
}

int main() {
    const std::string filename = "input.txt"; // Change this to your input file name
    std::ifstream inputFile(filename.c_str());
    int num_test_cases;
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return 1;
    }
    inputFile >> num_test_cases;
    for(int t = 0; t < num_test_cases; t++) {
        std::vector<int> arr = readInputFromFile(filename);
        std::cout << "Unsorted array: ";
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        pigeonholeSort(arr);
        std::cout << "Sorted array: ";
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
