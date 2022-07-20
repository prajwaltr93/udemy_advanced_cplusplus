#include<cstdint>
#include<memory>
#include<string>

using namespace std;

struct bitmap {
    private:
        int m_w{0};
        int m_h{0};
        unique_ptr<uint8_t[]> m_memory{nullptr};
    
    public:
        bitmap(int w, int h);
        bool write_to_file(string fn);
        void set_pixel(int x, int y, uint8_t r, uint8_t g,uint8_t b);
        ~bitmap(); // unique_ptr should deallocate itself when out of scope
};