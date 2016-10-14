#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<time.h>

void show_menu ();
void choice (int n);
void show_new_game_menu ();
void show_options();
void show_instructions();
void execute_exit_menu();
void audio_control ();
void game(int N);
void strike(int x_bullet[500],int y_bullet[500],int bullet[500],int x_balloon[500],char balloon[500]);
void Time(int x_bullet[500],int y_bullet[500],int bullet[500],int x_balloon[500],int y_balloon_t[500],char balloon[500]);
void l_move();
void r_move();
void new_balloon_s(int x_balloon[500],char balloon[500]);
void new_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500]);
void print_balloon_s(int x_balloon[500],char balloon[500]);
void print_bullet(int x_bullet[500],int y_bullet[500],int bullet[500]);
void print_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500]);
void erase_balloon_s(int x_balloon[500],char balloon[500]);
void erase_bullet(int x_bullet[500],int y_bullet[500],int bullet[500]);
void erase_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500]);
void hit_balloon_s(int x_balloon[500],int x_bullet[500],int y_bullet[500],char balloon[500],int bullet[500]);
void hit_balloon_t(int x_balloon[500],int y_balloon_t[500],int x_bullet[500],int y_bullet[500],char balloon[500],int bullet[500]);
void game_over(int I);
void show_high_score();
void gotoXY(int x,int y);
void color(int B, int C);
void loading();
void audio();
void view_high_score_t();
void view_high_score_s();

int x_base,y_base,y_balloon,balloon_pos_s[25]= {17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57},H_s,H_t,sound=75;
int score_s=0,score_t=0,life=5,g_over=1,count_balloon=0,count_bullet=0,life_ctrl=0,left_move=77,right_move=75,shoot=32,life_ctrl_b,t;
int i,j,k,a,b,c,flag=0,ran_pos,ran_num,ran_extra,balloon_pos_s_store[500],g_over_s,g_over_t,ran_t,ran_T,balloon_pos_t[20]= {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
char input,extra[500]= {3,2,15,1};
COORD coord= {0,0};

int main ()
{
    color(14,0);
    srand(time(NULL));
    loading();
    show_menu();
    return 0;
}

void show_menu ()
{
    int n,in=1;
    char ch;
    system("cls");
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        if(in==1)
            printf(" %c%c%cNEW GAME%c%c%c",176,176,176,176,176,176);
        else
            printf("    new game");
        gotoXY(45,16);
        if(in==2)
            printf(" %c%c%cSETTINGS%c%c%c",176,176,176,176,176,176);
        else
            printf("    settings");
        gotoXY(45,17);
        if(in==3)
            printf(" %c%cHIGH SCORE%c%c",176,176,176,176);
        else
            printf("   high score");
        gotoXY(45,18);
        if(in==4)
            printf(" %cINSTRUCTIONS%c",176,176);
        else
            printf("  instructions");
        gotoXY(45,19);
        if(in==5)
            printf(" %c%c%c%c%cEXIT%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176);
        else
            printf("      exit");
        ch=getch();
        if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>5)
            in=1;
        else if(in==0)
            in=5;
    }
    system("cls");
    choice (in);
}

void choice (int n)
{
    switch (n)
    {
    case 1:
        show_new_game_menu();
        break;
    case 2:
        show_options();
        break;
    case 3:
        show_high_score();
        break;
    case 4:
        show_instructions ();
        break;
    case 5:
        execute_exit_menu ();
        break;
    }
}
void show_new_game_menu ()
{
    int c,in=1;
    char ch;
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        if(in==1)printf("%c%c%c%cTIME TRAP%c%c%c%c",176,176,176,176,176,176,176,176);
        else     printf("    Time Trap");
        gotoXY(45,16);
        if(in==2)printf("%cSTRIKE STRAIGHT%c",176,176);
        else     printf(" Strike Straight");
        gotoXY(45,17);
        if(in==3)printf("%c%c%c%c%c%cBACK%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176);
        else     printf("      Back\n");
        ch=getch();
        if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>3)
            in=1;
        else if(in==0)
            in=3;
    }
    system("cls");
    switch (in)
    {
    case 1:
        game(in);
        break;
    case 2:
        game(in);
        break;
    case 3:
        show_menu ();
        break;
    }
}
void show_options()
{
    int t,in=1;
    char ch;
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        if(in==1)printf("%c%c%cSOUND%c%c%c%c",176,176,176,176,176,176,176);
        else     printf("   sound");
        gotoXY(45,16);
        if(in==2)printf("%c%c%c%cBACK%c%c%c%c\n",176,176,176,176,176,176,176,176);
        else     printf("    back\n");
        ch=getch();
        if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>2)
            in=1;
        else if(in==0)
            in=2;

    }
    system("cls");
    switch (in)
    {
    case 1:
        audio_control ();
        break;
    case 2:
        show_menu();
        break;
    }
}
void show_instructions()
{
    FILE* fp;
    char ch,input;
    fp = fopen ("Instructions for Pera Shoot.txt","r");
    while ((ch=getc(fp))!=EOF)
    {
        if(_kbhit()) input=_getch();
        if(input==27)show_menu();
        printf ("%c",ch);
        Sleep (30);
    }
    fclose (fp);
    printf("\n\n\npress any key to continue...");
    getch();
    show_menu();

}
void execute_exit_menu()
{
    int e,in=1;
    char ch;
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        printf ("Are You Sure To Quit?\n");
        gotoXY(35,17);
        if(in==1)printf("\t\t%cYES%c",176,176,176,176);
        else     printf("\t\t Yes");
        gotoXY(35,18);
        if(in==2)printf("\t\t%cNO%c%c",176,176,176);
        else     printf("\t\t No");
        ch=getch();
        if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>2)
            in=1;
        else if(in==0)
            in=2;

    }
    system("cls");
    switch (in)
    {
    case 1:
        exit(0);
        break;
    case 2:
        show_menu();
        break;
    }
}
void audio_control ()
{
    int in=1;
    char ch;
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        if(in==1&&sound==77)printf("%csound OFF%c",17,16);
        gotoXY(45,15);
        if(in==1&&sound==75)printf("%csound ON %c",17,16);

        if(in==2)
        {
            gotoXY(45,15);
            if(sound==77)printf(" sound OFF");
            if(sound==75)printf(" sound ON ");
            gotoXY(45,16);
            printf("%c%c%cBACK%c%c%c\n",176,176,176,176,176,176);
        }
        else
        {
            gotoXY(45,16);
            printf("   back\n");
        }
        ch=getch();
        if(sound==77&&ch==77&&in==1)sound=75;
        else if(sound==75&&ch==75&&in==1)sound=77;
        else if(ch==77&&in==1)sound=77;
        else if(ch==75&&in==1)sound=75;
        else if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>2)
            in=1;
        else if(in==0)
            in=2;

    }
    system("cls");
    switch (in)
    {
    case 1:
        show_options();
        break;
    case 2:
        show_options();
        break;
    }
}
void game(int N)
{
    system("cls");
    char balloon[500];
    int bullet[500],x_balloon[500],y_balloon_t[500],x_bullet[500],y_bullet[500];
    score_s=0;
    score_t=0;
    life=5;
    g_over=1;
    count_balloon=0;
    count_bullet=0;
    life_ctrl=0;
    flag=0;
    x_base=37;
    y_base=54;
    t=60;
    color(13,0);
    printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
    gotoXY(65,5);
    color(8,0);
    if(N==2)printf("LIFE LEFT : %d",life);
    gotoXY(65,5);
    if(N==1)printf("TIME LEFT : %d",t);
    if(N==1)new_balloon_t(x_balloon,y_balloon_t,balloon);
    if(N==2)new_balloon_s(x_balloon,balloon);
    gotoXY(x_base,y_base);
    color(10,0);
    printf("%c",262);
    if(N==1)Time(x_bullet,y_bullet,bullet,x_balloon,y_balloon_t,balloon);
    if(N==2)strike(x_bullet,y_bullet,bullet,x_balloon,balloon);
}
void strike(int x_bullet[500],int y_bullet[500],int bullet[500],int x_balloon[500],char balloon[500])
{
    input=0;
    while(g_over)
    {

        if(_kbhit()) input=_getch();
        if(input==left_move) l_move();
        if(input==right_move) r_move();
        if(input==27)show_menu();
        if(y_balloon==55)
        {
            life=life-(life_ctrl_b-life_ctrl);
            if(life<=0)game_over(1);
            gotoXY(65,5);
            color(8,0);
            printf("LIFE LEFT : %d",life);
            new_balloon_s(x_balloon,balloon);
        }
        gotoXY(65,1);
        color(8,0);
        printf("SCORE :      ");
        if(score_s<0)score_s=0;
        gotoXY(65,1);
        color(8,0);
        printf("SCORE : %d",score_s);
        print_balloon_s(x_balloon,balloon);
        print_bullet(x_bullet,y_bullet,bullet);
        if(input==shoot)
        {
            y_bullet[count_bullet]=53;
            x_bullet[count_bullet]=x_base;
            bullet[count_bullet]=18;
            count_bullet++;
        }
        if(input==80||input==112)getch();
        hit_balloon_s(x_balloon,x_bullet,y_bullet,balloon,bullet);
        Sleep(70);
        erase_balloon_s(x_balloon,balloon);
        erase_bullet(x_bullet,y_bullet,bullet);
        input=0;
        y_balloon++;
    }
}
void Time(int x_bullet[500],int y_bullet[500],int bullet[500],int x_balloon[500],int y_balloon_t[500],char balloon[500])
{
    input=0;
    time_t start,end,s,e;
    s=time(NULL);
    start=time(NULL);
    int I;

    while(g_over)
    {
        end=time(NULL);
        e=time(NULL);

        if(difftime(e,s)==1)
        {
            gotoXY(65,5);
            color(8,0);
            printf("TIME LEFT :    ");
            gotoXY(65,5);
            color(8,0);
            printf("TIME LEFT : %d",t);
            t--;
            s=time(NULL);
        }
        if(difftime(end,start)==62)game_over(2);
        if(_kbhit()) input=_getch();
        if(input==left_move) l_move();
        if(input==right_move) r_move();
        if(input==27)show_menu();
        ran_t=rand()%30;
        if(ran_t<10)new_balloon_t(x_balloon,y_balloon_t,balloon);
        gotoXY(65,1);
        color(8,0);
        printf("SCORE : %d",score_t);
        print_balloon_t(x_balloon,y_balloon_t,balloon);
        print_bullet(x_bullet,y_bullet,bullet);
        if(input==shoot)
        {
            y_bullet[count_bullet]=53;
            x_bullet[count_bullet]=x_base;
            bullet[count_bullet]=18;
            count_bullet++;

        }
        if(input==80||input==112)getch();
        hit_balloon_t(x_balloon,y_balloon_t,x_bullet,y_bullet,balloon,bullet);
        Sleep(80);
        erase_balloon_t(x_balloon,y_balloon_t,balloon);
        erase_bullet(x_bullet,y_bullet,bullet);
        input=0;
        for(I=11; I<=30; I++)
        {
            color(13,0);
            gotoXY(58,I);
            printf("%c",176);
        }
    }
}
void l_move()
{
    color(10,0);
    gotoXY(x_base,y_base);
    printf(" ");
    x_base=x_base+2;
    if(x_base>56)x_base=57;
    gotoXY(x_base,y_base);
    printf("%c",262);
}
void r_move()
{
    color(10,0);
    gotoXY(x_base,y_base);
    printf(" ");
    x_base=x_base-2;
    if(x_base<17)x_base=17;
    gotoXY(x_base,y_base);
    printf("%c",262);
}
void new_balloon_s(int x_balloon[500],char balloon[500])
{
    count_balloon=0;
    y_balloon=1;
    life_ctrl=0;
    life_ctrl_b=0;
    ran_num=rand()%5;
    ran_extra=rand()%10;
    if(ran_num==0)ran_num=ran_num+2;
    for(i=0; i<ran_num; i++)
    {
        ran_pos=rand()%21;
        balloon_pos_s_store[i]=balloon_pos_s[ran_pos];
    }
    for(i=0; i<ran_num; i++)
    {
        flag=0;
        for(j=i+1; j<ran_num; j++)
        {
            if(balloon_pos_s_store[i]==balloon_pos_s_store[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            x_balloon[count_balloon]=balloon_pos_s_store[i];
            if(ran_extra>=0&&ran_extra<4)balloon[count_balloon]=extra[ran_extra];
            else
            {
                balloon[count_balloon]='O';
                life_ctrl_b++;
            }
            ran_extra=10;
            count_balloon++;
        }
    }
}
void new_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500])
{
    ran_T=rand()%20;
    y_balloon_t[count_balloon]=balloon_pos_t[ran_T];
    x_balloon[count_balloon]=17;
    if(ran_t%5==0)balloon[count_balloon]=15;
    else balloon[count_balloon]='O';
    count_balloon++;
}
void print_balloon_s(int x_balloon[500],char balloon[500])
{
    for(j=0; j<count_balloon; j++)
    {
        if(x_balloon[j]==x_base&&y_balloon==54)continue;
        if(balloon[j]==32)continue;
        if(balloon[j]=='O')color(7,0);
        if(balloon[j]==3)color(6,0);
        if(balloon[j]==2)color(9,0);
        if(balloon[j]==15)color(12,0);
        if(balloon[j]==1)color(18,0);
        gotoXY(x_balloon[j],y_balloon);
        printf("%c",balloon[j]);

    }
}
void print_bullet(int x_bullet[500],int y_bullet[500],int bullet[500])
{
    for(i=0; i<count_bullet; i++)
    {
        if(y_bullet[i]<1)continue;
        if(bullet[i]==32)continue;
        gotoXY(x_bullet[i],y_bullet[i]);
        color(14,0);
        printf("%c",bullet[i]);
    }
}
void print_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500])
{
    for(j=0; j<count_balloon; j++)
    {
        if(x_balloon[j]>57)continue;
        if(balloon[j]==32)continue;
        gotoXY(x_balloon[j],y_balloon_t[j]);
        if(balloon[j]=='O')color(7,0);
        else color(4,0);
        printf("%c",balloon[j]);
    }
}

void erase_balloon_s(int x_balloon[500],char balloon[500])
{
    for(j=0; j<count_balloon; j++)
    {
        if(x_balloon[j]==x_base&&y_balloon==54)continue;
        if(balloon[j]==32);
        gotoXY(x_balloon[j],y_balloon);
        printf(" ");

    }
}
void erase_bullet(int x_bullet[500],int y_bullet[500],int bullet[500])
{
    for(i=0; i<count_bullet; i++)
    {
        if(y_bullet[i]<1)continue;
        if(bullet[i]==32)continue;
        gotoXY(x_bullet[i],y_bullet[i]);
        printf(" ");
        y_bullet[i]--;
    }
}
void erase_balloon_t(int x_balloon[500],int y_balloon_t[500],char balloon[500])
{
    for(j=0; j<count_balloon; j++)
    {
        if(x_balloon[j]>57)continue;
        if(balloon[j]==32);
        gotoXY(x_balloon[j],y_balloon_t[j]);
        printf(" ");
        x_balloon[j]++;

    }
}

void hit_balloon_s(int x_balloon[500],int x_bullet[500],int y_bullet[500],char balloon[500],int bullet[500])
{
    for(i=0; i<count_bullet; i++)
    {
        if(y_bullet[i]<1)continue;
        for(j=0; j<count_balloon; j++)
        {
            if(x_balloon[j]==x_bullet[i]&&y_bullet[i]<=y_balloon&&(balloon[j]=='O'||balloon[j]==3||balloon[j]==2||balloon[j]==1||balloon[j]==15)&&bullet[i]==18)
            {
                gotoXY(x_bullet[i],y_bullet[i]);
                audio();
                if(balloon[j]=='O')
                {
                    score_s++;
                    life_ctrl++;
                }
                if(balloon[j]==3)life++;
                if(balloon[j]==2)score_s=score_s+5;
                if(balloon[j]==15)game_over(1);
                if(balloon[j]==1)score_s=score_s-10;
                balloon[j]=32;
                bullet[i]=32;
            }
        }
    }
}

void hit_balloon_t(int x_balloon[500],int y_balloon_t[500],int x_bullet[500],int y_bullet[500],char balloon[500],int bullet[500])
{
    for(i=0; i<count_bullet; i++)
    {
        if(y_bullet[i]<1)continue;
        for(j=0; j<count_balloon; j++)
        {
            if(x_balloon[j]>57)continue;
            if(x_balloon[j]==x_bullet[i]&&bullet[i]==18&&(balloon[j]=='O'||balloon[j]==15)&&(y_bullet[i]==y_balloon_t[j]||y_balloon_t[j]+1==y_bullet[i]))
            {
                gotoXY(x_bullet[i],y_bullet[i]);
                audio();
                if(balloon[j]==15)game_over(2);
                score_t++;
                balloon[j]=32;
                bullet[i]=32;

            }
        }
    }
}
void game_over(int I)
{
    system("cls");
    color(13,0);
    printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c                                         %c\n",176,176);
    printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
    color(14,0);
    for(i=0; i<3; i++)
    {
        gotoXY(32,23);
        printf("         ");
        Sleep(300);
        gotoXY(32,23);
        printf("GAME OVER");
        Sleep(300);

    }
    if(I==1)high_score_s();
    if(I==2)high_score_t();
    gotoXY(32,23);
    color(11,0);
    if(I==1)printf("SCORE : %d",score_s);
    if(I==2)printf("SCORE : %d",score_t);
    Sleep(3000);
    g_over=0;
    system("cls");
    show_menu();
}
void show_high_score()
{
    char ch;
    int in=1;
    while(ch!=13)
    {
        system("cls");
        gotoXY(45,15);
        color(14,0);
        if(in==1)printf("%c%c%c%cTIME TRAP%c%c%c%c",176,176,176,176,176,176,176,176);
        else     printf("    Time Trap");
        gotoXY(45,16);
        if(in==2)printf("%cSTRIKE STRAIGHT%c",176,176);
        else     printf(" Strike Straight");
        gotoXY(45,17);
        if(in==3)printf("%c%c%c%c%c%cBACK%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176);
        else     printf("      Back\n");
        ch=getch();
        if(ch==72)
            in--;
        else if(ch==80)
            in++;
        if(in>3)
            in=1;
        else if(in==0)
            in=3;
    }
    system("cls");
    switch (in)
    {
    case 1:
        view_high_score_t();
        break;
    case 2:
        view_high_score_s();
        break;
    case 3:
        show_menu ();
        break;
    }
}
void loading()
{
    int i,j=5,k,l=14;
    char ar[]= {32,95,95,95,95,32,32,32,95,
                95,95,32,32,95,95,95,32,32,32,
                32,32,95,95,32,32,32,32,32,32,
                32,32,32,32,32,32,32,32,95,95,
                95,95,32,32,32,32,32,32,32,32,
                32,95,95,95,95,32,32,32,95,95,
                95,95,32,32,95,95,95,95,95,95,
                95,10,124,32,32,32,32,124,32,124,
                32,32,32,32,124,32,32,32,124,32,
                32,32,47,32,32,92,32,32,32,32,
                32,32,32,32,32,32,32,32,124,32,
                32,32,32,32,32,124,32,32,32,124,
                32,124,32,32,32,32,124,32,124,32,
                32,32,32,124,32,32,32,32,124,10,
                124,95,95,95,95,124,32,124,95,95,
                32,32,124,95,95,95,124,32,32,47,
                95,95,95,95,92,32,32,32,32,32,
                95,95,95,95,32,32,124,95,95,95,
                95,32,32,124,95,95,95,124,32,124,
                32,32,32,32,124,32,124,32,32,32,
                32,124,32,32,32,32,124,10,124,32,
                32,32,32,32,32,124,32,32,32,32,
                124,92,32,32,32,32,47,32,32,32,
                32,32,32,92,32,32,32,32,32,32,
                32,32,32,32,32,32,32,32,32,124,
                32,124,32,32,32,124,32,124,32,32,
                32,32,124,32,124,32,32,32,32,124,
                32,32,32,32,124,9,10,124,32,32,
                32,32,32,32,124,95,95,95,32,124,
                32,92,32,32,47,32,32,32,32,32,
                32,32,32,92,32,32,32,32,32,32,
                32,32,32,32,95,95,95,95,124,32,
                124,32,32,32,124,32,124,95,95,95,
                95,124,32,124,95,95,95,95,124,32,
                32,32,32,124,-99
               };
    gotoXY(25,15);
    for(i=0;; i++)
    {
        if(ar[i]==-99) break;
        putchar(ar[i]);
        if(ar[i]=='\n')printf("                         ");
    }
    Sleep(1000);
    for(i=0; i<70; i++)
    {   if(l%16!=0)color(l,0);
        gotoXY(25,15);
        for(k=0;; k++)
        {
            if(ar[k]==-99) break;
            putchar(ar[k]);
            if(ar[k]=='\n')printf("                         ");
        }
        if(i%2==0)l+=2;
        color(14,0);
        gotoXY(25+i,21);
        printf("%c",219);
        Sleep(120);
    }
    Sleep(1000);

}
void high_score_s()
{
    FILE *fp;
    fp=fopen("high_score_s.txt","rb");
    fscanf(fp,"%d",&H_s);
    if(H_s<score_s)
    {
        fp=fopen("high_score_s.txt","wb");
        H_s=score_s;
        fprintf(fp,"%d",H_s);
        color(11,0);
        gotoXY(32,23);
        printf("NEW HIGH SCORE");
        gotoXY(38,24);
        printf("%d",H_s);
        Sleep(3000);
        g_over=0;
        fclose(fp);
        system("cls");
        show_menu();
    }
    fclose(fp);
}
void high_score_t()
{
    FILE *fp;
    fp=fopen("high_score_t.txt","rb");
    fscanf(fp,"%d",&H_t);
    if(H_t<score_t)
    {
        fp=fopen("high_score_t.txt","wb");
        H_t=score_t;
        fprintf(fp,"%d",H_t);
        color(11,0);
        gotoXY(32,23);
        printf("NEW HIGH SCORE");
        gotoXY(38,24);
        printf("%d",H_t);
        Sleep(3000);
        g_over=0;
        system("cls");
        fclose(fp);
        show_menu();
    }
    fclose(fp);
}
void view_high_score_s()
{
    FILE *fp;
    int I;
    fp=fopen("high_score_s.txt","rb");
    fscanf(fp,"%d",&I);
    gotoXY(45,15);
    color(11,0);
    printf("HIGH SCORE");
    gotoXY(48,16);
    printf("%d",I);
    gotoXY(43,17);
    system("pause");
    fclose(fp);
    show_menu();
}
void view_high_score_t()
{
    FILE *fp;
    int I;
    fp=fopen("high_score_t.txt","rb");
    fscanf(fp,"%d",&I);
    color(11,0);
    gotoXY(45,15);
    printf("HIGH SCORE");
    gotoXY(48,16);
    printf("%d",I);
    gotoXY(43,17);
    system("pause");
    fclose(fp);
    show_menu();
}
void gotoXY(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void color(int B, int C)
{
    WORD wColor = ((C & 0x0F)<<4) + (B & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void audio()
{
    if(sound==77)printf(" ");
    else printf(" \a");
}


