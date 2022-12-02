#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "textlcd.h"

#define TEXTLCD_DRIVER_NAME "/dev/peritextlcd"
int fd = 0;

void TextInit(unsigned int linenum, char output[50])
{
   stTextLCD stlcd; // 구조체와 드라이버 인터페이스
   memset(&stlcd, 0, sizeof(stTextLCD)); // 구조체 초기화
   if (linenum == 1)
   {
      stlcd.cmdData = CMD_DATA_WRITE_LINE_1;
   }
   else if (linenum == 2)
   {
      stlcd.cmdData = CMD_DATA_WRITE_LINE_2;
   }
   else
          {
      printf ("linenum = %d wrong! Range (1-2) \n", linenum);
      return 1;
   }

//   if (sizeof(output) > COLUMN_NUM)
//   {
//      memcpy(stlcd.TextData[stlcd.cmdData - 1], output, COLUMN_NUM);
//   }

//   else
//   {
      memcpy(stlcd.TextData[stlcd.cmdData - 1], output, sizeof(output));
//   }

   stlcd.cmd = CMD_WRITE_STRING;

   fd = open (TEXTLCD_DRIVER_NAME, O_RDWR);
   if (fd < 0)
   {
      printf ("Error!\n");
      return 1;
   }

   write (fd, &stlcd, sizeof(stTextLCD));
}

void TextExit()
{
   close(fd);
   return 0;
}
