#include "raylib.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Moving Square");

	SetTargetFPS(60);

	Rectangle square = { 100, 100, 50, 50 };
	
	while(!WindowShouldClose())
	{
		if(IsKeyDown(KEY_RIGHT)) square.x += 2;
		if(IsKeyDown(KEY_LEFT)) square.x -= 2;
		if(IsKeyDown(KEY_DOWN)) square.y += 2;
		if(IsKeyDown(KEY_UP)) square.y -= 2;

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangleRec(square, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
