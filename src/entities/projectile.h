#ifndef projectile_h
#define projectile_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct Projectile {
    static const uint8_t v = 2;
    static EntityType update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame);
    /* static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game); */
};

#endif
