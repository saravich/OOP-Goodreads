#ifndef _USERS_HPP
#define _USERS_HPP_
#include "includes_defines.hpp"
#include "books.hpp"
#include "authors.hpp"

class User{
private:
    int id;
    std::string name;
    std::string place_of_birth;
    std::string member_since;
    int num_of_likes;
    std::vector<Author*> favorite_authors;
    std::vector<std::string> favorite_genres;
    std::vector<Book*> want_to_read;
    std::vector<Book*> currently_reading;
    std::vector<Book*> read;
public:
    User(std::vector <std::string> user_info,
            std::vector<Author*> favorite_authors_,
                std::vector<std::string> favorite_genres_,
                    std::vector <Book*> want_to_read_,
                        std::vector <Book*> currently_reading_,
                            std::vector <Book*> read_);
    std::string get_name() {return name;}
    std::vector<Author*> get_favorite_authors() {return favorite_authors;}
    std::vector<std::string> get_favorite_genres() {return favorite_genres;}
    std::vector<Book*> get_currently_reading() {return currently_reading;}
    std::vector<Book*> get_want_to_read() {return want_to_read;}
    std::vector<Book*> get_read() {return read;}
    int get_id() {return id;}
    int get_num_of_likes() {return num_of_likes;}
    void set_num_of_likes(int likes) {num_of_likes=likes;}
    std::string get_member_since() {return member_since;}
    std::string get_place_of_birth() {return place_of_birth;}

};

#endif