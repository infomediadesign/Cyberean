//
// Created by lukas on 12.09.2023.
//

#include "cutscene5.h"

void cutscene5::update(globalState &globalState) {
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
                    background = 5;
                    ResetCutscene();
                    break;
                case 12:
                    textpart++;
                    currentFullText = fullText13;
                    background = 1;
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
                    background = 5;
                    ResetCutscene();
                    break;
                case 17:
                    textpart++;
                    currentFullText = fullText18;
                    background = 1;
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
                    background = 4;
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
                    background = 5;
                    ResetCutscene();
                    break;
                case 23:
                    textpart++;
                    currentFullText = fullText24;
                    background = 1;
                    ResetCutscene();
                    break;
                case 24:
                    textpart++;
                    currentFullText = fullText25;
                    background = 5;
                    ResetCutscene();
                    break;
                case 25:
                    textpart++;
                    currentFullText = fullText26;
                    background = 6;
                    ResetCutscene();
                    break;
                case 26:
                    textpart++;
                    currentFullText = fullText27;
                    background = 3;
                    ResetCutscene();
                    break;
                case 27:
                    textpart++;
                    currentFullText = fullText28;
                    background = 1;
                    ResetCutscene();
                    break;
                case 28:
                    textpart++;
                    currentFullText = fullText29;
                    background = 5;
                    ResetCutscene();
                    break;
                case 29:
                    textpart++;
                    currentFullText = fullText30;
                    background = 1;
                    ResetCutscene();
                    break;
                case 30:
                    textpart++;
                    currentFullText = fullText31;
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
                    background = 3;
                    ResetCutscene();
                    break;
                case 33:
                    textpart++;
                    currentFullText = fullText34;
                    background = 5;
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
                    background = 6;
                    ResetCutscene();
                    break;
                case 36:
                    textpart++;
                    currentFullText = fullText37;
                    background = 4;
                    ResetCutscene();
                    break;
                case 37:
                    textpart++;
                    currentFullText = fullText38;
                    background = 5;
                    ResetCutscene();
                    break;
                case 38:
                    textpart++;
                    currentFullText = fullText39;
                    background = 1;
                    ResetCutscene();
                    break;
                case 39:
                    textpart++;
                    currentFullText = fullText40;
                    background = 5;
                    ResetCutscene();
                    break;
                case 40:
                    textpart++;
                    currentFullText = fullText41;
                    background = 1;
                    ResetCutscene();
                    break;
                case 41:
                    textpart++;
                    currentFullText = fullText42;
                    background = 5;
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
                    ResetCutscene();
                    break;
                case 44:
                    textpart++;
                    currentFullText = fullText45;
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
                    ResetCutscene();
                    break;
                case 49:
                    textpart++;
                    currentFullText = fullText50;
                    ResetCutscene();
                    break;
                case 50:
                    textpart++;
                    currentFullText = fullText51;
                    ResetCutscene();
                    break;
                case 51:
                    textpart++;
                    currentFullText = fullText52;
                    ResetCutscene();
                    break;
                case 52:
                    textpart++;
                    currentFullText = fullText53;
                    ResetCutscene();
                    break;
                case 53:
                    textpart++;
                    currentFullText = fullText54;
                    ResetCutscene();
                    break;
                case 54:
                    textpart++;
                    currentFullText = fullText55;
                    ResetCutscene();
                    break;
                case 55:
                    textpart++;
                    currentFullText = fullText56;
                    ResetCutscene();
                    break;
                case 56:
                    textpart++;
                    currentFullText = fullText57;
                    background = 2;
                    ResetCutscene();
                    break;
                case 57:
                    textpart++;
                    currentFullText = fullText58;
                    ResetCutscene();
                    break;
                case 58:
                    textpart++;
                    currentFullText = fullText59;
                    ResetCutscene();
                    break;
                case 59:
                    textpart++;
                    currentFullText = fullText60;
                    background = 4;
                    ResetCutscene();
                    break;
                case 60:
                    textpart++;
                    currentFullText = fullText61;
                    ResetCutscene();
                    break;
                case 61:
                    textpart++;
                    currentFullText = fullText62;
                    background = 6;
                    ResetCutscene();
                    break;
                case 62:
                    textpart++;
                    currentFullText = fullText63;
                    ResetCutscene();
                    break;
                case 63:
                    textpart++;
                    currentFullText = fullText64;
                    background = 3;
                    ResetCutscene();
                    break;
                case 64:
                    textpart++;
                    currentFullText = fullText65;
                    ResetCutscene();
                    break;
                case 65:
                    textpart++;
                    currentFullText = fullText66;
                    background = 1;
                    ResetCutscene();
                    break;
                case 66:
                    textpart++;
                    currentFullText = fullText67;
                    ResetCutscene();
                    break;
                case 67:
                    textpart++;
                    currentFullText = fullText68;
                    ResetCutscene();
                    break;
                case 68:
                    textpart++;
                    currentFullText = fullText69;
                    ResetCutscene();
                    break;
                case 69:
                    fadeout = true;
                    break;
                case 70:
                    textpart = 0;
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    if(storymodeactive){
                        storystate++;
                    }else{
                        globalState = creditsscreen;
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

void cutscene5::draw() {
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

void cutscene5::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene5::cutscene5(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    std::random_device rd;
    rng = std::mt19937(rd());

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 20;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "Turns out Koshka not only made his cyberspace traces harder to follow; the location they're pointing to\n"
            "is also a little more remote than where the rest of you usually - or even unusually, really\n"
            "- can be found.";
    fullText =
            "Your group waits for a relatively unseen moment and then slips away into one of the abandoned old metro\n"
            "maintenance tunnels.\n"
            "Not that the cameras wouldn't see you.\n"
            "But nobody cares about the non-vital parts of this system and everyone knows some shady dealings are\n"
            "happening in what remains of what once was Novosibirsk's underground.";
    fullText2 =
            "Just shady enough of a place that even you guys don't want to be seen entering it by everyone and their\n"
            "cousin Ivan.\n"
            "Here the 'Neo' really does not apply.";
    fullText3 =
            "No neon floods the semi-abandoned tunnels.\n"
            "No advertisements are getting shoved in the innocent traveller's face.";
    fullText4 =
            "Well, none dating back less than two and a half decades.";
    fullText5 =
            "It's surprisingly clean down here.";
    fullText6 =
            "And calm.";
    fullText7 =
            "Drops of water can be heard, some voices in the distance, maybe some damped music from a - true\n"
            "- underground venue.\n"
            "You pass a few vendors of whatever the next illegal lab has put out as this month's drug en vogue.\n"
            "But besides that, this place seems almost tranquil.";
    fullText8 =
            "It most definitely is, compared to whatever monster of a metropolis is raging just a few meters above\n"
            "your heads.";
    fullText9 =
            "Koshka's place is well-hidden within the labyrinth here; but more in a hidden in plain sight kind of way.\n"
            "No secret passages.\n"
            "No corridors with broken lights.";
    fullText10 =
            "Just a plain metal door.";
    fullText11 =
            "To everyone in your group's surprise - even Igor's - the door opens for you, Koshka standing in it.";
    fullText12 =
            "Hey guys.\n"
            "Took you just as long as I calculated since I saw you disappear from camera.\n"
            "Damn, even I am surprised how well I guessed it this time...\n"
            "Come in before someone I don't want to know I'm here sees you.";
    fullText13 =
            "The slightly baffled four of you enter; Koshka slams the door shut behind you.";
    fullText14 =
            "It's a simple place. \n"
            "But cozy.";
    fullText15 =
            "On one side there are two sofas with an accompanying table, a few racks, a fridge, the walls all around\n"
            "sprayed with grafities and hung with posters of numerous current and former underground artists.\n"
            "You manage to spot one of 'Cyberean' amongst them, albeit partially covered by newer ones.";
    fullText16 =
            "On the other side of the room there's a simple desk with multiple computers, monitors, other\n"
            "electronics... and a camping cooker that's recently been used to cook some unidentifiable mass that\n"
            "- you think - has had rice in it at some point in its history, still residing in a small pan on top of it.";
    fullText17 =
            "So I guess the little government tantrum over our music has made you activate code green.\n"
            "Honestly I gotta respect you actually managed to maneuver through cyberspace like that in its current ...";
    fullText18 =
            "Koshka can't finish his sentence as Igor squeezes the remaining air from his lungs as he hugs him.\n"
            "You think you hear something akin to a relieved sigh from Igor...";
    fullText19 =
            "Koshka always had held a special place in Igor's heart; basically he had dragged Koshka into the band\n"
            "when it all started. Rumor says it's partially because Koshka was the most cat-like being that he was\n"
            "allowed to bring along into both the school's music room and his old apartment.";
    fullText20 =
            "You already begin to fear that what Igor's put it through might have been too much for Koshka's rather\n"
            "frail body as it's finally allowed to emerge again from the giant's embrace.";
    fullText21 =
            "I missed you, Koshka.";
    fullText22 =
            "I'm glad to see you're safe and sound.";
    fullText23 =
            "Not as safe and sound as without you around it seems.";
    fullText24 =
            "Koshka coughs and gasps for air.";
    fullText25 =
            "Care to find out what's going on I presume, huh?";
    fullText26 =
            "You bet we do!";
    fullText27 =
            "Now that I think about it, they just mentioned what they were doing, not why...";
    fullText28 =
            "Koshka heaves himself over to his desk and hammers into the keyboard for a brief moment.\n"
            "You catch a glimpse of things reminding you a little too much of what you encountered in cyberspace.\n"
            "But eventually Koshka presents you with a simple video-player.";
    fullText29 =
            "Someone put one of our old songs into a satire video that mocks one of the 'more influential' corps;\n"
            "pretty funny stuff if you ask me.";
    fullText30 =
            "He presses play.";
    fullText31 =
            "He isn't wrong.";
    fullText32 =
            "Not quite your taste of humour, but still.\n"
            "Probably more something for the younger generation - and the likes of Koshka.";
    fullText33 =
            "And?";
    fullText34 =
            "No 'and' really... it's just that someone in the upper echelons didn't take the joke well.";
    fullText35 =
            "They initially only wanted to take down the vid but came across some of our other material which\n"
            "apparently was considered 'potentially subversive'.\n"
            "Not that they're wrong but... yeah.";
    fullText36 =
            "That's ridiculous!\n"
            "Who could have such a fragile ego?!";
    fullText37 =
            "I agree.\n"
            "Even I think that's childish.";
    fullText38 =
            "I always wanted us to get more political; change stuff!\n"
            "We had a huge stage and could have had an impact but you just became too comfy living the good life back\n"
            "then... Now you see where us not doing anything has lead not only us, but everyone to!";
    fullText39 =
            "Koshka seems to not be sure whether to laugh or let his anger towards you shine more through.\n"
            "It's true that, back in the day, 'Cyberean' had quite a crowd.\n"
            "And Koshka had always been wary regarding the ramping up government control and influence over\n"
            "everyone's day-to-day life.";
    fullText40 =
            "No need to worry, though. \n"
            "It's the same as with everything else.\n"
            "They ban it from whatever space they control.\n"
            "But they forget they've long lost control over much of the network they let go to hell years ago.";
    fullText41 =
            "This time Koshka laughs loudly.";
    fullText42 =
            "Our music gets shared more than ever before I think.\n"
            "Same with the vid by the way.\n"
            "And the corps might be stupid but just not diligent enough yet to move against any of you personally\n"
            "I suppose.";
    fullText43 =
            "Wouldn't change things.";
    fullText44 =
            "For the better or the worse, we don't really have a voice anymore.\n"
            "...\n"
            "Except me, maybe.";
    fullText45 =
            "But they don't know that that particular voice is mine so you should be good even after your little\n"
            "visit here.";
    fullText46 =
            "The four of you share some insecure looks.";
    fullText47 =
            "It's clear what every one of you thinks.\n"
            "You all feel ashamed for letting things get this bad.\n"
            "You feel sad for letting go of your voice over stupid reasons.";
    fullText48 =
            "But now you are back together, aren't you?";
    fullText49 =
            "No need to leave yet.";
    fullText50 =
            "Of course, you couldn't turn back time.";
    fullText51 =
            "But you could still change fate.";
    fullText52 =
            "Maybe.";
    fullText53 =
            "Yours.";
    fullText54 =
            "Your friends'.";
    fullText55 =
            "Everyone's?";
    fullText56 =
            "Maybe.";
    fullText57 =
            "You're right, Koshka.";
    fullText58 =
            "You also got every right to be angry with us.";
    fullText59 =
            "But we came here.\n"
            "Together.";
    fullText60 =
            "Even if we can't change the bigger picture for now, can't we be there for each other?";
    fullText60 =
            "It must have been a lonely crusade, comrade.";
    fullText61 =
            "I feel like I abandoned you.\n"
            "...\n"
            "Like we all abandoned each other.";
    fullText62 =
            "I couldn't fix what drove us apart back then.\n"
            "But I've learned a few things in the time being.\n"
            "And I think even Alex and Vasya did the same.";
    fullText63 =
            "Maybe.";
    fullText64 =
            "You heard the others.";
    fullText65 =
            "I left my nice apartment for this little adventure, cat boy.\n"
            "I'm sure you can tune down your righteous fury for a moment and talk things out now if I manage to\n"
            "do that.";
    fullText66 =
            "Koshka takes some time to decide on what to do.";
    fullText67 =
            "Eventually he walks over to his sofas, lets himself fall on one of them and points to the empty seats.";
    fullText68 =
            "Five are left.";
    fullText69 =
            "Igor would need two, so... a perfect fit.";



    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
