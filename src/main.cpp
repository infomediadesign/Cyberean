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
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};

    SetExitKey(0);

    bool isMusicPlaying = false;

    globalState state = mainMenu;

    InitAudioDevice();

    SoundPlayer soundPlayer;

    mainmenu themenu(&soundPlayer);

    MusicPlayer musicPlayermenu;

    levelselect thelevelselect(&soundPlayer, &musicPlayermenu);
    credits thecredits(&soundPlayer, &musicPlayermenu);
    cutscene thecutscene(&soundPlayer, &musicPlayermenu);

    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/cyberean_mainmenu.wav", MusicState::MainMenu);
    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/credits.wav", MusicState::credits);
    musicPlayermenu.LoadMusic("assets/audio/tracks/misc/cutscenes.wav", MusicState::cutscene);


    musicPlayermenu.PlayMusic(MusicState::MainMenu);

    MusicState previousState = MusicState::MainMenu; // Variable zum Speichern des vorherigen Zustands
    MusicState currentState = MusicState::MainMenu; // Variable zum Speichern des aktuellen Zustands
    //musicPlayermenu.PlayMusic(currentState); // Starten der Hintergrundmusik im Hauptmenü

    std::unique_ptr<gameScene> gs = nullptr;
    //gameScene gs(0, &musicPlayermenu, &musicPlayer1, &musicPlayer2, &musicPlayer3, &musicPlayer4, &musicPlayer5, &soundPlayer);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER)) { //Fullscreen logic.
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
                if(gs->restart == true){
                    gs = nullptr;
                    gs = std::make_unique<gameScene>(masterlevel, &musicPlayermenu,  &soundPlayer);
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
                thecutscene.update(state);
                break;
            default:
                break;
        }

        if (state == mainMenu && gs != nullptr) {
                gs = nullptr;
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
                    currentState = MusicState::MainMenu;
                    musicPlayermenu.SetAllMusicVolume(masterMusicControl);
                    break;
                case gameplay:
                    if (gs != nullptr && state == gameplay) {
                        gs->draw();
                    }
                    if (gs == nullptr && state == gameplay) {
                        if(thecutscene.cutsceneaktiv == false){
                            thelevelselect.draw();
                        }else{
                            thecutscene.draw();
                        }
                    }
                    break;
                case levelselection:
                    thelevelselect.draw();
                    break;
                case creditsscreen:
                    thecredits.draw();
                    break;
                case cutscenescreen:
                    thecutscene.draw();
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

void toDrawOnScreen(tson::Map *theMap, Texture &mapTex) {
    Rectangle sourceRec{};
    sourceRec.width = 32;
    sourceRec.height = 32;
    Vector2 destVec{};
    int tilesetColumns = 8;
    float tileSize = 32;
    int tileMapColumns = theMap->getSize().x;
    int tileMapRows = theMap->getSize().y;
    for (int y = 0; y < tileMapRows; y++) {
        for (int x = 0; x < tileMapColumns; x++) {
            int tileData = theMap->getLayer("main")->getTileData(x, y)->getId() - 1; //-1 because tiled does stuff >:(
            sourceRec.x = (tileData % tilesetColumns) * tileSize;
            sourceRec.y = (tileData / tilesetColumns) * tileSize;
            destVec.x = x * tileSize;
            destVec.y = y * tileSize;
            DrawTextureRec(mapTex, sourceRec, destVec, WHITE);
        }
    }
}