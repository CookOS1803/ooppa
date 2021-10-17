#include "Department.h"
#include "Book.h"
#include "Subscriber.h"

Department::Department()
{
	setName("");
	setDirections(nullptr, 0);
	setBooks(nullptr, 0);
}

Department::Department(const Department& other)
{
	setName(other.name);
	setDirections(other.directions, other.nDir);
	setBooks(other.books, other.nBooks);
}

Department::Department(string name, string* directions, int nDir, Book* books, int nBooks)
{
	setName(name);
	setDirections(directions, nDir);
	setBooks(books, nBooks);
}

Department::~Department()
{
	delete[] directions;
	delete[] books;
}

string Department::getName() const
{
	return name;
}

string* Department::getDirections() const
{
	return directions;
}

int Department::getDirectionsCount() const
{
	return nDir;
}

Book* Department::getBooks() const
{
	return books;
}

int Department::getBookCount() const
{
	return nBooks;
}

void Department::setName(string name)
{
	this->name = name;
}

void Department::setDirections(string* directions, int nDir)
{
	delete[] this->directions;

	this->directions = directions;
	this->nDir = nDir;
}

void Department::setBooks(Book* books, int nBooks)
{
	delete[] this->books;

	this->books = books;
	this->nBooks = nBooks;
}

void Department::addDirection(string direction)
{
	string* temp = new string[nDir + 1];

	for (int i = 0; i < nDir; i++)
		temp[i] = directions[i];
	temp[nDir] = direction;

	setDirections(temp, nDir + 1);
}

void Department::addBook(Book book)
{
	Book* temp = new Book[nBooks + 1];

	for (int i = 0; i < nBooks; i++)
		temp[i] = books[i];
	temp[nBooks] = book;

	setBooks(temp, nBooks + 1);
}

void Department::giveBook(Subscriber& sub, int i, int deadline)
{
	sub.addBook({books + i, deadline});
}
