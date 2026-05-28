#include <iostream>
#include "scrapper.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <url>" << std::endl;
        return 1;
    }

    try {
        Scrapper scrapper(argv[1]);
        std::string html = scrapper.fetchPage();
        Parser parser(html);
        auto links = parser.extractLinks();

        std::cout << "Found " << links.size() << " links:" << std::endl;
        for (const auto& link : links) {
            std::cout << "  " << link.href;
            if (!link.text.empty())
                std::cout << " (" << link.text << ")";
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}