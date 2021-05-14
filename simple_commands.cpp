#include "goodreads.hpp"
using namespace std;
void Goodreads::show_author_info(int author_id){
    Author* desired_author=find_author_by_id(author_id);
    cout<<"id: "<<desired_author->get_id();
    cout<<"\nName: "<<desired_author->get_name();
    cout<<"\nYear of Birth: "<<desired_author->get_year_of_birth();
    cout<<"\nPlace of Birth: "<<desired_author->get_place_of_birth();
    cout<<"\nMember Since: "<<desired_author->get_member_since();
    cout<<"\nGenres: ";
    desired_author->show_author_genres();
    cout<<"\nBooks:";
    desired_author->show_author_books();
    cout<<endl;
}
void Goodreads::show_shelf(vector<Book*> shelf,string genre){
    vector<Book*> same_genre_books;
    vector<Book*> other_genre_books;
    for(int i=0;i<shelf.size();i++){
        if(shelf[i]->get_genre().get_name()==genre)
            same_genre_books.push_back(shelf[i]);
        else
            other_genre_books.push_back(shelf[i]);
    }
    sort(same_genre_books.begin(),same_genre_books.end(),sort_alphabetic);
    sort(other_genre_books.begin(),other_genre_books.end(),sort_alphabetic);
    show_books_details(same_genre_books);
    show_books_details(other_genre_books);
}
void Goodreads::show_books_details(vector<Book*> shelf){
    for(int i=0;i<shelf.size();i++){
        cout<<"id: "<<shelf[i]->get_id();
        cout<<"\nTitle: "<<shelf[i]->get_title();
        cout<<"\nGenre: "<<shelf[i]->get_genre().get_name();
        cout<<"\nAuthor: "<<find_author_by_id(shelf[i]->get_author_id())->get_name();
        cout<<"\n***\n"; 
    }
}
void Goodreads::show_sorted_shelf(int user_id,string shelf_type,string genre){
    User* desired_user=find_user_by_id(user_id);
    if(shelf_type=="want_to_read")
        show_shelf(desired_user->get_want_to_read(),genre);
    if(shelf_type=="currently_reading") 
        show_shelf(desired_user->get_currently_reading(),genre);
    if(shelf_type=="read") 
        show_shelf(desired_user->get_read(),genre);
}
double Goodreads::calculate_user_credit(User* user){
    vector<Review> user_reviews;
    double user_reviews_likes=0;
    double num_of_likes=0;
    for(int i=0;i<reviews.size();i++){
        if(reviews[i].get_user_id()==user->get_id()){
            user_reviews.push_back(reviews[i]);
            user_reviews_likes=user_reviews_likes+reviews[i].get_num_of_likes();
        }
        num_of_likes=num_of_likes+reviews[i].get_num_of_likes();
    }
    double number_of_user_reviews=user_reviews.size();
    double total_number_of_reviews=reviews.size();
    return 0.5*(user_reviews_likes/num_of_likes+number_of_user_reviews/total_number_of_reviews);
}