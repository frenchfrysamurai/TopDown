#include "raylib.h"
#include <stdlib.h>

#define screenWidth 800
#define screenHeight 450
#define playerSpeed 5
#define frameSpeed 2 // Speed of animation (adjust as needed)
#define frameWidth 16 // Width of each fram in the sprite sheet
#define frameHeight 16
#define scaleMultiplier 4 // Scale multiplier for larger sprites

int main(void) {
	// Initialization
	InitWindow(screenWidth, screenHeight, "Zelda-style Game");

	// Load sprite sheet
	Texture2D spriteSheet = LoadTexture("../assets/link.png");

	// Define sprite rectangles
	Rectangle frameRects[4][2] = {
        	// Up animation
        	{ {69, 11, frameWidth, frameHeight}, {86, 11, frameWidth, frameHeight} },
        
        	// Down animation
        	{ {1, 11, frameWidth, frameHeight}, {18, 11, frameWidth, frameHeight} },
        
        	// Left animation
        	{ {35, 11, -frameWidth, frameHeight}, {52, 11, -frameWidth, frameHeight} },
        
        	// Right animation
        	{ {35, 11, frameWidth, frameHeight}, {52, 11, frameWidth, frameHeight} }
    	};	

	// Player position
	Vector2 playerPos = { 100, 100 };
	int currentDirection = 1; // Initial facing direction (down)
	int frameIndex = 0; // Current frame index
	int maxFrames = 2; // Number of frames per animation direction
	float frameTime = 0.0f; // Time accumulator for frame update
	bool moving = false; // Flag to indicate if the player is moving
	
	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose()) {
		// Input handling
		moving = false; // Reset moving flag
		if (IsKeyDown(KEY_W)) {
			playerPos.y -= playerSpeed;
			currentDirection = 0; // Up
			moving = true; // Set moving flag
		}
		if (IsKeyDown(KEY_S)) {
			playerPos.y += playerSpeed;
			currentDirection = 1; // Down
			moving = true; // Set moving flag
		}

		if (IsKeyDown(KEY_A)) {
			playerPos.x -= playerSpeed;
			currentDirection = 2; // Left
			moving = true;
		}
		if (IsKeyDown(KEY_D)) {
			playerPos.x += playerSpeed;
			currentDirection = 3; // Right
			moving = true;
		}

		// Update animation frame
		if(moving){
			frameTime += frameSpeed * GetFrameTime();
			if (frameTime >= 1.0f / frameSpeed) {
				frameIndex++;
				frameIndex %= maxFrames; // Loop back to the first frame when reaching the end of the animation
				frameTime = 0.0f;
			}
		} else {
			// Reset frame index when idle
			frameIndex = 0;
		}

		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw player character
		Rectangle sourceRect = frameRects[currentDirection][frameIndex];
        	Vector2 origin = {sourceRect.width / 2.0f, sourceRect.height / 2.0f};

		DrawTexturePro(spriteSheet, sourceRect, (Rectangle){ playerPos.x, playerPos.y, abs(frameWidth) * scaleMultiplier, frameHeight * scaleMultiplier },
                       origin, 0, WHITE);
	

		EndDrawing();
	}

	// Unload texture
	UnloadTexture(spriteSheet);

	CloseWindow();

	return 0;
}
