#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() {}
    virtual const char* what() const noexcept {
        return "Illegal balance exception, invalid balance";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
