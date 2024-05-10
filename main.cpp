#include"HeadFile.h"
#include"Function.h"
int main()
{
	init();
	srand((unsigned int)time(NULL));
		while (1)
		{
			int t = 0;
			ushort_16 shape = rand() % 7, form = rand() % 4, floor = 0;
			ushort_16 temp[4] =
			{ fall[shape][form][0]
			, fall[shape][form][1]
			, fall[shape][form][2]
			, fall[shape][form][3] };
			while (1)
			{
				Drawfall(temp, floor);
				if (t == 0)
				{
					t = 15000;
				}
				while (--t)
				{
					if (kbhit() != 0)
						break;
				}
				if (t != 0)
				{
					char ch = getch();
					switch (ch)
					{
					case DOWN:
					{
						if (!isDown(temp, floor))
						{
							DrawBlock(temp, floor);
							floor++;
						}
						break;
					}
					case LEFT:
					{
						auto isLeft = [&](ushort_16 temp[], ushort_16 floor)
							{
								for (ushort_16 j = 0; j <= 3; j++)
									if (((temp[j]<<1) & data[floor + j]))
										return true;
								return false;
							};
						if (!isLeft(temp, floor))
						{
							DrawBlock(temp, floor);
							for (int j = 0; j < 4; j++)
								temp[j] = temp[j] << 1;
						}
						break;
					}
					case RIGHT:
					{
						auto isRight = [&](ushort_16 temp[], ushort_16 floor)
							{
								for (ushort_16 j = 0; j <= 3; j++)
									if (((temp[j] >> 1) & data[floor + j]))
										return true;
								return false;
							};
							if (!isRight(temp, floor))
							{
								DrawBlock(temp, floor);
								for (int j = 0; j < 4; j++)
									temp[j] = temp[j] >> 1;
							}
						break;
					}
					case SPACE:
					{
						if (!isDown(temp, floor))
						{
							DrawBlock(temp, floor);
							form = (form + 1) % 4;
							for (int j = 0; j < 4; j++)
								temp[j] = fall[shape][form][j];
						}
						break;
					}
					case ESC:
					{
						system("cls");
						exit(0);
					}
					case 's':
					case 'S':
						system("pause>nul");
					case 'r':
					case 'R':
						system("cls");
						main();
					}
				}
				else
				{
					if (!isDown(temp, floor))
					{
						DrawBlock(temp, floor);
						floor++;

					}
					else
					{
						Fill(temp, floor);
						if (Full())
							Move();
						break;
					}
				}

			}

		}
}
