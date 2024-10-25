#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    //===========================================================================================
    bool operator==(const Mystring &rhs) const;  // equality operator overload
    bool operator!=(const Mystring &rhs) const;  // inequality operator overload
    bool operator<(const Mystring &rhs) const;   // lexically less-than overload
    bool operator>(const Mystring &rhs) const;   // lexically greater-than overload
    Mystring operator-() const;                  // unary minus operator overload
    Mystring operator+(const Mystring &rhs);     // plus operator overload
    Mystring operator+=(const Mystring &rhs);    // += operator overload
    Mystring operator*(int rhs);                 // unary * operator overload
    Mystring operator*=(int rhs);                // += operator overload
    Mystring operator++();                       // preincrement operator overload
    Mystring operator++(int);                    // postincrement operator overload
    //===========================================================================================
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_