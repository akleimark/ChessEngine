#ifndef MISC_H
#define MISC_H

#include <string>
#include <vector>
#include <sstream>

namespace misc
{
    void split(const std::string &string, const char &delimiter, std::vector<std::string> &split_string);
}



#endif // MISC_H
