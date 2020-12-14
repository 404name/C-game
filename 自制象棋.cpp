#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
//字符 L 下棋 

int x,y,i,j,p,q,num = 1,round,place_x1 = 0,place_y1 = 0,place_x2 = 0,place_y2 = 0;                                                       //基本参数 
int check_x,check_y,check_turn;
char ch, turn = 'O',turn1 = 'N',temp,temp1;    	
				//"||===================================||",
char map[1000][1000]= {  "[[===================================]]",
                             "[|①将         【|象棋|】        ②帥|]",
                             "[====================================]]",
                             "[[-----------------------------------]]",
                             "[[ 車—馬—相—仕—帥—仕—相—馬—車]]", 
                             "[[ |   |   |   | \\ | / |   |   |   | ]]",
                             "[[ +-—+-—+-—+-—+-—+-—+-—+-—+-]]",                            
                             "[[ |   |   |   | / | \\ |   |   |   | ]]",                           
                             "[[ +-—砲—+-—+-—+-—+-—+-—砲—+-]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ 卒—+-—卒—+-—卒—+-—卒—+-—卒]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ +-—+-—+-—+-—+-—+-—+-—+-—+-]]",
                             "[[===================================]]",
                             "[[ +-—+-—+-—+-—+-—+-—+-—+-—+-]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ 兵—+-—兵—+-—兵—+-—兵—+-—兵]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ +-—炮—+-—+-—+-—+-—+-—炮—+-]]",
                             "[[ |   |   |   | \\ | / |   |   |   | ]]",
                             "[[ +-—+-—+-—+-—+-—+-—+-—+-—+-]]",
                             "[[ |   |   |   | / | \\ |   |   |   | ]]",
                             "[[ 车—马—象—士—将—士—象—马—车]]",
                             "[[-----------------------------------]]",
                             "[=====================================]"};
char check_1[9][3] ={"车","马","象","士","将","炮","兵","+-"};  //取棋子时只判断前8合法， 
char check_2[9][3] ={"車","馬","相","仕","帥","砲","卒","+-"};	//下棋子时判断多一个空位合法 
char check[3];	
		
int check_main1(char* temp,char* temp1,char* turn,char* turn1,int *num)         //判断 将方  下棋是否合法 
{
	check[0] = *temp;
	check[1] = *temp1;
	check[2] = '\0';
	char a,b;								
	for ( i = 0; i < 8; i++)        
	{
		if( strcmp(check_2[i],check) == 0)
		{	
			*temp = *turn;
			*temp1 = *turn1;
			*turn = 'O';
			*turn1 = 'N'; 
			if( i < 7){
				printf("帅方的%s被吃\n",check_2[i]);
				Sleep(500);
			}	
			*num = *num + 1;
			for( i = 4; i <= 8; i = i + 2)   //判断帥是否死亡 
			{
				for(j = 15; j <= 23; j= j+ 4)
				{
					if(map[i][j] == check_2[4][0]  && map[i][j+1] == check_2[4][1])
					{
						place_x2 = i;
						place_y2 = j;
						break;
					}
				}
				if( j <= 23)
					break;
		    }
			if( i == 10)
			{
				printf("帥 被将军  将方获得胜利\n");
				Sleep(10000); 
				return 0; 
			}
			for( i = 18; i <= 22; i = i + 2)   //判断将是否死亡 
			{
				for(j = 15; j <= 23; j= j+ 4)
				{
					if(map[i][j] == check_1[4][0]  && map[i][j+1] == check_1[4][1])
					{
						place_x1 = i;
						place_y1 = j;
						break;
					}	
				}
				if( j <= 23)
					break;
			}
			if( i == 24)
				{
					printf("将方 被将军  帥方获得胜利\n");
					Sleep(10000); 
					return 0; 
				}
			if( place_y1 == place_y2)
			{
				for( i = place_x2 + 2; i <= place_x1 - 2; i = i +2)
				{
					if(map[i][place_y1] != '+')
					break;	
				}
				if( i == place_x1)
				{
					if(round == 1)
						printf(" 将方对将   帥方胜利");
					else if( round == 2)
						printf(" 帥方对将   将方胜利");
					Sleep(10000); 
					return 0;
				}   	
			}
			break; 
		}	
	}
	if( i == 8)
	{
		printf("不合法的走法\n");
		Sleep(500);
	} 	 
} 
int check_main2(char* temp,char* temp1,char* turn,char* turn1,int *num) //判断  帥方下棋是否合法 
{   
	check[0] = *temp;
	check[1] = *temp1;
	check[2] = '\0';
	char a,b;
	for ( i = 0; i < 8; i++)        
	{
		if( strcmp(check_1[i],check) == 0)
		{	
			*temp = *turn;
			*temp1 = *turn1;
			*turn = 'O';
			*turn1 = 'N'; 
			if( i < 7)
			{
				printf("将方的%s被吃",check_1[i]);
				Sleep(500);
			}	
		    *num = *num + 1; 
			for( i = 4; i <= 8; i = i + 2)   //判断帥是否死亡 
		    {
				for(j = 15; j <= 23; j= j+ 4)
				{
					if(map[i][j] == check_2[4][0]  && map[i][j+1] == check_2[4][1])
					{
						place_x2 = i;
						place_y2 = j;
						break;
					}
				}
				if( j <= 23)
					break;
			}
			if( i == 10)
			{
				printf("帥 被将军  将方获得胜利\n");
				Sleep(10000); 
				return 0; 
			}
			for( i = 18; i <= 22; i = i + 2)   //判断将是否死亡 
			{
				for(j = 15; j <= 23; j= j+ 4)
				{
					if(map[i][j] == check_1[4][0]  && map[i][j+1] == check_1[4][1])
					{
						place_x1 = i;
						place_y1 = j;
						break;
					}	
				}
				if( j <= 23)
					break;
			}
			if( i == 24)
				{
					printf("将方 被将军  帥方获得胜利\n");
					Sleep(10000); 
					return 0; 
				}
			if( place_y1 == place_y2)
			{
				for( i = place_x2 + 2; i <= place_x1 - 2; i = i +2)
				{
					if(map[i][place_y1] != '+')
						break;	
				}
				if( i == place_x1)
				{
					if(round == 1)
						printf(" 将方对将   帥方胜利");
					else if( round == 2)
						printf(" 帥方对将   将方胜利");
					Sleep(10000); 
					return 0;
				}   	
			} 
			break; 
		}	
	}
	if( i == 8)
	{
	printf("不合法的走法\n");
	Sleep(500);
	} 	 
}

int main()
{		
	printf("wasd移动L取子下棋");
	getchar();	
	system("cls"); 
	system("mode con cols=40 lines=30");      //迷你界面 
    system("color 30"); 				
	for ( i = 0; i < 27; i++)
	puts(map[i]);
	x = 6,y = 19;
    temp = map[x][y];
	temp1 = map[x][y+1];     
    while(num)            
    {    if(num % 2 == 1 &&num / 2 % 2 == 0){
    	printf("现在是'将'的回合\n");
    	round = 1;
	}	
	else if( num %2 == 1){
		printf("现在轮到'帥'的回合了\n");
		round = 2;  	
	}               
    ch = getch();
    if ( ch == 's')         //下移 
    {
        if( map[x+1][y]!= '-')
        {
            map[x][y] =temp;
            map[x][y+1] = temp1;
            x = x + 2;
            temp = map[x][y];
            temp1 = map[x][y+1];
            map[x][y] = turn;
            map[x][y+1] = turn1;
        }
    }
    else if ( ch == 'a')    //左移 
    {
        if(map[x][y-1]!=' ')
        {
            map[x][y] =temp;
            map[x][y+1] = temp1;
            y = y - 4;
            temp = map[x][y];
            temp1 = map[x][y+1];
            map[x][y] = turn;
            map[x][y+1] = turn1;
        }
    }
    else if ( ch == 'w')    //上移 
    {
        if(  map[x-1][y]!= '-')
        {
            map[x][y] =temp;
            map[x][y+1] = temp1;
            x = x - 2;
            temp = map[x][y];
            temp1 = map[x][y+1];
            map[x][y] = turn;
            map[x][y+1] = turn1;
        }
    }
    else if ( ch == 'd')    //右移 
    {
        if(map[x][y+2]!=']')
        {
            map[x][y] =temp;
            map[x][y+1] = temp1;
            y = y + 4;
            temp = map[x][y];
            temp1 = map[x][y+1];
            map[x][y] = turn;
            map[x][y+1] = turn1;
        }
    }
        else if( ch == 'l' || ch =='L') 
        {
        	if(num % 2 == 1 && temp != '+' && temp1 != '-')   //取 
        	{
				check[0] = temp;
				check[1] = temp1;
				check[2] = '\0';
				if( round == 1)
				{
					for (  i = 0; i < 7; i++)           //将方 
					{
						if( strcmp(check_1[i],check) == 0)
						{
							turn = temp;
        					turn1 = temp1;
        					temp = '+';
        					temp1 = '-';  
							check_x = x;
							check_y = y;
							check_turn = 10 + i;  
							num++;    
							break; 
						}	
					}
					if( i == 7){
						printf("这不是你的棋子\n");
						Sleep(500);
					}
				 }
				else if( round == 2)
				{
					for ( i = 0; i < 7; i++)           //将方 
					{
						if( strcmp(check_2[i],check) == 0)
						{
							turn = temp;
        					turn1 = temp1;
        					temp = '+';
        					temp1 = '-';
							check_x = x;
							check_y = y;
							check_turn = 20 + i;   
							num++;    
							break; 
						}	
					}
					if( i == 7){
						printf("这不是你的棋子\n");
						Sleep(500);
					}
					
				} 
			}
			else if( num % 2 == 0)                 //放 
			{             
		/*char check_1[8][3] ={"车","马","象","士","将","炮","卒","+-"}; 
		char check_2[8][3] ={"俥","馬","相","仕","帥","軳","兵","+-"};*/ 
			/*
		中界 楚河上下坐标  12    15 
		*/     
		//  往下2  往又4 
				if( check_turn < 20)          //将方 
				{
					if( check_turn == 10) 				//车    的走法规范     完成 
					{
						if((x == check_x && y == check_y))
						{		
							
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if(  y == check_y  )
						{
							if( x > check_x)
							{
								for(j = check_x + 2; j < x;j = j + 2)
								{
									if(map[j][y] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j >= x)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
								} 
							if( x < check_x)
							{
								for(j = check_x - 2; j > x;j = j - 2)
								{
									if(map[j][y] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j <= x)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
								} 	
						}
							
						else if(  x == check_x  )
						{
							if( y > check_y)
							{
								for(j = check_y + 4; j < y;j = j + 4)
								{
									if(map[x][j] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j >= y)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
								} 
							if( y < check_y)
							{
								for(j = check_y - 4; j > y;j = j - 4)
								{
									if(map[x][j] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j <= y)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
								} 	
						}	
						else
						{
							printf("不合法的下法\n");
							Sleep(500);
						}
					}
					if( check_turn == 11) 				//马    的走法规范   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
							else if( (abs( x - check_x) == 2&& abs( y - check_y) == 8)&& map[check_x][(y+check_y)/2] =='+')
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else if( (abs( x - check_x) == 4&& abs( y - check_y) == 4)&& map[(x + check_x)/2][check_y] == '+' )
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}	
						if( check_turn == 12) 				//相    的走法规范     完成 
					{
						if( x >= 15 &&(abs(y - check_y) == 8 && abs(x - check_x) == 4))
						{
							if((x == check_x && y == check_y))
							{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
							}
							else if((x == 22 && (y == 11 || y == 27))||(x == 18 && ( y == 3 || y == 19 || y == 35)) ||(x == 14 && (y == 11|| y ==27)))
							{		
								if( map[(x+check_x)/2][(y+check_y)/2] == '+')
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else
								{
									printf("棋子卡住，不可执行");
									Sleep(500); 
								} 
							}
							else
							{
									printf("不合法的下法\n");
								Sleep(500);
							}
						}
						else
						{
							printf("不合法的下法\n");
							Sleep(500);
						}  
					}
						if( check_turn == 13) 				//士    的走法规范    ok 
					{
						if((x == check_x && y == check_y))
						{		
							
						temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if( abs(x - check_x)== 2 && abs( y - check_y) == 4 &&((x==22 && (y == 15 || y == 23)) || ( x == 20 && y == 19) || ( x == 18 && ( y == 15 || y == 23))))
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}
						if( check_turn == 14) 				//将    的走法规范 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
					else if( ((abs(x - check_x)== 2 && abs( y - check_y) == 0 )|| (abs(x - check_x)== 0 && abs( y - check_y) == 4)) && x >= 18 && x <= 22 && y >= 15 && y <= 23 )
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}
						if( check_turn == 15) 				//炮    的走法规范 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if( y == check_y )
						{
							int check_pao = 0;
							if( x > check_x)
							{
								for(j = check_x + 2; j<= x ;j = j+ 2)
								{
									if(map[j][y] == '+' );
									else									
										check_pao++;
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
							else
							{
								for(j = check_x - 2; j>= x;j = j - 2)
								{
									if(map[j][y] == '+' );
									else
									{
										check_pao++;
									}
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
						}
						else if( x == check_x )
						{
								int check_pao = 0;
							if( y > check_y)
							{
								for(j = check_y + 4; j<= y ;j = j+4)
								{
									if(map[x][j] == '+' );
									else									
										check_pao++;
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
							else
							{
								for(j = check_y - 4; j>= y;j = j - 4)
								{
									if(map[x][j] == '+' );
									else
										check_pao++;
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}	
					if( check_turn == 16) 				//卒    的走法规范     成功 
					{
						if( x >= 14){
							if((x == check_x && y == check_y))
							{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
							}
							else if( x == check_x - 2 && y == check_y)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
							else
							{
								printf("不合法的下法\n");
								Sleep(500);
							}		
						}
						else{
							if((x - check_x == 0 && abs(y-check_y) ==4) ||( x - check_x == -2 && abs(y-check_y) == 0))
								check_main1(&temp,&temp1,&turn,&turn1,&num);
							else
							{
							printf("不合法的下法\n");
							Sleep(500);
							}	
						}
					}		
				}
				
				
				
				else						   //帅方 
				{ 
					if( check_turn == 20) 				//车    的走法规范       完成 
					{ 
						if((x == check_x && y == check_y))
						{		
							
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if(  y == check_y  )
						{
							if( x > check_x)
							{
								for(j = check_x + 2; j < x;j = j + 2)
								{
									if(map[j][y] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j >= x)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
								} 
							if( x < check_x)
							{
								for(j = check_x - 2; j > x;j = j - 2)
								{
									if(map[j][y] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j <= x)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
								} 	
						}
							
						else if(  x == check_x  )
						{
							if( y > check_y)
							{
								for(j = check_y + 4; j < y;j = j + 4)
								{
									if(map[x][j] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j >= y)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
								} 
							if( y < check_y)
							{
								for(j = check_y - 4; j > y;j = j - 4)
								{
									if(map[x][j] == '+');
									else
									{
									printf("不合法的下发\n");
									Sleep(500);
									break;
									}
								}
								if( j <= y)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
								} 	
						}	
						else
						{
							printf("不合法的下法\n");
							Sleep(500);
						}
					}
					if( check_turn == 21) 				//马    的走法规范   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
							else if( (abs( x - check_x) == 2&& abs( y - check_y) == 8)&& map[check_x][(y+check_y)/2] =='+')
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else if( (abs( x - check_x) == 4&& abs( y - check_y) == 4)&& map[(x + check_x)/2][check_y] == '+' )
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}	
						if( check_turn == 22) 				//相    的走法规范    完成 
					{
						if( x <= 12 && (abs(y - check_y) == 8 && abs(x - check_x) == 4))
						{
							if((x == check_x && y == check_y))
							{		
						temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
							}
							else if((x == 4 && (y == 11 || y == 27))||(x == 8 && ( y == 3 || y == 19 || y == 35)) ||(x == 12 && (y == 11|| y ==27)))
							{		
								if( map[(x+check_x)/2][(y+check_y)/2] == '+')
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else
								{
									printf("棋子卡住，不可执行");
									Sleep(500); 
								} 
							}
							else
							{
									printf("不合法的下法\n");
								Sleep(500);
							}
						}
						else
						{
							printf("不合法的下法\n");
							Sleep(500);
						}  
					}
						if( check_turn == 23) 				//士    的走法规范   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if( abs(x - check_x)== 2 && abs( y - check_y) == 4 &&((x==4 && (y == 15 || y == 23)) || ( x == 6 && y == 19) || ( x == 8 && ( y == 15 || y == 23))))
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}
						if( check_turn == 24) 				//将    的走法规范   ok
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if( ((abs(x - check_x)== 2 && abs( y - check_y) == 0 )|| (abs(x - check_x)== 0 && abs( y - check_y) == 4)) && x >= 4 && x <= 8 && y >= 15 && y <= 23 )
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}
						
					if( check_turn == 25) 				//炮    的走法规范 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
						}
						else if( y == check_y )
						{
							int check_pao = 0;
							if( x > check_x)
							{
								for(j = check_x + 2; j<= x ;j = j+ 2)
								{
									if(map[j][y] == '+' );
									else									
										check_pao++;
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
							else
							{
								for(j = check_x - 2; j>= x;j = j - 2)
								{
									if(map[j][y] == '+' );
									else
									{
										check_pao++;
									}
								}
								if(check_pao == 1&& temp== '+')       //  直线行走但不可吃棋子 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
						}
						else if( x == check_x )
						{
								int check_pao = 0;
							if( y > check_y)
							{
								for(j = check_y + 4; j<= y ;j = j+4)
								{
									if(map[x][j] == '+' );
									else									
										check_pao++;
								}
								if(check_pao == 1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //跳跃吃棋 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
							else
							{
								for(j = check_y - 4 ; j>= y;j = j - 4)
								{
									if(map[x][j] == '+' );
									else
										check_pao++;
								}
								if(check_pao ==1&& temp == '+')       //  直线行走但不可吃棋子 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2&& temp != '+')      //跳跃吃棋 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("不合法的下法\n");
									Sleep(500);
								}
							}
						}
						else
						{
								printf("不合法的下法\n");
							Sleep(500);
						}
					}	
					if( check_turn == 26) 				//卒    的走法规范     成功 
					{
						if( x <= 12){
							if((x == check_x && y == check_y))
							{		
								temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("少悔棋哦\n");
							printf("还是你的回合"); 
							Sleep(500);
							}
							else if( x == check_x + 2 && y == check_y)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
							else
							{
								printf("不合法的下法\n");
								Sleep(500);
							}		
						}
						else{
								if((x - check_x == 0 && abs(y-check_y) ==4) ||( x - check_x == 2 && abs(y-check_y) == 0))
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else{
								printf("不合法的下法\n");
								Sleep(500);
								}	
						}
					}
				} 
			}
        }
        system("cls");
        for(i = 0; i < 27; i++)
        puts(map[i]);
    }
    Sleep(5000);
 } 
