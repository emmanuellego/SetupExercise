#include "gf2d_entity.h"
#include "simple_logger.h"

typedef struct {
	Uint32 maxEnt;
	Entity * entList;
}EntityManager;

static EntityManager entManager;

void gf2d_entity_close() {
	gf2d_entity_clear_all();
	free(entManager.entList);
	slog("Closed Entity Manager! Bye bye.");
}

void gf2d_entity_init(Uint32 maxSize) {
	if (!maxSize) {
		slog("Can't create an Entity Manager with no entities.");
		return;
	}
	entManager.maxEnt = maxSize;
	entManager.entList = (Entity *)malloc(sizeof(Entity)*maxSize);
	memset(entManager.entList, 0, sizeof(Entity)*maxSize);
}

void gf2d_entity_free(Entity *ent) {
	if (!ent)
		return;
	ent->entRefCount--;
	// Dereferences the entity
}

Entity *gf2d_entity_new() {
	int ent;

	// for loop looks for unused entity addresses
	for (ent = 0; ent < entManager.maxEnt; ent++) {
		entManager.entList[ent].entRefCount = 1;
		return &entManager.entList[ent];
	}

	// for loop looks for and cleans up old unused data
	for (ent = 0; ent < entManager.maxEnt; ent++) {
		if (entManager.entList[ent].entRefCount == 0) {
			gf2d_entity_delete(&entManager.entList[ent]);
			entManager.entList[ent].entRefCount = 1;
			return &entManager.entList[ent];
		}
	}
	slog("No more available Entity Addresses. Sad face.");
	return NULL;
}

void gf2d_entity_move(Entity *ent, Vector2D vel) {
	ent->pos->x += vel.x;
	ent->pos->y += vel.y;
}

void gf2d_entity_move_all(Vector2D vel) {
	int ent;

	for (ent = 0; ent < entManager.maxEnt; ent++) {
		gf2d_entity_move(&entManager.entList[ent], vel);
	}
}

void gf2d_entity_delete(Entity *ent) {
	if (!ent)
		return;
	memset(ent, 0, sizeof(Entity));
}

void gf2d_entity_clear_all() {
	int i;
	for (i = 0; i < entManager.maxEnt; i++)
		gf2d_entity_delete(&entManager.entList[i]);
}

