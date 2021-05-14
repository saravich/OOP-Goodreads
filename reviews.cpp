#include"includes_defines.hpp"
#include "reviews.hpp"
using namespace std;

Review::Review(vector<string> review_info){
    id=stoi(review_info[0]);
    book_id=stoi(review_info[1]);
    user_id=stoi(review_info[2]);
    rating=stoi(review_info[3]);
    date=review_info[4];
    num_of_likes=stoi(review_info[5]);
}