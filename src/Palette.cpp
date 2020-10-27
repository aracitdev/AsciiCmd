#include <AsciiCmd/Palette.h>
#include <AsciiCmd/PaletteFunctions.h>

namespace AsciiCmd
{


Palette::Palette(const long unsigned int* c, Vector2<uint16_t> size, const std::wstring& font)
{
    fontFile=font;
    fontSize=size;
    for(uint16_t counter=0; counter < 16; counter++)
        colors[counter]=c[counter];
}


bool Palette::SaveToFile(const std::string& filename)
{
    std::ofstream out(filename.c_str(), std::ifstream::in | std::ifstream::binary);
    if(!out.is_open())
        return false;
    SaveToStream(out);
    return true;
}

bool Palette::LoadFromFile(const std::string& filename)
{
    std::ifstream in(filename.c_str(), std::ifstream::in | std::ifstream::binary);
    if(!in.is_open())
        return false;
    LoadFromStream(in);
    return true;
}

void Palette::SaveToStream(std::ostream& out)
{
    for(uint16_t counter=0; counter < 16; counter++)
        out.write((char*)(&colors[counter]), sizeof(colors[counter]));
    out.write((char*)(&fontSize.x), sizeof(fontSize.x));
    out.write((char*)(&fontSize.y), sizeof(fontSize.y));

    size_t sz=fontFile.size();
    out.write((char*)(&sz),sizeof(sz));
    for(uint32_t counter=0; counter < fontFile.size(); counter++)
    {
        wchar_t wchar=fontFile.at(counter);
        out.write((char*)(&wchar), sizeof(wchar));
    }
}

void Palette::LoadFromStream(std::istream& in)
{
    for(uint16_t counter=0; counter < 16; counter++)
        in.read((char*)(&colors[counter]), sizeof(colors[counter]));
    in.read((char*)(&fontSize.x),sizeof(fontSize.x));
    in.read((char*)(&fontSize.y),sizeof(fontSize.y));

    size_t sz;
    in.read((char*)(&sz),sizeof(sz));
    wchar_t* buffer= new wchar_t[sz];
    for(uint32_t counter=0; counter < sz; counter++)
    {
        in.read((char*)(&buffer[counter]),sizeof(buffer[counter]));
    }
    fontFile=std::wstring(buffer,sz);
    delete[] buffer;
}

unsigned long& Palette::operator[](size_t index)
{
    return colors[index];
}

void Palette::SwapPallete(void)
{
    SetConsolePalette(colors, fontSize.x, fontSize.y, (wchar_t*)fontFile.c_str());
}


void Palette::SetFontSize(Vector2<uint16_t> newSize)
{
    fontSize=newSize;
}

Vector2<uint16_t> Palette::GetFontSize(void)
{
    return fontSize;
}

void Palette::SetFontFile(const std::wstring& file)
{
    fontFile=file;
}

std::wstring Palette::GetFontFile(void)
{
    return fontFile;
}


const unsigned long Palette::defaultPalette[16]={
    0x00000000, 0x00800000, 0x00008000, 0x00808000,
    0x00000080, 0x00800080, 0x00008080, 0x00c0c0c0,
    0x00808080, 0x00ff0000, 0x0000ff00, 0x00ffff00,
    0x000000ff, 0x00ff00ff, 0x0000ffff, 0x00ffffff
};

}
