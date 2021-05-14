#include "get_command.hpp"
using namespace std;
void do_show_author_info(Goodreads site){
    string author_id;
    cin >> author_id;
    site.show_author_info(stoi(author_id));
}
void do_show_sorted_shelf(Goodreads site){
    string user_id;
    string shelf_type;
    string genre;
    cin>>user_id>>shelf_type>>genre;
    site.show_sorted_shelf(stoi(user_id),shelf_type,genre);
}
void do_show_user_credit(Goodreads site){
    string user_id;
    cin>>user_id;
    User* user=site.find_user_by_id(stoi(user_id));
    double credit=site.calculate_user_credit(user);
    cout<<fixed<<setprecision(6)<<credit<<endl;
}
void do_show_best_book(Goodreads site){
    site.show_best_book(site.find_best_book());
}
void do_show_best_reviewer(Goodreads site){
    site.show_best_reviewer_details(site.find_best_reviewer());

}
void do_recommend_first_aproach(Goodreads site){
    string user_id;
    cin>>user_id;
    User* user=site.find_user_by_id(stoi(user_id));
    site.show_recommended_book(site.recommend_best_book(user));
}
void get_command(Goodreads site){
    string command;
	cin>>command;
    if (command == "show_author_info") 
        do_show_author_info(site);
    if (command=="show_sorted_shelf")
        do_show_sorted_shelf(site);
    if(command=="credit")
        do_show_user_credit(site);
    if(command=="best_book")
        do_show_best_book(site);
    if(command=="best_reviewer")
        do_show_best_reviewer(site);
    if(command=="recommend_first_approach")
        do_recommend_first_aproach(site);
}