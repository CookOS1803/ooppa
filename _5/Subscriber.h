#pragma once

#include <string>

using std::string;

class Book;

class Subscriber
{
	string name;
	string faculty;
	int group;
	Book* books = nullptr;
	int bookCount;

public:

	Subscriber();
	Subscriber(const Subscriber& other);
	Subscriber(string name, string faculty, int group, Book* books, int n);

	string getName() const;
	string getFaculty() const;
	int getGroup() const;
	Book* getBooks() const;
	int getBookCount() const;

	void setName(string name);
	void setFaculty(string faculty);
	void setGroup(int group);
	void setBooks(Book* books, int n);

	void addBook(Book book);

	Book& operator[](int i);
};

