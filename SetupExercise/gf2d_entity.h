#pragma once
#ifndef __GF2D_ENTITY_H__
#define __GF2D_ENTITY_H__

#include <SDL.h>

#include "gf2d_types.h"
#include "gf2d_vector.h"
#include "gf2d_sprite.h"

/* @brief Creates a typedef for struct Entity
 * @param entRefCount Amount of Entity references
 * @param collider The collider/hitbox for the Entity
 * @param pos The position of the Entity
 * @param sprite The Entity's Sprite
 */

typedef struct Entity_S{
	int entRefCount;
	Vector2D *collider;
	Vector2D *pos;
	Sprite *sprite;

}Entity;

/* @brief Initializes the Entity Manager.
 * @param maxSize Allocates the maximum size for the Entity Manager. 
 */
void gf2d_entity_init(Uint32 maxSize);

/* @brief Frees and dereferences an Entity.
 * @param ent The Entity to be dereferenced.
 */
void gf2d_entity_free(Entity *ent);

/* @brief Creates a new Entity within the Entity Manager. 
*/
Entity *gf2d_entity_new();

/* @brief Changes the Entity's position. 
 * @param vel Velocity at which the Entity moves.
 */
void gf2d_entity_move(Entity *ent, Vector2D vel);

/* @brief Deletes the Entity from memory.
* @param ent The Entity to be deleted.
*/
void gf2d_entity_delete(Entity *ent);

/* @brief Clears all Entities.
*/
void gf2d_entity_clear_all();

#endif