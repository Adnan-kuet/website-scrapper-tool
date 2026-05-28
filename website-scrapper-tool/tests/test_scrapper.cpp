#include <iostream>
#include <cassert>
#include "scrapper.hpp"
#include "parser.hpp"

void test_parser_links() {
    std::string html = "<html><body><a href='https://example.com'>Example</a><a href='/page'>Page</a></body></html>";
    Parser parser(html);
    auto links = parser.extractLinks();
    assert(links.size() == 2);
    assert(links[0].href == "https://example.com");
    assert(links[0].text == "Example");
    assert(links[1].href == "/page");
    assert(links[1].text == "Page");
    std::cout << "test_parser_links passed" << std::endl;
}

void test_parser_no_links() {
    std::string html = "<html><body><p>No links here</p></body></html>";
    Parser parser(html);
    auto links = parser.extractLinks();
    assert(links.empty());
    std::cout << "test_parser_no_links passed" << std::endl;
}

int main() {
    test_parser_links();
    test_parser_no_links();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}