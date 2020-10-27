#include <AsciiCmd/Animation.h>

namespace AsciiCmd
{

Animation::Animation()
{
    playing=true;
}

bool Animation::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ifstream::in | std::ifstream::binary);
    if(!file.is_open())
        return false;
    LoadFromStream(file);
    return true;
}

bool Animation::SaveToFile(const std::string& filename)
{
    std::ofstream file(filename.c_str(), std::ofstream::out | std::ofstream::binary);
    if(!file.is_open())
        return false;
    SaveToStream(file);
    return true;
}

void Animation::SaveToStream(std::ostream& out)
{
    size_t animationCount=frames.size();
    out.write((char*)(&animationCount),sizeof(animationCount));
    for(uint32_t counter=0; counter < animationCount; counter++)
    {
        out.write((char*)(&delays[counter]), sizeof(delays[counter]));
        frames[counter].SaveToStream(out);
    }
}

void Animation::LoadFromStream(std::istream& in)
{
    size_t animationCount;
    in.read((char*)(&animationCount), sizeof(animationCount));
    frames.resize(animationCount);
    delays.resize(animationCount);
    for(uint32_t counter=0; counter < animationCount; counter++)
    {
        in.read((char*)(&delays[counter]), sizeof(delays[counter]));
        frames[counter].LoadFromStream(in);
    }
}

uint32_t Animation::GetFrameCount(void)
{
    return frames.size();
}

Texture& Animation::GetFrame(uint32_t counter)
{
    return frames[counter];
}

void Animation::Clear(void)
{
    frames.clear();
}

uint32_t Animation::GetFrameDelay(uint32_t counter)
{
    return delays[counter];
}

void Animation::SetFrameDelay(uint32_t counter, uint32_t delay)
{
    delays[counter]=delay;
}

void Animation::AddFrame(const Texture& frame)
{
    frames.push_back(frame);
    delays.push_back(0);
}


Texture& Animation::GetCurrentFrame(void)
{
    if(currentFrame >= frames.size())
        currentFrame=0;
    if(clock.GetTime().AsMilliseconds() > delays[currentFrame] && playing)
    {
        currentFrame=(currentFrame+1)%frames.size();
        clock.Restart();
    }
    return frames[currentFrame];
}

void Animation::Restart(void)
{
    playing=true;
    clock.Restart();
    currentFrame=0;
}

void Animation::SetCurrentFrame(uint32_t index)
{
    currentFrame=index%frames.size();
}

void Animation::RemoveFrame(uint32_t index)
{
    frames.erase(frames.begin()+index);
    delays.erase(delays.begin()+index);
}

void Animation::Stop(void)
{
    playing=false;
}

void Animation::Play(void)
{
    playing=true;
}


bool Animation::IsPlaying(void)
{
    return playing;
}

void Animation::SetPlaying(bool in)
{
    playing=in;
}

}
