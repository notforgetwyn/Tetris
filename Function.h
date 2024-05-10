#pragma once
ushort_16 data[24];
ushort_16 fall[7][4][4] =
{
		0x0,0x2,0x7,0x0,0x0,0x2,0x3,0x2,0x0,0x7,0x2,0x0,0x0,0x2,0x6,0x2,
		0x0,0x6,0x2,0x2,0x0,0x1,0x7,0x0,0x0,0x2,0x2,0x3,0x0,0x7,0x4,0x0,
		0x0,0x3,0x2,0x2,0x0,0x7,0x1,0x0,0x0,0x1,0x1,0x3,0x0,0x7,0x1,0x0,
		0x0,0x6,0x3,0x0,0x0,0x1,0x3,0x2,0x0,0x6,0x3,0x0,0x0,0x1,0x3,0x2,
		0x0,0x3,0x6,0x0,0x0,0x2,0x3,0x1,0x0,0x3,0x6,0x0,0x0,0x2,0x3,0x1,
		0x0,0x3,0x3,0x0,0x0,0x3,0x3,0x0,0x0,0x3,0x3,0x0,0x0,0x3,0x3,0x0,
		0x0,0x0,0xf,0x0,0x1,0x1,0x1,0x1,0x0,0x0,0xf,0x0,0x1,0x1,0x1,0x1
};
int x=0, y=0;
void init();
void HideCursor();
void CursorJump(int x, int y);
void StartGame();
void Drawfall(ushort_16 temp[], ushort_16 floor);
void DrawBlock(ushort_16 temp[], ushort_16 floor);
ushort_16 length(ushort_16 n);
void conversion( ushort_16 n);
void conversion1(ushort_16 n);
void conversion2(ushort_16 n);
bool isDown(ushort_16 temp[], ushort_16 floor);
void Fill(ushort_16 temp[], ushort_16 floor);
bool Full();
void Move();
void init()
{
	for (ushort_16 j = 0; j <= 22; j++)
		data[j] = 0xe007;
	data[23] = 0xffff;
	for (ushort_16 i = 0; i < 7; i++)
		for (int j = 0; j < 4; j++)
			for (ushort_16 k = 0; k < 4; k++)
				fall[i][j][k] = fall[i][j][k] << 4;
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
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1;  //如果没赋值的话，隐藏光标无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}
//光标跳转
void CursorJump(int x, int y)
{
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标设置
	pos.Y = y; //纵坐标设置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
}
void StartGame()
{
	while (1)
	{
		ushort_16 row = rand() % 7, colum = rand() % 4, floor = 0;
		ushort_16 temp[4] = 
		{ fall[row][colum][0]
		, fall[row][colum][1]
		, fall[row][colum][2]
		, fall[row][colum][3] };
		while (1)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case DOWN:
				{

				}
				}
			}
			else
			{
				Drawfall(temp, floor);
				if (!isDown(temp, floor))
				{
					Sleep(100);
					DrawBlock(temp, floor);
					floor++;
					
				}
				else
				{
					Fill(temp, floor);
					if(Full())
						Move();
					break;
				}
			}
			
		}

	}
}
void Drawfall(ushort_16 temp[],ushort_16 floor)
{
	x = 0; y = floor;
	for (ushort_16 j = 0; j < 4; j++)
	{
		x = x + (16 - length(temp[j]));
		conversion1(temp[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
void DrawBlock(ushort_16 temp[], ushort_16 floor)
{
	x = 0; y = floor;
	for (ushort_16 j = 0; j < 4; j++)
	{
		x = x +(16 - length(temp[j]));
		conversion2(temp[j]);
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
			std::cout << "■";
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
			std::cout << "■";
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
			std::cout << "■";
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
			std::cout << "■";
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
bool isDown(ushort_16 temp[], ushort_16 floor)
{
	for (ushort_16 j = 0; j <= 3; j++)
		if ((temp[j] & data[floor + j+1]))
			return true;
	return false;
}
void Fill(ushort_16 temp[], ushort_16 floor)
{
	for (ushort_16 j = 0; j <= 3; j++)
		data[floor + j] = data[floor + j] | temp[j];

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
	data[0] = data[23];
}
