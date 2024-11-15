// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string line;       
    std::string word;   
    std::ifstream in_file {"../words.txt"};
    if (in_file) {
        
        while(getline(in_file, line)) {  // read each line
            std::stringstream s(line);  // break each line down into a stringstream
            while(s >> word) {  // read each word from the string stream
            word = clean_string(word);
                auto it = words.find(word);
                if(it != words.end()) {  // if word is in the map
                    words.at(word) += 1;  // increment its count
                } else {
                    words[word] = 1;  // else add it in
                }
            }
        }
        
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"../words.txt"};
    if (in_file) {
     
        // You implement this code
        int line_count {0};
        while(getline(in_file, line)) {  // read each line
            line_count++;
            std::stringstream s(line);  // break each line down into a stringstream
            while(s >> word) {  // read each word from the string stream
            word = clean_string(word);
                auto it = words.find(word);
                if(it != words.end()) {  // if word is in the map
                    words[word].insert(line_count);
                } else {
                    words[word] = {line_count};
                }
            }
        }
        
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();
    return 0;
}

