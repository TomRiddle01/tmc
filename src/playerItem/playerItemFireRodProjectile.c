#define NENT_DEPRECATED
#include "asm.h"
#include "entity.h"
#include "sound.h"
#include "physics.h"
#include "functions.h"
#include "effects.h"
#include "playeritem.h"

typedef struct {
    Entity base;
    u8 unk68;
    u16 unk6a;
    u32 unk6c;
} FireRodProjectileEntity;

extern u8 gUnk_08003E44;

void sub_080A3084(FireRodProjectileEntity*);
void sub_080A310C(FireRodProjectileEntity*);

void PlayerItemFireRodProjectile(Entity* this) {
    static void (*const actionFuncs[])(FireRodProjectileEntity*) = {
        sub_080A3084,
        sub_080A310C,
    };
    actionFuncs[this->action]((FireRodProjectileEntity*)this);
}

void sub_080A3084(FireRodProjectileEntity* this) {
    static const Hitbox gUnk_08127278 = { 0, 0, { 4, 2, 2, 4 }, 6, 6 };
    super->spriteSettings.draw = 1;
    super->action = 0x01;
    CopyPosition(super->parent, super);
    if (super->type == 0) {
        super->collisionFlags = gPlayerEntity.collisionFlags + 1;
        super->hitbox = (Hitbox*)&gUnk_08127278;
        super->speed = 0x400;
        if (super->collisionLayer == 0x02) {
            super->type2 = 0x01;
        }
        super->direction = Direction8FromAnimationState(super->animationState);
        this->unk6c = 60;
        sub_0801766C(super);
        LinearMoveUpdate(super);
        SoundReq(SFX_ITEM_SWORD_BEAM);
    } else {
        super->timer = 6;
    }
    InitializeAnimation(super, 0x18);
    sub_080A310C(this);
}

void sub_080A310C(FireRodProjectileEntity* this) {
    if (super->type != 0) {
        if (super->timer-- == 0) {
            DeleteThisEntity();
        }
    } else {
        GetNextFrame(super);
        if (this->unk6c-- != 0) {
            GetNextFrame(super);
            LinearMoveUpdate(super);
            super->timer++;
            if (super->type2 == 0) {
                sub_0800451C(super);
            }
            if (sub_080B1BA4(COORD_TO_TILE(super), gPlayerEntity.collisionLayer, 0x80) == 0 &&
                sub_080040D8(super, &gUnk_08003E44, super->x.HALF.HI, super->y.HALF.HI)) {
                CreateFx(super, FX_SWORD_MAGIC, 0);
                DeleteThisEntity();
            }
            if (super->contactFlags != 0) {
                CreateFx(super, FX_SWORD_MAGIC, 0);
                DeleteThisEntity();
            }
            if (sub_08008790(super, 0xc)) {
                DeleteThisEntity();
            }
            super->child = CreatePlayerItem(PLAYER_ITEM_FIRE_ROD_PROJECTILE, 1, 0, this->unk68);
            if (super->child != NULL) {
                super->child->parent = super;
            }
        } else {
            DeleteThisEntity();
        }
    }
}
