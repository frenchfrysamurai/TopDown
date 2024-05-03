#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// Player structure definition
typedef struct {
	Vector2 position;
	// Add more player attributes as needed
	Vector2 size;
} Player;

// Function declarations
void InitPlayer(Player *player, Vector2 position);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);

#endif
