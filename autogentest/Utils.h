#ifndef UTILS_H
#define UTILS_H
#include <stdexcept>
#include <iostream>
#include <QString>
	
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

inline QString GetRandomString(const int randomStringLength) { // https://stackoverflow.com/a/18866593/6381767
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

#endif
