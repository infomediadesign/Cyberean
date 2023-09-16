//
// Created by lukas on 12.09.2023.
//

#include "cutscene4.h"

void cutscene4::update(globalState &globalState) {
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
                    background = 4;
                    ResetCutscene();
                    break;
                case 1:
                    textpart++;
                    currentFullText = fullText2;
                    background = 0;
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
                    background = 1;
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
                    ResetCutscene();
                    break;
                case 15:
                    textpart++;
                    currentFullText = fullText16;
                    background = 3;
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
                    background = 1;
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
                    textpart++;
                    currentFullText = fullText26;
                    ResetCutscene();
                    break;
                case 26:
                    textpart++;
                    currentFullText = fullText27;
                    ResetCutscene();
                    break;
                case 27:
                    textpart++;
                    currentFullText = fullText28;
                    ResetCutscene();
                    break;
                case 28:
                    textpart++;
                    currentFullText = fullText29;
                    ResetCutscene();
                    break;
                case 29:
                    textpart++;
                    currentFullText = fullText30;
                    ResetCutscene();
                    break;
                case 30:
                    textpart++;
                    currentFullText = fullText31;
                    background = 2;
                    ResetCutscene();
                    break;
                case 31:
                    textpart++;
                    currentFullText = fullText32;
                    background = 5;
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
                    background = 1;
                    ResetCutscene();
                    break;
                case 34:
                    textpart++;
                    currentFullText = fullText35;
                    background = 2;
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
                    background = 1;
                    ResetCutscene();
                    break;
                case 37:
                    textpart++;
                    currentFullText = fullText38;
                    background = 2;
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
                    background = 1;
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
                    background = 3;
                    ResetCutscene();
                    break;
                case 42:
                    textpart++;
                    currentFullText = fullText43;
                    ResetCutscene();
                    break;
                case 43:
                    textpart++;
                    currentFullText = fullText44;
                    background = 5;
                    ResetCutscene();
                    break;
                case 44:
                    textpart++;
                    currentFullText = fullText45;
                    background = 6;
                    ResetCutscene();
                    break;
                case 45:
                    textpart++;
                    currentFullText = fullText46;
                    background = 1;
                    ResetCutscene();
                    break;
                case 46:
                    textpart++;
                    currentFullText = fullText47;
                    ResetCutscene();
                    break;
                case 47:
                    textpart++;
                    currentFullText = fullText48;
                    ResetCutscene();
                    break;
                case 48:
                    textpart++;
                    currentFullText = fullText49;
                    background = 6;
                    ResetCutscene();
                    break;
                case 49:
                    textpart++;
                    currentFullText = fullText50;
                    background = 1;
                    ResetCutscene();
                    break;

                case 50:
                    fadeout = true;
                    break;

                case 51:
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

void cutscene4::draw() {
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
            DrawTexture(background_5, 0, 0, WHITE);
            break;
        case 5:
            DrawTexture(background_6, 0, 0, WHITE);
            break;
        case 6:
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

void cutscene4::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene4::cutscene4(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 20;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "Driving this far out felt... odd; the undertow of the city centre was hard to overcome once you had\n"
            "gotten used to it.\n"
            "From out here, it would probably be only half an hour to the city's edge, to where you could get a breath\n"
            "of truly fresh air, on a good day.";
    fullText =
            "Maybe here you get to see a star or two without experiencing a blackout.";
    fullText2 =
            "Anastasja laughed.";
    fullText3 =
            "The three of you had followed Alexey's traces out here to, what everyone in the neon-flooded inner city\n"
            "would refer to as, the suburban outskirts.\n"
            "Corporate middle-men and generally everyone who could afford it and who was not addicted to the vices of\n"
            "downtown tried securing a nice flat here.";
    fullText4 =
            "It most certainly wasn't a place where people like you were a common sight.\n"
            "Not a place where any of you felt at home.";
    fullText5 =
            "How could Alexey possibly have ended up here?";
    fullText6 =
            "This place was even beyond the reach of the city metro so Anastasja had *borrowed* one of the\n"
            "neighbour's old cars.\n"
            "Needed repairs only three times on the way here.\n"
            "In retrospect, said neighbour should probably pay you for Nastja probably had fixed a few other issues\n"
            "along with the necessary fixes.";
    fullText7 =
            "You finally take a turn off the main street and reach the house Alexey's supposed to live in.\n"
            "And indeed, his name is right there on the escutcheon.\n"
            "Igor takes it upon himself to press the tiny doorbell, almost activating several others with his\n"
            "enormous fingers.";
    fullText8 =
            "...";
    fullText9 =
            "Nothing.";
    fullText10 =
            "Anastasja rings for a second time.";
    fullText11 =
            "...";
    fullText12 =
            "Just as you're about to contemplate the possibility of Alexey not being willing to open the door\n"
            "for you, a man appears behind you on the pavement, carrying a heavy-looking grocery bag stemming from\n"
            "the nearest mega-mart.\n"
            "He seemed rather lost in thought but as he sees you, his jaw takes an involuntary drop\n"
            "- as does the grocery bag.";
    fullText13 =
            "Without his reaction, it probably would have been hard for any of you to identify the man as Alexey.\n"
            "Although, maybe the appearance of what must look like three downtown punks - possibly including a mob\n"
            "enforcer, taking into account Igor's stature - could have caused such a reaction in other residents of\n"
            "this district as well.";
    fullText14 =
            "Alexey clearly takes a moment to process what's going on; probably estimates his chances of succesfully\n"
            "a) making it to his appartment pretending to be someone else or\n"
            "b) making a run for whatever vehicle was near enough and usable to escape altogether.";
    fullText15 =
            "Only as Anastasja enthusiastically - or ironically - starts waving at him he decides on actually\n"
            "confronting your little group.";
    fullText16 =
            "Alex.";
    fullText17 =
            "What on earth are you guys doing here?!\n"
            "How did you find me?!\n"
            "And do you know how it makes me - everyone in this house, really - look to have you guys show up in\n"
            "that attire?!";
    fullText18 =
            "Hey, no need to be rude about it, Alex.\n"
            "But in that case, wouldn't it be nice to let us in and thus have us out of sight?";
    fullText19 =
            "Nastja smiles.";
    fullText20 =
            "And after a surprisingly long time of consideration, Alex seems to agree with her sentiment.\n"
            "Without an additional word, he opens the door and lets all of you enter.";
    fullText21 =
            "His appartment has got to be one of the most generic places you've ever been to.\n"
            "Maybe this is what's now considered sleek and modern but to you - and, judging by their looks,\n"
            "the other two - it seems almost sterile; not like a place where anyone could truly thrive.";
    fullText22 =
            "It takes time before Alexey comes to terms with your uninvited visit.";
    fullText23 =
            "He claims he brought his life in order; works full-time for one of the smaller mega corps; just a few\n"
            "dozen billions in sales.";
    fullText24 =
            "Thinks about buying a small hide-out near the river or something like that.";
    fullText25 =
            "But something about all his claims sounds hollow...";
    fullText26 =
            "Alexey always craved the fame, the buzz...";
    fullText27 =
            "Sometimes this side of his still shines through when Igor and Nastja talk about what's been going on\n"
            "on the shadier side of town lately.\n"
            "But what gets to him the most seems to be seeing Igor, Nastja and you back together, getting along.";
    fullText28 =
            "There's nothing in this apartment connecting Alex to anyone but Alex.\n"
            "Sure, he had always been full of himself.";
    fullText29 =
            "But not to this extent.";
    fullText30 =
            "It takes a few hours of uninvitedly staying and talking some nonsense into him but eventually, over\n"
            "some slices of semi-freshly delivered pizza, his new conformist facade cracks.";
    fullText31 =
            "I gotta admit: Old Artyom's was much better. Is that place still in business?";
    fullText32 =
            "Oh it for sure is, although Artyom's got a little crazy after he got that cyber implant... slizes the\n"
            "chilis six times as fast though!";
    fullText33 =
            "Damn we need to go out there sometime again...";
    fullText34 =
            "Everyone looks at him.";
    fullText35 =
            "You guys win, alright?\n"
            "Does this place look like me?";
    fullText36 =
            "Boring as you, yes.";
    fullText37 =
            "A few pieces of flying pizza later things nearly feel as they've once been.";
    fullText38 =
            "Guys, I need to tell you something...";
    fullText39 =
            "The corps showed up here before you; informed me of their little 'purge'...\n"
            "Told me not to meddle in their affairs...\n"
            "and that they're rather happy to see me evolving in a more 'socially acceptable' way.";
    fullText40 =
            "Everyone turns quiet again.";
    fullText41 =
            "Igor and Nastja seem worried now.";
    fullText42 =
            "Maybe we've been too generous with our time.\n"
            "They might let salaryman Alex here get away.";
    fullText43 =
            "I doubt they'll be as lenient with little Koshka.";
    fullText44 =
            "Damn Alex, couldn't you have told us this earlier?\n"
            "We might be in actual danger if they sent people after you...";
    fullText45 =
            "You are right, we should probably hurry and at least find him to make sure he's safe...";
    fullText46 =
            "You are surprised by your sudden show of leadership.";
    fullText47 =
            "Well, you were named band leader for a reason back in the day.";
    fullText48 =
            "Maybe you still had it in you.";
    fullText49 =
            "Please tell me this pretentious place at least has a decent network connection...";
    fullText50 =
            ">>> TRACK DOWN KOSHKA <<<";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
