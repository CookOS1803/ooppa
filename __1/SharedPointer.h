#pragma once

template <class T>
class SharedPointer
{
	struct status
	{
		T* pointer;
		int counter;
	};

	status* data;

public:

	SharedPointer();
	SharedPointer(T* pointer);
	SharedPointer(const SharedPointer& other);
	~SharedPointer();

	int GetCounter() const;
	void Destroy();

	SharedPointer<T>& operator=(const SharedPointer& other);
	SharedPointer<T>& operator=(T* pointer);
	T* operator->();
	T& operator*();
	const T& operator*() const;
};

template<class T>
SharedPointer<T>::SharedPointer() : data(nullptr)
{
}

template<class T>
SharedPointer<T>::SharedPointer(T* pointer)
{
	if (pointer == nullptr)
	{
		data = nullptr;
	}
	else
	{
		data = new status;
		data->pointer = pointer;
		data->counter = 1;
	}
}

template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer& other) : data(other.data)
{
	if (data)
	{
		data->counter++;
	}
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
	Destroy();
}

template<class T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other)
{
	Destroy();

	data = other.data;
	if (data)
	{
		data->counter++;
	}

	return *this;
}

template<class T>
SharedPointer<T>& SharedPointer<T>::operator=(T* pointer)
{
	Destroy();

	if (pointer)
	{
		data = new status;
		data->pointer = pointer;
		data->counter = 1;
	}

	return *this;
}

template<class T>
void SharedPointer<T>::Destroy()
{
	if (data)
	{
		data->counter--;

		if (data->counter == 0)
		{
			delete data->pointer;
			delete data;
		}

		data = nullptr;
	}
}

template<class T>
int SharedPointer<T>::GetCounter() const
{
	return data ? data->counter : 0;
}

template<class T>
T* SharedPointer<T>::operator->()
{
	return data->pointer;
}

template<class T>
T& SharedPointer<T>::operator*()
{
	return *data->pointer;
}

template<class T>
const T& SharedPointer<T>::operator*() const
{
	return *data->pointer;
}
