#ifndef _REVIEWS_HPP_
#define _REVIEWS_HPP_
#include "includes_defines.hpp"
#include "books.hpp"
class Review{
private: 
    int id;
    int book_id;
    int user_id;
    int rating;
    std::string date;
    int num_of_likes;
public:
    Review(std::vector<std::string> review_info);
    int get_id() {return id;}
    int get_book_id() {return book_id;}
    int get_user_id() {return user_id;}
    int get_num_of_likes() {return num_of_likes;}
    double get_rating() {return (double)rating;}
    std::string get_date() {return date;}
};


#endif