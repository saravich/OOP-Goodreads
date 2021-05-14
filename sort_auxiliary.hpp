#ifndef _SORT_HPP_
#define _SORT_HPP_
#include "includes_defines.hpp"
#include "books.hpp"
#include "authors.hpp"
bool sort_alphabetic(Book* book1,Book* book2);
bool sort_rating(std::vector<double> v1,std::vector<double> v2);
bool sort_alphabetic_author(Author* author1,Author* author2);
#endif