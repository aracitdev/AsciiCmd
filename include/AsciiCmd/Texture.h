#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#include <AsciiCmd/Vector2.h>
#include <cstdint>
#include <string>
#include <fstream>

typedef struct _CHAR_INFO CHAR_INFO;

namespace AsciiCmd
{
class Texture
{
public:

    struct Pixel
    {
        uint32_t character;
        int color;
    };

    Texture();
    Texture(Vector2<uint32_t> newSize, uint32_t c, int color);
    Texture(Vector2<uint32_t> newSize);
    Texture(const Texture& tex);

    Pixel GetPixel(Vector2<uint32_t> pos);
    void SetPixel(Vector2<uint32_t> pos, uint32_t c, int color);
    void Resize(Vector2<uint32_t> newSize);
    void Clear(uint32_t character, int color);
    void Clear(void);
    bool LoadFromFile(const std::string& in);
    void LoadFromStream(std::istream& in);
    bool SaveToFile(const std::string& out);
    void SaveToStream(std::ostream& out);

    Vector2<uint32_t> GetSize(void);
private:
    CHAR_INFO* buffer;
    Vector2<uint32_t> size;
};

}
#endif // TEXTURE_H_INCLUDED
