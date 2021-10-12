#include "Subscriber.h"
#include "Book.h"

Subscriber::Subscriber()
{
	setName("");
	setFaculty("");
	setGroup(0);
	setBooks(nullptr, 0);
}

Subscriber::Subscriber(const Subscriber& other)
{
	setName(other.name);
	setFaculty(other.faculty);
	setGroup(other.group);
	setBooks(other.books, other.bookCount);
}

Subscriber::Subscriber(string name, string faculty, int group, Book* books, int n)
{
	setName(name);
	setFaculty(faculty);
	setGroup(group);
	setBooks(books, n);
}

string Subscriber::getName() const
{
	return name;
}

string Subscriber::getFaculty() const
{
	return faculty;
}

int Subscriber::getGroup() const
{
	return group;
}

Book* Subscriber::getBooks() const
{
	return books;
}

int Subscriber::getBookCount() const
{
	return bookCount;
}

void Subscriber::setName(string name)
{
	this->name = name;
}

void Subscriber::setFaculty(string faculty)
{
	this->faculty = faculty;
}

void Subscriber::setGroup(int group)
{
	this->group = group;
}

void Subscriber::setBooks(Book* books, int n)
{
	delete[] this->books;

	this->books = books;
	bookCount = n;
}

void Subscriber::addBook(Book book)
{
	Book* temp = new Book[bookCount + 1];

	memcpy(temp, books, sizeof(Book) * bookCount);
	temp[bookCount] = book;

	setBooks(temp, bookCount + 1);	
}

Book& Subscriber::operator[](int i)
{
	return books[i];
}
