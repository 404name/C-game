//!!!�������������ɾ�� ��12 �� 

#include<stdio.h>
#include<string.h>
#include<conio.h>      //����getchȡ���������ַ� 
#include<windows.h>    //����ˢ�� 

int main()
{
    int x,y,i,p,q,num = 1,check;
    char ch, turn,temp;
    system("mode con cols=38 lines=30");      //������� 
    system("color 30"); 
    printf("<<��Ϸ����>>��!!!!!!!!!!!!!!!!\n\n");
    printf("<wasd˫����������ָ������>\n<���������Сд��L������Ϊȷ��>\n");
    printf("\n<���ⰴť��ʼ��Ϸ>\n\n");
  
    char map[1000][1000]= {  "||==================================||",
                             "||   x      ||����������||     o    ||",
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
    temp = map[x][y];           //temp�ǹؼ�����������ָ������һ�ε�״̬ ������ָ����½�״̬ 

    while(num)                 //������ʵ���ƶ���겢ָ���������� 
    {                          //��֤�����磬�ұ�֤������λ�ò����ٴα����� 
        if(num % 2 != 0){
        	turn = 'x';
			printf("�ֵ� %c ����\n������ĵ� %d ����\n",turn,(num + 1) / 2); 
		}
        else{
        	turn = 'o';
        	printf("���� %c �Ļغ�\n������ĵ� %d ����\n",turn,num /2);
		} 
		if(num > 544)
			return 0;
		else if(num > 540)
		 	printf("�еľ�ϲ��������Ҳ�벻���ĵ�����·���"); 
		else if( num > 500)
        	printf("�����о�ϲ�") ;
		else if( num > 200)
        	printf("������������̵�"); 
		else if( num > 150)
        	printf("���۾�������") ;
		else if( num > 100)
        	printf("��û�зֳ�ʤ��ne ") ;	
		else if( num > 80) 
        	printf("����ɹ���Զ��") ; 
		else if( num > 50)
        	printf("�����㻹�ܼ�����") ;
		else if( num > 30)
        	printf("�㻹������Ŀ���������") ;
		
		
		else if( num > 20)
        	printf("��ӽ�ʤ������\n") ;
		
		
	
		
        
         
		
		   
        ch = getch();
        if ( ch == 's')         //���� 
        {
            if( map[x+1][y]!= '=' &&map[x+1][y]!= ']' &&map[x+1][y]!= '[')
            {
                map[x][y] = temp;
                x++;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'a')    //���� 
        {
            if( map[x][y-1]!= '=' && map[x][y-1]!= '[' && map[x][y-1]!= ']')
            {
                map[x][y] = temp;
                y--;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'w')    //���� 
        {
            if(  map[x-1][y]!= '=' && map[x-1][y]!= '[' &&  map[x-1][y]!=  ']')
            {
                map[x][y] = temp;
                x--;
                temp = map[x][y];
                map[x][y] = turn;
            }
        }
        else if ( ch == 'd')    //���� 
        {
            if( map[x][y+1]!= '=' &&map[x][y+1]!= '[' &&map[x][y+1]!= ']')
            {
                map[x][y] =temp;
                y++;
                temp = map[x][y];
                map[x][y] = turn;
                
            }
        }
        else if( ch == 'l' || ch =='L')   //ȷ�������ı�����״̬�������ж��Ƿ������� 
        {
            if(temp == ' ')
            {
                map[x][y] = turn;
                temp = map[x][y];
                num++;
                
                
                check=1;                                //�ж�ˮƽ���� 
                {
                    p=x;
                    q=y;
                    q--;
                    
                    if( q >=0&& q<  38)
                    while(q >=0&& q< 38  &&  map[p][q]== turn)//��ֹ�����±�Խ��
                    {
                    	check++;
                   		q--;
                    }  
                    p=x;
                    q=y;
                    q++;
                    
                    if( q >=0&& q< 38 )
                    while(q >=0&& q<  38 &&  map[p][q] == turn)//��ֹ�����±�Խ��
                    {
                    	check++;
                    	q++;
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n��������˳���Ϸ",turn);
                    return 0;}
                                                       
                }
                
                
                check=1;								//�жϴ�ֱ���� 
                {
                    p=x;
                    q=y;
                    p--;
                    
                    if( p >=0&& p<= 22)
	                    while(p >=0&& p<= 22  &&  map[p][q]== turn)//��ֹ�����±�Խ��
	                    {
	                    	check++;
	                   		p--;
	                    }  
                    p=x;
                    q=y;
                    p++;
                    
                    if( p >=0&& p<= 22 )
	                    while(p >=0&& p<=  22 &&  map[p][q] == turn)//��ֹ�����±�Խ��
	                    {
	                    	check++;
	                    	p++;
	                    } 
	                if(check  >= 5 ){
	                printf("%c win the game\n��������˳���Ϸ",turn);
                    return 0;}
                }
                check=1;                                //�ж���б���� 
                {
                    p=x;
                    q=y;
                    q--;
                    p--; 
                    
                    if( q >=0&& q<  38 && p >=0 && p <= 22)
                    while(q >=0&& q<  38 && p >=0 && p <= 22 &&  map[p][q]== turn)//��ֹ�����±�Խ��
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
                    while(q >=0&& q<  38 && p >=0 && p <= 22 && map[p][q] == turn)//��ֹ�����±�Խ��
                    {
                    	check++;
                    	q++;
                    	p++; 
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n��������˳���Ϸ",turn);
                    return 0;}
                    
                    check=1;                                //�ж���б���� 
                {
                    p=x;
                    q=y;
                    q++;
                    p--; 
                    
                    if( q >=0&& q<  38 && p >=0 && p <= 22)
                    while(q >=0&& q<  38 && p >=0 && p <= 22 &&  map[p][q]== turn)//��ֹ�����±�Խ��
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
                    while(q >=0&& q<  38 && p >=0 && p <= 22 && map[p][q] == turn)//��ֹ�����±�Խ��
                    {
                    	check++;
                    	q--;
                    	p++; 
                    } 
                    if(check  >= 5 ){
                    printf("%c win the game\n��������˳���Ϸ",turn);
                    return 0;}
                                                       
                }                                    
                }
            }
            else if( temp =='o') {
                printf("�˴����������壡��\n");
                Sleep(500);
            }
            else if( temp =='x') {
                printf("�˴����������壡��\n");
                Sleep(500);
            }


        }
        system("cls");
        for(i = 0; i < 25; i++)
            puts(map[i]);
    }

}




