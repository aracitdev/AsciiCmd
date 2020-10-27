#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <AsciiCmd/Drawables/Sprite.h>
#include <vector>
#include <AsciiCmd/Timer.h>

namespace AsciiCmd
{

class Animation
{
public:
    Animation();

    bool LoadFromFile(const std::string& filename);
    void LoadFromStream(std::istream& in);

    bool SaveToFile(const std::string& filename);
    void SaveToStream(std::ostream& out);

    uint32_t GetFrameCount(void);
    Texture& GetFrame(uint32_t counter);
    Texture& GetCurrentFrame(void);
    void Restart(void);
    void SetCurrentFrame(uint32_t index);

    uint32_t GetFrameDelay(uint32_t counter);
    void SetFrameDelay(uint32_t counter, uint32_t delay);


    void Clear(void);
    void AddFrame(const Texture& frame);
    void RemoveFrame(uint32_t index);
    void Play(void);
    void Stop(void);
    bool IsPlaying(void);
    void SetPlaying(bool in);
private:
    bool playing;
    size_t currentFrame;
    Timer clock;
    std::vector<uint32_t> delays;
    std::vector<Texture> frames;
};

}
#endif // ANIMATION_H_INCLUDED
