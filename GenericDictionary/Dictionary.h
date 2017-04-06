#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <string>
#include <stdexcept>

#include "KeyValue.h"

template <typename H, typename J>
class Dictionary {
private:
    KeyValue* m_table[];
    unsigned int m_size = 10;
    unsigned int m_count = 0;

public:
    Dictionary();
    Dictionary(const unsigned int size);
    Dictionary(const Dictionary &obj);
    ~Dictionary() { delete[] m_table; }

    int getCount() { return m_count; };

    void add(const H key, const J value);
    const KeyValue getByKey(const H key);\
    const KeyValue getByIndex(const unsigned int i);
    void removeByKey(const H key);
    void removeByIndex(const unsigned int i);

    bool operator==(KeyValue &left, const int &right) { return left.getKey() == right; }
    bool operator==(KeyValue &left, const std::string &right) { return left.getValue() == right; }

private:
    void handleResize();
};

Dictionary::Dictionary() :
    m_table(new KeyValue*[m_size])
{
    for (unsigned int i = 0; i < m_size; ++i) m_table[i] = nullptr;
}

Dictionary::Dictionary(const unsigned int size) :
    m_size(size),
    m_table(new KeyValue*[size])
{
    for (unsigned int i = 0; i < m_size; ++i) m_table[i] = nullptr;
}

Dictionary::Dictionary(const Dictionary &obj) {
    m_table = new KeyValue*[obj.m_size];
    for (unsigned int i = 0; i < obj.m_size; ++i) m_table[i] = obj.m_table[i];
}

template <class H, class J>
void Dictionary::add(const H key, const J value) {
    if (m_count == m_size) handleResize();
    m_table[m_count++] = new KeyValue(key, value);
}

void Dictionary::handleResize() {
    unsigned int newSize = m_size * 2;
    KeyValue* temp[newSize];
    for (unsigned int i = 0; i < m_size; ++i) temp[i] = m_table[i];
    m_size = newSize;
    delete[] m_table;
    m_table = temp;
}

const KeyValue Dictionary::getByIndex(const unsigned int i) {
    if (i > m_size) throw std::out_of_range("Index is out of range");
    return *m_table[i];
}

template <class H, class J>
const KeyValue Dictionary::getByKey(const H key) {
    H temp;
    for (unsigned int i = 0; i < m_size; ++i) {
        if (m_table[i] != nullptr) {
            temp = m_table[i]->getKey();
            if (temp == key) return *m_table[i];
        }
    }

    throw std::out_of_range("Key not found");
}

template <class H, class J>
void Dictionary::removeByKey(const H key) {
    H temp;
    for (unsigned int i = 0; i < m_size; ++i) {
        if (m_table[i] != nullptr) {
            temp = m_table[i]->getKey();
            if (temp == key) {
                delete m_table[i];
                return;
            }
        }
    }

    throw std::out_of_range("Key not found");
}

void Dictionary::removeByIndex(const unsigned int i) {
    if (i > m_size) throw std::out_of_range("Index is out of range");
    delete m_table[i];
    m_table[i] = nullptr;
}

#endif //GENERICDICTIONARY_DICTIONARY_H
