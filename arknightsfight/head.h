#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <Windows.h>

    
#define width 1024
#define height 504

void load_play();//load necessary resource
void showstart();//Show selection scenarios
int choose_chapter();//select scene
void begin_chapter();//begin play
int progress();//the main part of combination
void Allscene();//can use in all scene
void show_chapter();
void role_update(int chapter);
void updateWithoutInput();
void updateWithInput();
void user();//load user information
void user_cre(char role[20]);//信息录入
void checkpass(char name[20], char password[20], int check);//注册
void scoreon(int winner);//update score
void bull(int judge_chapter);//bullet
int decide(int judge_chapter, int i); //判定子弹是否初始化
void priest();//music



/*                  总体流程
  一、数据初始化
  二、开始界面
		 选择地图
  三、换歌
  四、游戏界面
		 地图一
			 显示画面
			 计算变量
			 用户输入
			 判断游戏是否结束
		 地图二
			 ...
		 地图三
			 ...
  五、结束界面
		 结束界面一：人物一获胜
		 结束界面二：人物二获胜
		 结束界面三：平局，返回三，重置数据
  六、重置整个游戏：P键，返回一
*/