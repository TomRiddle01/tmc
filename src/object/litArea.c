#include "entity.h"
#include "room.h"
#include "screen.h"
#include "flags.h"
#include "functions.h"

void LitArea(Entity* this) {
    if (this->action == 0) {
        if (this->field_0x86.HWORD != 0 && CheckFlags(this->field_0x86.HWORD) == 0) {
            return;
        }
        this->spriteSettings.draw = 1;
        this->action = 1;
        this->spriteRendering.alphaBlend = 2;
        this->spriteRendering.b0 = 3;
        this->frameIndex = 3;
        this->flags |= ENT_PERSIST;
        this->field_0xf = gRoomControls.room;
        this->actionDelay = 2;
        this->field_0x68.HWORD = 0xfffe;
        this->field_0x6a.HWORD = 0x80;
        sub_0805EC9C(this, 0x80, 0x80, 0);
    } else {
        if (--this->actionDelay == 0) {
            this->actionDelay = 2;
            this->field_0x6a.HWORD += this->field_0x68.HWORD;
            if (this->field_0x6a.HWORD < 0x78) {
                this->field_0x68.HWORD = 1;
            }
            if (0x88 < this->field_0x6a.HWORD) {
                this->field_0x68.HWORD = 0xffff;
            }
            sub_0805EC9C(this, this->field_0x6a.HWORD, this->field_0x6a.HWORD, 0);
        }
    }
    gScreen.lcd.displayControl |= DISPCNT_OBJWIN_ON;
    gScreen.controls.windowOutsideControl = (gScreen.controls.windowOutsideControl & 0xff) | WINOUT_WINOBJ_BG0 |
                                            WINOUT_WINOBJ_BG1 | WINOUT_WINOBJ_BG2 | WINOUT_WINOBJ_OBJ |
                                            WINOUT_WINOBJ_CLR;
    if ((gRoomControls.room != this->field_0xf) && (gRoomControls.reload_flags == 0)) {
        DeleteThisEntity();
    }
}
