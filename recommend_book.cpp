#include "goodreads.hpp"
#include "sort_auxiliary.hpp"
using namespace std;
double Goodreads::calculate_book_rating(Book* book){
    double book_rating=0;
    double book_reviews_counter=0;
    for(int i=0;i<reviews.size();i++){
        if(book->get_id()==reviews[i].get_book_id()){
            double reviewer_credit=
                calculate_user_credit(find_user_by_id(reviews[i].get_user_id()));
            book_rating=book_rating+(double)reviews[i].get_rating()*reviewer_credit;
            book_reviews_counter++;
        }
    }
    return book_rating/book_reviews_counter;
}
int Goodreads::book_genre_is_user_favorite(Book* book,User* user){
    for(int i=0;i<user->get_favorite_genres().size();i++){
        if(book->get_genre().get_name()==user->get_favorite_genres()[i])
            return 1;
    }
    return 0;
}
int Goodreads::book_exists_in_shelf(Book* book,vector<Book*> shelf){
    for(int i=0;i<shelf.size();i++)
        if(book->get_id()==shelf[i]->get_id())
            return 1;
    return 0;
}
int Goodreads::book_exists_in_user_shelves(Book* book,User* user){
    if(book_exists_in_shelf(book,user->get_currently_reading())) 
        return 1;
    if(book_exists_in_shelf(book,user->get_want_to_read())) 
        return 1;
    if(book_exists_in_shelf(book,user->get_read())) 
        return 1;
    return 0;
}
double Goodreads::calculate_book_score(Book* book,User* user){
    if(book_exists_in_user_shelves(book,user)) 
        return 0;
    double book_score=0;
    if(book_genre_is_user_favorite(book,user)) 
        book_score=book_score+5;
    book_score=book_score+calculate_book_rating(book);
    return book_score;
}
Book* Goodreads::recommend_best_book(User* user){
    Book* most_recommended=&books[0];
    vector<vector<double>> books_id_scores;
    for(int i=0;i<books.size();i++){
        vector<double> new_info;
        new_info.push_back((double)books[i].get_id());
        new_info.push_back(calculate_book_score(&books[i],user));
        books_id_scores.push_back(new_info);
    }
    sort(books_id_scores.begin(),books_id_scores.end(),sort_rating);
    return find_book_by_id(books_id_scores[0][0]);
}

void Goodreads::show_recommended_book(Book* book){
    cout<<"id: "<<book->get_id();
    cout<<"\nTitle: "<<book->get_title();
    cout<<"\nGenre: "<<book->get_genre().get_name();
    cout<<"\nAuthor: "<<find_author_by_id(book->get_author_id())->get_name();
    cout<<"\nReviews:";
    for(int i=0;i<reviews.size();i++)
        if(reviews[i].get_book_id()==book->get_id())
            show_review_details(&reviews[i]);
    cout<<endl;
}
void Goodreads::show_review_details(Review* review){
    cout<<"\nid: "<<review->get_id();
    cout<<" Rating: "<<review->get_rating();
    cout<<" Likes: "<<review->get_num_of_likes();
    cout<<" Date: "<<review->get_date();
}