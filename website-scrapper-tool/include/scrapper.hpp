#ifndef SCRAPPER_HPP
#define SCRAPPER_HPP

#include <string>

class Scrapper {
public:
    Scrapper(const std::string& url);
    std::string fetchPage();
private:
    std::string url_;
};

#endif