//!!!如果出现乱码请删除 第12 行 

#include<stdio.h>
#include<string.h>
#include<conio.h>      //用于getch取键盘输入字符 
#include<windows.h>    //用于刷屏 

int main()
{
    int x,y,i,p,q,num = 1,check;
    char ch, turn,temp;
    system("mode con cols=38 lines=30");      //迷你界面 
    system("color 30"); 
    printf("<<游戏规则>>：!!!!!!!!!!!!!!!!\n\n");
    printf("<wasd双方轮流控制指针下棋>\n<键盘输入大小写‘L’都视为确认>\n");
    printf("\n<任意按钮开始游戏>\n\n");
  
    char map[1000][1000]= {  "||==================================||",
                             "||   x      ||欢乐五子棋||     o    ||",
                             "||          ==============          ||",
                             "[====================================]",
                             "[[==================================]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[                                  ]]",
                             "[[==================================]]",
                             "[====================================]"
                          };
    for(i = 0; i < 22; i++)
        puts(map[i]);
    
    x = 10,y = 18;
    temp = map[x][y];           //temp是关键：保存光标所指坐标上一次的状态 ，方便恢复与新建状态 

    while(num)                 //主程序：实现移动光标并指定坐标下棋 
    {                          //保证不出界，且保证已下棋位置不会再次被覆盖 
        if(num % 2 != 0){
        	turn = 'x';
			printf("轮到 %c 下了\n这是你的第 %d 步棋\n",turn,(num + 1) / 2); 
		}
        else{
        	turn = 'o';
        	printf("这是 %c 的回合\n这是你的第 %d 步棋\n",turn,num /2);
		} 
		if(num > 544)
			return 0;
		else if(num > 540)
		 	printf("有的惊喜就是在你也想不到的的情况下发生"); 
		else if( num > 500)
        	printf("填满有惊喜喔") ;
		else if( num > 200)
        	printf("你可以填满棋盘的"); 
		else if( num > 150)
        	printf("你眼睛不花吗") ;
		else if( num > 100)
        	printf("还没有分出胜负ne ") ;	
		else if( num > 80) 
        	printf("距离成功不远了") ; 
		else if( num > 50)
        	printf("看来你还能继续下") ;
		else if( num > 30)
        	printf("你还能清楚的看清棋盘吗？") ;
		
		
		else if( num > 20)
        	printf("快接近胜利了吗？\n") ;
		
		
	
		
        
         
		
		   
        ch = getch();
        if ( ch == 's')         //下移 
        {
            if( map[x+1][y]!= '=' &&map[x+1][y]!= ']' &&map[x+1][y]!= '[')
            {
                map[x][y] = temp;
                x++;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'a')    //左移 
        {
            if( map[x][y-1]!= '=' && map[x][y-1]!= '[' && map[x][y-1]!= ']')
            {
                map[x][y] = temp;
                y--;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'w')    //上移 
        {
            if(  map[x-1][y]!= '=' && map[x-1][y]!= '[' &&  map[x-1][y]!=  ']')
            {
                map[x][y] = temp;
                x--;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'd')    //右移 
        {
            if( map[x][y+1]!= '=' &&map[x][y+1]!= '[' &&map[x][y+1]!= ']')
            {
                map[x][y] =temp;
                y++;
                temp = map[x][y];
                map[x][y] = turn;
                
            }
        }
        else if( ch == 'l' || ch =='L')   //确认下棋后改变坐标状态，并且判断是否伍连。 
        {
            if(temp == ' ')
            {
                map[x][y] = turn;
                temp = map[x][y];
                num++;
                
                
                check=1;                                //判断水平方向 
                {
                    p=x;
                    q=y;
                    q--;
                    
                    if( q >=0&& q<  38)
                    while(q >=0&& q< 38  &&  map[p][q]== turn)//防止数组下标越界
                    {
                    	check++;
                   		q--;
                    }  
                    p=x;
                    q=y;
                    q++;
                    
                    if( q >=0&& q< 38 )
                    while(q >=0&& q<  38 &&  map[p][q] == turn)//防止数组下标越界
                    {
                    	check++;
                    	q++;
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n按任意键退出游戏",turn);
                    return 0;}
                                                       
                }
                
                
                check=1;								//判断垂直方向 
                {
                    p=x;
                    q=y;
                    p--;
                    
                    if( p >=0&& p<= 22)
	                    while(p >=0&& p<= 22  &&  map[p][q]== turn)//防止数组下标越界
	                    {
	                    	check++;
	                   		p--;
	                    }  
                    p=x;
                    q=y;
                    p++;
                    
                    if( p >=0&& p<= 22 )
	                    while(p >=0&& p<=  22 &&  map[p][q] == turn)//防止数组下标越界
	                    {
	                    	check++;
	                    	p++;
	                    } 
	                if(check  >= 5 ){
	                printf("%c win the game\n按任意键退出游戏",turn);
                    return 0;}
                }
                check=1;                                //判断左斜方向 
                {
                    p=x;
                    q=y;
                    q--;
                    p--; 
                    
                    if( q >=0&& q<  38 && p >=0 && p <= 22)
                    while(q >=0&& q<  38 && p >=0 && p <= 22 &&  map[p][q]== turn)//防止数组下标越界
                    {
                    	check++;
                   		q--;
                   		p--;
                    }  
                    p=x;
                    q=y;
                    q++;
                    p++;
                    if( q >=0&& q<  38 && p >=0 && p <= 22 )
                    while(q >=0&& q<  38 && p >=0 && p <= 22 && map[p][q] == turn)//防止数组下标越界
                    {
                    	check++;
                    	q++;
                    	p++; 
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n按任意键退出游戏",turn);
                    return 0;}
                    
                    check=1;                                //判断右斜方向 
                {
                    p=x;
                    q=y;
                    q++;
                    p--; 
                    
                    if( q >=0&& q<  38 && p >=0 && p <= 22)
                    while(q >=0&& q<  38 && p >=0 && p <= 22 &&  map[p][q]== turn)//防止数组下标越界
                    {
                    	check++;
                   		q++;
                   		p--;
                    }  
                    p=x;
                    q=y;
                    q--;
                    p++;
                    if( q >=0&& q<  38 && p >=0 && p <= 22 )
                    while(q >=0&& q<  38 && p >=0 && p <= 22 && map[p][q] == turn)//防止数组下标越界
                    {
                    	check++;
                    	q--;
                    	p++; 
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n按任意键退出游戏",turn);
                    return 0;}
                                                       
                }                                    
                }
            }
            else if( temp =='o') {
                printf("此处不可以下棋！！\n");
                Sleep(500);
            }
            else if( temp =='x') {
                printf("此处不可以下棋！！\n");
                Sleep(500);
            }


        }
        system("cls");
        for(i = 0; i < 25; i++)
            puts(map[i]);
    }

}




