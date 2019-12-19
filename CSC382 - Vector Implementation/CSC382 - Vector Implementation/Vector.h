// Data Structures and Algorithm Analysis
// Page 87
// CSC382 - Data Structures and Algorithms
// Shows how to create and implement a useable vector.

#pragma once

#include <algorithm>

template <typename Object>
class Vector
{
public:
	// The constructor below allows the user to specify an initial size, defaulting to 0 (initSize). Then it initializes the data members,
	// with the capacity just slightly larger than the size so push-backs can be made without the need for a capacity change.
	explicit Vector(int initSize = 0) : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
	{
		objects = new Object[theCapacity];
	}

	/* The copy constructor (The copy constructor is a constructor which creates an object by initializing it with an object of 
	the same class, which has been created previously. The copy constructor is used to − Initialize one object from another of 
	the same type. Copy an object to pass it as an argument to a function.) below makes a new Vector which can be used by a casual 
	implementation of operator=.*/
	Vector(const Vector& rhs) : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
	{
		objects = new Object[theCapacity];
		for (int k = 0; k < theSize; ++k)
		{
			objects[k] = rhs.objects[k];
		}
	}

	Vector& operator= (const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	// Destructor
	~Vector()
	{
		delete[] objects;
	}

	// Swapping done by moving using the code below.
	Vector(Vector&& rhs) : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
	{
		rhs.objects = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	Vector& operator= (Vector&& rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std:swap(objects, rhs.objects);
	}

	// Resize routine below. This code sets theSize data member, after possibly expanding the capacity. This is very expensive to do.
	// If the capacity is expanded, it doubles in size to prevent capacity changes again unless a very large size increase is needed.
	void resize(int newSize)
	{
		if (newSize > theCapacity)
		{
			reserve(newSize * 2);
		}

		theSize = newSize;
	}

	// Reserve routine below. Consists of allocation of a new array (Object *newArray), moving the old content and then reclaiming the old array.
	// Reserve can be used to shrink the underlying array, but only if the specified new capacity is at least as large as the size.
	// If not, the reserve request will be ignored.
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
		{
			return;
		}

		Object* newArray = new Object[newCapacity];

		for (int k = 0; k < theSize; ++k)
		{
			newArray[k] = std::move(objects[k]);
		}

		theCapacity = newCapacity;
		std::swap(objects, newArray);
		delete[] newArray;
	}

	// 2 operator[] below are trivial.
	Object& operator[](int index)
	{
		return objects[index];
	}

	const Object& operator[](int index) const
	{
		return objects[index];
	}

	// Error handling
	// Check to see if the vector is empty.
	bool empty() const
	{
		return size() == 0;
	}

	// Return the size of the vector.
	int size() const
	{
		return theSize;
	}

	// Return the capacity of the vector
	int capacity() const
	{
		return theCapacity;
	}

	// Short routines
	// push_back adds a new element to the vector. Currently unsure of why there are two push_back functions but it likely has something to do with
	// the copy constructor and different arguments.
	void push_back(const Object& x)
	{
		if (theSize == theCapacity)
		{
			reserve(2 * theCapacity + 1);
		}

		objects[theSize++] = x;
	}

	void push_back(Object&& x)
	{
		if (theSize == theCapacity)
		{
			reserve(2 * theCapacity + 1);
		}

		objects[theSize++] = std::move(x);
	}

	// pop_back removes an element at the end of the vector.
	void pop_back()
	{
		--theSize;
	}

	const Object& back() const
	{
		return objects[theSize - 1];
	}

	// Creates an iterator object.
	typedef Object* iterator;
	typedef const Object* const_iterator;

	// References the iterator to the beginning of the vector.
	iterator begin()
	{
		return &objects[0];
	}

	const_iterator begin() const
	{
		return &objects[0];
	}

	// References the iterator to the end of the vector.
	iterator end()
	{
		return &objects[size()];
	}

	const_iterator end() const
	{
		return &objects[size()];
	}

	static const int SPARE_CAPACITY = 16;

private:
	int theSize;
	int theCapacity;
	Object* objects;
};