#include "sys.h"
#include "eeprom.h"
#include "settings.h"

EEP_Param eep;
static code EEP_Param eepDef = {0xFF, 0, 2, 0, 0, 1, 5, 0, 7, 30, 1, 1, 1, 1, 1, 0, 0, 0};

code EEP_Param eepMin = {0xFF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -9};
code EEP_Param eepMax = {0xFF, 1, 5, 4, 4, 1, 7, 1, 23, 59, 1, 1, 1, 1, 1, 1, 1, 9};

static uint8_t workSector = 89;

static void settingsFirstEnable(void)
{
	bit needDef = 1;
	uint8_t i;
	for(i=0; i<9; i++){
		if( *((uint8_t*)(&eep.on + i)) != 0xFF ) {
			needDef = 0;
			break;
		}
	}
	if(needDef) {
		for( i=0; i<sizeof(EEP_Param); i++ ){
			*((uint8_t*)(&eep.pageBlock + i)) = *((uint8_t*)(&eepDef.pageBlock + i));
		}
		settingsSave();
	}

	return;
}

void settingsInit(void)
{
	uint8_t i;
	for( i=0; i < sizeof(EEP_Param); i++) {
		*((uint8_t*)&eep + i) = IapReadByte((uint16_t)(workSector <<9) + i);
	}
	settingsFirstEnable();

	return;
}

void settingsSave(void)
{
	uint8_t i;

	IapEraseSector((uint16_t)(workSector <<9));

	// � STC15F2K16S2 90 ������(��������) �� 512 ����, ����� ��� ����������� �� 100� ��������.
	// ������� ������������ � ������ ������� � 0x4000

	for( i=0; i < sizeof(EEP_Param); i++) {
		IapProgramByte((uint16_t)(workSector <<9) + i, *((uint8_t*)&eep + i));
	}

	return;
}