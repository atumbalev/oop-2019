#include <iostream>
#include <cassert>
#include <initializer_list>
#include <algorithm>
#include <stack>

template<class T>
class forward_list
{
private:
    struct node;
public:
    // Types required to work as a container for different adapters
    // Generally a good practice to use size_type instead of size_t in the implementation (avoid conflicts)
    using value_type = T;
    using reference = T&;
    using size_type = size_t;
    using const_reference = const T&;
    class iterator
    {
     public:
        // Types required for certain algorithms
        using value_type = T;
        using difference_type = size_t;  // Only needed for random_access iterators (e.g for vector)
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;
        iterator(node* ptr = nullptr): m_ptr{ptr} {}
        iterator& operator++()
        {
            assert(m_ptr);
            m_ptr = m_ptr->m_next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T& operator*()
        {
            return m_ptr->m_data;
        }

        const T& operator*() const
        {
            return m_ptr->m_data;
        }

        T* operator->()
        {
            return &m_ptr->m_data;
        }

        const T* operator->() const
        {
            return &m_ptr->m_data;
        }

        bool operator==(const iterator& other) const
        {
            return (other.m_ptr == m_ptr);
        }

        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }
     private:
        node* m_ptr;
    };
    forward_list(): m_start{nullptr}, m_size{0} {}
    ~forward_list()
    {
        // TODO: rewrite using pop_front / erase
        node* tmp = m_start;
        while(tmp)
        {
            tmp = tmp->m_next;
            delete m_start;
            m_start = tmp;
        }
    }

    template<class InputIt>
    forward_list(InputIt begin, InputIt end); // Copy contents from one iterator to the other, Use insert_after / push_front
    // templated because list and initializer_list use different kinds of iterators

    forward_list(const forward_list& other): m_size{other.m_size}
    {
        // TODO: rewrite using forward_list(InputIt, InputIt) with other.begin(), other.end()
        if (empty())
        {
            m_start = new node{other.m_start->m_data};
        }

        node* p1 = other.m_start->m_next;
        node* p2 = m_start;
        while(p1)
        {
            p2->m_next = new node{p1->m_data};
            p1 = p1->m_next;
            p2 = p2->m_next;
        }
    }

    forward_list(const std::initializer_list<int>& ls)
    {
        // TODO: rewrite using forward_list(InputIt, InputIt) with ls.begin(), ls.end()
        for (auto it = ls.end() - 1; it != ls.begin() - 1; --it)  // UGH, be we only implemented push_front (you reap what you sow)
        {
            push_front(*it);
        }
    }

    forward_list& operator=(const forward_list& other); // TODO
    // VERY GOOD IDEA to use copy and swap idiom

    void push_front(const T& elem)
    {
        m_start = new node{elem, m_start};
        m_size++;
    }

    void pop_front()
    {
        assert(!empty());
        node * tmp = m_start;
        m_start = m_start->m_next;
        delete tmp;
        m_size--;
    }

    bool empty() const
    {
        return !m_start;
    }

    size_t size() const
    {
        return m_size;
    }

    T& front()
    {
        return m_start->m_data;
    }

    const T& front() const
    {
        return m_start->m_data;
    }

    iterator begin() const
    {
        return iterator(m_start);
    }

    iterator end() const
    {
        return iterator(nullptr);
    }
private:
    struct node
    {
        T m_data;
        node* m_next = nullptr;
    };

    node* m_start = nullptr;
    size_t m_size = 0;
};

int main()
{
    // Initialize with initializer list
    forward_list<int> a = {1,2,3};

    for (const int& num : a)
    {
        // Can be read as FOR EVERY ELEMENT const int& IN THE CONTAINER, EXECUTE THE LOOP BODY
        // Requires begin(), end() (or cbegin, cend) that return an iterator with ++, != and * 
        std::cout << num << std::endl;
    }

    // Works with algorithms
    std::for_each(a.begin(), a.end(), [](int x) { std::cout << x << " "; });

    // This algorithm requires the member types that we have provided
    auto found = std::find(a.begin(), a.end(), 3);
    std::cout << *found;

    // Container for a stack (requires member types)
    std::stack<int, forward_list<int>> st; // This compiles, but won't work because it requires push_back and back that we don't have (you can rename push_front and front to test)
    
    return 0;
}