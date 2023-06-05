#pragma once
#include <iostream>
#include <exception>

template<typename Key, typename Value>
class MyMap
{
public:
    MyMap();
    MyMap(Key& key, Value& value);
    ~MyMap();
    int size() const;
    void add(const Key& key, const Value& value);
    void remove(const Key& key);
    void print()const;
    Value find(const Key& key) const;
private:
    struct Map
    {
        Key key;
        Value value;
        Map(const Key& _key, const Value& _value);
    };
    Map** map;
    int count = 0;
};

template<typename Key, typename Value>
MyMap<Key, Value>::Map::Map(const Key& _key, const Value& _value)
{
    key = _key;
    value = _value;
}

template<typename Key, typename Value>
MyMap<Key, Value>::MyMap(){}

template<typename Key, typename Value>
MyMap<Key, Value>:: MyMap(Key& key, Value& value) : count(1)
{
    map = new Map(key, value);
}

template<typename Key, typename Value>
MyMap<Key, Value>::~MyMap()
{
    for(int i = 0; i < count; ++i)
        delete (map+i);
}

template<typename Key, typename Value>
int MyMap<Key, Value>::size() const
{
    return count;
}

template<typename Key, typename Value>
void MyMap<Key, Value>::add(const Key& key, const Value& value)
{
    bool flag = true;
    for(int i = 0 ; i < count; ++i)
    {
        if(map[i]->key == key)
        {
            map[i]->key = key;
            map[i]->value = value;
            flag = false;
            break;
        }
    }
    if(flag)
    {
        map[count++] = new Map(key, value);
    }
}

template<typename Key, typename Value>
void MyMap<Key, Value>::remove(const Key& key)
{
    for(int i = 0; i < count; ++i)
    {
        if(key == map[i]->key)
        {
            for(int j = (i + 1); j < count; ++j, ++i)
            {
                map[i]->key = map[j]->key;
                map[i]->value = map[j]->value;
            }
            delete map[--count];
            ++i;
        }
    }
}

template<typename Key, typename Value>
void MyMap<Key, Value>::print() const
{
    for(int i = 0; i < count ; ++i)
    {
        for(int j = 0; j < 40 ; ++j)
            std::cout << "-";
        std::cout << "\nKey - " << map[i]->key << " value - " << map[i]->value << std::endl;
    }
}

template<typename Key, typename Value>
Value MyMap<Key, Value>::find(const Key& key) const
{
    try
    {
        for (int i = 0; i < count; ++i)
        {
            if(key == map[i]->key)
            {
                return map[i]->value;
            }
        }
        throw "The search failed. An element with such a key is missing.";
    }
    catch (const char* error_message)
    {
        std::cerr << error_message << std::endl;
    }
}
