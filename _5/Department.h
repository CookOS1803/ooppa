#pragma once

#include <string>

using std::string;

class Book;
class Subscriber;

class Department
{
	string name;
	string* directions = nullptr;
	Book* books = nullptr;
	int nDir;
	int nBooks;

public:

	Department();
	Department(const Department& other);
	Department(string name, string* directions, int nDir, Book* books, int nBooks);
	virtual ~Department();

	string getName() const;
	string* getDirections() const;
	int getDirectionsCount() const;
	Book* getBooks() const;
	int getBookCount() const;

	void setName(string name);
	void setDirections(string* directions, int nDir);
	void setBooks(Book* books, int nBooks);

	void addDirection(string direction);
	void addBook(Book book);

	void giveBook(Subscriber& sub, int i, int deadline);

	virtual string getDepartmentType() const = 0;
};

