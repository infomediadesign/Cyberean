#include "cutscene.h"

void cutscene::update(globalState &globalState) {
    if (currentTextIndex < currentFullText.length()) {
        if (IsKeyPressed(KEY_ENTER)) {
            currentText = currentFullText;
            currentTextIndex = currentFullText.length();
        } else if (textTimer >= textSpeed) {
            currentText += currentFullText[currentTextIndex];
            currentTextIndex++;
            textTimer = 0;
        } else {
            textTimer++;
        }
    } else {
        if (IsKeyPressed(KEY_ENTER)) {
            if (whichcutscene == 0) {
                whichcutscene++;
                currentFullText = fullText;
                ResetCutscene();
            } else if (whichcutscene == 1) {
                whichcutscene++;
                currentFullText = fullText2;
                ResetCutscene();
            }else if(whichcutscene == 2){
                globalState = mainMenu;
            }
        }
    }
}

void cutscene::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawText(currentText.c_str(), textX, textY, fontSize, textColor);
}

void cutscene::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
    cutsceneFinished = false;
}

cutscene::cutscene(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    musicPlayerPtr->StopMusic();

    background = LoadTexture("assets/screens/cutscene_screen/Textbox_1.png");
    fontSize = 24;
    textColor = WHITE;

    whichcutscene = 0;
    cutsceneFinished = false;

    currentFullText =
            "*BZZZ* *BZZZ* *BZZZ*\n"
            "The uncomfy sound of your antiquated alarm clock puts an end to your\n"
            "almost equally uncomfortable sleep.\n"
            "The sun is about to go down. Finally.\n"
            "Time to stumble out of bed and make your way over to the computer and \n"
            "waste away another night in this god-forsaken city.";

    fullText =
            "This time you do not just stumble, you trip over some memorabilia of\n"
            "the olden days and curse at all of them\n"
            "your first amplifier, your old personalised mic stand which has somehow\n"
            "made its way right in front of your bed, almost as if someone placed it\n"
            "there as a trap. But then again, it's not like you have much recollection\n"
            "of what you get up to sometimes when staying up late.";

    fullText2 =
            "You start your day as always; turn on one of the classic playlists, check\n"
            "the never-changing news...Today something seems off, though...\n"
            "Or maybe your sleep has just been worse than usual.\n"
            "You get up, force yourself to grab some cereal from the kitchen.\n"
            "A message has made it through your multi-layered anti-spam filter.\n"
            "But yeah, something's definitely off today.";


    textX = 200;
    textY = 660;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
