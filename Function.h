#pragma once
unsigned short data[24];
unsigned short fall[7][4][4] =
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
void Drawfall(unsigned short temp[], unsigned short floor);
void DrawBlock(unsigned short temp[], unsigned short floor);
void conversion( unsigned short n);
void conversion1(unsigned short n);
void conversion2(unsigned short n);
bool isDown(unsigned short temp[], unsigned short floor);
void Fill(unsigned short temp[], unsigned short floor);
bool Full();
void init()
{
	for (unsigned short j = 0; j <= 22; j++)
		data[j] = 0xe007;
	data[23] = 0xffff;
	for (unsigned short i = 0; i < 7; i++)
		for (int j = 0; j < 4; j++)
			for (unsigned short k = 0; k < 4; k++)
				fall[i][j][k] = fall[i][j][k] << 4;
	for (unsigned short j = 0; j < 24; j++)
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
		unsigned short row = rand() % 7, colum = rand() % 4, floor = 0;
		unsigned short temp[4] = 
		{ fall[row][colum][0]
		, fall[row][colum][1]
		, fall[row][colum][2]
		, fall[row][colum][3] };
		while (1)
		{
			if (_kbhit())
			{
				;
			}
			else
			{
				Drawfall(temp, floor);
				if (isDown(temp, floor))
				{
					Sleep(500);
					DrawBlock(temp, floor);
					floor++;
					
				}
				else
				{
					Fill(temp, floor);
					Full();
					break;
				}
			}
			
		}

	}
}
void Drawfall(unsigned short temp[],unsigned short floor)
{
	x = 0, y = floor;
	for (unsigned short j = 0; j < 4; j++)
	{
		conversion1(temp[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
void DrawBlock(unsigned short temp[], unsigned short floor)
{
	x = 0, y = floor;
	for (unsigned short j = 0; j < 4; j++)
	{
		conversion2(temp[j]);
		std::cout << std::endl;
		x = 0;
		y++;
	}
}
void conversion(unsigned unsigned short n) {
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
		if (n%2 == 1)
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
void conversion1(unsigned unsigned short n) {
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
			x++;
		}
	}
}
void conversion2(unsigned unsigned short n) {
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
		conversion(n / 2);
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
bool isDown(unsigned short temp[], unsigned short floor)
{
	for (unsigned short j = 0; j <= 3; j++)
		if ((temp[0] & data[floor + j+1]) + (temp[1] & data[floor + j + 1]) + (temp[2] & data[floor + j + 1]) + (temp[3] & data[floor + j + 1])) return true;
	return false;
}
void Fill(unsigned short temp[], unsigned short floor)
{
	for (unsigned short j = 0; j <= 3; j++)
		data[floor + j] = data[floor + j] | temp[floor];

}
bool Full()
{
	for (unsigned short j = 0; j <= 22; j++)
	{
		if (data[j] == 0xffff)
		{
			data[j] = 0x0000;
			return true;
		}
	}
	return false;
}

