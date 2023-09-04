#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#pragma once

#include <raylib.h>
#include <map>
#include <string>

enum class MusicState {
    MainMenu,
    part_1,
    part_2,
    part_3,
    part_4,
    part_5,
    credits,
    cutscene,
    // Weitere Zustände hier hinzufügen, wenn nötig
};

class MusicPlayer {
public:
    MusicPlayer();

    ~MusicPlayer();

    void LoadMusic(const std::string &filename, MusicState state);

    void UnLoadMusic();

    void PlayMusic(MusicState state);

    void StopMusic();

    void StopAllMusic();

    void StopAllMusicExceptMainMenu();

    void SetMusicVolume(float volume);

    void SetAllMusicVolume(float volume);

    void Update();

    MusicState GetCurrentMusicState();

private:
    std::map<MusicState, Music> musicMap;
    MusicState currentMusicState;
};

#endif // MUSICPLAYER_H