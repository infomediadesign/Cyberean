//
// Created by lukas on 12.09.2023.
//

#include "cutscene3.h"

void cutscene3::update(globalState &globalState) {
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
                    background = 1;
                    ResetCutscene();
                    break;
                case 7:
                    textpart++;
                    currentFullText = fullText8;
                    background = 3;
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
                    background = 4;
                    ResetCutscene();
                    break;
                case 10:
                    textpart++;
                    currentFullText = fullText11;
                    background = 3;
                    ResetCutscene();
                    break;
                case 11:
                    textpart++;
                    currentFullText = fullText12;
                    background = 1;
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
                    background = 2;
                    ResetCutscene();
                    break;
                case 14:
                    textpart++;
                    currentFullText = fullText15;
                    background = 7;
                    ResetCutscene();
                    break;
                case 15:
                    textpart++;
                    currentFullText = fullText16;
                    background = 5;
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
                    background = 5;
                    ResetCutscene();
                    break;
                case 18:
                    textpart++;
                    currentFullText = fullText19;
                    background = 2;
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
                    background = 6;
                    ResetCutscene();
                    break;
                case 25:
                    textpart++;
                    currentFullText = fullText26;
                    background = 7;
                    ResetCutscene();
                    break;
                case 26:
                    textpart++;
                    currentFullText = fullText27;
                    background = 2;
                    ResetCutscene();
                    break;
                case 27:
                    textpart++;
                    currentFullText = fullText28;
                    background = 6;
                    ResetCutscene();
                    break;
                case 28:
                    textpart++;
                    currentFullText = fullText29;
                    background = 7;
                    ResetCutscene();
                    break;
                case 29:
                    textpart++;
                    currentFullText = fullText30;
                    background = 2;
                    ResetCutscene();
                    break;
                case 30:
                    textpart++;
                    currentFullText = fullText31;
                    background = 7;
                    ResetCutscene();
                    break;
                case 31:
                    textpart++;
                    currentFullText = fullText32;
                    ResetCutscene();
                    break;
                case 32:
                    textpart++;
                    currentFullText = fullText33;
                    background = 2;
                    ResetCutscene();
                    break;
                case 33:
                    textpart++;
                    currentFullText = fullText34;
                    ResetCutscene();
                    break;
                case 34:
                    textpart++;
                    currentFullText = fullText35;
                    ResetCutscene();
                    break;
                case 35:
                    textpart++;
                    currentFullText = fullText36;
                    background = 5;
                    ResetCutscene();
                    break;
                case 36:
                    textpart++;
                    currentFullText = fullText37;
                    background = 2;
                    ResetCutscene();
                    break;
                case 37:
                    textpart++;
                    currentFullText = fullText38;
                    ResetCutscene();
                    break;
                case 38:
                    textpart++;
                    currentFullText = fullText39;
                    ResetCutscene();
                    break;
                case 39:
                    textpart++;
                    currentFullText = fullText40;
                    ResetCutscene();
                    break;
                case 40:
                    textpart++;
                    currentFullText = fullText41;
                    ResetCutscene();
                    break;
                case 41:
                    textpart++;
                    currentFullText = fullText42;
                    ResetCutscene();
                    break;
                case 42:
                    fadeout = true;
                    break;
                case 43:
                    textpart = 0;
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    if(storymodeactive){
                        storystate++;
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

void cutscene3::draw() {
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
            DrawTexture(background_8, 0, 0, WHITE);
            break;
        case 4:
            DrawTexture(background_4, 0, 0, WHITE);
            break;
        case 5:
            DrawTexture(background_5, 0, 0, WHITE);
            break;
        case 6:
            DrawTexture(background_6, 0, 0, WHITE);
            break;
        case 7:
            DrawTexture(background_7, 0, 0, WHITE);
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

void cutscene3::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene3::cutscene3(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 20;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "The next trail directs you straight into one of Neosibirsk's industrial districts.\n"
            "Sure, smokestacks, the sounds of heavy machinery and the searing heat of freshly smelted metal alloys\n"
            "are not what the average megalopolis dweller associates with this 'cyber age', but cyber-tech upgrades,\n"
            "the endless array of chips and the neon lights needed to keep this shiny new world running are not\n"
            "materialised out of thin air.";
    fullText =
            "Cowering in the shadow of factories, that never changed their aesthetics since their collectivist\n"
            "beginnings, the more curious - or devious - visitor to these parts of town finds a multitude of small\n"
            "workshops, where whatever's left, stolen or sometimes just untested products of their big neighbours\n"
            "are sold to whomever is willing to risk taking their deals.\n"
            "It's one of those humble establishments you and Igor are headed for now.";
    fullText2 =
            "Igor truly was an asset here.";
    fullText3 =
            "A few streets back a group of gopniks - who usually come here to scour the factories' trash for whatever\n"
            "valuables that might make it past the gates - had tried to mug you.";
    fullText4 =
            "Igor had - without you noticiting - stopped and, in vain, tried to befriend one of the street cats like\n"
            "he usually does whenever spotting one...\n"
            "Once he caught up to you again, the group became more docile than probably any cat in high-rise district\n"
            "and politely explained the remaining route to you.";
    fullText5 =
            "You eventually arrive.\n"
            "Admittedly, you - and even Igor - can't wait to get inside anything with a working air filtration device.\n"
            "And the little workshop you enter is definitely one of the more respectable ones around.";
    fullText6 =
            "It even has what would some describe as a \"female touch\" to it.\n"
            "It feels... surprisingly welcoming.\n"
            "If you ignore the blood-stained cyber-ware operation table in the corner at least.";
    fullText7 =
            "Just one moment please, I'll be with you in a sec!";
    fullText8 =
            "it sounds from the backroom.\n"
            "Apparently your old friend had turned her passion for fixing whatever she came across into her new\n"
            "profession. Anastasja's voice sounds like she's had to deal with a few too many uncooperative customers\n"
            "and/or gopniks the past couple of years, but it's still undoubtedly her's you're hearing.";
    fullText9 =
            "Your heart seems to suddenly be located somewhere near your stomach or worse.\n"
            "But Igor reassuringly places his hand on your shoulder.";
    fullText10 =
            "Do not worry, Vasya.";
    fullText11 =
            "He must have spoken loud enough for it to be heard in the backroom for whatever commotion seemed to be\n"
            "coming from there suddenly halts.";
    fullText12 =
            "Igor?";
    fullText13 =
            "Nastja.";
    fullText14 =
            "Anastasja emerges from the backroom, but stops well clear of you two, crossing her arms.\n"
            "She looks - nearly - just like in your memory; you're glad to see she didn't ditch her signature\n"
            "heart-shaped glasses.";
    fullText15 =
            "And Vasily, huh... \n"
            "What brings the two of you here, wanna buy something maybe?\n"
            "I know you can be rather miserly, Vasya, but I've got a business to run and there won't be special\n"
            "discounts for old acquaintances.\n"
            "Sorry you came all the way in vain.";
    fullText16 =
            "Nastja, please.";
    fullText17 =
            "Igor lets go of your shoulder and calmly approaches your hostile host.";
    fullText18 =
            "No need to pretend.\n"
            "Not that things are good.\n"
            "Not that you don't care about seeing us.\n"
            "Let's just sit down and talk.";
    fullText19 =
            "She seems to struggle with herself for a moment.";
    fullText20 =
            "But eventually she waves the two of you over and points at a surprisingly orderly table in a corner of\n"
            "the room. Igor switches the illuminated 'Welcome'-sign to 'Sorry, we're closed' and the the three of you\n"
            "sit down together.\n"
            "Anastasja even summons a bunch of drinks from somewhere in the back.";
    fullText21 =
            "The three of you start talking.";
    fullText22 =
            "It's different from how it's been with Igor.\n"
            "Things are more complicated between you and Nastja.\n"
            "Maybe it's also that she's more complicated.\n"
            "Sometimes, it feels like back in the day when everything seemed alright; sometimes, the conversation\n"
            "goes quiet for a while...";
    fullText23 =
            "You missed Nastja.\n"
            "She always was the most cheerful; held you all together when things got tense.\n"
            "You can't help but feel awful that you managed to create the one crack she was not able\n"
            "- or willing - to fix.\n"
            "Sometimes she looks at you in a weird way... almost expectingly...";
    fullText24 =
            "And you realise something.";
    fullText25 =
            "I never really apologised, did I?";
    fullText26 =
            "No, you did not, really.";
    fullText27 =
            "It's still hard for you to talk about that subject matter.\n"
            "Every word costs you dearly, but you eventually manage to - albeit stuttering - adress the elephant\n"
            "in the room.";
    fullText28 =
            "I always was and am still sorry, Anastasja... for everything I did back then. \n"
            "I mean it. \n"
            "I never should have...";
    fullText29 =
            "No need to recount all that, Vasya.";
    fullText30 =
            "Anastasja stops you right in your tracks.";
    fullText31 =
            "I know you feel bad for it all.\n"
            "You never were a bad person.\n"
            "And even the best people make a few mistakes...";
    fullText32 =
            "So yours are probably too many for every assembled chip in here to calculate.\n"
            "But I missed you.\n"
            "And it's good to finally hear those words from you.";
    fullText33 =
            "Anastasja looks like she's about to tear up a bit.\n"
            "You're sure that, eventually, you will need to adress your troublesome past again.\n"
            "But she makes it clear that this time is not now.";
    fullText34 =
            "Now, she's really just happy to have her old friends around again it seems.";
    fullText35 =
            "After another, more somber round of talking between the three of you, as the evening nears its\n"
            "conclusion, Igor says:";
    fullText36 =
            "Looks like we might bring the band back together after all.";
    fullText37 =
            "Everyone laughs.";
    fullText38 =
            "It's time to end the evening and get some well-deserved rest.";
    fullText39 =
            "Tomorrow it's time to track down no.4.";
    fullText40 =
            "What would you guys be without the most important band member?";
    fullText41 =
            "Bassist Alexey.";
    fullText42 =
            ">>> GET SOME REST FOR TOMORROW <<<";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
