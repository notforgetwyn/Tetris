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
int x = 0, y = 0 ;short Offset_Left = 0, Offset_Right = 0;
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
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &curInfo);
}
//¹â±êÌø×ª
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
void conversion(unsigned ushort_16 n) {
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
void conversion1(unsigned ushort_16 n) {
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
			x++;
		}
	}
	else {
		conversion1(n / 2);
		if (n % 2 == 1)
		{
			CursorJump(x, y);
			std::cout << "1";
			x++;
		}
		else
		{
			CursorJump(x, y);
			x++;
		}
	}
}
void conversion2(unsigned ushort_16 n) {
	if (n <= 1) {
		if (n == 1)
		{
			CursorJump(x, y);
			std::cout << "  ";
			x++;
		}
		else
		{
			CursorJump(x, y);
			x++;
		}
	}
	else {
		conversion2(n / 2);
		if (n % 2 == 1)
		{
			CursorJump(x, y);
			std::cout << "  ";
			x++;
		}
		else
		{
			CursorJump(x, y);
			x++;
		}
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
	Offset_Left = 0, Offset_Right = 0;
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
