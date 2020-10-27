#ifndef PALETTE_H_INCLUDED
#define PALETTE_H_INCLUDED
#include <fstream>
#include <string>
#include <AsciiCmd/Vector2.h>

namespace AsciiCmd
{

class Palette
{
public:
    static const unsigned long defaultPalette[16];

    Palette(const long unsigned int* c = defaultPalette, Vector2<uint16_t> fontSize=Vector2<uint16_t>(8,8), const std::wstring& font=L"Cour.ttf");
    bool LoadFromFile(const std::string& filename);
    void LoadFromStream(std::istream& in);
    void SaveToStream(std::ostream& out);
    bool SaveToFile(const std::string& filename);

    unsigned long& operator[](size_t v);
    void SwapPallete(void);

    void SetFontSize(Vector2<uint16_t> newSize);
    Vector2<uint16_t> GetFontSize(void);

    void SetFontFile(const std::wstring& file);
    std::wstring GetFontFile(void);

    const uint32_t colorCount=16;
private:
    unsigned long colors[16];
    Vector2<uint16_t> fontSize;
    std::wstring fontFile;
};

}
#endif // PALETTE_H_INCLUDED
