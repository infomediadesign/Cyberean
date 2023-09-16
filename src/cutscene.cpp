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
            soundplayerPtr->cutsceneenter_sound();
            currentText = currentFullText;
            currentTextIndex = currentFullText.length();
        } else if (textTimer >= textSpeed) {
            currentText += currentFullText[currentTextIndex];
            currentTextIndex++;
            textTimer = 0;
            std::uniform_int_distribution<int> dist(1, 2);
            counter = dist(rng);

            if(counter == 1){
                soundplayerPtr->cutscenevoice_sound();
            }
        } else {
            textTimer++;
        }
    } else {
        if (IsKeyPressed(KEY_ENTER) && !fadein) {
            soundplayerPtr->cutsceneenter_sound();
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
                    //background = 3;
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
                    background = 1;
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
                    //background = 1;
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
                    textpart++;
                    currentFullText = fullText13;
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
                    background = 0;
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
                    fadeout = true;
                    break;
                case 22:
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

void cutscene::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene::cutscene(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    std::random_device rd;
    rng = std::mt19937(rd());

    cutsceneaktiv = true;

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "*BZZZ* *BZZZ* *BZZZ*\n"
            "The uncomfy sound of your antiquated alarm clock puts an end to your almost equally uncomfortable sleep.\n"
            "The sun is about to go down. Finally.\n"
            "Time to stumble out of bed and make your way over to the computer and waste away another night in this\n"
            "god-forsaken city.\n";

    fullText =
            "This time you do not just stumble, you trip over some memorabilia of the olden days and curse at all of\n"
            "them; your first amplifier, your old personalised mic stand which has somehow made its way right in\n"
            "front of your bed, almost as if someone placed it there as a trap.\n"
            "But then again, it's not like you have much recollection of what you get up to sometimes when staying up\n"
            "late.";

    fullText2 =
            "You start your day as always; turn on one of the classic playlists, check the never-changing news...\n"
            "Today something seems off, though... something's missing...\n"
            "Or maybe your sleep has just been worse than usual.";
    fullText3 =
            "You get up, force yourself to grab some cereal from the kitchen and return to your screen.\n"
            "A message has made it through your multi-layered anti-spam filter.\n"
            "Spending years doing nothing besides dwelling in virtual places, hoping to keep your mind somewhat\n"
            "entertained, has had its upsides...";
    fullText4 =
            "But yeah, something's definitely off today.";
    fullText5 =
            "Anyways, you decide to reward the effort by actually reading the mail this time...";
    fullText6 =
            "It's from Igor.\n"
            "Somehow.\n"
            "You hadn't heard from your old mate in years.\n"
            "A quick glance over to one of the old band posters scattered all over your wall of - now accursed -\n"
            "memorabilia reminds you of how he used to be; used to look like.\n";
    fullText7 =
            "What could he want after all that time?";
    fullText8 =
            "Vasily";
    fullText9 =
            "It's been a while, comrade.\n"
            "Things between all of us got complicated, I do know that.\n"
            "But I think to know you, deep down, are a good man and friend, Vasily.\n"
            "That's why I come to you now.";
    fullText10 =
            "Maybe you listen to our old songs sometimes.\n"
            "You can't anymore.\n"
            "They were wiped from the net earlier this week.";
    fullText11 =
            "And I haven't found anything regarding the others since then, either.\n"
            "Only you got your fan mail account still running it seems.\n"
            "You know me; I can handle my own matters.";
    fullText12 =
            "But the others and you might be in trouble.\n"
            "I'd like to have you by my side now.\n"
            "And then maybe we can find the others.\n"
            "Figure out what's going on.";
    fullText13 =
            "I got a friend of mine to create a this little something for me.\n"
            "You can link yourself up into cyberspace and follow the trails to find me.\n"
            "If you do still care, Vasya.\n"
            "(Threw some music in for old time's sake.)";
    fullText14 =
            "Hope to see you soon,\n"
            "Igor";
    fullText15 =
            "Well, that at least explains what was missing earlier.\n"
            "Now you realise that your band's tracks were all gone from your playlists.";
    fullText16 =
            "But what to do now?\n"
            "Follow Igor's trail?";
    fullText17 =
            "Directly entering whatever was left by now of the cyberspace is not really what one would consider *safe*\n"
            "- for various reasons.\n"
            "The government had run down a multitude of things, including the grand virtual spaces of old.\n"
            "You even know - or knew - some of the guys responsible for its current state...\n"
            "You glance over to the band posters again, Koshka on them hiding behind his mask as always...";
    fullText18 =
            "And maybe you do still care.";
    fullText19 =
            "After all.";
    fullText20 =
            "Another night in cyberspace it is...";
    fullText21 =
            ">>> FOLLOW IGOR'S TRAIL <<<";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
