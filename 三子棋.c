#define  _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
int Menu() {
	printf("=============\n");
	printf("  1.开始游戏 \n");
	printf("  2.结束游戏 \n");
	printf("=============\n");
	printf(" 请输入你的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
char chess_board[MAX_ROW][MAX_COL];


void Init() {
	//1.创建并初始化棋盘
	//棋盘使用 x 表示玩家落子，o表示电脑落子，‘’表示未落子
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess_board[row][col] = ' ';
		}
	}
}
void Print() {
	//2.打印棋
	printf("\n ___ ___ ___\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1) {			printf("|___|___|___|\n");
		}		
	}
	printf("|___|___|___|\n");
	printf("\n");
}

void PlayerMove() {
	//3.玩家落子
	printf("玩家落子\n");
	while (1) {
		printf("请输入一组坐标(row,col):\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("你的输入非法!\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("你输入的坐标被占用!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
int IsFull() {
	//如果棋盘满了返回1，否则0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

//返回 x 表示玩家胜
//返回 o 表示电脑胜
//返回 q 表示和棋
//返回 '' 继续游戏
char CheckGameOver() {
	//4.检测游戏结束
	//检查所有的行
	for (int row = 0; row < MAX_ROW; row++) {
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]) {
			return chess_board[row][0];
		}
	}
	//检查所有的列
	for (int col = 0; col < MAX_COL; col++) {
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]) {
			return chess_board[0][col];
		}
	}
	//检查所有的对角线
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]) {
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]) {
		return chess_board[0][2];
	}
	if (IsFull()) {
		return 'q';
	}
	return ' ';

}
void ComputerMove() {
	//5.电脑落子
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
void Game() {
	char winner = ' ';
	//1.创建并初始化棋盘
	Init();
	while (1) {
		system("cls");
		//2.打印期盼
		Print();
		//3.玩家落子
		PlayerMove();
		//4.检测游戏结束
		CheckGameOver();
		winner = CheckGameOver();
		if (winner != ' ') {
			//分出胜负或和棋
			break;
		}
		//5.电脑落子
		ComputerMove();
		//6.检测游戏结束
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
	}
	system("cls");
	Print();
	if (winner == 'x') {
		printf("玩家胜利！\n");
	}
	else if (winner == 'o') {
		printf("电脑胜利！\n");
	}
	else if (winner == 'q') {
		printf("和棋！\n");
	}
	else {
		printf("出错了！\n");
	}
}



int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 2) {
			printf("goodbye\n");
			break;
		}
		else {
			printf("你的输入有误\n");
		}
	}
	system("pause");
	return 0;

}