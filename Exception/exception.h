#include <iostream>
#include <exception>

struct OutOfRangeException : public std::exception {
    const char* what () const throw () {
        return "Index out of range!";
    }
};