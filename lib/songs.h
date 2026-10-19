#ifndef SONGS_H
#define SONGS_H

#include "N5110.h"
#include "Joystick.h" 

#define NOTE_G3  185
#define NOTE_A3  208
#define NOTE_B3  233
#define NOTE_C4  262    //octave 4 - middle c
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define REST  1

// set global variables so they are accesible across entire program
extern int y_pos_note;
extern int score;
extern float final_score; 
extern bool previousbutton;

// Each note sprite
const int A_note[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
};

const int B_note[7][5] = {
    {1,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,0},
};

const int C_note[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,1},
    {0,1,1,1,0},
};

const int D_note[7][5] = {
    {1,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,1,0},
    {1,1,1,0,0},
};

const int E_note[7][5] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,1,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,1,1},
};

const int F_note[7][5] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,1,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
};

//song notes and durations in tuples
extern std::vector<std::pair<int, float>> twinkle;
extern std::vector<std::pair<int, float>> wii;
extern std::vector<std::pair<int, float>> brightside;

// function declerations
void gamelayout(N5110 &lcd);
void play_song(int frequency);
void play_note(int frequency);
void song_1(N5110 &lcd);
void song_2(N5110 &lcd);
void song_3(N5110 &lcd);

#endif