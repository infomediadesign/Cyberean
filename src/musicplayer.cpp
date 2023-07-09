#include "musicplayer.h"

MusicPlayer::MusicPlayer() {
    InitAudioDevice();
    currentMusicState = MusicState::MainMenu;
}

MusicPlayer::~MusicPlayer() {
    StopMusic();

    for (auto& pair : musicMap) {
        UnloadMusicStream(pair.second);
    }

    CloseAudioDevice();
}

void MusicPlayer::LoadMusic(const std::string& filename, MusicState state) {
    Music music = LoadMusicStream(filename.c_str());
    musicMap[state] = music;
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

void MusicPlayer::SetMusicVolume(float volume) {
    ::SetMusicVolume(musicMap[currentMusicState], volume);
}

void MusicPlayer::Update() {
    UpdateMusicStream(musicMap[currentMusicState]);
}