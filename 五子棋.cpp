#include <stdio.h>
#include <stdlib.h>

 //���������ҵ1�������� 
const int max = 15;//������ı����̴�С 
char map[max][max];//�ö�ά����洢���� 
int turn = 0;//�ڰ׻غ� ��Ĭ�Ϻ������� 
bool judge = true;//�Ƿ������Ϸ�ı�־
int h, l;//������к��� 
int xia = 8;//�ж�����֮���費��Ҫ���뵽�ж���Ӯ 
char winner = 'r';//�洢Ӯ��,'r'����ƽ�� 
 
bool menu()//�˵� 
{
	printf("=================================\n");
	printf("�����Ƿ�ʼ������1��ʼ,����0����\n");
	printf("=================================\n");
	int b;
	scanf("%d", &b);
	if(b == 1)
	return true;
	else
	return false;
}

void int_map()//��ʼ�� 
{
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			map[i][j] = '+';//��+��ʾ�հ� 
		}
	}
	turn = 0;
	judge = true;
	winner = 'r';
}

void chess()//�������Ӻ���
{
	scanf("%d%d", &h, &l);//�������� 
	if(h > max || h < 0 || l > max || l < 0 || map[h-1][l-1] != '+')
	{
		printf("\n");
		printf("\n");
		printf("================================\n");
		printf("���Ǹ��ط����Ϸ���������ѡ��λ��\n");
		printf("================================\n");
		xia = 0;
		return;
	}
	else if(turn >= max * max)
	{
		printf("\n");
		printf("\n");
		printf("===========================\n");
		printf("���������ޣ� ������ѡ��λ��\n");
		printf("===========================\n");
		xia = 0;
		return;
	}
	else if(turn & 1)//������������ǰ��嶯 
	{
		map[h-1][l-1] = 'o';//����Ϊo 
		xia = 1;
		turn++; //�غ��Լӽ��뵽��һ���� 
	}
	else//ż��Ϊ�� 
	{
		map[h-1][l-1] = 'v';//����Ϊv 
		xia = 1;
		turn++;
	}
 } 
 
void print()//��ӡ���� 
{
	system("cls");//ˢ��
	printf("\n");
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			printf("%c ", map[i][j]);//��ͨ�������� 
		}
		printf("\n");
	}
//	printf("\n");
//	printf("\n");
}

void lose_win()//�ж���Ӯ�� ˼·Ϊ���ĸ�������� 
{
	int count = 1;//����,��Ϊ�Ѿ�����һ�������Դ�1��ʼ 
	char temp = map[h-1][l-1];//һ����ʱ�Ĵ��������µ�����ʲô��ɫ֮����������ѭ�� 
	for(int x = 0; x == 0; x++)//ˮƽ����
	{
		for(int i = 1; map[h-1-i][l-1] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1+i][l-1] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)//���ɵĸ�������5���ͽ����������� 
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;//ÿ�α���һ������������ 
	for(int x = 0; x == 0; x++)//��ֱ���� 
	{
		for(int i = 1; map[h-1][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;
	for(int x = 0; x == 0; x++)//'\'���� 
	{
		for(int i = 1; map[h-1-i][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1+i][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;
	for(int x = 0; x == 0; x++)//'/'���� 
	{
		for(int i = 1; map[h-1+i][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1-i][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
}

int main()//������ 
{
	if(!menu())//����0���� 
	{
		printf("��ӭ�Ժ�������");
	}
	else//����1��Ϸ��ʼ 
	{
		c:;
		printf("��Ϸ���򣺺������У�����Ϊ'v'������Ϊ'o'������ˮƽ����ֱ��б�������������ͬ���������ʤ\n");
		int_map();
		do{
			print();//����ҿ�һ��������ʲô��� 
			if(turn & 1)
			{
				printf("�����ǰ��ӻغϣ� �������������꣬��ʽΪ����+�ո�+�С���:1 2\n"); 
			}
			else
			{
				printf("�����Ǻ��ӻغϣ� �������������꣬��ʽΪ����+�ո�+�С���:1 2\n"); 
			}
			chess();//���� 
			if(xia == 1)//����µ�λ�úϷ����뵽�ж���Ӯ 
			lose_win();//�ж���Ӯ 
		}while(judge != false);//���жϽ����Ϊ����һֱ���� 
		print();
		if(winner == 'o')
		printf("�����ʤ"); 
		else if(winner == 'v')
		printf("�����ʤ"); 
		else
		printf("ƽ��");
		printf("\n�����Ƿ�����һ�֣�����һ��������1�� ������Ϸ������2\n");//�������ж��Ƿ�Ҫ����һ�� 
	int k;
	scanf("%d", &k);
	if(k == 1)//����1 ������һ�� 
	goto c;
	else
	printf("��Ϸ��������ӭ�´�����");
	}
	return 0;
}
