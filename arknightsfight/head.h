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
void user_cre(char role[20]);//��Ϣ¼��
void checkpass(char name[20], char password[20], int check);//ע��
void scoreon(int winner);//update score
void bull(int judge_chapter);//bullet
int decide(int judge_chapter, int i); //�ж��ӵ��Ƿ��ʼ��
void priest();//music



/*                  ��������
  һ�����ݳ�ʼ��
  ������ʼ����
		 ѡ���ͼ
  ��������
  �ġ���Ϸ����
		 ��ͼһ
			 ��ʾ����
			 �������
			 �û�����
			 �ж���Ϸ�Ƿ����
		 ��ͼ��
			 ...
		 ��ͼ��
			 ...
  �塢��������
		 ��������һ������һ��ʤ
		 ������������������ʤ
		 ������������ƽ�֣�����������������
  ��������������Ϸ��P��������һ
*/