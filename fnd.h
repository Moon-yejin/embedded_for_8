#ifndef _FND_H_
#define _FND_H_

#define MAX_FND_NUM 6
#define FND_DATA_BUFF_LEN (MAX_FND_NUM + 2)

typedef struct FNDWriteDataForm_tag
{
	char DataNumeric[FND_DATA_BUFF_LEN];
	char DataDot[FND_DATA_BUFF_LEN];
	char DataValid [FND_DATA_BUFF_LEN];
}stFndWriteForm, *pStFndWriteForm;

int fndDispInit(int num, int dotflag);
void fndDispExit();

#endif
