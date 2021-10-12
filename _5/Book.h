#pragma once

#include <string>

using std::string;

class Book
{
	string name;
	string author;
	string publisher;

public:

	Book();
	Book(const Book& other);
	Book(string name, string author, string publisher);

	string getName() const;
	string getAuthor() const;
	string getPublisher() const;

	void setName(string name);
	void setAuthor(string author);
	void setPublisher(string publisher);
};

