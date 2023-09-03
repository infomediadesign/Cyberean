#include "musicplayer.h"

MusicPlayer::MusicPlayer() {
    currentMusicState = MusicState::MainMenu;
}

MusicPlayer::~MusicPlayer() {
    StopMusic();

    for (auto &pair: musicMap) {
        UnloadMusicStream(pair.second);
    }

}

void MusicPlayer::LoadMusic(const std::string &filename, MusicState state) {
    Music music = LoadMusicStream(filename.c_str());
    musicMap[state] = music;
}


void MusicPlayer::UnLoadMusic() {

    for (auto &pair: musicMap) {
        UnloadMusicStream(pair.second);
    }
}


void MusicPlayer::PlayMusic(MusicState state) {

    auto it = musicMap.find(state);
    if (it != musicMap.end()) {
        currentMusicState = state;
        PlayMusicStream(it->second);
    }
}

void MusicPlayer::StopMusic() {
    StopMusicStream(musicMap[currentMusicState]);
}

void MusicPlayer::StopAllMusic() {
    for (auto &pair : musicMap) {
        StopMusicStream(pair.second);
    }
}

void MusicPlayer::StopAllMusicExceptMainMenu() {
    for (auto &pair : musicMap) {
        if (pair.first != MusicState::MainMenu) {
            StopMusicStream(pair.second);
        }
    }
}


void MusicPlayer::SetMusicVolume(float volume) {
    ::SetMusicVolume(musicMap[currentMusicState], volume);
}

void MusicPlayer::SetAllMusicVolume(float volume) {
    for (auto &pair : musicMap) {
        SetMusicVolume(volume);
    }
}

void MusicPlayer::Update() {
    UpdateMusicStream(musicMap[currentMusicState]);
}

MusicState MusicPlayer::GetCurrentMusicState() {
    return currentMusicState;
}