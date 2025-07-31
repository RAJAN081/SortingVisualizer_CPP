#include "sorting_algos/common_visuals.h"


void selectionSort();
void insertionSort();
void bubbleSort();
void mergeSort(int a[], int si, int ei);
void quickSort(int a[], int si, int ei);
void inplaceHeapSort(int* input, int n);

int arr[arrSize];
int Barr[arrSize];
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
bool complete = false;

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    window = SDL_CreateWindow("Sorting Visualizer - C++ SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    return true;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void visualize(int x, int y, int z) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < arrSize; i++) {
        if (i == x)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // red
        else if (i == y)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // green
        else if (i == z)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // blue
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // white

        SDL_Rect bar = { i * rectSize, SCREEN_HEIGHT - arr[i], rectSize - 1, arr[i] };
        SDL_RenderFillRect(renderer, &bar);
    }

    SDL_RenderPresent(renderer);
}

void intro() {
    srand(time(0));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % (SCREEN_HEIGHT - 50) + 10;
    }
    if (!init()) {
        cout << "Initialization failed!" << endl;
        exit(1);
    }
    visualize();
}

bool controls() {
    cout << "Choose sorting algorithm:\n";
    cout << "1 - Selection Sort\n";
    cout << "2 - Insertion Sort\n";
    cout << "3 - Bubble Sort\n";
    cout << "4 - Merge Sort\n";
    cout << "5 - Quick Sort\n";
    cout << "6 - Heap Sort\n";
    cout << "0 - Generate New Array\n";
    cout << "q - Quit\n";
    cout << "Enter choice: ";
    char c;
    cin >> c;

    switch (c) {
    case '0':
        intro();
        return true;
    case '1':
        selectionSort();
        break;
    case '2':
        insertionSort();
        break;
    case '3':
        bubbleSort();
        break;
    case '4':
        mergeSort(arr, 0, arrSize - 1);
        break;
    case '5':
        quickSort(arr, 0, arrSize - 1);
        break;
    case '6':
        inplaceHeapSort(arr, arrSize);
        break;
    case 'q':
    case 'Q':
        close();
        return false;
    default:
        cout << "Invalid choice\n";
        return controls();
    }

    return true;
}

void execute() {
    visualize();
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }
}
