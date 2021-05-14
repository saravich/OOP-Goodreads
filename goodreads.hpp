#ifndef _GOODREADS_HPP_
#define _GOODREADS_HPP_
#include "includes_defines.hpp"
#include "books.hpp"
#include "users.hpp"
#include "authors.hpp"
#include "reviews.hpp"
#include "read_info.hpp"
#include "sort_auxiliary.hpp"


class Goodreads{
private:
    std::vector<Book> books;
    std::vector<Author> authors;
    std::vector<User> users;
    std::vector<Genre> genres;
    std::vector<Review> reviews;
    
public:
    Goodreads(std::string books_file,std::string authors_file,std::string users_file,std::string reviews_file);
    Author* find_author_by_book(Book* book);
    Author* find_author_by_id(int id);
    Genre* find_genre_by_name(std::string name);
    Book* find_book_by_id(int id);
    User* find_user_by_id(int id);
    void organize_authors_books();
    void organize_authors_genres();
    double total_rating();
    void find_written_genres(Author* author);
    void make_genres_vector();
    User create_user(std::vector<std::string> users_info);
    void make_users_vector(std::string users_file);
    std::vector<Review> make_reviews_vector(std::vector<std::vector<std::string>> reviews_info);
    void show_author_info(int author_id);
    void show_shelf(std::vector<Book*> shelf,std::string genre);
    void show_books_details(std::vector<Book*> shelf);
    void show_sorted_shelf(int user_id,std::string shelf_type,std::string genre);
    double calculate_user_credit(User* user);
    double calculate_book_average_rating(Book* book);
    double calculate_book_rating(Book* book);
    Book* find_best_book();
    void show_best_book(Book* book);
    void show_recommended_book(Book* book);
    void show_review_details(Review* review);
    void organize_reviewers_likes();
    User* find_best_reviewer();
    Book* recommend_best_book(User* user);
    void show_best_reviewer_details(User* best_reviewer);
    int book_genre_is_user_favorite(Book* book,User* user);
    int book_exists_in_shelf(Book* book,std::vector<Book*> shelf);
    int book_exists_in_user_shelves(Book* book,User* user);
    double calculate_book_score(Book* book,User* user);
    std::vector<Author> get_authors() {return authors;}
    std::vector<Book> get_books() {return books;}
    std::vector<Genre> get_genres() {return genres;}
    std::vector<User> get_users() {return users;}
    std::vector<Review> get_reviews() {return reviews;}
};

#endif