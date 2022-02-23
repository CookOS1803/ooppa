#pragma once
#include "UniquePointer.h"

template <class T>
class Transaction
{
	UniquePointer<T> previousState;
	UniquePointer<T> currentState;

public:

	Transaction();
	Transaction(const T& currentState);
	Transaction(const Transaction& other);

	void BeginTransaction(const T& newState);
	void RollBack();
	void Commit();

	const T& GetCurrentState() const;
	const T* GetCurrentStatePointer() const;

	const T* operator->() const;
};

template<class T>
Transaction<T>::Transaction() : previousState(), currentState(new T)
{
}

template<class T>
Transaction<T>::Transaction(const T& currentState)
	: previousState(), currentState(new T(currentState))
{
}

template<class T>
Transaction<T>::Transaction(const Transaction& other)
	: currentState(new T(*other.currentState))
{
	if (other.previousState)
	{
		previousState = new T(*other.previousState);
	}
}

template<class T>
void Transaction<T>::BeginTransaction(const T& newState)
{
	currentState.GiveOwnershipTo(previousState);
	currentState = new T(newState);
}

template<class T>
void Transaction<T>::RollBack()
{
	if (previousState)
	{
		previousState.GiveOwnershipTo(currentState);
	}
}

template<class T>
void Transaction<T>::Commit()
{
	if (previousState)
	{
		previousState.Destroy();
	}
}

template<class T>
const T& Transaction<T>::GetCurrentState() const
{
	return *currentState;
}

template<class T>
inline const T* Transaction<T>::GetCurrentStatePointer() const
{
	return currentState.GetRawPointer();
}

template<class T>
const T* Transaction<T>::operator->() const
{
	return currentState.GetRawPointer();
}

