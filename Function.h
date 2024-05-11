#pragma once
ushort_16 data[24];
ushort_16 ball[7][4][4] =
{
		0x0<< 4,0x2<< 4,0x7<< 4,0x0<< 4,0x0<< 4,0x2<< 4,0x3<< 4,0x2<< 4,0x0<< 4,0x7<< 4,0x2<< 4,0x0<< 4,0x0<< 4,0x2<< 4,0x6<< 4,0x2<< 4,
		0x0<< 4,0x6<< 4,0x2<< 4,0x2<< 4,0x0<< 4,0x1<< 4,0x7<< 4,0x0<< 4,0x0<< 4,0x2<< 4,0x2<< 4,0x3<< 4,0x0<< 4,0x7<< 4,0x4<< 4,0x0<< 4,
		0x0<< 4,0x3<< 4,0x2<< 4,0x2<< 4,0x0<< 4,0x7<< 4,0x1<< 4,0x0<< 4,0x0<< 4,0x1<< 4,0x1<< 4,0x3<< 4,0x0<< 4,0x7<< 4,0x1<< 4,0x0<< 4,
		0x0<< 4,0x6<< 4,0x3<< 4,0x0<< 4,0x0<< 4,0x1<< 4,0x3<< 4,0x2<< 4,0x0<< 4,0x6<< 4,0x3<< 4,0x0<< 4,0x0<< 4,0x1<< 4,0x3<< 4,0x2<< 4,
		0x0<< 4,0x3<< 4,0x6<< 4,0x0<< 4,0x0<< 4,0x2<< 4,0x3<< 4,0x1<< 4,0x0<< 4,0x3<< 4,0x6<< 4,0x0<< 4,0x0<< 4,0x2<< 4,0x3<< 4,0x1<< 4,
		0x0<< 4,0x3<< 4,0x3<< 4,0x0<< 4,0x0<< 4,0x3<< 4,0x3<< 4,0x0<< 4,0x0<< 4,0x3<< 4,0x3<< 4,0x0<< 4,0x0<< 4,0x3<< 4,0x3<< 4,0x0<< 4,
		0x0<< 4,0x0<< 4,0xf<< 4,0x0<< 4,0x1<< 4,0x1<< 4,0x1<< 4,0x1<< 4,0x0<< 4,0x0<< 4,0xf<< 4,0x0<< 4,0x1<< 4,0x1<< 4,0x1<< 4,0x1<< 4
};
int x = 0, y = 0,grade=0;short Offset_Left = 0, Offset_Right = 0;
void init();
void HideCursor();
void CursorJump(int x, int y);
void StartGame();
void Drawfall(ushort_16 fall[], ushort_16 floor);
void DrawBlock(ushort_16 fall[], ushort_16 floor);
ushort_16 length(ushort_16 n);
void conversion( ushort_16 n);
void conversion1(ushort_16 n);
void conversion2(ushort_16 n);
bool isDown(ushort_16 fall[], ushort_16 floor);
void Fill(ushort_16 fall[], ushort_16 floor);
void JudgeEnd(ushort_16 fall[], ushort_16 floor);
bool Full();
void Move();
void color(int c);
void init()
{
	HideCursor();
	x = 0, y = 0;
	for (ushort_16 j = 0; j <= 22; j++)
		data[j] = 0xe007;
	data[23] = 0xffff;
	for (ushort_16 j = 0; j < 24; j++)
	{
		conversion(data[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
	x = 16, y = 23;
	for (int j = 0; j < 16; j++)
	{
		
		CursorJump(x, y);
		printf("1");
		x++;
	}
	for (int j = 0; j <24; j++)
	{

		CursorJump(x, y);
		printf("11");
		y--;
	}
	x = 16, y =6;
	for (int j = 0; j < 16; j++)
	{

		CursorJump(x, y);
		printf("1");
		x++;
	}
	CursorJump(18, 0);
	printf("下一个方块：");

	CursorJump(20, 8);
	printf("左移：←");

	CursorJump(20, 10);
	printf("右移：→");

	CursorJump(20, 12);
	printf("加速：↓");

	CursorJump(20,14);
	printf("旋转：空格");

	CursorJump(20,16);
	printf("暂停: S");

	CursorJump(20, 18);
	printf("退出: Esc");

	CursorJump(20,20);
	printf("重新开始:R");

	CursorJump(20, 22);
	printf("当前分数：%d", grade);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &curInfo);
}
//光标跳转
void CursorJump(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void Drawfall(ushort_16 fall[],ushort_16 floor)
{
	x = 0; y = floor;
	for (ushort_16 j = 0; j < 4; j++)
	{
		x = x + (16 - length(fall[j]));
		conversion1(fall[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
void DrawBlock(ushort_16 fall[], ushort_16 floor)
{
	x = 0; y = floor;
	for (ushort_16 j = 0; j < 4; j++)
	{
		x = x +(16 - length(fall[j]));
		conversion2(fall[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
ushort_16 length(ushort_16 n)
{
	ushort_16 sum = 0;
	while (n != 0)
	{
		sum++;
		n = n / 2;
	}
	return sum;
}
void conversion(ushort_16 n) {
	if (n <= 1) {
		if (n == 1)
		{
			CursorJump(x, y);
			std::cout << "1";
			x++;
		}
		else
		{
			CursorJump(x, y);
			std::cout << "  ";
			x++;
		}
	}
	else {
		conversion(n / 2);
		if (n % 2 == 1)
		{
			CursorJump(x, y);
			std::cout << "1";
			x++;
		}
		else
		{
			CursorJump(x, y);
			std::cout << "  ";
			x++;
		}
	}
}
void conversion1( ushort_16 n) {
	if (n <= 1) {
		if (n == 1)
		{
			CursorJump(x, y);
			std::cout << "1";
		}
		x++;
	}
	else {
		conversion1(n / 2);
		if (n % 2 == 1)
		{
			CursorJump(x, y);
			std::cout << "1";
		}
		x++;
	}
}
void conversion2(ushort_16 n) {
	if (n <= 1) {
		if (n == 1)
		{
			CursorJump(x, y);
			std::cout << " ";
		}
		x++;
	}
	else {
		conversion2(n / 2);
		if (n % 2 == 1)
		{
			CursorJump(x, y);
			std::cout << " ";
		}
			x++;
	}
}
bool isDown(ushort_16 fall[], ushort_16 floor)
{
	for (ushort_16 j = 0; j <= 3; j++)
		if ((fall[j] & data[floor + j+1]))
			return true;
	return false;
}
void Fill(ushort_16 fall[], ushort_16 floor)
{
	for (ushort_16 j = 0; j <= 3; j++)
		data[floor + j] = data[floor + j] | fall[j];
}
void JudgeEnd(ushort_16 fall[], ushort_16 floor)
{
	auto pass = [&](ushort_16 fall[], ushort_16 floor)
		{
			for (ushort_16 j = 0; j <= 3; j++)
				if ((fall[j] & data[floor + j]))
					return true;
			return false;
		};
	if (pass(fall, floor))
	{
		;
	}
}
bool Full()
{
	for (ushort_16 j = 0; j <= 22; j++)
	{
		if (data[j] == 0xffff)
		{
			data[j] = 0x0000;
			return true;
		}
	}
	return false;
}
void Move()
{
	for (ushort_16 j = 22; j > 0; j--)
	{
		data[j] = data[j - 1];
	}
	data[0] = 0xe007;
	x = 0; y = 0;
	for (ushort_16 j = 0; j < 24; j++)
	{
		
		conversion(data[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
void color(int c)
{
	switch (c)
	{
	case 0:
		c = 13; //“T”形方块设置为紫色
		break;
	case 1:
	case 2:
		c = 12; //“L”形和“J”形方块设置为红色
		break;
	case 3:
	case 4:
		c = 10; //“Z”形和“S”形方块设置为绿色
		break;
	case 5:
		c = 14; //“O”形方块设置为黄色
		break;
	case 6:
		c = 11; //“I”形方块设置为浅蓝色
		break;
	default:
		c = 7; //其他默认设置为白色
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}