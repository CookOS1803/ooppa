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

Subscriber::Subscriber(string name, string faculty, int group, info* books, int nDir)
{
	setName(name);
	setFaculty(faculty);
	setGroup(group);
	setBooks(books, nDir);
}

Subscriber::~Subscriber()
{
	delete[] books;
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

info* Subscriber::getBooks() const
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

void Subscriber::setBooks(info* books, int nDir)
{
	delete[] this->books;

	this->books = books;
	bookCount = nDir;
}

void Subscriber::addBook(info book)
{
	info* temp = new info[bookCount + 1];

	for (int i = 0; i < bookCount; i++)
		temp[i] = books[i];
	temp[bookCount] = book;

	setBooks(temp, bookCount + 1);	
}

info& Subscriber::operator[](int i)
{
	return books[i];
}
