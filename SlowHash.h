#pragma once
#include <iostream>

template <typename KeyT, typename ValueT>
class SlowHash
{
	KeyT *key;
	ValueT *value;
	unsigned size, capacity;
public:
	SlowHash()
	{
		capacity = 20;
		size = 0;
		key = new KeyT[capacity];
		value = new ValueT[capacity];
	}
	SlowHash(const SlowHash<KeyT,ValueT> &other)
	{
		size = other.size;
		capacity = other.capacity;
		key = new KeyT[other.capacity];
		value = new ValueT[other.capacity];
		for (unsigned int = 0; i < size; i++)
		{
			key[i] = other.key[i];
			value[i] = other.calue[i];
		}
	}
	~SlowHash()
	{
		delete[] key;
		delete[] value;
	}
	void operator = (const SlowHash<KeyT, ValueT> &other)
	{
		if (!(this == &other))
		{
			delete[] key;
			delete[] value;
			size = other.size;
			capacity = other.capacity;
			key = new KeyT[other.capacity];
			value = new ValueT[other.capacity];
			for (unsigned int = 0; i < size; i++)
			{
				key[i] = other.key[i];
				value[i] = other.calue[i];
			}
		}
	}
	void add(KeyT _key, ValueT _value)
	{
		for (unsigned i = 0; i < size; i++)
		{
			if (key[i] == _key) break;
		}
		if (size < capacity)
		{
			key[size] = _key;
			value[size] = _value;
			size++;
		}
		else
		{
			capacity *= 2;
			KeyT *n_key = new KeyT[capacity];
			ValueT *n_value = new ValueT[capacity];
			for (unsigned i = 0; i < size; i++)
			{
				n_key[i] = key[i];
				n_value[i] = value[i];
			}
			n_key[size] = _key;
			n_value[size] = _value;
			key = n_key;
			value = n_value;
			size++;
		}
	}
	void remove(KeyT _key)
	{
		for (unsigned i = 0; i < size; i++)
		{
			if (key[i] == _key)
			{
				KeyT *n_key = new KeyT[capacity];
				ValueT *n_value = new ValueT[capacity];
				for (unsigned k = 0; k < i; k++)
				{
					n_key[k] = key[k];
					n_value[k] = value[k];
				}
				for (unsigned k = i+1; k < size; k++)
				{
					n_key[k] = key[k];
					n_value[k] = value[k];
				}
				key = n_key;
				value = n_value;
				size--;
				break;
			}
		}
	}
	bool has_key(KeyT _key)
	{
		for (unsigned i = 0; i < size; i++)
		{
			if (key[i] == _key) return true;
		}
		return false;
	}
	ValueT get_value(KeyT _key)
	{
		for (unsigned i = 0; i < size; i++)
		{
			if (key[i] == _key) return value[i];
		}
		return 0;
	}
};