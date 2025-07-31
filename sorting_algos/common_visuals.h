#ifndef COMMON_VISUALS_H
#define COMMON_VISUALS_H
#include <SDL2/SDL.h>
#include <iostream>
#include <time.h>
#include <string>
#include <cstring>
using namespace std;


const int SCREEN_WIDTH = 910;
const int SCREEN_HEIGHT = 750;
const int arrSize = 130;
const int rectSize = 7;

extern int arr[arrSize];
extern int Barr[arrSize];
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern bool complete;

bool init();
void close();
void visualize(int x = -1, int y = -1, int z = -1);
void loadArr();
void randomizeAndSaveArray();
void execute();
bool controls();
void intro();

#endif