#include <cstdlib>
#include <algorithm>

#include "raylib.h"

#include "config.h"
#include "../Library/tileson.hpp"
#include "masterhead.h"
#include "mainmenu.h"
#include "musicplayer.h"
#include "gameszene.h"

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

    bool isMusicPlaying = false;

    globalState state = mainMenu;

    mainmenu themenu;
    //musik initialisier stuff
    MusicPlayer musicPlayer;
    musicPlayer.LoadMusic("assets/audio/tracks/cyberean_mainmenu.wav", MusicState::MainMenu);
    musicPlayer.LoadMusic("assets/audio/tracks/cyberean_lvl_1.wav", MusicState::Lvl1);
    musicPlayer.PlayMusic(MusicState::MainMenu);

    MusicState previousState = MusicState::MainMenu; // Variable zum Speichern des vorherigen Zustands
    MusicState currentState = MusicState::MainMenu; // Variable zum Speichern des aktuellen Zustands
    musicPlayer.PlayMusic(currentState); // Starten der Hintergrundmusik im Hauptmenü

    gameSzene gs(0);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth,Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }
        // Updates that are made by frame are coded here
        // ...
        // ...
        switch(state){
            case mainMenu:

                themenu.update(state);
                break;
            case gameplay:
             //   gameplay();
                break;
            case settings:
               // settings();
                break;
            case pause:
                //pause();
                break;
        }

        if (themenu.IsMusicMuted() == false) { //Mute Möglichkeit
            musicPlayer.SetMusicVolume(0.0f);
        } else {
            musicPlayer.SetMusicVolume(1.0f); //auf 1.0f einstellen um die Musik zu hören
        }


        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(ColorFromHSV(time(nullptr),1,1));
            switch(state){
                case mainMenu:
                    themenu.draw();
                    themenu.buttons();
                    currentState = MusicState::MainMenu;
                    break;
                case gameplay:
                    gs.draw();
                    break;
                default:
                    DrawText("lol",100,100,50,BLACK);
                    currentState = MusicState::Lvl1;
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

        if (currentState != previousState) { //beim ändern des states wird ein anderes Lied abgespielt
            musicPlayer.PlayMusic(currentState);
            previousState = currentState;
        }

        musicPlayer.Update();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();
    musicPlayer.StopMusic();

    return EXIT_SUCCESS;
}
void to_zeichnen_auf_den_Bildschirm(tson::Map *theMap, Texture &mapTex) {
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