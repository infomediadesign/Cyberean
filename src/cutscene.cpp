#include "cutscene.h"

void cutscene::update(globalState &globalState) {
    storymodeactive = true;
    musicPlayerPtr->PlayMusic(MusicState::cutscene);

    if(fadein){
        alpha -= fadeSpeed * GetFrameTime();
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            fadein = false;

        }
    }

    if(fadeout){
        alpha += fadeSpeed * GetFrameTime();
        if (alpha >= 1.0f) {
            alpha = 1.0f;
            textpart++;
            textpart = 0;
            musicPlayerPtr->StopMusic();
            globalState = storymodesection;
            storystate++;
        }
    }

    if (currentTextIndex < currentFullText.length() && !fadein) {
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
        if (IsKeyPressed(KEY_ENTER) && !fadein) {
            switch(textpart){
                case 0:
                    textpart++;
                    currentFullText = fullText;
                    ResetCutscene();
                    break;
                case 1:
                    textpart++;
                    currentFullText = fullText2;
                    ResetCutscene();
                    cutsceneaktiv = true;
                    break;
                case 2:
                    textpart++;
                    currentFullText = fullText3;
                    ResetCutscene();
                    break;
                case 3:
                    textpart++;
                    currentFullText = fullText4;
                    ResetCutscene();
                    break;
                case 4:
                    textpart++;
                    currentFullText = fullText5;
                    igor = true;
                    igorname = true;
                    background = 3;
                    ResetCutscene();
                    break;
                case 5:
                    textpart++;
                    currentFullText = fullText6;
                    ResetCutscene();
                    break;
                case 6:
                    textpart++;
                    currentFullText = fullText7;
                    ResetCutscene();
                    break;
                case 7:
                    textpart++;
                    currentFullText = fullText8;
                    ResetCutscene();
                    break;
                case 8:
                    textpart++;
                    currentFullText = fullText9;
                    ResetCutscene();
                    break;
                case 9:
                    textpart++;
                    currentFullText = fullText10;
                    igor = false;
                    igorname = false;
                    background = 1;
                    ResetCutscene();
                    break;
                case 10:
                    textpart++;
                    currentFullText = fullText11;
                    ResetCutscene();
                    break;
                case 11:
                    textpart++;
                    currentFullText = fullText12;
                    ResetCutscene();
                    break;
                case 12:
                    fadeout = true;
                    break;
                case 13:
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    storystate++;
                    break;
                default:
                    break;
            }
        }
    }
    musicPlayerPtr->Update();
    musicPlayerPtr->SetMusicVolume(masterMusicControl);

    if(IsKeyPressed(KEY_F2)){
        textpart = 12;
    }
}

void cutscene::draw() {
    switch(background){
        case 0:
            DrawTexture(background_1, 0, 0, WHITE);
            break;
        case 1:
            DrawTexture(background_2, 0, 0, WHITE);
            break;
        case 2:
            DrawTexture(background_3, 0, 0, WHITE);
            break;
        case 3:
            DrawTexture(background_4, 0, 0, WHITE);
            break;
        default:
            break;
    }
    if(vasilyname){
       DrawTexture(Vasily_name, 217, 585, WHITE);
    }

    if(igorname){
        DrawTexture(Igor_name, 217, 585, WHITE);
    }

    if(vasily){
        DrawTexture(Vasily, 230, 220, WHITE);
    }

    if(igor){
        DrawTexture(Igor, 860, 220, WHITE);
    }

    DrawTextEx(myFont, currentText.c_str(), Vector2{textX, textY}, fontSize, spacing,  textColor);
    //DrawText(currentText.c_str(), textX, textY, fontSize, textColor);


    if(fadein){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }

    if(fadeout){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }
}

void cutscene::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene::cutscene(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    cutsceneaktiv = true;

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 24;
    //fontSize = 24;

    textColor = WHITE;

    textpart = 0;

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
    fullText3 =
            "Anyways, you decide to reward the effort by actually reading the mail\n"
            "this time...It's from Igor...Somehow.\n"
            "You hadn't heard from your old mate in years.\n"
            "A quick glance over to one of the old band posters scattered all over\n"
            "your wall of - now accursed - memorabilia reminds you of how he used\n"
            "to be; used to look like. What could he want after all that time?";
    fullText4 =
            " - - - ";
    fullText5 =
            "Vasily\n"
            "\n"
            "It's been a while, comrade.\n"
            "Things between all of us got complicated, I do know that.\n"
            "But I think to know you, deep down, are a good man and friend, Vasily.\n"
            "That's why I come to you now.";
    fullText6 =
            "Maybe you listen to our old songs sometimes.\n"
            "You can't anymore.\n"
            "They were wiped from the net earlier this week.";
    fullText7 =
            "And I haven't found anything regarding the others since then, either.\n"
            "Only you got your fan mail account still running it seems.\n"
            "You know me; I can handle my own matters.\n"
            "But the others and you might be in trouble.\n"
            "I'd like to have you by my side now.\n"
            "And then maybe we can find the others.";
    fullText8 =
            "I got a friend of mine to create a this little something for me.\n"
            "You can link yourself up into cyberspace and follow the trails to find me.\n"
            "If you do still care, Vasya.\n"
            "(Threw some music in for old time's sake.)";
    fullText9 =
            "Hope to see you soon,\n"
            "Igor\n"
            "\n"
            "\n"
            "- - -";
    fullText10 =
            "Well, that at least explains what was missing earlier.Now you realise\n"
            "that your band's tracks were all gone from your playlists.\n"
            "\n"
            "But what to do now?\n"
            "Follow Igor's trail?";
    fullText11 =
            "Directly entering whatever was left by now of the cyberspace is not\n"
            "what one would consider `safe` - for various reasons.\n"
            "The government had run down a multitude of things,\n"
            "including the grand virtual spaces of old. You even know - or knew - some\n"
            "of the guys responsible for its current state...You glance over to the\n"
            "band posters again, Koshka on them hiding behind his mask as always...";
    fullText12 =
            "And maybe you do still care.\n"
            "After all.\n"
            "Another night in cyberspace it is...\n"
            "\n"
            "\n"
            ">>> FOLLOW IGOR'S TRAIL <<<";

    textX = 200.0f;
    textY = 660.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
