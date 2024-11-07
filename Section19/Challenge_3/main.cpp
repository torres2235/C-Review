// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::string search {};
    int word_count {0};
    int found_count {0};
    
    std::ifstream play {"../romeoandjuliet.txt"};
    if(!play) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }
    
    std::cout << "Enter the substring to search for: ";
    std::cin >> search;
    
    std::string word {};
    while(play >> word) {
        word_count++;
        if(word.find(search) != std::string::npos)
            found_count++;
    }
    
    std::cout << word_count << " words were searched..." << std::endl;
    std::cout << "The substring " << search << " was found " << found_count << " found times." << std::endl;
    
    std::cout << std::endl;
    return 0;
}

