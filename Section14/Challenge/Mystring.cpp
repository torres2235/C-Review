#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//===========================================================================================
//overloaded equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

//overloaded inequality operator
bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

//overloaded less-that operator
bool Mystring::operator<(const Mystring &rhs) const {
    return (str < rhs.str);
}

//overloaded greater-that operator
bool Mystring::operator>(const Mystring &rhs) const {
    return (str > rhs.str);
}

//overloaded unary minus operator   (lower case conversion)
Mystring Mystring::operator-() const{
    char *buff = new char[get_length() + 1];
    std::strcpy(buff, str);
    for(size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//overloaded unary plus operator    (concatination)
Mystring Mystring::operator+(const Mystring &rhs) {
    char *buff = new char[get_length() + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//overloaded += operator    (concatination and assignment)
Mystring Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs.str;
    return *this;
}

//overladed * operator
Mystring Mystring::operator*(int rhs) {
    char *buff = new char[get_length() * rhs + 1];
    std::strcpy(buff, str);
    for(int i {1}; i < rhs; i++) {
        std::strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//overloaded *= operator 
Mystring Mystring::operator*=(int rhs) {
    Mystring curr {*this};
    for(int i {1}; i < rhs; i++) {
        *this += curr;
    }
    return *this;
}

//overloaded preincrement operator
Mystring Mystring::operator++() {
    for(size_t i {0}; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

//overloaded postincrement operator
Mystring Mystring::operator++(int) {
    Mystring temp (*this);       // make a copy
   operator++();                    // call pre-increment - make sure you call preincrement!
   return temp;                     // return the old value
}
//===========================================================================================