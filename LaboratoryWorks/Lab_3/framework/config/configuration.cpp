#include "configuration.h"
#include "../linear_algebra/linalg.h"

#include <iostream>
#include <stdexcept>
#include <cmath>

const int FIELD_WIDTH = 1920;
const int FIELD_HEIGHT = 1080;

const int DEFAULT_WINDOW_WIDTH = 1600;//getDesktopMetrics(CXSCREEN);
const int DEFAULT_WINDOW_HEIGHT = 900;//getDesktopMetrics(CYSCREEN);
const int WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;


static double RATIO;
static double HORIZONTAL_SPACE;
static double VERTICAL_SPACE;

using namespace linalg::aliases;

void setParameters(SDL_Renderer *renderer) {
    int window_width_, window_height_;
    SDL_GetRendererOutputSize(renderer, &window_width_, &window_height_);

    double r1 = static_cast<double>(window_width_) / window_height_;
    double r2 = static_cast<double>(FIELD_WIDTH) / FIELD_HEIGHT;
    if (r1 > r2) 
        RATIO = static_cast<double>(window_height_) / FIELD_HEIGHT;
    else 
        RATIO = static_cast<double>(window_width_) / FIELD_WIDTH;

    HORIZONTAL_SPACE = (window_width_ - (RATIO * FIELD_WIDTH)) / 2.0;
    VERTICAL_SPACE = (window_height_ - (RATIO * FIELD_HEIGHT)) / 2.0;
}

int initialize() {
    if (FIELD_WIDTH <= 0 || FIELD_HEIGHT <= 0 ||
        DEFAULT_WINDOW_WIDTH <= 0 || DEFAULT_WINDOW_HEIGHT <= 0)
        throw std::invalid_argument("Wrong game parameters");

    if ((SDL_Init(SDL_INIT_EVERYTHING) != 0)) {
        std::cerr << "Could't initialize SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    int IMG_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
    if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS) {
        std::cerr << "Could't initialize IMG: " << IMG_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    if(TTF_Init() == -1) {
        std::cerr << "Could't initialize TFF: " << TTF_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    int MIX_FLAGS = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG;
    if (Mix_Init(MIX_FLAGS) & MIX_FLAGS != MIX_FLAGS) {
        std::cerr << "Could't initialize MIX: " << Mix_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048) != 0) {
		std::cerr << "Could't open Audio MIX: " << Mix_GetError() << std::endl;
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}

void finalize() {
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int convert(SDL_Renderer *renderer, double value) {
    setParameters(renderer);
    return static_cast<int>(std::ceil(value * RATIO));
}   

SDL_Point convert(SDL_Renderer *renderer, const SDL_Point &point) {
    setParameters(renderer);
    double x = point.x;
    double y = point.y;
    double3x1 vector = {{ x, y, 1.0 }};
    double3x3 matrix = {
        { RATIO, 0.0, 0.0 }, 
        { 0.0, RATIO, 0.0 }, 
        { HORIZONTAL_SPACE, VERTICAL_SPACE, 0.0 }
    };    
    auto result = mul(matrix, vector);

    int new_x = static_cast<int>(result[0][0]);
    int new_y = static_cast<int>(result[0][1]);
    return SDL_Point{ new_x, new_y };
}

int getDesktopMetrics(int flag) {
    RECT r;
    GetWindowRect(GetDesktopWindow(), &r);

    if (flag == CXSCREEN)
        return r.right;
    else if (flag == CYSCREEN)
        return r.bottom;
    else
        return -1;
}