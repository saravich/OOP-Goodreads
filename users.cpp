#include "users.hpp"
using namespace std;
User::User(vector <string> user_info,vector<Author*> favorite_authors_,
        vector<string> favorite_genres_,vector <Book*> want_to_read_,
            vector <Book*> currently_reading_,vector <Book*> read_){
    id=stoi(user_info[0]);
    name=user_info[1];
    place_of_birth=user_info[2];
    member_since=user_info[3];
    favorite_authors=favorite_authors_;
    favorite_genres=favorite_genres_;
    want_to_read=want_to_read_;
    currently_reading=currently_reading_;
    read=read_;
}