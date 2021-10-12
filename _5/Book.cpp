#include "Book.h"

Book::Book()
{
	setName("");
	setAuthor("");
	setPublisher("");
}

Book::Book(const Book& other)
{
	setName(other.name);
	setAuthor(other.author);
	setPublisher(other.publisher);
}

Book::Book(string name, string author, string publisher)
{
	setName(name);
	setAuthor(author);
	setPublisher(publisher);
}

string Book::getName() const
{
	return name;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getPublisher() const
{
	return publisher;
}

void Book::setName(string name)
{
	this->name = name;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setPublisher(string publisher)
{
	this->publisher = publisher;
}
