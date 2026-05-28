cmake_minimum_required(VERSION 3.10)
project(website-scrapper-tool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
find_package(Gumbo REQUIRED)

add_executable(scrapper src/main.cpp src/scrapper.cpp src/parser.cpp)
target_link_libraries(scrapper ${CURL_LIBRARIES} ${GUMBO_LIBRARIES})
target_include_directories(scrapper PRIVATE ${CURL_INCLUDE_DIRS} ${GUMBO_INCLUDE_DIRS} include)

add_executable(test_scrapper tests/test_scrapper.cpp src/scrapper.cpp src/parser.cpp)
target_link_libraries(test_scrapper ${CURL_LIBRARIES} ${GUMBO_LIBRARIES})
target_include_directories(test_scrapper PRIVATE ${CURL_INCLUDE_DIRS} ${GUMBO_INCLUDE_DIRS} include)