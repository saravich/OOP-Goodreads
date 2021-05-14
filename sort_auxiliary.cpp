#include "sort_auxiliary.hpp"
using namespace std;

bool sort_alphabetic(Book* book1,Book* book2){
    return (book1->get_title())<(book2->get_title());
}
bool sort_rating(vector<double> v1,vector<double> v2){
    return v1[1]>v2[1];
}
bool sort_alphabetic_author(Author* author1,Author* author2){
    return (author1->get_name()<author2->get_name());
}