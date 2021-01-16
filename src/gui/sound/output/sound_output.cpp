#include "sound_output.hpp"

using namespace std;

void SoundOutput::startSoundThread()
{
    this->thread = std::thread(&SoundOutput::soundThreadWrapper, this);
}

void SoundOutput::soundThreadWrapper()
{
    try {
        this->soundThread();
    } catch (string message) {
        wxMessageBox(message);
    } catch (const char* message) {
        wxMessageBox(message);
    }
}