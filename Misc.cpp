#include "Misc.h"
#include <sstream>

void misc::split(const std::string &string, const char &delimiter, std::vector<std::string> &split_string)
{
    std::stringstream ss;
    for(unsigned int index = 0; index < string.size(); index++)
    {
        if(string[index] == delimiter)
        {
            ss.flush();
            split_string.push_back(ss.str());
            ss.str("");
            continue;
        }
        ss << string[index];
    }

    ss.flush();
    split_string.push_back(ss.str());
}
