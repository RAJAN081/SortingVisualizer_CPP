#define SDL_MAIN_HANDLED

#include "sorting_algos/common_visuals.h"
#include <SDL2/SDL.h> // include SDL manually if needed
#include <iostream>

using namespace std;
void shuffle();
void selectionSort();
void insertionSort();
void bubbleSort();
void mergeSort(int[], int, int);
void quickSort(int[], int, int);
void inplaceHeapSort(int[], int);
extern int arr[];
extern const int arrSize;

int main(int argc, char* args[]) {
    intro();
    cout << "\n------ SORTING VISUALIZER CONTROLS ------\n";
cout << "0 - Shuffle Array\n";
cout << "1 - Selection Sort\n";
cout << "2 - Insertion Sort\n";
cout << "3 - Bubble Sort\n";
cout << "4 - Merge Sort\n";
cout << "5 - Quick Sort\n";
cout << "6 - Heap Sort\n";
cout << "q - Quit\n";
cout << "-----------------------------------------\n";

    SDL_Event event;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_0: shuffle(); break;
                    case SDLK_1: selectionSort(); break;
                    case SDLK_2: insertionSort(); break;
                    case SDLK_3: bubbleSort(); break;
                    case SDLK_4: mergeSort(arr, 0, arrSize - 1); break;
                    case SDLK_5: quickSort(arr, 0, arrSize - 1); break;
                    case SDLK_6: inplaceHeapSort(arr, arrSize); break;
                    case SDLK_q: quit = true; break;
                }
            }
        }

        visualize(-1, -1, -1);  // redraw current state
        SDL_Delay(16); // ~60 FPS
    }

    SDL_Quit();
    return 0;
}
void shuffle() {
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++) {
        int j = rand() % arrSize;
        swap(arr[i], arr[j]);
    }
    visualize(-1, -1, -1);
    SDL_Delay(300);  // delay to show shuffle
}
