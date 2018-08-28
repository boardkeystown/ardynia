#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "bitmaps.h"
#include "blob.h"
#include "sword.h"
#include "boomerang.h"

const uint8_t PROGMEM entityProperties[] = {
    // 0 SWORD
    16,           // width
    16,           // height
    DOWN,         // direction
    0,            // health
    1,            // damage
    20,           // duration

    // 1 BLOB
    8,
    8,
    DOWN,
    2, // health
    1, // damage
    0, // duration

    // 2 OVERWORLD_DOOR
    16,
    16,
    DOWN,
    0,
    0,
    0,

    // 3, BUMPER
    0,
    0,
    DOWN,
    0,
    0,
    0,

    // 4, BOOMERANG
    16,
    16,
    DOWN,
    0,
    0,
    20
};

const void* const PROGMEM entityPointers[] = {
    // 0 SWORD
    sword_tiles,        // tiles
    sword_mask_tiles,   // masks
    Sword::spawn,       // spawn
    Sword::update,      // update
    NULL,               // render
    NULL,               // onCollide

    // 1 BLOB
    blob_tiles,
    blob_mask_tiles,
    NULL,
    Blob::update,
    NULL,
    Blob::onCollide,

    // 2 OVERWORLD_DOOR
    overworld_door_tiles,
    overworld_door_mask_tiles,
    NULL,
    NULL,
    NULL,
    NULL,

    // 3 BUMPER
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    
    // 4 BOOMERANG
    itemIcons_tiles,
    itemIcons_mask_tiles,
    Boomerang::spawn,
    Boomerang::update,
    NULL,
    Boomerang::onCollide
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

