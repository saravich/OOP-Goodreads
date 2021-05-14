#ifndef _READ_INFO_HPP_
#define _READ_INFO_HPP_
#include "includes_defines.hpp"
#include "books.hpp"
#include "genres.hpp"
#include "authors.hpp"
std::vector<std::vector<std::string>> file_info_to_vector(std::string file_info);
std::vector<std::string> string_info_to_vector(std::string string_info);
std::vector<Book> make_books_vector(std::vector<std::vector<std::string>> books_info);
std::vector<Author> make_authors_vector(std::vector<std::vector<std::string>> authors_info);
#endif