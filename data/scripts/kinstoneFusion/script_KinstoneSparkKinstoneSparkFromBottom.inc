@ Hyrule Town KINSTONE_SPARK Kinstone spark red from bottom
SCRIPT_START script_KinstoneSparkKinstoneSparkFromBottom
	BeginBlock
	SetEntitySpeed 0x0120
	SetAnimation 0x0004
	EndBlock
	Wait 0x000a
	DoPostScriptAction 0x0007
	PlaySound SFX_136
	_0807EEF4 0x0000, 0xff90
	Wait 0x001e
	_0807EEF4 0x0000, 0xffb0
	Wait 0x003c
	SetRoomFlag 0x00ff
	SetAnimation 0x0005
	Wait 0x000f
SCRIPT_END
	.2byte 0x0000