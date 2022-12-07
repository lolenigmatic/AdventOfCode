#include <string>
#include <vector>

using namespace std;
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c

vector<string> split(string s, string delimiter)
{
    vector<string> splitVector;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        splitVector.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    splitVector.push_back(s);

    return splitVector;
}
