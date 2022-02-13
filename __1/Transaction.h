#pragma once
#include "SmartPointer.h"

template <class T>
class Transaction
{
	SmartPointer<T> previousState;
	SmartPointer<T> currentState;

public:

	Transaction();
	Transaction(const Transaction& other);

	void BeginTransaction(const T& newState);
	void RollBack();
	void Commit();

	const T& GetCurrentState() const;
};




template<class T>
inline Transaction<T>::Transaction() : previousState(), currentState()
{
}

template<class T>
inline Transaction<T>::Transaction(const Transaction& other)
	: previousState(new T(*previousState)), currentState(new T(*currentState))
{
}

template<class T>
inline const T& Transaction<T>::GetCurrentState() const
{
	return *currentState;
}

