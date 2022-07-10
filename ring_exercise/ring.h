// template has to defined in headers, only exception
template <class t>
class ring {
    private:
        int size;
        t *store; 
        int pos;
    public:
        ring(int i) : size(i), store(NULL), pos(0) {
            store = new t[size];
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
};