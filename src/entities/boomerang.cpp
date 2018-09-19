#include "boomerang.h"
#include "player.h"
#include "../sfx.h"
#include "../game.h"
#include "../util.h"

EntityType Boomerang::update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;
    
    // initial duration? then "spawn"
    if (me->duration == 20) {
        me->dir = player.dir;
        me->x = player.x;
        me->y = player.y - 6;
        Sfx::boomerang();
    }

    if (me->duration > 0) {
        me->duration -= 1;
        switch (me->dir) {
            case LEFT:
                me->moveTo(me->x - Boomerang::v, me->y);
                break;
            case RIGHT:
                me->moveTo(me->x + Boomerang::v, me->y);
                break;
            case UP:
                me->moveTo(me->x, me->y - Boomerang::v);
                break;
            case DOWN:
                me->moveTo(me->x, me->y + Boomerang::v);
                break;
        }
    } else {
        if (abs(px - me->x) < 3 && abs(py - me->y) < 3) {
            me->type = UNSET;
        } else {
            int16_t nx = me->x;
            int16_t ny = me->y;

            if (me->x > px) {
                nx -= Boomerang::v;
            }
            else if (me->x < px) {
                nx += Boomerang::v;
            }
            if (me->y > py) {
                ny -= Boomerang::v;
            } else if (me->y < py) {
                ny += Boomerang::v;
            }

            me->moveTo(nx, ny);
        }
    }

    MirrorMode mirror = 0;

    if (frame > 49) {
        mirror = MIRROR_HORIZONTAL | MIRROR_VERTICAL;
    } else if (frame > 39) {
        mirror = MIRROR_HORIZONTAL;
    } else if (frame > 29) {
        mirror = 0;
    } else if (frame > 19) {
        mirror = MIRROR_HORIZONTAL | MIRROR_VERTICAL;
    } else if (frame > 9) {
        mirror = MIRROR_HORIZONTAL;
    }

    me->mirror = mirror;

    return UNSET;
}

EntityType Boomerang::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    EntityType otherType = other.type;

    // hit something the user can collect? collect it and keep going
    if ((otherType >= KEY && otherType <= HEART) || otherType == BOMB) {
        return player.onCollide(other, player, game);
    }

    // hit an enemy? then begin returning to the player
    if (otherType >= BLOB && otherType <= NEMESIS) {
        me->duration = 0;
    }

    if (otherType == SWITCH) {
        other.mirror = MIRROR_HORIZONTAL;
        game.removeAllTriggerDoors();
    }

    // hit anything else? don't care, keep flying

    return UNSET;
}