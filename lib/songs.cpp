#include "songs.h"
#include "N5110.h"
#include <vector>
#include <utility> // For std::pair

BusOut leds(PC_8, PC_6, PC_9, PB_8, PC_5, PB_9);
DigitalIn buttonA(PA_12);
DigitalIn buttonB(PA_11);
DigitalIn buttonC(PA_5);
DigitalIn buttonD(PA_6);
DigitalIn buttonE(PB_12);
DigitalIn buttonF(PA_7);
PwmOut buzzer1(PA_15);
PwmOut buzzer2(PB_7);

std::vector<std::pair<int, float>> twinkle = {
    {NOTE_C4, 0.5}, {NOTE_C4, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_A4, 0.5} ,{NOTE_A4, 0.5},{NOTE_G4, 1.0},
    {NOTE_F4, 0.5}, {NOTE_F4, 0.5}, {NOTE_E4, 0.5}, {NOTE_E4, 0.5}, {NOTE_D4, 0.5} ,{NOTE_D4, 0.5},{NOTE_C4, 1.0},
    {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_F4, 0.5}, {NOTE_F4, 0.5}, {NOTE_E4, 0.5} ,{NOTE_E4, 0.5},{NOTE_D4, 1.0},
    {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_F4, 0.5}, {NOTE_F4, 0.5}, {NOTE_E4, 0.5} ,{NOTE_E4, 0.5},{NOTE_D4, 1.0},
    {NOTE_C4, 0.5}, {NOTE_C4, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_A4, 0.5} ,{NOTE_A4, 0.5},{NOTE_G4, 1.0},
    {NOTE_F4, 0.5}, {NOTE_F4, 0.5}, {NOTE_E4, 0.5}, {NOTE_E4, 0.5}, {NOTE_D4, 0.5} ,{NOTE_D4, 0.5},{NOTE_C4, 1.0},
};

std::vector<std::pair<int, float>> brightside = {
    {NOTE_B4, 0.5}, {NOTE_C5, 0.5}, {NOTE_B4, 0.5}, {NOTE_G4, 1.0}, {NOTE_A4, 1.0}, {NOTE_B4, 0.5}, 
    {NOTE_G4, 0.5}, {NOTE_B4, 1.0}, {NOTE_B4, 1.0}, {REST, 0.5}, {NOTE_D4, 0.5}, {NOTE_A4, 0.5}, 
    {NOTE_G4, 0.25}, {NOTE_G4, 0.5}, {NOTE_A4, 0.5}, {NOTE_A4, 0.5}, {NOTE_G4, 1.0}, {REST, 2.0}, 
    {NOTE_F4, 0.5}, {NOTE_G4, 0.25}, {NOTE_G4, 0.5}, {REST, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, 
    {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_F4, 0.5}, {NOTE_G4, 0.25}, {NOTE_G4, 0.5}, {REST, 0.5}, 
    {NOTE_F4, 0.5}, {NOTE_G4, 0.5}, {NOTE_F4, 0.5}, {NOTE_G4, 0.5}, {NOTE_F4, 0.5}, {NOTE_G4, 0.25}, 
    {NOTE_G4, 0.5}, {REST, 0.5}, {NOTE_G4, 0.5},{NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, 
    {NOTE_F4, 0.5}, {NOTE_G4, 0.25}, {NOTE_G4, 0.5}, {REST, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, 
    {NOTE_G4, 0.5}, {NOTE_A4, 0.5}, {NOTE_C5, 0.5}, {NOTE_B4, 0.25}, {NOTE_B4, 0.5}, {REST, 0.5}, 
    {NOTE_C5, 0.5}, {NOTE_B4, 0.5}, {NOTE_G4, 0.5}, {NOTE_D4, 0.5}, {NOTE_A4, 0.5}, {NOTE_G4, 0.25}, 
    {NOTE_G4, 0.5}, {REST, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_G4, 0.5}, {NOTE_A4, 0.5}, 
    {NOTE_C5, 0.5}, {NOTE_B4, 0.25}, {NOTE_B4, 0.5}, {NOTE_B4, 0.5}, {NOTE_B4, 1.0}, {REST, 0.5}, 
    {REST, 0.25}, {NOTE_D4, 0.25}, {NOTE_B4, 0.5}, {NOTE_A4, 0.5}, {NOTE_G4, 0.5}, {NOTE_A4, 1.0}, {NOTE_G4, 1.0}
};

std::vector<std::pair<int, float>> wii = {
    {NOTE_E4, 0.50}, {NOTE_G4, 0.25}, {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_G4, 0.25}, {REST , 0.25}, 
    {NOTE_E4, 0.25}, {NOTE_C4, 0.25}, {NOTE_C4, 0.25}, {NOTE_C4, 0.50}, {REST , 1.00}, {REST , 0.25}, 
    {NOTE_E4, 0.25}, {NOTE_G4, 0.25}, {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_G4, 0.25}, {REST , 0.25}, 
    {NOTE_E4, 0.25}, {NOTE_D5, 0.50}, {NOTE_C5, 0.25}, {NOTE_C5, 0.50}, {REST , 0.50}, {NOTE_F4, 0.50}, 
    {NOTE_B4, 0.25}, {NOTE_E4, 0.25}, {REST , 0.25}, {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_F4, 0.25}, 
    {REST , 0.25}, {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_F4, 0.25}, {NOTE_E4, 0.50}, {NOTE_D4, 0.50}, 
    {NOTE_D4, 0.25}, {NOTE_D4, 0.25}, {NOTE_D4, 0.50}, {REST , 0.50}, {NOTE_D4, 0.25}, {NOTE_D4, 0.25}, 
    {NOTE_D4, 0.50}, {REST , 0.50}, {NOTE_C4, 0.50}, {NOTE_C4, 0.50}, {NOTE_E4, 0.50}, {NOTE_G4, 0.25}, 
    {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_G4, 0.25}, {REST , 0.25}, {NOTE_E4, 0.25}, {NOTE_C4, 0.25}, 
    {NOTE_C4, 0.25}, {NOTE_C4, 0.50}, {NOTE_D5, 0.25}, {NOTE_D5, 0.25}, {NOTE_D5, 0.50}, {REST , 0.25}, 
    {NOTE_E4, 0.25}, {NOTE_G4, 0.25}, {NOTE_B4, 0.25}, {REST , 0.25}, {NOTE_G4, 0.25}, {REST , 0.25}, 
    {NOTE_E4, 0.25}, {NOTE_D5, 1.00},{NOTE_C5, 0.50}, {REST , 0.50}, {NOTE_F4, 0.25}, {NOTE_F4, 0.25}, 
    {NOTE_C4, 0.25}, {NOTE_B3, 0.25}, {NOTE_B3, 0.25}, {NOTE_F4, 0.25}, {NOTE_F4, 0.25}, {NOTE_B3, 0.25}, 
    {NOTE_G4, 0.25}, {NOTE_E4, 0.25}, {NOTE_A3, 0.25}, {NOTE_A3, 0.25}, {NOTE_A3, 0.25}, {NOTE_D4, 0.25}, 
    {NOTE_C4, 0.25}, {NOTE_A3, 0.25}, {NOTE_D4, 0.25}, {NOTE_D4, 0.25}, {NOTE_D4, 0.50}, {REST , 0.50},
    {REST , 0.25}, {NOTE_G3, 0.25}, {NOTE_A3, 0.25}, {NOTE_B3, 0.25}, {NOTE_C4, 0.25}, {NOTE_E4, 0.25}, {NOTE_G4, 0.50}
};

void gamelayout(N5110 &lcd){    // the grid and notes for repeatability
    lcd.clear();
    lcd.printString("A", 3, 5); 
    lcd.drawLine(11,10,11,48,1); 
    lcd.printString("B", 17, 5);
    lcd.drawLine(26,10,26,48,1); 
    lcd.printString("C", 32, 5);
    lcd.drawLine(41,10,41,48,1); 
    lcd.printString("D", 47, 5);
    lcd.drawLine(56,10,56,48,1); 
    lcd.printString("E", 62, 5);
    lcd.drawLine(71,10,71,48,1); 
    lcd.printString("F", 77, 5);
    lcd.refresh();
}

void play_song(int frequency){
    buzzer1.period_us((float) 1000000.0f/ (float) frequency); //set the period of the pwm signal (in us)
    buzzer1.pulsewidth_us(buzzer1.read_period_us()/2); //set pulse width of the pwm to 1/2 the period
}

void play_note(int frequency){ 
    buzzer2.period_us((float) 1000000.0f/ (float) frequency); //set the period of the pwm signal (in us)
    buzzer2.pulsewidth_us(buzzer2.read_period_us()/2); //set pulse width of the pwm to 1/2 the period
    ThisThread::sleep_for(300ms); //play sound for 500ms
}

void song_1(N5110 &lcd){
    score = 0; // initallize score when user plays again new round
    leds.write(0);
    lcd.clear();
    lcd.printString("GET READY!!!", 0, 3); // countdown screen
    lcd.refresh(); 
    ThisThread::sleep_for(1000ms);
    lcd.clear();
    lcd.printString("3", 30, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",2", 37, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",1", 50, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);

    for(int i = 0; i < 42; i++){     
        int y_pos_note = 18; // Starting position of the note
        int note_duration = twinkle[i].second * 1000;
        int time = 0; // increment in loop and compare to note_duration to keep track of time passed
        leds.write(0);

        while (time < (note_duration *0.25)) { //continue until a qurater of note_duration time has passed
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("TWINKLE TWINKLE", 0, 0);
            // check for the notes we are playing with in this level
            if (twinkle[i].first == NOTE_A4) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note); // start animation of the note dropping
                leds.write(1); // turn on led for A-note
            } else if (twinkle[i].first == NOTE_C4) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                leds.write(4);
            } else if (twinkle[i].first == NOTE_D4) {
                lcd.drawSprite(47, y_pos_note, 7, 5, (int*)D_note);
                leds.write(8);
            }
            lcd.refresh();
            play_song(twinkle[i].first);
            ThisThread::sleep_for(50ms); // to control note dropping speed
            y_pos_note += (1.00 / twinkle[i].second); // note dropping speed based on note length
            time += 50; // increment for next loop
        } 

        while (time >= (note_duration *0.25) && note_duration >= time){ //complete the rest of the note_duration
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("TWINKLE TWINKLE", 0, 0);
            if (twinkle[i].first == NOTE_A4) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note);
                lcd.drawCircle(6,41,7,FILL_TRANSPARENT); // to indicate to user its time to press button
                lcd.refresh();
                // check if user presses button during the allowed range
                if (buttonA.read() != previousbutton){ 
                previousbutton = buttonA.read(); // update for second time through the loop
                    if (buttonA.read() == 0){
                        score++;
                        play_note(twinkle[i].first); // play the note on second buzzer to indicate a point
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (twinkle[i].first == NOTE_C4) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                lcd.drawCircle(35,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonC.read() != previousbutton){
                previousbutton = buttonC.read(); // update for second time through the loop
                    if (buttonC.read() == 0){
                        score++;
                        play_note(twinkle[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (twinkle[i].first == NOTE_D4) {
                lcd.drawSprite(47, y_pos_note, 7, 5, (int*)D_note);
                lcd.drawCircle(50,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonD.read() != previousbutton){
                previousbutton = buttonD.read(); // update for second time through the loop
                    if (buttonD.read() == 0){
                        score++;
                        play_note(twinkle[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            }
            lcd.refresh();
            play_song(twinkle[i].first);
            ThisThread::sleep_for(50ms); // Control note dropping speed
            y_pos_note += (1.00 / twinkle[i].second); // note dropping speed based on note length
            time += 50; // to keep track of actual note length
        } 

        buzzer1.pulsewidth_us(0);
        ThisThread::sleep_for(50ms);
    }
    printf("score out of 16: %i\n", score);
    final_score = (score / 16.00); // calculate score percentage
}

void song_2(N5110 &lcd){
    score = 0;
    leds.write(0);
    lcd.clear();
    lcd.printString("GET READY!!!", 0, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.clear();
    lcd.printString("3", 30, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",2", 37, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",1", 50, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);

    for(int i = 0; i < 79; i++){     
        int y_pos_note = 27; // Starting position of the note
        int note_duration = brightside[i].second * 1000;
        int time = 0;
        leds.write(0);

        while (time*2 < (note_duration *0.4)) { //continue until a 40% of note_duration time has passed
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("MR BRIGHTSIDE", 0, 0);
            // check for the notes we are playing with in this levels
            if (brightside[i].first == NOTE_A4) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note); // start animation of the note dropping
                leds.write(1); // turn on led for A-note
            } else if (brightside[i].first == NOTE_B4) {
                lcd.drawSprite(17, y_pos_note, 7, 5, (int*)B_note);
                leds.write(2);
            } else if (brightside[i].first == NOTE_C5) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                leds.write(4);
            } else if (brightside[i].first == NOTE_F4) {
                lcd.drawSprite(77, y_pos_note, 7, 5, (int*)F_note);
                leds.write(32);
            }
            lcd.refresh();
            play_song(brightside[i].first);
            ThisThread::sleep_for(50ms); // Control note dropping speed
            y_pos_note += (1.00 / brightside[i].second); // note dropping speed based on note length
            time += 50; // to keep track of actual note length
        } 

        while (time*2 >= (note_duration *0.4) && note_duration >= time*2){ //complete the rest of the note_duration
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("MR BRIGHTSIDE", 0, 0);
            if (brightside[i].first == NOTE_A4) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note);
                lcd.drawCircle(6,41,7,FILL_TRANSPARENT); // to indicate to user its time to press button
                lcd.refresh();
                // check if user presses button during the allowed range
                if (buttonA.read() != previousbutton){
                previousbutton = buttonA.read(); // update for second time through the loop
                    if (buttonA.read() == 0){
                        score++;
                        play_note(brightside[i].first); // play the note on second buzzer to indicate a point
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (brightside[i].first == NOTE_B4) {
                lcd.drawSprite(17, y_pos_note, 7, 5, (int*)B_note);
                lcd.drawCircle(20,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonB.read() != previousbutton){
                previousbutton = buttonB.read(); // update for second time through the loop
                    if (buttonB.read() == 0){
                        score++;
                        play_note(brightside[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (brightside[i].first == NOTE_C5) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                lcd.drawCircle(35,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonC.read() != previousbutton){
                previousbutton = buttonC.read(); // update for second time through the loop
                    if (buttonC.read() == 0){
                        score++;
                        play_note(brightside[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (brightside[i].first == NOTE_F4) {
                lcd.drawSprite(77, y_pos_note, 7, 5, (int*)F_note);
                lcd.drawCircle(80,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonF.read() != previousbutton){
                previousbutton = buttonF.read(); // update for second time through the loop
                    if (buttonF.read() == 0){
                        score++;
                        play_note(brightside[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            }
            lcd.refresh();
            play_song(brightside[i].first);
            ThisThread::sleep_for(50ms); // Control note dropping speed
            y_pos_note += (1.00 / brightside[i].second); // note dropping speed based on note length
            time += 50; // to keep track of actual note length
        } 

        buzzer1.pulsewidth_us(0);
        ThisThread::sleep_for(50ms);
    }
    printf("score out of 32: %i\n", score);
    final_score = (score / 32.00); // calculate score percentage
}

void song_3(N5110 &lcd){
    score = 0;
    leds.write(0);
    lcd.clear();
    lcd.printString("GET READY!!!", 0, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.clear();
    lcd.printString("3", 30, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",2", 37, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);
    lcd.printString(",1", 50, 3);
    lcd.refresh();
    ThisThread::sleep_for(1000ms);

    for(int i = 0; i < 97; i++){     
        int y_pos_note = 25; // Starting position of the note
        int note_duration = wii[i].second * 1000;
        int time = 0;
        leds.write(0);

        while (time*1.5 < (note_duration *0.5)) { //continue until a half of note_duration time has passed and increase the spped of the song (*0.5)
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("WII THEME", 0, 0);
            // check for the notes we are playing with in this level
            if (wii[i].first == NOTE_A3) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note); // start animation of the note dropping
                leds.write(1); // turn on led for A-note
            } else if (wii[i].first == NOTE_B4 || wii[i].first == NOTE_B3) {
                lcd.drawSprite(17, y_pos_note, 7, 5, (int*)B_note);
                leds.write(2);
            } else if (wii[i].first == NOTE_C4 || wii[i].first == NOTE_C5) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                leds.write(4);
            } else if (wii[i].first == NOTE_D4 || wii[i].first == NOTE_D5) {
                lcd.drawSprite(47, y_pos_note, 7, 5, (int*)D_note);
                leds.write(8);
            } else if (wii[i].first == NOTE_E4) {
                lcd.drawSprite(62, y_pos_note, 7, 5, (int*)E_note);
                leds.write(16);
            } else if (wii[i].first == NOTE_F4) {
                lcd.drawSprite(77, y_pos_note, 7, 5, (int*)F_note);
                leds.write(32);
            }
            lcd.refresh();
            play_song(wii[i].first);
            ThisThread::sleep_for(50ms); // Control note dropping speed
            y_pos_note += (1.00 / wii[i].second); // note dropping speed based on note length
            time += 50; // to keep track of actual note length
        } 

        while (time*1.5 >= (note_duration *0.5) && note_duration >= time*1.5){ // complete the rest of the note_duration
            lcd.clear();
            gamelayout(lcd);
            lcd.printString("WII THEME", 0, 0);
            if (wii[i].first == NOTE_A4) {
                lcd.drawSprite(3, y_pos_note, 7, 5, (int*)A_note);
                lcd.drawCircle(6,41,7,FILL_TRANSPARENT); // to indicate to user its time to press button
                lcd.refresh();
                // check if user presses button during the allowed range
                if (buttonA.read() != previousbutton){
                previousbutton = buttonA.read(); // update for second time through the loop
                    if (buttonA.read() == 0){
                        score++;
                        play_note(wii[i].first); // play the note on second buzzer to indicate a point
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (wii[i].first == NOTE_B4 || wii[i].first == NOTE_B3) {
                lcd.drawSprite(17, y_pos_note, 7, 5, (int*)B_note);
                lcd.drawCircle(20,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonB.read() != previousbutton){
                previousbutton = buttonB.read(); // update for second time through the loop
                    if (buttonB.read() == 0){
                        score++;
                        play_note(wii[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (wii[i].first == NOTE_C4 || wii[i].first == NOTE_C5) {
                lcd.drawSprite(32, y_pos_note, 7, 5, (int*)C_note);
                lcd.drawCircle(35,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonC.read() != previousbutton){
                previousbutton = buttonC.read(); // update for second time through the loop
                    if (buttonC.read() == 0){
                        score++;
                        play_note(wii[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (wii[i].first == NOTE_D4 || wii[i].first == NOTE_D5) {
                lcd.drawSprite(47, y_pos_note, 7, 5, (int*)D_note);
                lcd.drawCircle(50,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonD.read() != previousbutton){
                previousbutton = buttonD.read(); // update for second time through the loop
                    if (buttonD.read() == 0){
                        score++;
                        play_note(wii[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (wii[i].first == NOTE_E4) {
                lcd.drawSprite(62, y_pos_note, 7, 5, (int*)E_note);
                lcd.drawCircle(65,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonE.read() != previousbutton){
                previousbutton = buttonE.read(); // update for second time through the loop
                    if (buttonE.read() == 0){
                        score++;
                        play_note(wii[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            } else if (wii[i].first == NOTE_F4) {
                lcd.drawSprite(77, y_pos_note, 7, 5, (int*)F_note);
                lcd.drawCircle(80,41,7,FILL_TRANSPARENT);
                lcd.refresh();
                if (buttonF.read() != previousbutton){
                previousbutton = buttonF.read(); // update for second time through the loop
                    if (buttonF.read() == 0){
                        score++;
                        play_note(wii[i].first);
                        buzzer2.pulsewidth_us(0);
                        break;
                    }
                }
            }
            lcd.refresh();
            play_song(wii[i].first);
            ThisThread::sleep_for(50ms); // Control note dropping speed
            y_pos_note += (1.00 / wii[i].second); // note dropping speed based on note length
            time += 50; // to keep track of actual note length
        } 

        buzzer1.pulsewidth_us(0);
        ThisThread::sleep_for(50ms);
    }
    printf("score out of 65: %i\n", score);
    final_score = (score / 50.00); // calculate score percentage
}