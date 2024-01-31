#ifndef PRECONG_VIOLATED_EXCEPTION
#define PRECONG_VIOLATED_EXCEPTION

#include <iostream>

using namespace std;

class PreconViolatedExcept : public exception
{
public:
    const char *what() const throw()
    {
        return "an empty list or invalid index";
    }
};

#endif