#pragma once

#include <stdio.h>
#include "gl\glew.h"
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <glm\glm.hpp>
#include <glm/gtx/transform.hpp>

#include "VisualisationScene.h"
#include "Shaders.h"
#include "Camera.h"

#undef main


#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

class Visualisation
{
public:
	Visualisation(char* windowTitle, int windowWidth = DEFAULT_WINDOW_WIDTH, int windowHeight = DEFAULT_WINDOW_HEIGHT);
	~Visualisation();

	bool init();
	void handleKeypress(SDL_Keycode keycode, int x, int y);
	void close();
	void run(); // @todo - improve

	char* getWindowTitle();
	void setWindowTitle(char* windowTitle);
	
	void setQuit(bool quit);
	void toggleFullScreen();
	void toggleMouseMode();
	void resizeWindow();
	void resizeWindow_2();

	void handleMouseMove(int x, int y);
	bool isFullscreen();
	void updateFPS();


private:
	SDL_Window* window, *window_2;
	SDL_GLContext context;
	Camera camera, camera_2;
	Shaders* vechShaders = nullptr;
	Shaders* envShaders = nullptr;
	VisualisationScene* scene;
	glm::mat4 frustum, frustum_2;

	bool isInitialised;
	bool quit;

	char* windowTitle;
	int windowWidth;
	int windowHeight;
	bool window0Active;
	
	SDL_Rect windowedBounds;

	unsigned int previousTime = 0;
	unsigned int currentTime;
	unsigned int frameCount = 0;

};

