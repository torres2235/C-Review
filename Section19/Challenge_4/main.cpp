// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>

int main() {
    std::ifstream play {"../romeoandjuliet"};
    std::ofstream copy {"../copy_romeoandjuliet.txt"};
    if(!play){
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if(!copy) {
        std::cerr << "Error opening output file" << std::endl;
    }
    
    std::string line {};
    int line_num {1};
    while(std::getline(play, line)){
        if(line != ""){
            copy << line_num << "\t" << line << std::endl;
            line_num++;
        } else {
            copy << line << std::endl;
        }
    }
    
    std::cout << "file copied" << std::endl;
    
    play.close();
    copy.close();
    return 0;
}

