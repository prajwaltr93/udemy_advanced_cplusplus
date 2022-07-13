// template has to defined in headers, only exception
#include<initializer_list>

template <class t>
class ring {
    private:
        int size;
        t *store; 
        int pos;
    
    public:
        class iterator; // this forward declaration would not have worked if this were a .cpp file
    public:
        ring(int i) : size(i), store(NULL), pos(0) {
            store = new t[size];
        }
        
        ring(std::initializer_list<int> init_list, int size) {
            size = init_list.size();
            pos = 0;
            store = new t[size];
            for(auto temp : init_list) {
                this->add(temp);
            }
        }
        
        ~ring() {
            delete[] store;
        }

        void add(t value) {
            store[pos++] = value;
            pos = pos % size;
        }

        int get_size(void) {
            return size;
        }

        int get(int index) {
            return store[index];
        }

        iterator begin() {
            return iterator(0, *this);
        }

        iterator end() {
            return iterator(size, *this);
        }
};

template<typename t>
class ring<t>::iterator {
    public:
        int m_pos;
        ring<t> &instance;
        iterator(int i, ring<t> &ins) : m_pos(i), instance(ins) {
        }

        void operator++(int) {
            m_pos++;
        }
        void operator++() {
            ++m_pos;
        }

        t operator*() {
            return instance.get(m_pos);
        }
        
        bool operator!=(const iterator &other) const {
            return m_pos != other.m_pos;
        }
};