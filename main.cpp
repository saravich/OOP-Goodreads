#include "goodreads.hpp"
#include "get_command.hpp"

using namespace std;
int main(int argc,char* argv[]){
    string books_info_path=string(argv[1])+BOOKS_INFO_FILE_NAME;
    string authors_info_path=string(argv[1])+AUTHORS_INFO_FILE_NAME;
    string users_info_path=string(argv[1])+USERS_INFO_FILE_NAME;
    string reviews_info_path=string(argv[1])+REVIEWS_INFO_FILE_NAME;
    Goodreads site(books_info_path,authors_info_path,users_info_path,reviews_info_path);
    get_command(site);
    return 0;
}
 