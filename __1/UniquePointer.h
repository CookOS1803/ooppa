#pragma once

template <class T>
class UniquePointer
{
	T* data;

public:

	UniquePointer();
	UniquePointer(T* data);
	UniquePointer(const UniquePointer& other) = delete;
	~UniquePointer();

	T* GetRawPointer() const;
	T* ReleaseOwnership();
	void Destroy();
	void GiveOwnershipTo(UniquePointer& other);

	UniquePointer<T>& operator=(T* data);
	T* operator->();
	T& operator*();
	const T& operator*() const;
	bool operator!() const;
	operator bool() const;
};

template<class T>
UniquePointer<T>::UniquePointer() : data(nullptr)
{
}

template<class T>
UniquePointer<T>::UniquePointer(T* data) : data(data)
{
}

template<class T>
UniquePointer<T>::~UniquePointer()
{
	delete data;
}

template<class T>
T* UniquePointer<T>::GetRawPointer() const
{
	return data;
}

template<class T>
T* UniquePointer<T>::ReleaseOwnership()
{
	T* result = data;
	data = nullptr;

	return result;
}

template<class T>
void UniquePointer<T>::Destroy()
{
	delete data;
	data = nullptr;
}

template<class T>
void UniquePointer<T>::GiveOwnershipTo(UniquePointer& other)
{
	delete other.data;
	other.data = data;
	data = nullptr;
}

template<class T>
UniquePointer<T>& UniquePointer<T>::operator=(T* data)
{
	delete this->data;
	this->data = data;

	return *this;
}

template<class T>
T* UniquePointer<T>::operator->()
{
	return data;
}

template<class T>
T& UniquePointer<T>::operator*()
{
	return *data;
}

template<class T>
const T& UniquePointer<T>::operator*() const
{
	return *data;
}

template<class T>
bool UniquePointer<T>::operator!() const
{
	return !data;
}

template<class T>
UniquePointer<T>::operator bool() const
{
	return data;
}
