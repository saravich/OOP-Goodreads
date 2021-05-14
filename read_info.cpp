#include "read_info.hpp"
using namespace std;
vector<vector<string>> file_info_to_vector(string file_info){
    vector<vector<string>> string_info;
    ifstream ifile(file_info);
    string line,word;
    vector<string> info_vector;
    while(getline(ifile,line)){
        stringstream stream_line(line);
        vector<string> new_item;
        while(getline(stream_line,word,',')){
            new_item.push_back(word);
        }
        string_info.push_back(new_item);
    }
    return string_info;
}
vector<string> string_info_to_vector(string string_info){
    stringstream stream_line(string_info);
    string word;
    vector<string> info_vector;
    while(getline(stream_line,word,'$')){
        info_vector.push_back(word);
    }
    return info_vector;
}
vector<Book> make_books_vector(vector<vector<string>> books_info){
    vector<Book> books;
    for(int i=1;i<books_info.size();i++){
        Book new_book(books_info[i]);
        books.push_back(new_book);
    }
    return books;
}

vector<Author> make_authors_vector(vector<vector<string>> authors_info){
    vector<Author> authors;
    for(int i=1;i<authors_info.size();i++){
        Author new_author(authors_info[i]);
        authors.push_back(new_author);
    }
    return authors;    
}