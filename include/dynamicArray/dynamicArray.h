#pragma once
#include <deque>

#define INITIAL_SIZE 128
#define INCREMENT_SIZE 4096

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(int);
    ~DynamicArray() = default;
    DynamicArray& operator=(DynamicArray& other) {return *this;};
    DynamicArray(DynamicArray& other) {};
    void set(const int, const int);
    int get(const int idx);
    void sort();
    double getMeanValue();
    double getMedianValue();
    int count() { return m_count; };

private:
    void _resize(const int idx);
    int m_count{-1};
    bool m_isEmpty{true};
    std::deque<int> m_ary;
};

