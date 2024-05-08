#include"HeadFile.h"
#include"Function.h"
int main()
{
	init();
	while (1)
	{
		int row = rand() % 7, colum = rand() % 4, floor = 0;
		int temp[4] = { fall[row][colum][0]
		, fall[row][colum][1]
		, fall[row][colum][2]
		, fall[row][colum][3]};
		if (_kbhit())
		{
			;
		}
		else
		{
			Drawfall(temp,floor);
			if (Check_Lowest(temp,floor))
				DOWN(&floor);
			else
				Fill(temp, floor);
			Full();
		}
		Sleep(5000);
	}
}