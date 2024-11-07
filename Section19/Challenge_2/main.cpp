// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    std::ifstream in_file {"../responses.txt"};
    
    if(!in_file) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    } else {
        std::string key {};
        std::string name {};
        std::string answers {};
        double avg {0};
        int count {0};
        std::getline(in_file, key);
        
        std::cout << std::setw(25) << std::left << "Student" << "Score" << std::endl;
        std::cout << std::setw(31) << std::setfill('-') << std::right << ' ' << std::endl;
        std::cout << std::setfill(' ');
        while(in_file >> name >> answers){
            cout << std::setw(27) << std::left << name;
            int score {0};
            count++;
            for(int i {0}; i < key.length(); i++){
                if(key[i] == answers[i]){
                    score++;
                }
            }
            avg += score;
            cout << score << endl;
        }
        std::cout << std::setw(31) << std::setfill('-') << std::right << ' ' << std::endl;
        std::cout << std::setfill(' ');
        avg /= count;
        cout << std::setw(26) << std::left << "Average Score" << avg << std::endl;
    }
    
    in_file.close();
    return 0;
}

