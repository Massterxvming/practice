#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include<conio.h>
#include<windows.h>
#include <stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

void initgamePicture();   //������ϷͼƬ
void SetPlayer();       //��ʾ��ɫ��Ϣ
void initPlayer();      //��ʼ����Ϸ��ɫ
void SetMap();         //������Ϸ��ͼ
char* intToString(int Number); //������ת�����ַ���
void playGame();          //��ʼ��Ϸ
int Combat(int x);
int VS(int playHP, int playATT, int playDEF, int monHP, int monATT, int monDEF);

int playerx, playery;
char str[20] = "";
//��ͼ1
int qw = 1;
int map[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 98, 1, 14, 15, 14, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 8, 1, 1, 2, 1, 0, 5, 6, 1, 0, 1, 0 },
	{ 0, 1, 12, 1, 0, 1, 0, 4, 8, 1, 0, 1, 0 },
	{ 0, 0, 2, 0, 0, 1, 0, 0, 0, 14, 0, 1, 0 },
	{ 0, 6, 1, 1, 0, 1, 3, 10, 11, 10, 0, 1, 0 },
	{ 0, 1, 13, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 0, 14, 0, 0, 0, 14, 0, 0 },
	{ 0, 8, 1, 6, 0, 7, 1, 6, 0, 1, 10, 1, 0 },
	{ 0, 8, 1, 6, 0, 1, 99, 1, 0, 14, 9, 14, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int map2[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 98, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 8, 1, 1, 2, 1, 1, 5, 6, 1, 0, 1, 0 },
	{ 0, 1, 12, 1, 0, 1, 1, 4, 8, 1, 0, 1, 0 },
	{ 0, 0, 2, 0, 0, 1, 1, 0, 0, 14, 0, 1, 0 },
	{ 0, 6, 1, 1, 0, 1, 1, 10, 11, 10, 0, 1, 0 },
	{ 0, 1, 13, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 14, 0, 0 },
	{ 0, 8, 1, 6, 0, 7, 1, 6, 0, 1, 10, 1, 0 },
	{ 0, 99, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
IMAGE Wall, Ground, Green_Slime, Red_Slime, Blue_Cry, Red_Cry, Blue_Key, Yellow_Key,
Red_Med, Blue_Med, Ladder, Small_Skull, Big_Skull, Small_Bat, Small_Wizard,
Blue_door, Yellow_door, Player, Message;
HWND hwnd;
struct gamerole
{
	char name[20] = "��ʥ";  //�������
	int HP;	    //Ѫ��
	int MP;
	int DEF;	//����
	int ATT;    //����
	int Lv;     //�ȼ�
	int Exp;    //����
	int Num_Blue_Key; //��Կ������
	int Num_Yellow_Key;
}player;

struct monster
{
	int HP;	    //Ѫ��
	int ATT;    //����
	int DEF;	//����
	int Exp;    //����
};
struct monster Green_Slime_Pro = { 50,10,12,200 };    //��ʷ��ķ����     
struct monster Red_Slime_Pro = { 100, 20, 12, 400 };  //��ʷ��ķ����
struct monster Small_Wizard_Pro = { 100, 30, 9, 400 };//С��ʦ����
struct monster Small_Bat_Pro = { 20, 10, 9, 50 };         //С��������
struct monster Small_Skull_Pro = { 100, 20, 10, 300 };   //С��������
struct monster Big_Skull_Pro = { 150, 50, 25, 500 };     //����������


int main()
{
	mciSendString("play  ħ��.mp3", 0, 0, 0);
	initPlayer();
	hwnd = initgraph(60 * 14, 60 * 13);
	initgamePicture();

	while (1) {
		SetMap();
		SetPlayer();
		playGame();
	}
system("pause");
	return 0;
}

/*
*��ʾ��ɫ��Ϣ
*/
void SetPlayer()
{
	putimage(60 * 13, 0, &Message);
	outtextxy(60 * 13 + 12, 100, player.name);
	outtextxy(60 * 13 + 12, 180, intToString(player.Lv));
	outtextxy(60 * 13 + 12, 235, intToString(player.Exp));
	outtextxy(60 * 13 + 12, 362, intToString(player.HP));
	outtextxy(60 * 13 + 12, 425, intToString(player.MP));
	outtextxy(60 * 13 + 12, 517, intToString(player.ATT));
	outtextxy(60 * 13 + 12, 567, intToString(player.DEF));
	outtextxy(60 * 13 + 12, 689, intToString(player.Num_Yellow_Key));
	outtextxy(60 * 13 + 12, 759, intToString(player.Num_Blue_Key));
}

/*
*   ������ϷͼƬ
*/
void initgamePicture()
{
	loadimage(&Wall, "ǽ.jpg", 60, 60);
	loadimage(&Ground, "�ذ�.jpg", 60, 60);
	loadimage(&Green_Slime, "��ʷ��ķ.jpg", 60, 60);
	loadimage(&Red_Slime, "��ʷ��ķ.jpg", 60, 60);

	loadimage(&Blue_Cry, "��ˮ��.jpg", 60, 60);
	loadimage(&Red_Cry, "��ˮ��.jpg", 60, 60);

	loadimage(&Blue_Key, "��Կ��.jpg", 60, 60);
	loadimage(&Yellow_Key, "��Կ��.jpg", 60, 60);

	loadimage(&Red_Med, "С��ҩˮ.JPG", 60, 60);
	loadimage(&Blue_Med, "С��ҩˮ.jpg", 60, 60);

	loadimage(&Ladder, "����.jpg", 60, 60);
	loadimage(&Small_Bat, "С����.jpg", 60, 60);
	loadimage(&Small_Wizard, "С��ʦ.jpg", 60, 60);
	loadimage(&Small_Skull, "���ñ�.jpg", 60, 60);
	loadimage(&Big_Skull, "�����ñ�.jpg", 60, 60);

	loadimage(&Blue_door, "����.jpg", 60, 60);
	loadimage(&Yellow_door, "����.jpg", 60, 60);
	loadimage(&Player, "��.jpg", 60, 60);
	loadimage(&Message, "info.jpg");
}

/*
*��ʼ����Ϸ��ɫ
*/
void initPlayer()
{
	player.Lv = 0;
	player.ATT = 20;
	player.DEF = 0;
	player.Num_Blue_Key = 0;
	player.Num_Yellow_Key = 0;
	player.HP = 500;
	player.MP = 250;
	player.Exp = 0;
	playerx = 11;
	playery = 6;
}

//����ת��Ϊ�ַ�
char* intToString(int Number)
{
	int len = 0;

	if (Number == 0) {
		str[0] = '0';
		len++;
	}
	while (Number)
	{
		str[len++] = Number % 10 + '0';
		Number /= 10;
	}
	for (int i = 0; i < len / 2; i++) {
		char t = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = t;
	}
	str[len] = '\0';
	return str;
}

/*
*������Ϸ��ͼ
*
*/
void SetMap()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			switch (map[i][j])
			{

			case 0:
				putimage(j * 60, i * 60, &Wall);          //ǽ
				break;
			case 1:
				putimage(j * 60, i * 60, &Ground);        //�ذ�
				break;
			case 2:
				putimage(j * 60, i * 60, &Blue_door);     //����
				break;
			case 3:
				putimage(j * 60, i * 60, &Yellow_door);    //����
				break;
			case 4:
				putimage(j * 60, i * 60, &Blue_Cry);         //��ˮ��
				break;
			case 5:
				putimage(j * 60, i * 60, &Red_Cry);          //��ˮ��
				break;
			case 6:
				putimage(j * 60, i * 60, &Blue_Key);        //��Կ��
				break;
			case 7:
				putimage(j * 60, i * 60, &Yellow_Key);     //��Կ��
				break;
			case 8:
				putimage(j * 60, i * 60, &Red_Med);          //��ҩˮ
				break;
			case 9:
				putimage(j * 60, i * 60, &Blue_Med);         //��ҩˮ
				break;
			case 10:
				putimage(j * 60, i * 60, &Small_Bat);        //С����
				break;
			case 11:
				putimage(j * 60, i * 60, &Small_Wizard);     //С��ʦ
				break;
			case 12:
				putimage(j * 60, i * 60, &Small_Skull);      //С����
				break;
			case 13:
				putimage(j * 60, i * 60, &Big_Skull);        //������
				break;
			case 14:
				putimage(j * 60, i * 60, &Green_Slime);      //��ʷ��ķ
				break;
			case 15:
				putimage(j * 60, i * 60, &Red_Slime);        //��ʷ��ķ
				break;
			case 98:
				putimage(j * 60, i * 60, &Ladder);         //����
				break;
			case 99:
				putimage(j * 60, i * 60, &Player);          //���
				break;
			}

		}
	}
}

void Setmap()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			switch (map2[i][j])
			{

			case 0:
				putimage(j * 60, i * 60, &Wall);          //ǽ
				break;
			case 1:
				putimage(j * 60, i * 60, &Ground);        //�ذ�
				break;
			case 2:
				putimage(j * 60, i * 60, &Blue_door);     //����
				break;
			case 3:
				putimage(j * 60, i * 60, &Yellow_door);    //����
				break;
			case 4:
				putimage(j * 60, i * 60, &Blue_Cry);         //��ˮ��
				break;
			case 5:
				putimage(j * 60, i * 60, &Red_Cry);          //��ˮ��
				break;
			case 6:
				putimage(j * 60, i * 60, &Blue_Key);        //��Կ��
				break;
			case 7:
				putimage(j * 60, i * 60, &Yellow_Key);     //��Կ��
				break;
			case 8:
				putimage(j * 60, i * 60, &Red_Med);          //��ҩˮ
				break;
			case 9:
				putimage(j * 60, i * 60, &Blue_Med);         //��ҩˮ
				break;
			case 10:
				putimage(j * 60, i * 60, &Small_Bat);        //С����
				break;
			case 11:
				putimage(j * 60, i * 60, &Small_Wizard);     //С��ʦ
				break;
			case 12:
				putimage(j * 60, i * 60, &Small_Skull);      //С����
				break;
			case 13:
				putimage(j * 60, i * 60, &Big_Skull);        //������
				break;
			case 14:
				putimage(j * 60, i * 60, &Green_Slime);      //��ʷ��ķ
				break;
			case 15:
				putimage(j * 60, i * 60, &Red_Slime);        //��ʷ��ķ
				break;
			case 98:
				putimage(j * 60, i * 60, &Ladder);         //����
				break;
			case 99:
				putimage(j * 60, i * 60, &Player);          //���
				break;
			}

		}
	}
}

int Combat(int x)
{
	int ID;
	switch (x) {
	case 10:
		ID = MessageBox(hwnd, "С����", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Small_Bat_Pro.HP, Small_Bat_Pro.ATT, Small_Bat_Pro.DEF)) {
				player.Exp += Small_Bat_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�", "��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT += 10;
					player.DEF += 10;
				}
				return 1;
			}
		}
		break;
	case 11:
		ID = MessageBox(hwnd, "����С��ʦ", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Small_Wizard_Pro.HP, Small_Wizard_Pro.ATT, Small_Wizard_Pro.DEF)) {
				player.Exp += Small_Wizard_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�", "��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT += 10;
					player.DEF += 10;
				}
				return 1;
			}
		}
		break;
	case 12:
		ID = MessageBox(hwnd, "����С����", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Small_Skull_Pro.HP, Small_Skull_Pro.ATT, Small_Skull_Pro.DEF)) {
				player.Exp += Small_Skull_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�", "��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT += 10;
					player.DEF += 10;
				}
				return 1;
			}
		}
		break;
	case 13:
		ID = MessageBox(hwnd, "����������", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Big_Skull_Pro.HP, Big_Skull_Pro.ATT, Big_Skull_Pro.DEF)) {
				player.Exp += Big_Skull_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�", "��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT += 10;
					player.DEF += 10;
				}
				return 1;
			}
		}
		break;
	case 14:
		ID = MessageBox(hwnd, "������ʷ��ķ", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Green_Slime_Pro.HP, Green_Slime_Pro.ATT, Green_Slime_Pro.DEF)) {
				player.Exp += Green_Slime_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�","��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT +=10;
					player.DEF +=10;
				}
				return 1;
			}
		}
		break;
	case 15:
		ID = MessageBox(hwnd, "������ʷ��ķ", "�Ƿ񹥻���", MB_YESNO);
		if (ID == IDYES)
		{
			if (VS(player.HP, player.ATT, player.DEF, Red_Slime_Pro.HP, Red_Slime_Pro.ATT, Red_Slime_Pro.DEF)) {
				player.Exp += Green_Slime_Pro.Exp;
				if (player.Exp >= 1000)
				{
					MessageBox(hwnd, "�������ˣ�", "��ʾ", MB_OK);
					player.Exp = 0;
					player.Lv++;
					player.HP += 200;
					player.ATT += 10;
					player.DEF += 10;
				}
				return 1;
			}
		}
		break;

	}
	return 0;
}

int VS(int playHP, int playATT, int playDEF, int monHP, int monATT, int monDEF)
{
	while (playHP > 0 || monHP > 0)
	{
		monHP -= (playATT - monDEF);
		if (monHP < 0)
			break;
		playHP -= (monATT - playDEF);
	}
	if (playHP > 0) {
		player.HP = playHP;
		return 1;
	}

	else {
		MessageBox(hwnd, "", "�򲻹�", MB_YESNO);
		return 0;
	}
}
void playGame()
{
	while (1)
	{
		char ch = _getch();
		switch (ch) {
		case 'w':
		case 72:
			if (map[playerx - 1][playery] == 98)
			{
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
				MessageBox(hwnd, "�����ڴ���", "��ʾ", MB_OK);
			}
			else if (map[playerx - 1][playery] == 1) {         //��һ���ǵذ�
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
			}
			else if (map[playerx - 1][playery] == 6) {      //��һ������Կ��
				player.Num_Blue_Key++;
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
			}
			else if (map[playerx - 1][playery] == 7) {     //��һ���ǻ�Կ��
				player.Num_Yellow_Key++;
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
			}
			//��һ���ǹ���
			else if (map[playerx - 1][playery] == 10 || map[playerx - 1][playery] == 11 ||
				map[playerx - 1][playery] == 12 || map[playerx - 1][playery] == 13 ||
				map[playerx - 1][playery] == 14 || map[playerx - 1][playery] == 15)
			{
				int x = Combat(map[playerx - 1][playery]);
				if (x == 1) {
					map[playerx - 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx--;
				}
			}
			//����ҩˮ
			else if (map[playerx - 1][playery] == 8 || map[playerx - 1][playery] == 9) {
				if (map[playerx - 1][playery] == 8)
					player.HP += 200;
				else
					player.HP += 500;
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
			}
			//������
			else if (map[playerx - 1][playery] == 2 || map[playerx - 1][playery] == 3) {
				if (map[playerx - 1][playery] == 2 && player.Num_Blue_Key) {
					player.Num_Blue_Key--;
					map[playerx - 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx--;
				}
				if (map[playerx - 1][playery] == 3 && player.Num_Yellow_Key) {
					player.Num_Yellow_Key--;
					map[playerx - 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx--;
				}
			}
			//����ˮ��
			//��ˮ��+2����
			//��ˮ��+2����
			else if (map[playerx - 1][playery] == 4 || map[playerx - 1][playery] == 5) {
				if (map[playerx - 1][playery] == 4)
					player.DEF += 10;
				else if (map[playerx - 1][playery] == 5)
					player.ATT += 10;
				map[playerx - 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx--;
			}
			break;
		case 's':
		case 80:
			if (map[playerx + 1][playery] == 1) {         //��һ���ǵذ�
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
			}
			else if (map[playerx + 1][playery] == 98)
			{
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
				MessageBox(hwnd, "�����ڴ���", "��ʾ", MB_OK);
			}
			else if (map[playerx + 1][playery] == 6) {      //��һ������Կ��
				player.Num_Blue_Key++;
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
			}
			else if (map[playerx + 1][playery] == 7) {     //��һ���ǻ�Կ��
				player.Num_Yellow_Key++;
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
			}
			//��һ���ǹ���
			else if (map[playerx + 1][playery] == 10 || map[playerx + 1][playery] == 11 ||
				map[playerx + 1][playery] == 12 || map[playerx + 1][playery] == 13 ||
				map[playerx + 1][playery] == 14 || map[playerx + 1][playery] == 15)
			{
				int x = Combat(map[playerx + 1][playery]);
				if (x == 1) {
					map[playerx + 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx++;
				}
			}
			//����ҩˮ
			else if (map[playerx + 1][playery] == 8 || map[playerx + 1][playery] == 9) {
				if (map[playerx + 1][playery] == 8)
					player.HP += 200;
				else
					player.HP += 500;
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
			}
			//������
			else if (map[playerx + 1][playery] == 2 || map[playerx + 1][playery] == 3) {
				if (map[playerx + 1][playery] == 2 && player.Num_Blue_Key) {
					player.Num_Blue_Key++;
					map[playerx + 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx++;
				}
				if (map[playerx + 1][playery] == 3 && player.Num_Yellow_Key) {
					player.Num_Yellow_Key++;
					map[playerx + 1][playery] = 99;
					map[playerx][playery] = 1;
					playerx++;
				}
			}
			//����ˮ��
			//��ˮ��+2����
			//��ˮ��+2����
			else if (map[playerx + 1][playery] == 4 || map[playerx + 1][playery] == 5) {
				if (map[playerx + 1][playery] == 4)
					player.DEF += 10;
				else if (map[playerx + 1][playery] == 5)
					player.ATT += 10;
				map[playerx + 1][playery] = 99;
				map[playerx][playery] = 1;
				playerx++;
			}
			break;
		case 'a':
		case 75:
			if (map[playerx][playery - 1] == 1) {         //��һ���ǵذ�
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
			}
			else if (map[playerx][playery - 1] == 98)
			{
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
				MessageBox(hwnd, "�����ڴ���", "��ʾ", MB_OK);
				qw = 2;
			}
			else if (map[playerx][playery - 1] == 6) {      //��һ������Կ��
				player.Num_Blue_Key++;
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
			}
			else if (map[playerx][playery - 1] == 7) {     //��һ���ǻ�Կ��
				player.Num_Yellow_Key++;
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
			}
			//��һ���ǹ���
			else if (map[playerx][playery - 1] == 10 || map[playerx][playery - 1] == 11 ||
				map[playerx][playery - 1] == 12 || map[playerx][playery - 1] == 13 ||
				map[playerx][playery - 1] == 14 || map[playerx][playery - 1] == 15)
			{
				int x = Combat(map[playerx][playery - 1]);
				if (x == 1) {
					map[playerx][playery - 1] = 99;
					map[playerx][playery] = 1;
					playery--;
				}
			}
			//����ҩˮ
			else if (map[playerx][playery - 1] == 8 || map[playerx][playery - 1] == 9) {
				if (map[playerx][playery - 1] == 8)
					player.HP += 200;
				else
					player.HP += 500;
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
			}
			//������
			else if (map[playerx][playery - 1] == 2 || map[playerx][playery - 1] == 3) {
				if (map[playerx][playery - 1] == 2 && player.Num_Blue_Key) {
					player.Num_Blue_Key--;
					map[playerx][playery - 1] = 99;
					map[playerx][playery] = 1;
					playery--;
				}
				if (map[playerx][playery - 1] == 3 && player.Num_Yellow_Key) {
					player.Num_Yellow_Key--;
					map[playerx][playery - 1] = 99;
					map[playerx][playery] = 1;
					playery--;
				}
			}
			//����ˮ��
			//��ˮ��+2����
			//��ˮ��+2����
			else if (map[playerx][playery - 1] == 4 || map[playerx][playery - 1] == 5) {
				if (map[playerx][playery - 1] == 4)
					player.DEF += 10;
				else if (map[playerx][playery - 1] == 5)
					player.ATT += 10;
				map[playerx][playery - 1] = 99;
				map[playerx][playery] = 1;
				playery--;
			}
			break;
		case 'd':
		case 77:
			if (map[playerx][playery + 1] == 1) {         //��һ���ǵذ�
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
			}
			else if (map[playerx][playery + 1] == 98)
			{
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
				MessageBox(hwnd, "�����ڴ���", "��ʾ", MB_OK);
			}
			else if (map[playerx][playery + 1] == 6) {      //��һ������Կ��
				player.Num_Blue_Key++;
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
			}
			else if (map[playerx][playery + 1] == 7) {     //��һ���ǻ�Կ��
				player.Num_Yellow_Key++;
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
			}
			//��һ���ǹ���
			else if (map[playerx][playery + 1] == 10 || map[playerx][playery + 1] == 11 ||
				map[playerx][playery + 1] == 12 || map[playerx][playery + 1] == 13 ||
				map[playerx][playery + 1] == 14 || map[playerx][playery + 1] == 15)
			{
				int x = Combat(map[playerx][playery + 1]);
				if (x == 1) {
					map[playerx][playery + 1] = 99;
					map[playerx][playery] = 1;
					playery++;
				}
			}
			//����ҩˮ
			else if (map[playerx][playery + 1] == 8 || map[playerx][playery + 1] == 9) {
				if (map[playerx][playery + 1] == 8)
					player.HP += 200;
				else
					player.HP += 500;
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
			}
			//������
			else if (map[playerx][playery + 1] == 2 || map[playerx][playery + 1] == 3) {
				if (map[playerx][playery + 1] == 2 && player.Num_Blue_Key) {
					player.Num_Blue_Key--;
					map[playerx][playery + 1] = 99;
					map[playerx][playery] = 1;
					playery++;
				}
				if (map[playerx][playery + 1] == 3 && player.Num_Yellow_Key) {
					player.Num_Yellow_Key--;
					map[playerx][playery + 1] = 99;
					map[playerx][playery] = 1;
					playery++;
				}
			}
			//����ˮ��
			//��ˮ��+10����
			//��ˮ��+10����
			else if (map[playerx][playery + 1] == 4 || map[playerx][playery + 1] == 5) {
				if (map[playerx][playery + 1] == 4)
					player.DEF += 10;
				else if (map[playerx][playery + 1] == 5)
					player.ATT += 10;
				map[playerx][playery + 1] = 99;
				map[playerx][playery] = 1;
				playery++;
			}
			break;

		}
		if(qw==1)
		SetMap();  //������ʾ��ͼ
		else Setmap();
		SetPlayer(); //������ʾ��ɫ��Ϣ
	}
}