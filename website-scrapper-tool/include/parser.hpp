#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

struct Link {
    std::string href;
    std::string text;
};

class Parser {
public:
    explicit Parser(const std::string& html);
    std::vector<Link> extractLinks();
private:
    std::string html_;
};

#endif