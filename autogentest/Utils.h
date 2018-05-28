#ifndef UTILS_H
#define UTILS_H
#include <stdexcept>
#include <iostream>
	
class NotImplementedException : public std::logic_error
{
private:

    NotImplementedException(const char* message, const char* function): std::logic_error((QString(message) + QString(" : ") + QString(function)).toStdString()) {};

public:

    NotImplementedException(const char* message)
        :
        NotImplementedException("Not Implemented", message)
    {
    }
};

#define NotImplementedException() NotImplementedException(__PRETTY_FUNCTION__)


#define debugline() std::cerr << "DEBUG ###: " << __PRETTY_FUNCTION__ << " : " << __LINE__ << " : " << __FILE__ << "\n"
#endif
