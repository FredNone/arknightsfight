#include "head.h"
#include "define.h"

void user() {

	char roleone_name[20] = { 0 }, roletwo_name[20] = { 0 };
	count = fopen("C:\\picture\\score.txt", "w");
	boardc = fopen("C:\\picture\\board.txt", "w");

	//user_paswrd = fopen("C:\\picture\\user_password.txt", "w");

	printf("  Please press playerone name:");
	scanf("%s", roleone_name);
	fprintf(count, "%s\n", roleone_name);
	user_cre(roleone_name);

	printf("  Please press playertwo name:");
	scanf("%s", roletwo_name);
	fprintf(count, "%s\n", roletwo_name);
	user_cre(roletwo_name);

	printf("  Confirm! %s vs %s! Press 'Enter' to continue~ ", roleone_name, roletwo_name);
	fprintf(boardc, "%s_0_vs_%s_0_\n", roleone_name, roletwo_name);

	fclose(count);
	fclose(boardc);

	_getch();
}

void checkpass(char name[20], char password[20], int check)//注册
{
	user_paswrd = fopen("C:\\picture\\user_password.txt", "a+");
	char ch[40] = { 0 }; char ch2[40] = { 0 };
	strcat(ch, name); strcat(ch, password);
	//printf("%s", ch);
	while (check) {
		while ((fscanf(user_paswrd, "%s", ch2)) != EOF) {
			if (strcmp(ch, ch2) == 0) {
				printf("  Check, welcome~\n");
				fclose(user_paswrd);
				return;
			}
		}
		printf("%s? Not that, try again~:", password);
		strcpy(ch, ""); strcpy(ch2, "");
		scanf("%s", password);
		strcat(ch, name); strcat(ch, password);
		fclose(user_paswrd);
		user_paswrd = fopen("C:\\picture\\user_password.txt", "a+");
	}
	fprintf(user_paswrd, "%s%s\n", name, password);
	printf("  Created! This is for you.");
	fclose(user_paswrd);
}

void user_cre(char role[20]) {
	char ch[20] = { 0 };		//用于比对的存储字符串
	int check = 0;				//检测是否存在用户
	char password[20] = { 0 };
	user_mes = fopen("C:\\picture\\user_message.txt", "a+");

	while ((fscanf(user_mes, "%s", ch)) != EOF)//判断读到的是否为文件尾
	{
		char ch2[20] = { 0 };
		strcpy(ch2, ch);
		//printf("%s\n", ch2);
		if (strcmp(role, ch2) == 0) {
			printf("  Already created, password? (0~20):");
			scanf("%s", password);
			check = 1;
			checkpass(role, password, check);
			break;
		}; //处理输入
	}

	if (check == 0) {
		printf(" Not found, created! Please set your password: ");
		fprintf(user_mes, "%s\n", role);
		scanf("%s", password);
		checkpass(role, password, check);
	};
	fclose(user_mes);
}

void load_play() {
		initgraph(width, height);
		loadimage(&img_start, _T("C:\\picture\\land\\landstar1.jpg"), width, height);
		loadimage(&img_bk, _T("C:\\picture\\land\\land1.png"), width, height);
		loadimage(&img_bk2, _T("C:\\picture\\land\\land2.png"), width, height);
		loadimage(&img_bk3, _T("C:\\picture\\land\\land3.png"), width, height);
		loadimage(&img_bkmin, _T("C:\\picture\\land\\land1.png"), width/2, height/2);
		loadimage(&img_bkmin2, _T("C:\\picture\\land\\land2.png"), width/2, height/2);
		loadimage(&img_bkmin3, _T("C:\\picture\\land\\land3.png"), width/2, height/2);
		loadimage(&img_menu, _T("C:\\picture\\land\\menu.PNG"), width/3, height/3);
		loadimage(&img_amier, _T("C:\\picture\\role\\amier.png"), 900, 383);
		loadimage(&img_amierzhe, _T("C:\\picture\\role\\amierzhezhao.jpg"), 900, 383);
		loadimage(&img_yifulite, _T("C:\\picture\\role\\yifulite.png"), 1141, 529);
		loadimage(&img_yifulitezhe, _T("C:\\picture\\role\\yifulitezhezhao.jpg"), 1141, 529);
		
		loadimage(&img_sheep1, _T("C:\\picture\\role\\1.png"), 265, 281);//结束背景
		loadimage(&img_sheep2, _T("C:\\picture\\role\\2.png"), 265, 281);
		loadimage(&img_sheep3, _T("C:\\picture\\role\\3.png"), 265, 281);
		loadimage(&img_sheep4, _T("C:\\picture\\role\\4.png"), 265, 281);

		mciSendString("open C:\\picture\\music\\duosuoleisi.mp3 alias bkmusic1", NULL, 0, NULL);//background music
		mciSendString("play bkmusic1 repeat", NULL, 0, NULL);//circle play
		mciSendString("close bkmusic22", NULL, 0, NULL);
		mciSendString("close bkmusic32", NULL, 0, NULL);
		mciSendString("close bkmusic42", NULL, 0, NULL);
		mciSendString("close bkmusic5", NULL, 0, NULL);
		mciSendString("close over10086", NULL, 0, NULL);

		loadimage(&img_prop1, _T("C:\\picture\\role\\role1.png"), 50, 50);//道具1
		loadimage(&img_prop2, _T("C:\\picture\\role\\role2.png"), 50, 50);//道具2

		for (int i = 0; i < 3; i++)
		{
				loadimage(&img_bulletone[i], _T("C:\\picture\\bullet\\bullet1.png"), 40, 10);//子弹1	
				loadimage(&img_bullettwo[i], _T("C:\\picture\\bullet\\bullet2.png"), 40, 10);//子弹2
		}

}//load all the resource

void Init() {
		G = 0.3, roleone_x = 200, roleone_y = 0, roletwo_x = 770, roletwo_y = 0;
		roleone_speedx = 0, roleone_speedy = -10;
		roletwo_speedx = 0, roletwo_speedy = -10;
		blood1 = 100, blood2 = 100;
		roleone_jumpdec = 0;
		roletwo_jumpdec = 0;
		roleone_face = 0, roletwo_face = 1;
		voicetime1 = 300;
		voicetime2 = 0;
		proptime1 = 300;
		proptime2 = 0;
		propovertime1 = 200;
		propovertime2 = 200;
		for (int i = 0; i < 3; i++)
		{
				bullet11_x[i] = -50;
				bullet11_y[i] = -50;
				bullet12_x[i] = -50;
				bullet12_y[i] = -50;
				bullet21_x[i] = -50;
				bullet21_y[i] = -50;
				bullet22_x[i] = -50;
				bullet22_y[i] = -50;
		}
}//reset all the role's message

int progress()
{
		load_play();
		do {
				Init();
				while (!choose_chapter()) {
						showstart();
						Allscene();
				}
				begin_chapter();

				
		} while (end_judgement);
		return 0;
}//the progress of the game

void Allscene() {
		if ((GetAsyncKeyState(0x4f) & 0x8000)) //open menu
		while (1)
		{
				putimage(300, 200, &img_menu);
				if ((GetAsyncKeyState(0x49) & 0x8000))
						break;
				FlushBatchDraw(); 
		}
		/*if (GetAsyncKeyState(0x1B) & 0x8000)
			end_judgement = 0;*/
		if ((GetAsyncKeyState(0x50) & 0x8000))
				judge_chapter = 0;
		/*if ((GetAsyncKeyState(27) & 0x8000))
				end_judgement = 0;*/
}//the function which could be used in all scenes

void showstart()
{
		putimage(0, 0, &img_start);

		if (chapter == 1)
		{
				putimage(width/4, height/4, &img_bkmin);
		}
		if (chapter == 2)
		{
				putimage(width/4, height/4, &img_bkmin2);
		}
		if (chapter == 3)
		{
				putimage(width/4, height/4, &img_bkmin3);
		}
		setcolor(BLACK);
		rectangle(width / 4, height / 4, width * 3 / 4, height * 3 / 4);
		Sleep(100);
}

int choose_chapter() {
		char input;
		if (_kbhit()) {
				input = _getch();
				if (input == '1') {
						chapter = 1;
						//change music put here
						mciSendString("close bkmusic1", NULL, 0, NULL);
						mciSendString("close bkmusic31", NULL, 0, NULL);
						mciSendString("close bkmusic41", NULL, 0, NULL);
						mciSendString("open C:\\picture\\music\\洪炉示岁.mp3 alias bkmusic21", NULL, 0, NULL);//背景音乐2
						mciSendString("play bkmusic21 repeat", NULL, 0, NULL);
						roleone_x = 200;
						roleone_y = landheightone - rHigh - 105;
						roletwo_x = 774;
						roletwo_y = landheightone - rHigh2 - 105;
				}
				if (input == '2') {
						chapter = 2;
						//change music put here
						mciSendString("close bkmusic1", NULL, 0, NULL);
						mciSendString("close bkmusic21", NULL, 0, NULL);
						mciSendString("close bkmusic41", NULL, 0, NULL);
						mciSendString("open C:\\picture\\music\\milinghanjiang.mp3 alias bkmusic31", NULL, 0, NULL);//背景音乐3
						mciSendString("play bkmusic31 repeat", NULL, 0, NULL);
						roleone_x = 200;
						roleone_y = platform_threey - 105 - rHigh;
						roletwo_x = 774;
						roletwo_y = platform_threey - 105 - rHigh;
				}
				if (input == '3') {
						chapter = 3;
						//change music put here
						mciSendString("close bkmusic1", NULL, 0, NULL);
						mciSendString("close bkmusic21", NULL, 0, NULL);
						mciSendString("close bkmusic31", NULL, 0, NULL);
						mciSendString("open C:\\picture\\music\\qianfengxingdong.mp3 alias bkmusic41", NULL, 0, NULL);//背景音乐4
						mciSendString("play bkmusic41 repeat", NULL, 0, NULL);
						roleone_x = 200;
						roleone_y = landheightone - rHigh - 105;
						roletwo_x = 774;
						roletwo_y = landheightone - rHigh2 - 105;
				}
				if (input == 'f') {
						//change music put here
						judge_chapter = 1;
						return 1;
				}
		}
		return 0;
}

void begin_chapter()
{
		
		BeginBatchDraw();
		while (judge_chapter)
		{
				cleardevice();
				switch (chapter)
				{
				case 1:
						putimage(0, 0, &img_bk);
						break;
				case 2:
						putimage(0, 0, &img_bk2);
						break;
				case 3:
						putimage(0, 0, &img_bk3);
						break;
				}
				show_chapter();
				role_update(chapter);
				updateWithoutInput();
				updateWithInput();
				//priest();
				Sleep(5);
				FlushBatchDraw();
		}
		EndBatchDraw();
}

void show_chapter()
{
		if (roleone_face == 1)
		{
				putimage(roleone_x, roleone_y, rWidth, rHigh, &img_amierzhe, 25, 4, NOTSRCERASE);
				putimage(roleone_x, roleone_y, rWidth, rHigh, &img_amier, 25, 4, SRCINVERT);
		}
		if (roleone_face == 0)
		{
				putimage(roleone_x, roleone_y, rWidth, rHigh, &img_amierzhe, 15, 196, NOTSRCERASE);
				putimage(roleone_x, roleone_y, rWidth, rHigh, &img_amier, 15, 196, SRCINVERT);
		}
		if (roletwo_face == 1)
		{
				putimage(roletwo_x, roletwo_y, rWidth2, rHigh2, &img_yifulitezhe, 126, 0, NOTSRCERASE);
				putimage(roletwo_x, roletwo_y, rWidth2, rHigh2, &img_yifulite, 126, 0, SRCINVERT);
		}
		if (roletwo_face == 0)
		{
				putimage(roletwo_x, roletwo_y, rWidth2, rHigh2, &img_yifulitezhe, 0, 0, NOTSRCERASE);
				putimage(roletwo_x, roletwo_y, rWidth2, rHigh2, &img_yifulite, 0, 0, SRCINVERT);
		}
		setcolor(WHITE);
		char s1[30], s2[30];
		int i = 0;
		count = fopen("C:\\picture\\score.txt", "r+");
			fscanf(count, "%s", s1);
			fscanf(count, "%s", s2);
		fclose(count);

		outtextxy(10, 20, s1);
		outtextxy(10, 40, s2);

		TCHAR word_role1_blood[4];
		_stprintf_s(word_role1_blood, _T("%d"), blood1);
		outtextxy(140, 20, word_role1_blood);

		TCHAR word_role2_blood[4];
		_stprintf_s(word_role2_blood, _T("%d"), blood2);
		outtextxy(140, 40, word_role2_blood);

		TCHAR word[4];//监视变量
		_stprintf_s(word, _T("%d"), end_judgement);
		outtextxy(200, 20, word);

		char word_board[40] = {0};
		boardc = fopen("C:\\picture\\board.txt", "r+");
		fscanf(boardc, "%s", word_board);
		TCHAR board[40];
		_stprintf_s(board, _T("%s"), word_board);
		outtextxy(250, 20, board);
		fclose(boardc);
			
		for (int i = 0; i < 3; i++)
		{
				putimage(bullet11_x[i], bullet11_y[i], bullWidth, bullHigh, &img_bulletone[i], 0, 0);
				putimage(bullet12_x[i], bullet12_y[i], bullWidth, bullHigh, &img_bulletone[i], 20, 0);

				putimage(bullet21_x[i], bullet21_y[i], bullWidth, bullHigh, &img_bullettwo[i], 0, 0);
				putimage(bullet22_x[i], bullet22_y[i], bullWidth, bullHigh, &img_bullettwo[i], 20, 0);
		}


}

void role_update(int chapter)
{
	//if (roleone_touch != 1 ) {
	//		if(roleone_speedy <= 10)
	//				roleone_speedy += G;
	//		roleone_y += roleone_speedy;
	//}
	//if (roletwo_touch != 1) {
	//		if(roletwo_speedy <= 10)
	//				roletwo_speedy += G;
	//		roletwo_y += roletwo_speedy;
	//}
	int uplatform_oney = 0;			//platform height
	int uplatform_oneleft = 0;			//platform left
	int uplatform_oneright = 0;		//platform right
	int uplatform_twoy = 0;			//platform two height 
	int uplatform_twoleft = 0;			//platform two left
	int uplatform_tworight = 0;		//platform two right
	int uplatform_threeleft = 0;		//platform three left
	int uplatform_threeright = 0;		//platform three right
	int uplatform_threey = 0;			//platform three height
	switch (chapter) {

	case 1:
		uplatform_oney = platform_oney;			//platformone height
		uplatform_oneleft = platform_oneleft;			//platformone left
		uplatform_oneright = platform_oneright;		//platformone right
		uplatform_twoy = platform_twoy;			//platform two height 
		uplatform_twoleft = platform_twoleft;			//platform two left
		uplatform_tworight = platform_tworight;		//platform two right
		uplatform_threeleft = platform_threeleft;		//platform three left
		uplatform_threeright = platform_threeright;		//platform three right
		uplatform_threey = platform_threey;			//platform three height
		break;
	case 2:
		uplatform_oney = platformtwo_oney;			//platformone height
		uplatform_oneleft = platformtwo_oneleft;			//platformone left
		uplatform_oneright = platformtwo_oneright;		//platformone right
		uplatform_twoy = platformtwo_twoy;			//platform two height 
		uplatform_twoleft = platformtwo_twoleft;			//platform two left
		uplatform_tworight = platformtwo_tworight;		//platform two right
		uplatform_threeleft = platformtwo_threeleft;		//platform three left
		uplatform_threeright = platformtwo_threeright;		//platform three right
		uplatform_threey = platformtwo_threey;			//platform three height
		break;
	case 3:
		uplatform_oney = platformthree_oney;			//platformone height
		uplatform_oneleft = platformthree_oneleft;			//platformone left
		uplatform_oneright = platformthree_oneright;		//platformone right
		uplatform_twoy = platformthree_twoy;			//platform two height 
		uplatform_twoleft = platformthree_twoleft;			//platform two left
		uplatform_tworight = platformthree_tworight;		//platform two right
		uplatform_threeleft = platformthree_threeleft;		//platform three left
		uplatform_threeright = platformthree_threeright;		//platform three right
		uplatform_threey = platformthree_threey;			//platform three height
	default:
		break;

	}
	platform_touch1_1 = (roleone_x > uplatform_oneleft - rWidth) && (roleone_x < uplatform_oneright) && (roleone_y > uplatform_oney - rHigh) && (roleone_y < uplatform_oney - rHigh + 20);
	platform_touch1_2 = (roleone_x > uplatform_twoleft - rWidth) && (roleone_x < uplatform_tworight) && (roleone_y > uplatform_twoy - rHigh) && (roleone_y < uplatform_twoy - rHigh + 20);
	platform_touch1_3 = (roleone_x > uplatform_threeleft - rWidth) && (roleone_x < uplatform_threeright) && (roleone_y > uplatform_threey - rHigh) && (roleone_y < uplatform_threey - rHigh + 20);
	platform_touch2_1 = (roletwo_x > uplatform_oneleft - rWidth2) && (roletwo_x < uplatform_oneright) && (roletwo_y > uplatform_oney - rHigh2) && (roletwo_y < uplatform_oney - rHigh2 + 20);
	platform_touch2_2 = (roletwo_x > uplatform_twoleft - rWidth2) && (roletwo_x < uplatform_tworight) && (roletwo_y > uplatform_twoy - rHigh2) && (roletwo_y < uplatform_twoy - rHigh2 + 20);
	platform_touch2_3 = (roletwo_x > uplatform_threeleft - rWidth2) && (roletwo_x < uplatform_threeright) && (roletwo_y > uplatform_threey - rHigh2) && (roletwo_y < uplatform_threey - rHigh2 + 20);


	//platform_touch1_1 = (roleone_x > platformtwo_oneleft - rWidth) && (roleone_x < platformtwo_oneright) && (roleone_y > platformtwo_oney - rHigh) && (roleone_y < platformtwo_oney - rHigh + 22);
	//platform_touch1_2 = (roleone_x > platformtwo_twoleft - rWidth) && (roleone_x < platformtwo_tworight) && (roleone_y > platformtwo_twoy - rHigh) && (roleone_y < platformtwo_twoy - rHigh + 22);
	//platform_touch2_1 = (roletwo_x > platformtwo_oneleft - rWidth2) && (roletwo_x < platformtwo_oneright) && (roletwo_y > platformtwo_oney - rHigh2) && (roletwo_y < platformtwo_oney - rHigh2 + 22);
	//platform_touch2_2 = (roletwo_x > platformtwo_twoleft - rWidth2) && (roletwo_x < platformtwo_tworight) && (roletwo_y > platformtwo_twoy - rHigh2) && (roletwo_y < platformtwo_twoy - rHigh2 + 22);
	//platform_touch1_3 = (roleone_x > platformtwo_threeleft - rWidth) && (roleone_x < platformtwo_threeright) && (roleone_y > platformtwo_threey - rHigh) && (roleone_y < platformtwo_threey - rHigh + 22);
	//platform_touch2_3 = (roletwo_x > platformtwo_threeleft - rWidth2) && (roletwo_x < platformtwo_threeright) && (roletwo_y > platformtwo_threey - rHigh2) && (roletwo_y < platformtwo_threey - rHigh2 + 22);

	//if (platform_touch1_1 || platformtouch1_2 || platformtouch1_3)
	//	roleone_touch = 1;
	//if (platformtouch2_1 || platformtouch2_2 || platformtouch2_3)
	//	roletwo_touch = 1;
	//jump
	//roleone
	int landheight = 0;
	switch (chapter) {
	case 1:
		landheight = landheightone;
		break;
	case 2:
		landheight = landheighttwo;
		break;
	case 3:
		landheight = landheightthree;
		break;
	default:
		break;
	}
	if (roleone_jumpdec == 1)
	{
		roleone_jumptime++;
		roleone_y += roleone_speedy + G * roleone_jumptime;
	}
	if (roleone_jumpdec == 0 && roleone_y < landheight - rHigh && (platform_touch1_1 == 0 && platform_touch1_2 == 0 && platform_touch1_3 == 0))
	{
		roleone_jumptime++;
		roleone_y += G * roleone_jumptime;
	}
	if (roleone_y >= landheight - rHigh)
	{
		roleone_jumptime = 0;
		roleone_jumpdec = 0;
		roleone_y = landheight - rHigh;
	}
	if ((roleone_speedy + G * roleone_jumptime > 0) && platform_touch1_1)
	{
		roleone_jumptime = 0;
		roleone_jumpdec = 0;
		roleone_y = uplatform_oney - rHigh;
	}
	if ((roleone_speedy + G * roleone_jumptime > 0) && platform_touch1_2)
	{
		roleone_jumptime = 0;
		roleone_jumpdec = 0;
		roleone_y = uplatform_twoy - rHigh;
	}
	if ((roleone_speedy + G * roleone_jumptime > 0) && platform_touch1_3)
	{
		roleone_jumptime = 0;
		roleone_jumpdec = 0;
		roleone_y = uplatform_threey - rHigh;
	}

	//roletwo
	if (roletwo_jumpdec == 1)
	{
		roletwo_jumptime++;
		roletwo_y += roletwo_speedy + G * roletwo_jumptime;
	}
	if (roletwo_jumpdec == 0 && roletwo_y < landheight - rHigh2 && (platform_touch2_1 == 0 && platform_touch2_2 == 0 && platform_touch2_3 == 0))
	{
		roletwo_jumptime++;
		roletwo_y += G * roletwo_jumptime;
	}
	if (roletwo_y >= landheight - rHigh2)
	{
		roletwo_jumptime = 0;
		roletwo_jumpdec = 0;
		roletwo_y = landheight - rHigh2;
	}
	if ((roletwo_speedy + G * roletwo_jumptime > 0) && platform_touch2_1)
	{
		roletwo_jumptime = 0;
		roletwo_jumpdec = 0;
		roletwo_y = uplatform_oney - rHigh2;
	}
	if ((roletwo_speedy + G * roletwo_jumptime > 0) && platform_touch2_2)
	{
		roletwo_jumptime = 0;
		roletwo_jumpdec = 0;
		roletwo_y = uplatform_twoy - rHigh2;
	}
	if ((roletwo_speedy + G * roletwo_jumptime > 0) && platform_touch2_3)
	{
		roletwo_jumptime = 0;
		roletwo_jumpdec = 0;
		roletwo_y = uplatform_threey - rHigh2;
	}
	FlushBatchDraw();

}

void updateWithoutInput()
{
		Allscene();
		//惯性计算与接触计算
		//if (roleone_y >= landheightone - rHigh) {
		//		roleone_touch = 1;
		//}
		//if (roleone_y < landheightone - rHigh) {
		//		roleone_touch = 0;
		//}
		//if (roletwo_y >= landheightone - rHigh2) {
		//		roletwo_touch = 1;
		//}
		//if (roletwo_y < landheightone - rHigh2) {
		//		roletwo_touch = 0;
		//}
		if (roleone_speedx < 0) {
				roleone_x += roleone_speedx;
				roleone_speedx++;
		}
		if (roleone_speedx > 0) {
				roleone_x += roleone_speedx;
				roleone_speedx--;
		}
		if (roletwo_speedx < 0) {
				roletwo_x += roletwo_speedx;
				roletwo_speedx++;
		}
		if (roletwo_speedx > 0) {
				roletwo_x += roletwo_speedx;
				roletwo_speedx--;
		}
		
		

		//out of range cross the wall
		if (roleone_x < -200)
				roleone_x = width;
		if (roleone_x > width + 100)
				roleone_x = -rWidth;
		if (roletwo_x < -200)
				roletwo_x = width;
		if (roletwo_x > width + 100)
				roletwo_x = -rWidth2;

		int speedbull = 8;//子弹速度
		for (int i = 0; i < 3; i++)  //子弹移动
		{
			if (begin[0][i] == 1)
			{
				bullet12_x[i] += speedbull;
			}
			if (begin[1][i] == 1)
			{
				bullet11_x[i] -= speedbull;
			}
			if (begin[2][i] == 1)
			{
				bullet22_x[i] += speedbull;
			}
			if (begin[3][i] == 1)
			{
				bullet21_x[i] -= speedbull;
			}
			//子弹击中后初始化
			if (decide(0, i) == 1)
			{
				bullet11_x[i] = -50;
				bullet11_y[i] = -50;
				begin[0][i] == 0;
			}
			if (decide(1, i) == 1)
			{
				bullet12_x[i] = -50;
				bullet12_y[i] = -50;
				begin[1][i] == 0;
			}
			if (decide(2, i))
			{
				bullet21_x[i] = -50;
				bullet21_y[i] = -50;
				begin[2][i] == 0;
			}
			if (decide(3, i))
			{
				bullet22_x[i] = -50;
				bullet22_y[i] = -50;
				begin[3][i] == 0;
			}
		}
		voicetime1++;
		voicetime2++;
		if (voicetime1 == 600)
		{
			voice1_1 = rand() % 100;
			if (voice1_1 < 10)
			{
				mciSendString("close amiervoice1", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\阿米娅_作战中1.wav alias amiervoice1", NULL, 0, NULL);
				mciSendString("play amiervoice1", NULL, 0, NULL);
			}
			if (voice1_1 < 20 && voice1_1>9)
			{
				mciSendString("close amiervoice2", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\阿米娅_作战中2.wav alias amiervoice2", NULL, 0, NULL);
				mciSendString("play amiervoice2", NULL, 0, NULL);
			}
			if (voice1_1 < 30 && voice1_1>19)
			{
				mciSendString("close amiervoice3", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\阿米娅_作战中3.wav alias amiervoice3", NULL, 0, NULL);
				mciSendString("play amiervoice3", NULL, 0, NULL);
			}
			if (voice1_1 < 40 && voice1_1>29)
			{
				mciSendString("close amiervoice4", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\阿米娅_作战中4.wav alias amiervoice4", NULL, 0, NULL);
				mciSendString("play amiervoice4", NULL, 0, NULL);
			}
			voicetime1 = rand() % 300;
		}
		if (voicetime2 == 600)
		{
			voice2_1 = rand() % 100;
			if (voice2_1 < 10)
			{
				mciSendString("close yifulitevoice1", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\伊芙利特_作战中1.wav alias yifulitevoice1", NULL, 0, NULL);
				mciSendString("play yifulitevoice1", NULL, 0, NULL);
			}
			if (voice2_1 < 20 && voice2_1>9)
			{
				mciSendString("close yifulitevoice2", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\伊芙利特_作战中2.wav alias yifulitevoice2", NULL, 0, NULL);
				mciSendString("play yifulitevoice2", NULL, 0, NULL);
			}
			if (voice2_1 < 30 && voice2_1>19)
			{
				mciSendString("close yifulitevoice3", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\伊芙利特_作战中3.wav alias yifulitevoice3", NULL, 0, NULL);
				mciSendString("play yifulitevoice3", NULL, 0, NULL);
			}
			if (voice2_1 < 40 && voice2_1>29)
			{
				mciSendString("close yifulitevoice4", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\伊芙利特_作战中4.wav alias yifulitevoice4", NULL, 0, NULL);
				mciSendString("play yifulitevoice4", NULL, 0, NULL);
			}
			voicetime2 = rand() % 300;
		}
		proptime1++;
		proptime2++;
		if (proptime1 >= 600 && prop1 != 2)
		{
			prop1_x = rand() % (width - 50);
			prop1_y = rand() % (landheightone - 50);
			prop1 = 1;
			proptime1 = 0;
		}
		if (proptime2 >= 600 && prop2 != 2)
		{
			prop2_x = rand() % (width - 50);
			prop2_y = rand() % (landheightone - 50);
			prop2 = 1;
			proptime2 = 0;
		}
		if (prop1 == 2)
		{
			propovertime1--;
		}
		if (prop2 == 2)
		{
			propovertime2--;
		}
		if (propovertime1 == 0)
		{
			prop1 = 0;
			roleone_speedx = 4;
			roletwo_speedx = 4;
			propovertime1 = 400;
		}
		if (propovertime2 == 0)
		{
			prop2 = 0;
			harm11 = 5;
			harm21 = 5;
			propovertime2 == 400;
		}
		if ((blood1 <= 0) && (blood2 > 0))
		{
				end_judgement = 2;
				judge_chapter = 0;
				scoreon(end_judgement);
		}
		if ((blood2 <= 0) && (blood1 > 0))
		{
				end_judgement = 1;
				judge_chapter = 0;
				scoreon(end_judgement);
		}
		if ((blood1 <= 0) && (blood2 <= 0))
		{
				end_judgement = 3;
				blood1 = 1;
				blood2 = 1;
				roleone_x = 200;
				roleone_y = landheightone - rHigh - 200;
				roletwo_x = 774;
				roletwo_y = landheightone - rHigh2 - 200;
		}

}

void updateWithInput()
{
		//role one
		if ((GetAsyncKeyState(0x41) & 0x8000)) // 位置左移
		{
				roleone_face = 1;
				if (roleone_speedx > -10) {
						roleone_speedx--;
				}
				roleone_x += roleone_speedx;
				//Sleep(5);
		}
		if ((GetAsyncKeyState(0x44) & 0x8000))// 位置右移
		{
				roleone_face = 0;
				if (roleone_speedx < 10) {
						roleone_speedx++;
				}
				roleone_x += roleone_speedx;
				//Sleep(5);
		}
		if ((GetAsyncKeyState(0x57) & 0x8000)) // 位置上移（跳跃）
		{
				if (roleone_jumpdec == 0 && roleone_y >= landheightone - rHigh)
						roleone_jumpdec = 1;
				if (roleone_jumpdec == 0 && (platform_touch1_1 || platform_touch1_2 || platform_touch1_3))
						roleone_jumpdec = 1;
				
		}                             
		if ((GetAsyncKeyState(0x53) & 0x8000)) // 位置下移
		{
				roleone_y += 21;
		}
		if ((GetAsyncKeyState(0x4a) & 0x8000)) // 人物1发射子弹1（j）
		{
				bulltimeone++;
				if (bulltimeone == 5)
				{
				bull(1);
				mciSendString("close boom", NULL, 0, NULL);
				mciSendString("open C:\\picture\\music\\boom.mp3 alias boom", NULL, 0, NULL);
				mciSendString("play boom", NULL, 0, NULL);
				bulltimeone = 0;
				}
		}
		if ((GetAsyncKeyState(0x51) & 0x8000))
		{
			if(roleone_face == 1)
					roleone_x -= 25;
			else
					roleone_x += 25;
		}

		//role two
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) // 位置左移
		{
				roletwo_face = 1;
				if (roletwo_speedx > -10) {
						roletwo_speedx--;
				}
				roletwo_x += roletwo_speedx;
		}
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) // 位置右移
		{
				roletwo_face = 0;
				if (roletwo_speedx < 10) {
						roletwo_speedx++;
				}
				roletwo_x += roletwo_speedx;
		}
		if ((GetAsyncKeyState(VK_UP) & 0x8000)) // 位置上移（跳跃）
		{
				if (roletwo_jumpdec == 0 && roletwo_y >= landheightone - rHigh2)
						roletwo_jumpdec = 1;
				if (roletwo_jumpdec == 0 && (platform_touch2_1 || platform_touch2_2 || platform_touch2_3))
						roletwo_jumpdec = 1;
		}
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) // 位置下移
		{
				roletwo_y += 21;
		}
		if ((GetAsyncKeyState(VK_NUMPAD1) & 0x8000)) // 人物2发射子弹1（1）
		{
				bulltimetwo++;
				if (bulltimetwo == 5)
				{
						bull(2);
						mciSendString("close boom", NULL, 0, NULL);
						mciSendString("open C:\\picture\\music\\boom.mp3 alias boom", NULL, 0, NULL);
						mciSendString("play boom", NULL, 0, NULL);
						bulltimetwo = 0;
				}
		}
		if ((GetAsyncKeyState(VK_NUMPAD2) & 0x8000))
		{
			if (roletwo_face == 1)
				roletwo_x -= 25;
			else
				roletwo_x += 25;
		}
}

void scoreon(int winner) {
		char scoreup[50] = { 0 };
		boardc = fopen("C:\\picture\\board.txt", "r");
		fscanf(boardc, "%s", scoreup);
		int set = 0;
		for (int num = 0; scoreup[num] != '\0'; num++) {
				if(scoreup[num] >= '0' && scoreup[num] <= '9')
						set++;
				if (set == winner) {
					scoreup[num] += 1;
					break;
				}		
		}
		boardc = fopen("C:\\picture\\board.txt", "w+");
		fprintf(boardc, "%s", scoreup);
		fclose(boardc);
}

void bull(int judge_chapter)//子弹显示位置
{
	if (quantityone >= 3)
		quantityone = 0;
	if (quantitytwo >= 3)
		quantitytwo = 0;
	switch (judge_chapter)
	{
	case 1://角色1发射子弹
		if (roleone_face == 0)
		{
			begin[0][quantityone] = 1;
			bullet12_x[quantityone] = roleone_x + rWidth;
			bullet12_y[quantityone] = roleone_y + 35;
			quantityone++;
		}
		if (roleone_face == 1)
		{
			begin[1][quantityone] = 1;
			bullet11_x[quantityone] = roleone_x - bullWidth;
			bullet11_y[quantityone] = roleone_y + 35;
			quantityone++;
		}
		break;
	case 2://角色2发射子弹
		if (roletwo_face == 0)
		{
			begin[2][quantitytwo] = 1;
			bullet22_x[quantitytwo] = roletwo_x + rWidth2;
			bullet22_y[quantitytwo] = roletwo_y + 35;
			quantitytwo++;
		}
		if (roletwo_face == 1)
		{
			begin[3][quantitytwo] = 1;
			bullet21_x[quantitytwo] = roletwo_x - bullWidth;
			bullet21_y[quantitytwo] = roletwo_y + 35;
			quantitytwo++;
		}
		break;
	}
}

int decide(int judge_chapter, int i) //判定子弹是否初始化
{
	int result = 0;
	switch (judge_chapter)
	{
	case 0:
		if (bullet11_x[i]<0 || bullet11_x[i]>width)
			result = 1;
		if ((bullet11_x[i]<(roletwo_x + rWidth2) && bullet11_x[i]>(roletwo_x - bullWidth)) && (bullet11_y[i]<(roletwo_y + rHigh2) && bullet11_y[i]>(roletwo_y - bullHigh)))
		{
			mciSendString("close click", NULL, 0, NULL);
			mciSendString("open C:\\picture\\music\\click.wav alias click", NULL, 0, NULL);
			mciSendString("play click", NULL, 0, NULL);
			blood2 -= harm11;
			result = 1;
		}
		/*if ((bullet11_x[i] > platform_1x1 - bullWidth) && (bullet11_x[i] < platform_1x2) && (bullet11_y[i] > platform_1y - bullHigh) && (bullet11_y[i] < platform_1y  + 7))
			result = 1;
		if ((bullet11_x[i] > platform_2x1 - bullWidth) && (bullet11_x[i] < platform_2x2) && (bullet11_y[i] > platform_2y - bullHigh) && (bullet11_y[i] < platform_2y  + 7))
			result = 1;
		if ((bullet11_x[i] > platform_3x1 - bullWidth) && (bullet11_x[i] < platform_3x2) && (bullet11_y[i] > platform_3y - bullHigh) && (bullet11_y[i] < platform_3y  + 7))
			result = 1;*/

		break;
	case 1:
		if (bullet12_x[i]<0 || bullet12_x[i]>width)
			result = 1;
		if ((bullet12_x[i]<(roletwo_x + rWidth2 + bullWidth) && bullet12_x[i]>roletwo_x) && (bullet12_y[i]<(roletwo_y + rHigh2) && bullet12_y[i]>(roletwo_y - bullHigh)))
		{
			mciSendString("close click", NULL, 0, NULL);
			mciSendString("open C:\\picture\\music\\click.wav alias click", NULL, 0, NULL);
			mciSendString("play click", NULL, 0, NULL);
			blood2 -= harm11;
			result = 1;
		}
		/*if ((bullet12_x[i] > platform_1x1 - bullWidth) && (bullet12_x[i] < platform_1x2) && (bullet12_y[i] > platform_1y - bullHigh) && (bullet12_y[i] < platform_1y  + 7))
			result = 1;
		if ((bullet12_x[i] > platform_2x1 - bullWidth) && (bullet12_x[i] < platform_2x2) && (bullet12_y[i] > platform_2y - bullHigh) && (bullet12_y[i] < platform_2y  + 7))
			result = 1;
		if ((bullet12_x[i] > platform_3x1 - bullWidth) && (bullet12_x[i] < platform_3x2) && (bullet12_y[i] > platform_3y - bullHigh) && (bullet12_y[i] < platform_3y  + 7))
			result = 1;*/

		break;
	case 2:
		if (bullet21_x[i]<0 || bullet21_x[i]>width)
			result = 1;
		if ((bullet21_x[i]<(roleone_x + rWidth) && bullet21_x[i]>(roleone_x - bullWidth)) && (bullet21_y[i]<(roleone_y + rHigh) && bullet21_y[i]>(roleone_y - bullHigh)))
		{
			mciSendString("close click", NULL, 0, NULL);
			mciSendString("open C:\\picture\\music\\click.wav alias click", NULL, 0, NULL);
			mciSendString("play click", NULL, 0, NULL);
			blood1 -= harm21;
			result = 1;
		}
		/*if ((bullet21_x[i] > platform_1x1 - bullWidth) && (bullet21_x[i] < platform_1x2) && (bullet21_y[i] > platform_1y - bullHigh) && (bullet21_y[i] < platform_1y  + 7))
			result = 1;
		if ((bullet21_x[i] > platform_2x1 - bullWidth) && (bullet21_x[i] < platform_2x2) && (bullet21_y[i] > platform_2y - bullHigh) && (bullet21_y[i] < platform_2y  + 7))
			result = 1;
		if ((bullet21_x[i] > platform_3x1 - bullWidth) && (bullet21_x[i] < platform_3x2) && (bullet21_y[i] > platform_3y - bullHigh) && (bullet21_y[i] < platform_3y  + 7))
			result = 1;*/

		break;
	case 3:
		if (bullet22_x[i]<0 || bullet22_x[i]>width)
			result = 1;
		if ((bullet22_x[i]<(roleone_x + rWidth + bullWidth) && bullet22_x[i]>roleone_x) && (bullet22_y[i]<(roleone_y + rHigh) && bullet22_y[i]>(roleone_y - bullHigh)))
		{
			mciSendString("close click", NULL, 0, NULL);
			mciSendString("open C:\\picture\\music\\click.wav alias click", NULL, 0, NULL);
			mciSendString("play click", NULL, 0, NULL);
			blood1 -= harm21;
			result = 1;
		}
		/*if ((bullet22_x[i] > platform_1x1 - bullWidth) && (bullet22_x[i] < platform_1x2) && (bullet22_y[i] > platform_1y - bullHigh) && (bullet22_y[i] < platform_1y  + 7))
			result = 1;
		if ((bullet22_x[i] > platform_2x1 - bullWidth) && (bullet22_x[i] < platform_2x2) && (bullet22_y[i] > platform_2y - bullHigh) && (bullet22_y[i] < platform_2y  + 7))
			result = 1;
		if ((bullet22_x[i] > platform_3x1 - bullWidth) && (bullet22_x[i] < platform_3x2) && (bullet22_y[i] > platform_3y - bullHigh) && (bullet22_y[i] < platform_3y  + 7))
			result = 1;*/

		break;
	}
	return result;
}



//排行榜
//esc
