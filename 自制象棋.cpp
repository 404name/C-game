#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
//�ַ� L ���� 

int x,y,i,j,p,q,num = 1,round,place_x1 = 0,place_y1 = 0,place_x2 = 0,place_y2 = 0;                                                       //�������� 
int check_x,check_y,check_turn;
char ch, turn = 'O',turn1 = 'N',temp,temp1;    	
				//"||===================================||",
char map[1000][1000]= {  "[[===================================]]",
                             "[|�ٽ�         ��|����|��        �ڎ�|]",
                             "[====================================]]",
                             "[[-----------------------------------]]",
                             "[[ ܇���R���ࡪ�ˡ������ˡ��ࡪ�R��܇]]", 
                             "[[ |   |   |   | \\ | / |   |   |   | ]]",
                             "[[ +-��+-��+-��+-��+-��+-��+-��+-��+-]]",                            
                             "[[ |   |   |   | / | \\ |   |   |   | ]]",                           
                             "[[ +-���h��+-��+-��+-��+-��+-���h��+-]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ �䡪+-���䡪+-���䡪+-���䡪+-����]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ +-��+-��+-��+-��+-��+-��+-��+-��+-]]",
                             "[[===================================]]",
                             "[[ +-��+-��+-��+-��+-��+-��+-��+-��+-]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ ����+-������+-������+-������+-����]]",
                             "[[ |   |   |   |   |   |   |   |   | ]]",
                             "[[ +-���ڡ�+-��+-��+-��+-��+-���ڡ�+-]]",
                             "[[ |   |   |   | \\ | / |   |   |   | ]]",
                             "[[ +-��+-��+-��+-��+-��+-��+-��+-��+-]]",
                             "[[ |   |   |   | / | \\ |   |   |   | ]]",
                             "[[ ��������ʿ������ʿ��������]]",
                             "[[-----------------------------------]]",
                             "[=====================================]"};
char check_1[9][3] ={"��","��","��","ʿ","��","��","��","+-"};  //ȡ����ʱֻ�ж�ǰ8�Ϸ��� 
char check_2[9][3] ={"܇","�R","��","��","��","�h","��","+-"};	//������ʱ�ж϶�һ����λ�Ϸ� 
char check[3];	
		
int check_main1(char* temp,char* temp1,char* turn,char* turn1,int *num)         //�ж� ����  �����Ƿ�Ϸ� 
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
				printf("˧����%s����\n",check_2[i]);
				Sleep(500);
			}	
			*num = *num + 1;
			for( i = 4; i <= 8; i = i + 2)   //�жώ��Ƿ����� 
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
				printf("�� ������  �������ʤ��\n");
				Sleep(10000); 
				return 0; 
			}
			for( i = 18; i <= 22; i = i + 2)   //�жϽ��Ƿ����� 
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
					printf("���� ������  �������ʤ��\n");
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
						printf(" �����Խ�   ����ʤ��");
					else if( round == 2)
						printf(" �����Խ�   ����ʤ��");
					Sleep(10000); 
					return 0;
				}   	
			}
			break; 
		}	
	}
	if( i == 8)
	{
		printf("���Ϸ����߷�\n");
		Sleep(500);
	} 	 
} 
int check_main2(char* temp,char* temp1,char* turn,char* turn1,int *num) //�ж�  ���������Ƿ�Ϸ� 
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
				printf("������%s����",check_1[i]);
				Sleep(500);
			}	
		    *num = *num + 1; 
			for( i = 4; i <= 8; i = i + 2)   //�жώ��Ƿ����� 
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
				printf("�� ������  �������ʤ��\n");
				Sleep(10000); 
				return 0; 
			}
			for( i = 18; i <= 22; i = i + 2)   //�жϽ��Ƿ����� 
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
					printf("���� ������  �������ʤ��\n");
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
						printf(" �����Խ�   ����ʤ��");
					else if( round == 2)
						printf(" �����Խ�   ����ʤ��");
					Sleep(10000); 
					return 0;
				}   	
			} 
			break; 
		}	
	}
	if( i == 8)
	{
	printf("���Ϸ����߷�\n");
	Sleep(500);
	} 	 
}

int main()
{		
	printf("wasd�ƶ�Lȡ������");
	getchar();	
	system("cls"); 
	system("mode con cols=40 lines=30");      //������� 
    system("color 30"); 				
	for ( i = 0; i < 27; i++)
	puts(map[i]);
	x = 6,y = 19;
    temp = map[x][y];
	temp1 = map[x][y+1];     
    while(num)            
    {    if(num % 2 == 1 &&num / 2 % 2 == 0){
    	printf("������'��'�Ļغ�\n");
    	round = 1;
	}	
	else if( num %2 == 1){
		printf("�����ֵ�'��'�Ļغ���\n");
		round = 2;  	
	}               
    ch = getch();
    if ( ch == 's')         //���� 
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
    else if ( ch == 'a')    //���� 
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
    else if ( ch == 'w')    //���� 
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
    else if ( ch == 'd')    //���� 
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
        	if(num % 2 == 1 && temp != '+' && temp1 != '-')   //ȡ 
        	{
				check[0] = temp;
				check[1] = temp1;
				check[2] = '\0';
				if( round == 1)
				{
					for (  i = 0; i < 7; i++)           //���� 
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
						printf("�ⲻ���������\n");
						Sleep(500);
					}
				 }
				else if( round == 2)
				{
					for ( i = 0; i < 7; i++)           //���� 
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
						printf("�ⲻ���������\n");
						Sleep(500);
					}
					
				} 
			}
			else if( num % 2 == 0)                 //�� 
			{             
		/*char check_1[8][3] ={"��","��","��","ʿ","��","��","��","+-"}; 
		char check_2[8][3] ={"�e","�R","��","��","��","�N","��","+-"};*/ 
			/*
		�н� ������������  12    15 
		*/     
		//  ����2  ����4 
				if( check_turn < 20)          //���� 
				{
					if( check_turn == 10) 				//��    ���߷��淶     ��� 
					{
						if((x == check_x && y == check_y))
						{		
							
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
							printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
					if( check_turn == 11) 				//��    ���߷��淶   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}	
						if( check_turn == 12) 				//��    ���߷��淶     ��� 
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
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
							}
							else if((x == 22 && (y == 11 || y == 27))||(x == 18 && ( y == 3 || y == 19 || y == 35)) ||(x == 14 && (y == 11|| y ==27)))
							{		
								if( map[(x+check_x)/2][(y+check_y)/2] == '+')
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else
								{
									printf("���ӿ�ס������ִ��");
									Sleep(500); 
								} 
							}
							else
							{
									printf("���Ϸ����·�\n");
								Sleep(500);
							}
						}
						else
						{
							printf("���Ϸ����·�\n");
							Sleep(500);
						}  
					}
						if( check_turn == 13) 				//ʿ    ���߷��淶    ok 
					{
						if((x == check_x && y == check_y))
						{		
							
						temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
						}
						else if( abs(x - check_x)== 2 && abs( y - check_y) == 4 &&((x==22 && (y == 15 || y == 23)) || ( x == 20 && y == 19) || ( x == 18 && ( y == 15 || y == 23))))
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
						if( check_turn == 14) 				//��    ���߷��淶 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
						}
					else if( ((abs(x - check_x)== 2 && abs( y - check_y) == 0 )|| (abs(x - check_x)== 0 && abs( y - check_y) == 4)) && x >= 18 && x <= 22 && y >= 15 && y <= 23 )
						{
							check_main1(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
						if( check_turn == 15) 				//��    ���߷��淶 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main1(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main1(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
									Sleep(500);
								}
							}
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}	
					if( check_turn == 16) 				//��    ���߷��淶     �ɹ� 
					{
						if( x >= 14){
							if((x == check_x && y == check_y))
							{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
							}
							else if( x == check_x - 2 && y == check_y)
								check_main1(&temp,&temp1,&turn,&turn1,&num);
							else
							{
								printf("���Ϸ����·�\n");
								Sleep(500);
							}		
						}
						else{
							if((x - check_x == 0 && abs(y-check_y) ==4) ||( x - check_x == -2 && abs(y-check_y) == 0))
								check_main1(&temp,&temp1,&turn,&turn1,&num);
							else
							{
							printf("���Ϸ����·�\n");
							Sleep(500);
							}	
						}
					}		
				}
				
				
				
				else						   //˧�� 
				{ 
					if( check_turn == 20) 				//��    ���߷��淶       ��� 
					{ 
						if((x == check_x && y == check_y))
						{		
							
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
									printf("���Ϸ����·�\n");
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
							printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
					if( check_turn == 21) 				//��    ���߷��淶   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}	
						if( check_turn == 22) 				//��    ���߷��淶    ��� 
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
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
							}
							else if((x == 4 && (y == 11 || y == 27))||(x == 8 && ( y == 3 || y == 19 || y == 35)) ||(x == 12 && (y == 11|| y ==27)))
							{		
								if( map[(x+check_x)/2][(y+check_y)/2] == '+')
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else
								{
									printf("���ӿ�ס������ִ��");
									Sleep(500); 
								} 
							}
							else
							{
									printf("���Ϸ����·�\n");
								Sleep(500);
							}
						}
						else
						{
							printf("���Ϸ����·�\n");
							Sleep(500);
						}  
					}
						if( check_turn == 23) 				//ʿ    ���߷��淶   ok 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
						}
						else if( abs(x - check_x)== 2 && abs( y - check_y) == 4 &&((x==4 && (y == 15 || y == 23)) || ( x == 6 && y == 19) || ( x == 8 && ( y == 15 || y == 23))))
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
						if( check_turn == 24) 				//��    ���߷��淶   ok
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
						}
						else if( ((abs(x - check_x)== 2 && abs( y - check_y) == 0 )|| (abs(x - check_x)== 0 && abs( y - check_y) == 4)) && x >= 4 && x <= 8 && y >= 15 && y <= 23 )
						{
							check_main2(&temp,&temp1,&turn,&turn1,&num);
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}
						
					if( check_turn == 25) 				//��    ���߷��淶 
					{
						if((x == check_x && y == check_y))
						{		
							temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao == 1&& temp== '+')       //  ֱ�����ߵ����ɳ����� 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao == 1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2 && temp != '+')      //��Ծ���� 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
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
								if(check_pao ==1&& temp == '+')       //  ֱ�����ߵ����ɳ����� 
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else if( check_pao == 2&& temp != '+')      //��Ծ���� 
									check_main2(&temp,&temp1,&turn,&turn1,&num); 
								else
								{
									printf("���Ϸ����·�\n");
									Sleep(500);
								}
							}
						}
						else
						{
								printf("���Ϸ����·�\n");
							Sleep(500);
						}
					}	
					if( check_turn == 26) 				//��    ���߷��淶     �ɹ� 
					{
						if( x <= 12){
							if((x == check_x && y == check_y))
							{		
								temp = turn;
							temp1 = turn1;
							turn = 'O';
							turn1 = 'N';
							num--;
							printf("�ٻ���Ŷ\n");
							printf("������Ļغ�"); 
							Sleep(500);
							}
							else if( x == check_x + 2 && y == check_y)
								check_main2(&temp,&temp1,&turn,&turn1,&num);
							else
							{
								printf("���Ϸ����·�\n");
								Sleep(500);
							}		
						}
						else{
								if((x - check_x == 0 && abs(y-check_y) ==4) ||( x - check_x == 2 && abs(y-check_y) == 0))
									check_main2(&temp,&temp1,&turn,&turn1,&num);
								else{
								printf("���Ϸ����·�\n");
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
