#pragma once
#include "head.h"
#pragma comment(lib,"Winmm.lib")

FILE* count = NULL;
FILE* boardc = NULL;
FILE* user_mes = NULL;
FILE* user_paswrd = NULL;

IMAGE img_start, img_bk, img_bkmin, img_bk2, img_bkmin2, img_bk3, img_bkmin3, img_gover1, img_gover2, img_menu;
IMAGE img_amier, img_amierzhe, img_yifulite, img_yifulitezhe;
IMAGE img_prop1, img_role11, img_prop2;
IMAGE img_sheep1, img_sheep2, img_sheep3, img_sheep4;
IMAGE img_bulletone[3], img_bullettwo[3];

int end_judgement = 1;				//end of the game
int chapter = 1;					//chapter choose ,origin 1
float G = 0.8, roleone_x = 200, roleone_y = 0, roletwo_x = 770, roletwo_y = 0;										// the position of the role
float roleone_speedx = 0, roleone_speedy = 0;			//the speed of role one
float roletwo_speedx = 0, roletwo_speedy = 0;			//the speed of role two
int rWidth = 60, rHigh = 90, rWidth2 = 60, rHigh2 = 80;	// the pixel of two role
int roleone_face = 0, roletwo_face = 1;					// which aspect does role face
int judge_chapter = 1;									//control when we restart
int roleone_jumptime, roletwo_jumptime;//jump counter
//int roleone_touch, roletwo_touch;//whether the role touch the ground
float roleone_jumpdec, roletwo_jumpdec;//jumping or not

			//chapter one
int landheightone = 374;				//the basic land height		
int platform_oney = 237;			//platformone height
int platform_oneleft = 63;			//platformone left
int platform_oneright = 326;		//platformone right
int platform_twoy = 231;			//platform two height 
int platform_twoleft = 643;			//platform two left
int platform_tworight = 945;		//platform two right
int platform_threeleft = 330;		//platform three left
int platform_threeright = 640;		//platform three right
int platform_threey = 87;			//platform three height
			//chapter two
int landheighttwo = 400;			//the basic land height	
int platformtwo_oney = 250;			//platformone height
int platformtwo_oneleft = 157;		//platformone left
int platformtwo_oneright = 393;		//platformone right
int platformtwo_twoy = 240;			//platform two height
int platformtwo_twoleft = 566;		//platform two left
int platformtwo_tworight = 866;		//platform two right
int platformtwo_threeleft = 64;		//platform three left
int platformtwo_threeright = 944;	//platform three right
int platformtwo_threey = 100;		//platform three height
			//chapter three还未确定的高度
int landheightthree = 374;				//the basic land height		
int platformthree_oney = 180;			//platformthree height
int platformthree_oneleft = 63;			//platformthree left
int platformthree_oneright = 366;		//platformthree right
int platformthree_twoy = 231;			//platform two height 
int platformthree_twoleft = 643;			//platform two left
int platformthree_tworight = 840;		//platform two right
int platformthree_threeleft = 400;		//platform three left
int platformthree_threeright = 970;		//platform three right
int platformthree_threey = 87;			//platform three height

			//bullet 
int bullHigh = 10;
int bullWidth = 20;
int bulltimeone = 0, bulltimetwo = 0;
int quantityone = 0, quantitytwo = 0;
int begin[4][3] = { 0 };//bullet begin
int harm11 = 10, harm21 = 10;
int voicetime1, voicetime2;//语音计时
int voice1_1, voice2_1;//语音随机数

int proptime1, proptime2;//道具出现计时
int propovertime1, propovertime2;//道具结束计时
int prop1, prop2;//道具状态，0：不出现  1：出现  2：作用
int prop1_x, prop1_y, prop2_x, prop2_y;//道具坐标 position and motion

int platform_touch1_1, platform_touch1_2, platform_touch1_3, platform_touch2_1, platform_touch2_2, platform_touch2_3;//whether the role is upon the plat

int blood1, blood2;					//role player blood
int bullet11_x[3], bullet11_y[3], bullet12_x[3], bullet12_y[3], bullet21_x[3], bullet21_y[3], bullet22_x[3], bullet22_y[3];//bullet position
