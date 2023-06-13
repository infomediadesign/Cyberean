#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <raylib.h>
#include <map>
#include <string>

enum class MusicState {
    MainMenu,
    Lvl1,
    // Weitere Zustände hier hinzufügen, wenn nötig
};

class MusicPlayer {
public:
    MusicPlayer();
    ~MusicPlayer();

    void LoadMusic(const std::string& filename, MusicState state);
    void PlayMusic(MusicState state);
    void StopMusic();
    void SetMusicVolume(float volume);
    void Update();

private:
    std::map<MusicState, Music> musicMap;
    MusicState currentMusicState;
};

#endif // MUSICPLAYER_H