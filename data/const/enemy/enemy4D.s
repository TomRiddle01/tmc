	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

Enemy4D_Functions:: @ 080D0880
	.4byte Enemy4D_OnTick
	.4byte Enemy4D_OnCollision
	.4byte Enemy4D_OnKnockback
	.4byte Enemy4D_OnDeath
	.4byte GenericConfused
	.4byte Enemy4D_OnGrabbed

gUnk_080D0898:: @ 080D0898
	.4byte sub_0803EB44
	.4byte sub_0803EBB4
	.4byte sub_0803EC28
	.4byte sub_0803EC68
	.4byte sub_0803EC94
	.4byte sub_0803ED04
	.4byte sub_0803ED40
	.4byte sub_0803ED7C
	.4byte sub_0803EDD4
	.4byte sub_0803EDEC
	.4byte sub_0803EE38

gUnk_080D08C4:: @ 080D08C4
	.incbin "enemy4D/gUnk_080D08C4.bin"

gUnk_080D08C8:: @ 080D08C8
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF74
	.4byte sub_0803EFAC
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EFAC
	.4byte sub_0803EF70
	.4byte sub_0803EFAC
	.4byte sub_0803EFAC
	.4byte sub_0803EFAC
	.4byte sub_0803EF70
	.4byte sub_0803EF70
	.4byte sub_0803EFAC
