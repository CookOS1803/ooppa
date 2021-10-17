#pragma once

#include <string>

using std::string;

class Book;

struct info
{
	Book* book;
	int deadline;
};

class Subscriber
{
	string name;
	string faculty;
	int group;
	info* books = nullptr;
	int bookCount;

public:

	Subscriber();
	Subscriber(const Subscriber& other);
	Subscriber(string name, string faculty, int group, info* books, int nDir);
	~Subscriber();

	string getName() const;
	string getFaculty() const;
	int getGroup() const;
	info* getBooks() const;
	int getBookCount() const;

	void setName(string name);
	void setFaculty(string faculty);
	void setGroup(int group);
	void setBooks(info* books, int nDir);

	void addBook(info book);
	void removeBook(int n);

	info& operator[](int i);
};

