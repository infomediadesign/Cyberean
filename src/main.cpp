#include <cstdlib>
#include <algorithm>

#include "raylib.h"

#include "config.h"
#include "../Library/tileson.hpp"
#include "masterhead.h"
#include "mainmenu.h"
#include "musicplayer.h"
#include "gameszene.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "levelselect.h"
#include "credits.h"
#include "cutscene.h"
#include "storymode.h"
#include "cutscene2.h"
#include "cutscene3.h"
#include "cutscene4.h"
#include "cutscene5.h"
#include "TextureManager.h"

//#pragma comment(linker, "/SUBSYSTEM:windows/ENTRY:mainCRTStartup")

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    TextureManager::InitializeTextures();
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};

    Color backgroundColor = BLACK;
    float fadeSpeed = 2.0f;
    float fadeAlpha = 0.0f;
    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");

    Font myFont = LoadFont("assets/font/7pixelsOfPerfection.ttf");

    SetExitKey(0);

    int storymodestage = 0;

    globalState state = mainMenu;

    InitAudioDevice();

    SoundPlayer soundPlayer;

    mainmenu themenu(&soundPlayer);

    MusicPlayer musicPlayermenu;

    levelselect thelevelselect(&soundPlayer, &musicPlayermenu);
    credits thecredits(&soundPlayer, &musicPlayermenu);

    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/cyberean_mainmenu.wav", MusicState::MainMenu);
    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/credits.wav", MusicState::credits);
    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/cutscenes.wav", MusicState::cutscene);

    musicPlayermenu.PlayMusic(MusicState::MainMenu);

    std::unique_ptr<gameScene> gs = nullptr;
    std::unique_ptr<storymode> mystorymode = nullptr;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_F)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth, Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }

        switch (state) {
            case mainMenu:
                themenu.update(state);
                musicPlayermenu.PlayMusic(MusicState::MainMenu);
                break;
            case gameplay:
                if (gs == nullptr) {
                    gs = std::make_unique<gameScene>(masterlevel, &musicPlayermenu, &soundPlayer);
                }
                if (gs->restart == true) {
                    gs = nullptr;
                    gs = std::make_unique<gameScene>(masterlevel, &musicPlayermenu, &soundPlayer);
                }
                gs->update(state);
                break;
            case levelselection:
                thelevelselect.update(state);
                break;
            case creditsscreen:
                thecredits.update(state);
                break;
            case cutscenescreen:
                break;
            case storymodesection:
                if (mystorymode == nullptr) {
                    mystorymode = std::make_unique<storymode>();
                    musicPlayermenu.StopMusic();
                }
                if (mystorymode != nullptr) {
                    mystorymode->update(state);
                    musicPlayermenu.StopMusic();
                }
                break;
            default:
                break;
        }

        if (state == mainMenu && gs != nullptr) {
            gs = nullptr;
        }

        if(storystate == 10 && state == mainMenu){
            storystate = 0;
            mystorymode->reset();
        }

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instead
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(BLACK);
            switch (state) {
                case mainMenu:
                    themenu.draw();
                    themenu.buttons();
                    musicPlayermenu.Update();
                    musicPlayermenu.SetAllMusicVolume(masterMusicControl);
                    thelevelselect.fadeout = false;
                    thelevelselect.alpha = 0.0f;
                    storymodeactive = false;
                    storymodestage = 0;
                    break;
                case gameplay:
                    if (gs != nullptr && state == gameplay) {
                        gs->draw();
                    }
                    if (gs == nullptr && state == gameplay) {
                        thelevelselect.draw();
                    }
                    break;
                case levelselection:
                    thelevelselect.draw();
                    break;
                case creditsscreen:
                    thecredits.draw();
                    break;
                case cutscenescreen:
                    break;
                case storymodesection:
                    if (mystorymode != nullptr && state == storymodesection) {
                        mystorymode->draw();
                    }
                    break;
                default:
                    break;
            }
        }
        EndTextureMode();
        //The following lines put the canvas in the middle of the window and have the negative as black
        ClearBackground(BLACK);
        renderScale = std::min(GetScreenHeight() /
                               (float) canvas.texture.height, //Calculates how big or small the canvas has to be rendered.
                               GetScreenWidth() / (float) canvas.texture.width);
        renderRec.width = canvas.texture.width * renderScale;
        renderRec.height = canvas.texture.height * renderScale;
        renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
        renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;
        DrawTexturePro(canvas.texture, Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                       renderRec,
                       {}, 0, WHITE);
        EndDrawing();

        musicPlayermenu.Update();


    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();
    musicPlayermenu.StopMusic();

    CloseAudioDevice();

    return EXIT_SUCCESS;
}