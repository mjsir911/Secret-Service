#include <stdexcept>
	
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
