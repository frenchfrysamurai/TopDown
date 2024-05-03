#include "player.h"
#include "raylib.h"

void InitPlayer(Player *player, Vector2 position) {
	// Initialize player attributes
	player->position = position;
	// Add more initialization code as needed
}

void UpdatePlayer(Player *player) {
	// Update player logic here
	//
	// Define movement speed
	const float speed = 5.0f;
	
	// Check for key presses and update player position
	if (IsKeyDown(KEY_W)) {
		player->position.y -= speed; // Move up
	} else if (IsKeyDown(KEY_S)) {
		player->position.y += speed; // Move down
	}

	if (IsKeyDown(KEY_A)) {
		player->position.x -= speed; // Move left
	} else if (IsKeyDown(KEY_D)) {
		player->position.x += speed; // Move right
	}

	// Ensure player statys within screen boundaries
	if (player->position.x < 0) {
		player->position.x = 0;
	} else if (player->position.x + player->size.x > GetScreenWidth()) {
		player->position.x = GetScreenWidth() - player->size.x;
	}

	if (player->position.y < 0) {
		player->position.y = 0;
	} else if (player->position.y + player->size.y > GetScreenHeight()) {
		player->position.y = GetScreenHeight() - player->size.y;
	}
}

void DrawPlayer(Player *player) {
	// Draw player sprite here
	// Example: Draw a blue rectangle for the player
	DrawRectangle(player->position.x, player->position.y, 50, 50, BLUE); 
}
