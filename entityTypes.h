#ifndef entityTypes_h
#define entityTypes_h

typedef uint8_t EntityType;

const EntityType ENTITY_MASK = 0x0F;
const EntityType DOOR_ID_MASK = 0xF0;

const EntityType UNSET = -1;
const EntityType SWORD = 0;
const EntityType BLOB = 1;
const EntityType OVERWORLD_DOOR = 2;

const EntityType PLAYER = 255;

#endif

