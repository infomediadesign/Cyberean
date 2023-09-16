//
// Created by lukas on 12.09.2023.
//

#include "cutscene2.h"

void cutscene2::update(globalState &globalState) {
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
            if(storymodeactive){
                storystate++;
            }else{
                globalState = gameplay;
            }
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
                    background = 1;
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
                    background = 2;
                    ResetCutscene();
                    break;
                case 10:
                    textpart++;
                    currentFullText = fullText11;
                    background = 4;
                    ResetCutscene();
                    break;
                case 11:
                    textpart++;
                    currentFullText = fullText12;
                    background = 3;
                    ResetCutscene();
                    break;
                case 12:
                    textpart++;
                    currentFullText = fullText13;
                    background = 4;
                    ResetCutscene();
                    break;
                case 13:
                    textpart++;
                    currentFullText = fullText14;
                    ResetCutscene();
                    break;
                case 14:
                    textpart++;
                    currentFullText = fullText15;
                    ResetCutscene();
                    break;
                case 15:
                    textpart++;
                    currentFullText = fullText16;
                    ResetCutscene();
                    break;
                case 16:
                    textpart++;
                    currentFullText = fullText17;
                    background = 2;
                    ResetCutscene();
                    break;
                case 17:
                    textpart++;
                    currentFullText = fullText18;
                    ResetCutscene();
                    break;
                case 18:
                    textpart++;
                    currentFullText = fullText19;
                    background = 4;
                    ResetCutscene();
                    break;
                case 19:
                    textpart++;
                    currentFullText = fullText20;
                    ResetCutscene();
                    break;
                case 20:
                    textpart++;
                    currentFullText = fullText21;
                    ResetCutscene();
                    break;
                case 21:
                    textpart++;
                    currentFullText = fullText22;
                    ResetCutscene();
                    break;
                case 22:
                    textpart++;
                    currentFullText = fullText23;
                    ResetCutscene();
                    break;
                case 23:
                    textpart++;
                    currentFullText = fullText24;
                    ResetCutscene();
                    break;
                case 24:
                    textpart++;
                    currentFullText = fullText25;
                    ResetCutscene();
                    break;
                case 25:
                    fadeout = true;
                    break;
                case 26:
                    fadeout = true;
                    textpart = 0;
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    if(storymodeactive){
                        globalState = storymodesection;
                    }else{
                        globalState = gameplay;
                    }
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

void cutscene2::draw() {
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
        case 4:
            DrawTexture(background_5,0,0,WHITE);
            break;
        default:
            break;
    }
    /*if(vasilyname){
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
    }*/

    //DrawTextEx(myFont, currentText.c_str(), Vector2{textX, textY}, fontSize, spacing,  textColor);
    DrawText(currentText.c_str(), textX, textY, fontSize, textColor);

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

void cutscene2::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene2::cutscene2(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 20;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "The clues left by Igor send you down town.\n"
            "Deep down town.\n"
            "The mega corps have long forgone this part of town.\n"
            "They relocated to the newer, more modern and spacious areas a little farther out; their buildings'\n"
            "lights just soil the sky above the old heart of the city.";
    fullText =
            "The adress you're headed for didn't seem familiar to you at all... but these streets for sure do.\n"
            "It's been years since you've been here but back in the day you and the others passed through these\n"
            "dimly-lit streets regularly.\n"
            "One more corner and you're finally there.";
    fullText2 =
            "The name's since been changed.\n"
            "Proabably more than once.\n"
            "But you still remember this place quite well.";
    fullText3 =
            "One of the first club's you had a gig at...\n"
            "How long was it now? \n"
            "Your first agent discovered you guys at this place.\n"
            "One could say Cyberean became a thing here.";
    fullText4 =
            "After reminiscing for a moment you enter.\n"
            "Back when you had played here the venue was already past its golden days.\n"
            "Safe to say its state didn't turn the trend around since.";
    fullText5 =
            "You wonder whether the health inspector still gets bribed or is simply too afraid for his life\n"
            "in order for him to still show up here as you make your way over to the bar area.\n"
            "The dim red lighting can't prevent you from recognising the towering silhoutte sitting there.";
    fullText6 =
            "Igor's hit his head way too often walking through various underground backstage areas.\n"
            "Most of the times it ended worse for whatever door frame had decided to stand in his way.";
    fullText7 =
            "Should you just sit down?";
    fullText8 =
            "Approaching Igor from behind and potentially startling him does not really appeal to you that much...";
    fullText9 =
            "One friendly brawl between you all had seen Alexey, Koshka and you admitted to the next hospital,\n"
            "Igor carrying the three of you there...";
    fullText10 =
            "Vasily. I'm glad you've come.";
    fullText11 =
            "Igor's voice - as with everything about him - had not changed the slightest.\n"
            "It was still that kind of voice that instantly told you that he was no-one to mess with.\n"
            "... If his appearance wasn't already enough to convince you in regards to that.";
    fullText12 =
            "Igor... it's been a while...";
    fullText13 =
            "He finally turns his head towards you.\n"
            "If you're honest with yourself it's a big relief that you can not make out any signs of animosity on his\n"
            "face.";
    fullText14 =
            "Rather, it seems as if a big burden falls from his shoulders as he sees you standing next to him.\n"
            "And before you can begin to speculate what kind of physical burden would be needed to truly *burden* Igor,\n"
            "he gets up from his stool and gives you the probably most intense hug of your life.";
    fullText15 =
            "The two of you catch up on things.\n"
            "Things are... well, they just \"are\" for the most part.\n"
            "No need to ponder on just how bad.\n"
            "Igor must have squeezed out whatever had soured your relationship for so long with his long hug earlier;\n"
            "you still haven't fully recovered.";
    fullText16 =
            "Eventually, you get to the topic of the others, of what Igor wrote in his mail.";
    fullText17 =
            "I haven't been entirely honest with you, Vasily.\n"
            "I needed to see whether I could still trust you.\n"
            "And if you still cared.\n"
            "Not that I doubted you.\n"
            "But a man needs to stick to his principles.";
    fullText18 =
            "I kept in touch with Nastja and the others.\n"
            "In fact, the friend I spoke of was Koshka.\n"
            "He built similar trails for all of us, for cases such as this one.\n"
            "Now I've got you with me in this we can follow their trails and make sure they're safe as well.";
    fullText19 =
            "After this little revelation Igor suddenly gets up, heads towards the door and holds it open.";
    fullText20 =
            "For you, apparently.";
    fullText21 =
            "It was good to get back together with Igor.\n"
            "He had been like a brother to you back in the good old days.";
    fullText22 =
            "But the others?";
    fullText23 =
            "Igor's never doubted you, had he?";
    fullText24 =
            "Turns out he was right.";
    fullText25 =
            ">>> FOLLOW IGOR <<<";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
