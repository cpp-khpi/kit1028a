#pragma once
#include "Counter.h"

template <class T>
class smart_pointer : private Counter<T> {
	T *m_obj;
public:
	using Counter<T>::GetCount;
	smart_pointer(T *obj)
		: m_obj(obj)
	{
	}
	~smart_pointer() {
		delete m_obj;
	}
	T* operator->() { return m_obj; }
	T& operator* () { return *m_obj; }
};