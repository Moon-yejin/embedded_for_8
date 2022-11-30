#ifndef _TEXTLCD_H_
#define _TEXTLCD_H_

#define LINE_BUFF_NUM (COLUMN_NUM + 4)
#define LINE_NUM 2
#define COLUMN_NUM 16

#define CMD_WRITE_STRING 0x20
#define CMD_DATA_WRITE_BOTH_LINE 0
#define CMD_DATA_WRITE_LINE_1 1
#define CMD_DATA_WRITE_LINE_2 2

typedef struct TextLCD_tag
{
	unsigned char cmd;
	unsigned char cmdData;
	unsigned char reserved[2];

	char TextData[LINE_NUM][LINE_BUFF_NUM];
}stTextLCD, *pStTextLCD;

void TextInit(unsigned int linenum, char output);
void TextExit();

#endif
