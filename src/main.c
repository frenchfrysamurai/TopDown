#include "raylib.h"
#include "player.h"

int main()
{
	// Screen Initialization
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Top-down");

	SetTargetFPS(60);

	Player player;
	InitPlayer(&player, (Vector2){ screenWidth / 2, screenHeight / 2 }); // Initialize player at the center of the screen
	
	while(!WindowShouldClose())
	{
		// Update
		UpdatePlayer(&player);

		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw here
		DrawPlayer(&player);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
