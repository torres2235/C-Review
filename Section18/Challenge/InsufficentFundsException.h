#ifndef _INSUFFICENT_FUNDS_EXCEPTION_H_
#define _INSUFFICENT_FUNDS_EXCEPTION_H_

class InsufficentFundsException : public std::exception {
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() {}
    virtual const char* what() const noexcept {
        return "Insufficent Funds Exception, withdrawing too much";
    }
};

#endif // _INSUFFICENT_FUNDS_EXCEPTION_H_
