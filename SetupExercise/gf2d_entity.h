#pragma once

#include <SDL.h>

#include "gf2d_types.h"
#include "gf2d_vector.h"
#include "gf2d_sprite.h"

/* @brief Creates a typedef for struct Entity
 * @param entRefCount Amount of Entity references
 * @param collider The collider/hitbox for the Entity
 * @param sprite The Entity's Sprite
 */

typedef struct Entity_S{
	int entRefCount;
	Vector2D *collider;
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

/* @brief Deletes the Entity from memory.
 * @param ent The Entity to be deleted.
 */

void gf2d_entity_delete(Entity *ent);

/* @brief Clears all Entities.
*/

void gf2d_entity_clear_all();