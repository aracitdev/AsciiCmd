#include <AsciiCmd/Texture.h>
#include <windows.h>

namespace AsciiCmd
{

Texture::Texture()
{
    buffer=nullptr;
}

Texture::Texture(Vector2<uint32_t> newSize, uint32_t c, int color)
{
    buffer=nullptr;
    Resize(newSize);
    Clear(c,color);
}

Texture::Texture(Vector2<uint32_t> newSize)
{
    buffer=nullptr;
    Resize(newSize);
}

Texture::Texture(const Texture& tex)
{
    Resize(tex.size);
    for(uint32_t counterx=0; counterx < size.x; counterx++)
        for(uint32_t countery=0; countery < size.y; countery++)
        {
            buffer[countery * size.x + counterx]=tex.buffer[countery * size.x + counterx];
        }
}

Texture::Pixel Texture::GetPixel(Vector2<uint32_t> pos)
{
    CHAR_INFO& pix = buffer[pos.y * size.x + pos.x];
    return {pix.Char.UnicodeChar, pix.Attributes};
}

void Texture::SetPixel(Vector2<uint32_t> pos, uint32_t c, int color)
{
    if(pos.x < size.x && pos.y < size.y)
    {
        CHAR_INFO tmp;
        tmp.Char.UnicodeChar=c;
        tmp.Attributes=color;
        buffer[pos.y * size.x + pos.x]=tmp;
    }
}

void Texture::Resize(Vector2<uint32_t> newSize)
{
    if(buffer)
        delete[] buffer;
    size=newSize;
    buffer=new CHAR_INFO[size.x *size.y];
    Clear();
}

void Texture::Clear(uint32_t c, int color)
{
    Vector2<uint32_t> currentPos;
    for(currentPos.x=0; currentPos.x < size.x; currentPos.x++)
        for(currentPos.y=0; currentPos.y < size.y; currentPos.y++)
        SetPixel(currentPos, c,color);
}

void Texture::Clear(void)
{
    Clear(' ', 0x0f);
}

bool Texture::LoadFromFile(const std::string& filename)
{
    std::ifstream in;
    in.open(filename.c_str(), std::ifstream::in | std::ifstream::binary);
    if(!in.is_open())
        return false;
    LoadFromStream(in);
    return true;
}

void Texture::LoadFromStream(std::istream& in)
{
    in.read((char*)(&size.x),sizeof(size.x));
    in.read((char*)(&size.y),sizeof(size.y));
    Resize(size);
    for(uint32_t counterx=0; counterx < size.x; counterx++)
        for(uint32_t countery=0; countery < size.y; countery++)
        {
            WCHAR character;int color;
            in.read((char*)(&character), sizeof(character));
            in.read((char*)(&color),sizeof(character));
            buffer[counterx + size.x*countery].Char.UnicodeChar=character;
            buffer[counterx + size.x*countery].Attributes = color;
        }
}

bool Texture::SaveToFile(const std::string& file)
{
    std::ofstream out;
    out.open(file.c_str(), std::ofstream::out | std::ofstream::binary);
    if(!out.is_open())
        return false;
    SaveToStream(out);
    return true;
}

void Texture::SaveToStream(std::ostream& out)
{
    out.write((char*)(&size.x),sizeof(size.x));
    out.write((char*)(&size.y),sizeof(size.y));
    for(uint32_t counterx=0; counterx < size.x; counterx++)
        for(uint32_t countery=0; countery < size.y; countery++)
        {
            WCHAR character;int color;
            character=buffer[counterx + size.x*countery].Char.UnicodeChar;
            color=buffer[counterx + size.x*countery].Attributes;
            out.write((char*)(&character), sizeof(character));
            out.write((char*)(&color),sizeof(character));
        }
}

Vector2<uint32_t> Texture::GetSize(void)
{
    return size;
}
}
