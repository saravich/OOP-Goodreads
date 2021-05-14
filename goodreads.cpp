#include "goodreads.hpp"
using namespace std;


Goodreads::Goodreads(string books_file,string authors_file,string users_file,
    string reviews_file){
    books=make_books_vector(file_info_to_vector(books_file));
    authors=make_authors_vector(file_info_to_vector(authors_file));
    organize_authors_books();
    organize_authors_genres();
    make_genres_vector();
    make_users_vector(users_file);
    reviews=make_reviews_vector(file_info_to_vector(reviews_file));
    organize_reviewers_likes();
}

void Goodreads::organize_authors_books(){
    for(int j=0;j<books.size();j++){
        if(find_author_by_book(&books[j])!=NULL){
            Author* author_of_the_book=find_author_by_book(&books[j]);
            author_of_the_book->add_book_to_author(&books[j]);
        }
    }
}
void Goodreads::organize_authors_genres(){
    for(int i=0;i<authors.size();i++){
        find_written_genres(&authors[i]);
    }
}
void Goodreads::organize_reviewers_likes(){
    int liked_num;
    for(int i=0;i<users.size();i++){
        liked_num=0;
        for(int j=0;j<reviews.size();j++){
            if(users[i].get_id()==reviews[j].get_user_id())
                liked_num=liked_num+reviews[j].get_num_of_likes();
        }
        users[i].set_num_of_likes(liked_num);
    }
}
void Goodreads::make_genres_vector(){
    set<string> genres_names;
    for(int i=0;i<books.size();i++){
        genres_names.insert(books[i].get_genre().get_name());
    }
    vector<string> genres_names_vector;
    genres_names_vector.assign(genres_names.begin(),genres_names.end());
    for(int i=0;i<genres_names_vector.size();i++){
        Genre new_genre;
        new_genre.set_name(genres_names_vector[i]);
        genres.push_back(new_genre);
    }
}

User Goodreads::create_user(vector<string> users_info){
    vector<string> fav_authors_str=string_info_to_vector(users_info[4]);
    vector<Author*> fav_authors_ptr;
    for(int i=0;i<fav_authors_str.size();i++){
        fav_authors_ptr.push_back(find_author_by_id(stoi(fav_authors_str[i])));
    }
    vector<string> fav_genres_ptr=string_info_to_vector(users_info[5]);
    vector<string> want_to_read_str=string_info_to_vector(users_info[6]);
    vector<Book*> want_to_read_ptr;
    for(int i=0;i<want_to_read_str.size();i++){
        want_to_read_ptr.push_back(find_book_by_id(stoi(want_to_read_str[i])));
    }

    vector<string> currently_reading_str=string_info_to_vector(users_info[7]);
    vector<Book*> currently_reading_ptr;
    for(int i=0;i<currently_reading_str.size();i++){
        currently_reading_ptr.push_back(find_book_by_id(stoi(currently_reading_str[i])));
    }
    vector<string> read_str=string_info_to_vector(users_info[8]);
    vector<Book*> read_ptr;
    for(int i=0;i<read_str.size();i++){
        read_ptr.push_back(find_book_by_id(stoi(read_str[i])));
    }
    User new_user(users_info,fav_authors_ptr,fav_genres_ptr,
            want_to_read_ptr,currently_reading_ptr,read_ptr);
    return new_user;
}
void Goodreads::make_users_vector(string users_file){
    for(int i=1;i<file_info_to_vector(users_file).size();i++)
        users.push_back(create_user(file_info_to_vector(users_file)[i]));
}
vector<Review> Goodreads::make_reviews_vector(vector<vector<string>> reviews_info){
    vector<Review> authors;
    for(int i=1;i<reviews_info.size();i++){
        Review new_review(reviews_info[i]);
        reviews.push_back(new_review);
    }
    return reviews;    
}




