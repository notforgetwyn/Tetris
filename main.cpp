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
			ushort_16 next_shape = rand() % 7, next_form = rand() % 4,next_floor=0;
			ushort_16 fall[4] =
			{ ball[shape][form][0]
			, ball[shape][form][1]
			, ball[shape][form][2]
			, ball[shape][form][3] };
			color(shape);
			JudgeEnd(fall, floor);
			while (1)
			{
				Drawfall(fall, floor);
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
					auto isRight = [&](ushort_16 fall[], ushort_16 floor)
						{
							for (ushort_16 j = 0; j <= 3; j++)
								if (((fall[j] >> 1) & data[floor + j]))
									return true;
							return false;
						};
					auto isLeft = [&](ushort_16 fall[], ushort_16 floor)
						{
							for (ushort_16 j = 0; j <= 3; j++)
								if (((fall[j] << 1) & data[floor + j]))
									return true;
							return false;
						};
					char ch = getch();
					switch (ch)
					{
					case DOWN:
					{
						if (!isDown(fall, floor))
						{
							DrawBlock(fall, floor);
							floor++;
						}
						break;
					}
					case LEFT:
					{
						if (!isLeft(fall, floor))
						{
							DrawBlock(fall, floor);
							for (int j = 0; j < 4; j++)
								fall[j] = fall[j] << 1;
						}
						break;
					}
					case RIGHT:
					{
							if (!isRight(fall, floor))
							{
								DrawBlock(fall, floor);
								for (int j = 0; j < 4; j++)
									fall[j] = fall[j] >> 1;
							}
						break;
					}
					case SPACE:
					{
						if (!isDown(fall, floor))
						{
							DrawBlock(fall, floor);
								ushort_16 i = 0, j = 0;
							while (1)
							{
								auto ConverRight = [&]()
									{
										if ((fall[0]== (ball[shape][form][0] >> i)) &&
											(fall[1] == (ball[shape][form][1] >> i)) &&
											(fall[2] == (ball[shape][form][2] >> i)) &&
											(fall[3] == (ball[shape][form][3] >> i)))
												return true;
										return false;
									};
								auto ConverLeft = [&]()
									{
										if ((fall[0] == (ball[shape][form][0] << j)) &&
											(fall[1] == (ball[shape][form][1] << j)) &&
											(fall[2] == (ball[shape][form][2] << j)) &&
											(fall[3] == (ball[shape][form][3] << j)))
												return true;
										return false;
									};
								if (ConverRight())
								{
									Offset_Right = i;
									break;
								}
								if (ConverLeft())
								{
									Offset_Left = j;
									break;
								}
								i++;
								j++;
							}
							form = (form + 1) % 4;
							for (int j = 0; j < 4; j++)
								fall[j] = ball[shape][form][j];
							for (int i = 0; i < Offset_Left; i++)
							{
								if(!isLeft(fall, floor))
									for (int j = 0; j < 4; j++)
										fall[j] = fall[j] << 1;
							}
							for (int k = 0; k < Offset_Right; k++)
							{
								if (!isLeft(fall, floor))
									for (int j = 0; j < 4; j++)
										fall[j] = fall[j] << 1;
							}
							Offset_Right = 0, Offset_Left = 0;
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
						break;
					case 'r':
					case 'R':
						system("cls");
						main();
					}
				}
				else
				{
					if (!isDown(fall, floor))
					{
						DrawBlock(fall, floor);
						floor++;

					}
					else
					{
						Fill(fall, floor);
						if (Full())
						{
							Move();
							grade = grade + 10;
							CursorJump(20, 22);
							printf("当前分数：%d", grade);
						}
						break;
					}
				}

			}

		}
}
