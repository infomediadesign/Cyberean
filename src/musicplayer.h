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
    part_1,
    part_2,
    part_3,
    part_4,
    part_5,
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