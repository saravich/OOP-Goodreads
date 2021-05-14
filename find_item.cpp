#include "goodreads.hpp"
using namespace std;

Author* Goodreads::find_author_by_book(Book* book){
    for(int i=0;i<authors.size();i++){
        if(authors[i].get_id()==book->get_author_id())
            return &authors[i];
    }
    cout<<"author not found!"<<endl;
    return NULL;
}
Author* Goodreads::find_author_by_id(int id){
    for(int i=0;i<authors.size();i++){
        if(authors[i].get_id()==id)
            return &authors[i];
    }
    cout<<"author not found!"<<endl;
    return NULL;
}
Genre* Goodreads::find_genre_by_name(string name){
    for(int i=0;i<genres.size();i++){
        if(genres[i].get_name()==name)
            return &genres[i];
    }
    cout<<"genre not found!"<<endl;
    return NULL;
}
Book* Goodreads::find_book_by_id(int id){
    for(int i=0;i<books.size();i++){
        if(books[i].get_id()==id)
            return &books[i];
    }
    cout<<"book not found!"<<endl;
    return NULL;
}
User* Goodreads::find_user_by_id(int id){
    for(int i=0;i<users.size();i++){
        if(users[i].get_id()==id)
            return &users[i];
    }
    cout<<"user not found!"<<endl;
    return NULL;
}
void Goodreads::find_written_genres(Author* author){
    set<string> authors_genres_set;
    for(int i=0;i<author->get_written_books().size();i++){
        authors_genres_set.insert(author->get_written_books()[i]->get_genre().get_name());
    }
    vector<string> written_genres_vec;
    written_genres_vec.assign(authors_genres_set.begin(),authors_genres_set.end());
    for(int i=0;i<written_genres_vec.size();i++){
        Genre new_genre;
        new_genre.set_name(written_genres_vec[i]);
        author->add_genre_to_author(new_genre);
    }
}