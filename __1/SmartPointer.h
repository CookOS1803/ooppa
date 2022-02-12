#pragma once

template <class T>
class SmartPointer
{
	struct status
	{
		T* pointer;
		int counter;
	};

	status* data;

public:

	SmartPointer();
	SmartPointer(T* pointer);
	SmartPointer(const SmartPointer& other);
	~SmartPointer();

	int GetCounter() const;
	void Destroy();

	SmartPointer<T>& operator=(const SmartPointer& other);
	T* operator->();

};

template<class T>
inline SmartPointer<T>::SmartPointer() : data(nullptr) {}

template<class T>
SmartPointer<T>::SmartPointer(T* pointer)
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
SmartPointer<T>::SmartPointer(const SmartPointer& other) : data(other.data)
{
	if (data)
	{
		data->counter++;
	}
}

template<class T>
inline SmartPointer<T>::~SmartPointer()
{
	Destroy();
}

template<class T>
inline int SmartPointer<T>::GetCounter() const
{
	return data ? data->counter : 0;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& other)
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
inline T* SmartPointer<T>::operator->()
{
	return data ? data->pointer : nullptr;
}

template<class T>
void SmartPointer<T>::Destroy()
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