#include <iostream>
#include <stack>
#include <cstring>

template<typename T>
class stack
{
public:
                stack();
                stack(const stack& other);
    stack&      operator=(const stack& other);
                ~stack();

    void        push(const T& elem);
    void        pop() { --m_size; }
    T&          top() { return m_data[m_size - 1]; }
    const T&    top() const { return m_data[m_size - 1]; }
    bool        empty() const { return !m_size; }
    size_t      size() const { return m_size; }
    
    friend void swap(stack& lhs, stack& rhs)
    {
        using std::swap;
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_capacity, rhs.m_capacity);
        swap(lhs.m_size, rhs.m_size);
    }
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;
    
    void resize(size_t newCapcity);
};

template<typename T>
stack<T>::stack():
    m_size(0),
    m_capacity(8),
    m_data(new T[m_capacity])
{}

template<typename T>
stack<T>::stack(const stack& other):
    m_size(other.m_size),
    m_capacity(other.m_capacity),
    m_data(new T[other.m_capacity])
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

template<typename T>
stack<T>& stack<T>::operator=(const stack& other)
{
    if (this != &other)
    {
        if (m_capacity < other.m_capacity)
        {
            using std::swap;
            stack tmp = other;
            swap(*this, tmp);
            m_size = other.m_size;
            m_capacity = other.m_capacity;
        }
        else
        {
            m_size = other.m_size;
            for (size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }
    }
    
    return *this;
}

template<typename T>
stack<T>::~stack()
{
    delete [] m_data;
}

template<typename T>
void stack<T>::resize(size_t newCapacity)
{
    m_capacity = newCapacity;
    T* tmp = m_data;
    m_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = tmp[i];
    }
    delete [] tmp;
}

template<typename T>
void stack<T>::push(const T& elem)
{
    if (m_size == m_capacity)
    {
        resize((m_capacity * 3 + 1) / 2);
    }
    
    m_data[m_size++] = elem;
}

int main(int argc, char const *argv[])
{
    stack<int> x;
    x.push(10);
    std::cout << x.top() << std::endl;
    x.top() = 30;
    std::cout << x.top() << std::endl;
    stack<int> y = x;
    std::cout << y.top() << std::endl;
    stack<int> z;
    z = x;
    std::cout << z.top() << std::endl;
}
