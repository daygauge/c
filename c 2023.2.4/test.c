#define _CRT_SECURE_NO_WARNINGS 1;
#include "text.h"


void baochunweijian(hj* txrs)
{
	FILE* a = fopen("test.asb", "w");
	if (a == NULL)
	{
		perror("fopen");
		return;
	}
	fwrite(txrs->ji, sizeof(hej), txrs->su, a);
	printf("已保存当前联系人信息");
}

void jiazaiwenjian(hj* txrs)
{
	FILE* a = fopen("test.asb", "r");
	if (a == NULL)
	{
		perror("fopen");
		return;
	}
	hej sz = { 0 };
	while (fread(&sz,sizeof(hej),1,a))
	{
		shifssukr(txrs);
		txrs->ji[txrs->su] = sz;
		txrs->su++;
	}
	fclose(a);
	a = NULL;
}
void chushihua(hj* txrs)
{
	txrs->ji = (hej*)calloc(CSNC ,sizeof(hej));
	if (txrs->ji == NULL)
	{
		perror("内存不足,无法创建通讯录空间\n");
		return;
	}
	txrs->su = 0;
	txrs->jic = CSNC;

	jiazaiwenjian(txrs);
}

void shifssukr(hj* txrt)
{
	if (txrt->su == txrt->jic)
	{
		hej* lings = (hej*)realloc(txrt->ji, (txrt->jic + JA) * sizeof(hej));
		if (lings == NULL)
		{
			printf("扩容失败\n");
			return ;
		}
		txrt->ji = lings;
		txrt->jic += JA;
		printf("扩容成功\n");
	}
}
void tianjiahs(hj* txrs)
{
	shifssukr(txrs);

	printf("请输入姓名:");
	scanf("%s",txrs->ji[txrs->su].xmin);
	printf("请输入性别:");
	scanf("%s", txrs->ji[txrs->su].xinb);
	printf("请输入年龄:");
	scanf("%d",&(txrs->ji[txrs->su].nianling));
	printf("请输入电话:");
	scanf("%s", txrs->ji[txrs->su].dianhua);
	printf("请输入地址:");
	scanf("%s", txrs->ji[txrs->su].dizhi);

	txrs->su++;
	printf("添加成功\n");

}



void ckanlbiaos(hj* txrs)
{
	printf("%-10s %-5s %-5s %-20s %-20s\n", "姓名","性别", "年龄", "电话", "地址");
	for (int i = 0;i < txrs->su ;i++)
	{
		printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin, 
			                                    txrs->ji[i].xinb,
			                                    txrs->ji[i].nianling,
			                                    txrs->ji[i].dianhua,
			                                    txrs->ji[i].dizhi);
	}
}

void chazaos(hj* txrs)
{
	char s[XM]={0};
		printf("请输入联系人姓名进行查找:\n");
		scanf("%s", s);
		for (int i = 0;i < txrs->su;i++)
		{
			if (strstr(txrs->ji[i].xmin, s))
			{
				printf("%-10s %-5s %-5s %-20s %-20s\n", "姓名", "性别", "年龄", "电话", "地址");
				printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin,
					txrs->ji[i].xinb,
					txrs->ji[i].nianling,
					txrs->ji[i].dianhua,
					txrs->ji[i].dizhi);
				return ;
			}
		}
		printf("找不到联系人,请确认联系人是否正确\n");
	return ;
}

void xgailxr(hj* txrs)
{
	char s[XM] = { 0 };
	printf("请输入需要修改的联系人名称:\n");
	scanf("%s", s);
	for (int i = 0;i < txrs->su;i++)
	{
		if (strstr(txrs->ji[i].xmin, s))
		{
			printf("%-10s %-5s %-5s %-20s %-20s\n", "姓名", "性别", "年龄", "电话", "地址");
			printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin,
				                                    txrs->ji[i].xinb,
				                                    txrs->ji[i].nianling,
				                                    txrs->ji[i].dianhua,
			                                      	txrs->ji[i].dizhi);

			printf("请输入修改后的姓名:\n");
			scanf("%s", txrs->ji[i].xmin);
			printf("请输入性别:\n");
			scanf("%s", txrs->ji[i].xinb);
			printf("请输入修改后的年龄:\n");
			scanf("%d", &(txrs->ji[i].nianling));
			printf("请输入修改后的电话:\n");
			scanf("%s", txrs->ji[i].dianhua);
			printf("请输入修改后的地址:\n");
			scanf("%s", txrs->ji[i].dizhi);
			printf("修改成功\n");
			return ;
		}
	}
	printf("输入的联系人名称不存在\n");
}

void shanchus(hj* txrs)
{
	char s[XM] = { 0 };
	printf("请输入需要删除的联系人名称:\n");
	scanf("%s", s);
	for (int i = 0;i <= TXRDX;i++)
	{
		if (strstr(txrs->ji[i].xmin, s))
		{
			for (int j = i;j <= txrs->su;j++)
			{
				txrs->ji[j] = txrs->ji[j + 1];
			}
			txrs->su--;
			printf("删除成功\n");
			return ;
		}
	}
	printf("删除失败,请确认输入的联系人名称是否正确\n");
}

int cmp(const void* s1, const void* s2)
{
	return ((hej*)s1)->nianling - ((hej*)s2)->nianling;
}

void paixulianxir(hj* txrs)
{
	qsort(txrs->ji, txrs->su, sizeof(txrs->ji[0]), cmp);
	ckanlbiaos(txrs);
}