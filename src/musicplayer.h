#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#pragma once
#include <raylib.h>
#include <map>
#include <string>

enum class MusicState {
    MainMenu,
    Lvl1,
    Lvl1_part1,
    Lvl1_part2,
    Lvl1_part3,
    Lvl1_part4,
    Lvl1_part5,
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
    MusicState GetCurrentMusicState();

private:
    std::map<MusicState, Music> musicMap;
    MusicState currentMusicState;
};

#endif // MUSICPLAYER_H