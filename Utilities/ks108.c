
#include "ks108.h"

/*This should be in ROM*/
char Font8x8[] = {
    /*0 - 9*/
    0x00,0x1C,0x3E,0x61,0x43,0x3E,0x1C,0x00,       // ASCII -  48
	0x00,0x00,0x44,0x7F,0x7F,0x40,0x00,0x00,       // ASCII -  49
	0x00,0x46,0x67,0x71,0x59,0x4F,0x66,0x00,       // ASCII -  50
	0x00,0x22,0x63,0x49,0x4D,0x7F,0x32,0x00,       // ASCII -  51
	0x00,0x18,0x1C,0x52,0x7F,0x7F,0x50,0x00,       // ASCII -  52
	0x00,0x2F,0x6F,0x45,0x45,0x7D,0x39,0x00,       // ASCII -  53
	0x00,0x3C,0x7E,0x4B,0x49,0x79,0x30,0x00,       // ASCII -  54
	0x00,0x07,0x43,0x71,0x7D,0x0F,0x03,0x00,       // ASCII -  55
	0x00,0x36,0x7F,0x4D,0x59,0x7F,0x36,0x00,       // ASCII -  56
	0x00,0x06,0x4F,0x49,0x69,0x3F,0x1E,0x00,       // ASCII -  57
};

void InitDisplay(void){
    U8 i, j, k;
    DATA_DIR_OUT();
    WR_DATA(0x3F);
    for(i = 0; i < 3; i ++)
    {
        ChipSelect(i);
        E = 1;
        mydelay_ms(100);
        E = 0;
    }
    ClearDisplay();
    ChipSelect(0);
    PageSelect(0);
    RowSelect(0);
    StartLine(0);
}

void ChipSelect(U8 chip){
	switch(chip)
	{
		case 0:
			CSA = 0;
			CSB = 0;
            break;
		case 1:
			CSA = 0;
			CSB = 1;
            break;
		case 2:
			CSA = 1;
			CSB = 0;
            break;
	}
}

void ClearDisplay(void){
	U8 i, j, k;
	for(i = 0; i < 3; i ++){
		ChipSelect(i);
		for(j = 0; j < 8; j++){
			PageSelect(j);
			RowSelect(0);
			WR_DATA(0);
			RS = 1;
			for(k = 0; k < 0x40; k++){
				E = 1;
				mydelay_ms(1);
				E = 0;
			}
		}
	}
}

/*X Address*/
void PageSelect(U8 page){
	RW = 0;
	RS = 0;
	WR_DATA(0xB8 | page);
	E = 1;
	mydelay_ms(2);
	E = 0;
}

/*Y Address*/
void RowSelect(U8 row){
	RW = 0;
	RS = 0;
	WR_DATA(0x40 | row);
	E = 1;
	mydelay_ms(2);
	E = 0;
}

void StartLine(U8 line){
	RW = 0;
	RS = 0;
	WR_DATA(0xC0 | line);
	E = 1;
	mydelay_ms(2);
	E = 0;
}

void WriteByte(U8 byt){
	WR_DATA(byt);
	E = 1;
	mydelay_ms(1);
	E = 0;
}

void WriteChar(U8 ch, U8 rev){
    U8 i, j;
    U8 OffsetMem = 48U;
    char *chr;
    RS = 1;
    RW = 0;
    /*Due to memory constrain we only have digits 0 to 7
      So we have an offset operation...*/
    chr = Font8x8 + ((ch - OffsetMem) * 8U);
    for(i = 0; i < 8; i++){
        if(rev){
            WriteByte(~(*chr++));
        }
        else{
            WriteByte(*chr++);
        }
    }
}