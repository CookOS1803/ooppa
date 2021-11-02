#pragma once

#include <iostream>

using std::ostream;

template <class T>
struct Iterator
{
	Iterator<T> *next = nullptr, *prev = nullptr;
	T info;
};

template <class T>
class LinkedList
{
private:

	Iterator<T> *begin, *end;

public:

	LinkedList() : begin(nullptr), end(nullptr) {}
	LinkedList(const LinkedList& other) : LinkedList()
	{
		Iterator<T>* temp = other.begin;

		while (temp != nullptr)
		{
			pushBack(temp->info);
			temp = temp->next;
		}
	}
	~LinkedList()
	{
		while (begin != nullptr)
		{
			Iterator<T>* temp = begin->next;
			delete begin;
			begin = temp;
		}
	}

	Iterator<T>* getBegin() const { return begin; }
	Iterator<T>* getEnd()   const { return end; }

	void pushBack(const T& element)
	{
		if (begin == nullptr)
		{
			begin = new Iterator<T>;
			begin->info = element;
			end = begin;
		}
		else
		{
			Iterator<T>* temp = new Iterator<T>;
			temp->info = element;
			temp->prev = end;
			end->next = temp;
			end = temp;
		}
	}

	void popBack()
	{
		if (begin == nullptr) return;

		Iterator<T>* temp = end->prev;
		delete end;
		end = temp;

		if (end != nullptr) end->next = nullptr;
	}

	template <class T2>
	bool operator==(const LinkedList<T2>& other)
	{
		Iterator<T>*  temp1 = begin;
		Iterator<T2>* temp2 = other.getBegin();

		while (true)
		{
			if (temp1 == nullptr and temp2 == nullptr) return true;
			if (temp1 == nullptr or temp2 == nullptr) return false;

			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	friend ostream& operator<<(ostream& out, const LinkedList& l)
	{
		Iterator<T> *temp = l.begin;

		while (temp != nullptr)
		{
			out << temp->info << " ";
			temp = temp->next;
		}

		return out;
	}
};
