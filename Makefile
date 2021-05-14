CC=g++ -std=c++11

all: Goodreads.out

Goodreads.out: main.o authors.o best_book.o best_reviewer.o books.o find_item.o get_command.o goodreads.o read_info.o recommend_book.o reviews.o simple_commands.o sort_auxiliary.o users.o
	${CC} main.o authors.o best_book.o best_reviewer.o books.o find_item.o get_command.o goodreads.o read_info.o recommend_book.o reviews.o simple_commands.o sort_auxiliary.o users.o -o ./Goodreads.out

main.o: main.cpp goodreads.hpp
	${CC} -c main.cpp
authors.o: authors.hpp authors.cpp includes_defines.hpp books.hpp
	${CC} -c authors.cpp
best_book.o: best_book.cpp goodreads.hpp
	${CC} -c best_book.cpp
best_reviewer.o: best_reviewer.cpp goodreads.hpp
	${CC} -c best_reviewer.cpp
books.o: books.cpp books.hpp includes_defines.hpp
	${CC} -c books.cpp 
find_item.o: find_item.cpp goodreads.hpp
	${CC} -c find_item.cpp
get_command: get_command.cpp get_command.hpp goodreads.hpp
	${CC} -c get_command.cpp
goodreads: goodreads.hpp goodreads.cpp includes_defines.hpp books.hpp users.hpp authors.hpp reviews.hpp read_info.hpp sort_auxiliary.hpp
	${CC} -c goodreads.cpp
read_info.o: read_info.cpp goodreads.hpp 
	${CC} -c read_info.cpp
recommend_book.o: recommend_book.cpp goodreads.hpp sort_auxiliary.hpp
	${CC} -c recommend_book.cpp
reviews.o: reviews.hpp reviews.cpp books.hpp includes_defines.hpp
	${CC} -c reviews.cpp
simple_commands.o: simple_commands.cpp goodreads.hpp
	${CC} -c simple_commands.cpp
sort_auxiliary.o: sort_auxiliary.cpp sort_auxiliary.hpp includes_defines.hpp books.hpp authors.hpp
	${CC} -c sort_auxiliary.cpp
users.o: users.cpp users.hpp books.hpp authors.hpp includes_defines.hpp
	${CC} -c users.cpp
clean:
	rm *.o Goodreads.out