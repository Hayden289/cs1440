#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

template <typename H, typename J>
class KeyValue {
private:
    H m_key;
    J m_value;

public:
    KeyValue(const H key, const J value) :
        m_key(key),
        m_value(value)
    {}
    KeyValue(const KeyValue &obj);

    const H getKey() { return m_key; }
    const J getValue() { return m_value; }
};

KeyValue::KeyValue(const KeyValue &obj) {
    m_key = obj.m_key;
    m_value = obj.m_value;
}

#endif //GENERICDICTIONARY_KEYVALUE_H
