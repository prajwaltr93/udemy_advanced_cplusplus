// define bitmap definitions here
#include "bitmap.h"
#include "fileinfoheader.h"
#include "bitmapheader.h"
#include <fstream>

bitmap::bitmap(int w, int h) : m_w(w), m_h(h), m_memory(new uint8_t[3 * m_w * m_h]{}) { }

bool bitmap::write_to_file(string fn) {
    BitMapFileHeader fileheader;
    BitmapInfoHeader infoheader;

    fileheader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitmapInfoHeader) + m_w * m_h * 3; // multiplication first precedence
    fileheader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitmapInfoHeader);

    infoheader.height = m_h;
    infoheader.width = m_w;

    ofstream fhandler;
    fhandler.open(fn, ios::out | ios::binary);

    if (fhandler) {
        fhandler.write((char *)&fileheader, sizeof(fileheader));
        fhandler.write((char *)&infoheader, sizeof(infoheader));
        fhandler.write((char *)m_memory.get(), (3 * m_h * m_w));
        fhandler.close();
        return true;
    }

    return false;
}

void bitmap::set_pixel(int x, int y, uint8_t r, uint8_t g,uint8_t b) {
    auto p_index = m_memory.get(); // uint8_t
    p_index += (y * 3) * m_w + (x * 3);
    *p_index = b; // pointer arithematic instead of indexing []
    *(p_index + 1) = g;
    *(p_index + 2) = r;
}

bitmap::~bitmap() {

}