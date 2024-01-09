#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
//char t[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char t[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char turn ='X';
int i,j,r=1,c=1,input,draw=0,win=0;
class tic
{
	public:
	void intro();
	void linep();
	void symp();
	void print();
	int get();
	void display();
	void result();
	};
void tic::intro()   // For intro
{
		int gdriver = DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	for(i =3;i<7;i++)
	{
		setcolor(i);
		settextstyle(i,0,i);
		outtextxy(100,20*i,"Tic Tac Toe");
		delay(500);
		}
	setcolor(WHITE);
	settextstyle(6,0,2);
	outtextxy(100,350,"- Game By Ishaan");
	delay(2000);
	clrscr();
	}
void tic::linep() // For Printing lines
{
	int x1,x2,y1,y2;
	setcolor(15);
	x1=225,y1=150,x2=225,y2=400; // For first vertical line
	line(x1,y1,x2,y2);
	x1=125,y1=220,x2=475,y2=220; // For first horizontal line
	line(x1,y1,x2,y2);
	x1=375,y1=150,x2=375,y2=400; // For second vertical line
	line(x1,y1,x2,y2);
	x1=125,y1=320,x2=475,y2=320; // For second horizontal line
	line(x1,y1,x2,y2);
	}
void tic::symp()
{
	setcolor(11);
	settextstyle(3,0,5);
	if(t[0][0]=='X')
	outtextxy(170,155,"X"); //First Box
	if(t[0][1]=='X')
	outtextxy(290,155,"X"); //Second Box
	if(t[0][2]=='X')
	outtextxy(420,155,"X"); //Third Box
	if(t[1][0]=='X')
	outtextxy(170,245,"X"); //Fourth Box
	if(t[1][1]=='X')
	outtextxy(290,245,"X"); //Fifth Box
	if(t[1][2]=='X')
	outtextxy(420,245,"X"); //Sixth Box
	if(t[2][0]=='X')
	outtextxy(170,335,"X"); //Seventh Box
	if(t[2][1]=='X')
	outtextxy(290,335,"X"); //Eigth Box
	if(t[2][2]=='X')
	outtextxy(420,335,"X"); //Ninth Box
	setcolor(RED);
	if(t[0][0]=='O')
	outtextxy(170,155,"O"); //First Box
	if(t[0][1]=='O')
	outtextxy(290,155,"O"); //Second Box
	if(t[0][2]=='O')
	outtextxy(420,155,"O"); //Third Box
	if(t[1][0]=='O')
	outtextxy(170,245,"O"); //Fourth Box
	if(t[1][1]=='O')
	outtextxy(290,245,"O"); //Fifth Box
	if(t[1][2]=='O')
	outtextxy(420,245,"O"); //Sixth Box
	if(t[2][0]=='O')
	outtextxy(170,335,"O"); //Seventh Box
	if(t[2][1]=='O')
	outtextxy(290,335,"O"); //Eigth Box
	if(t[2][2]=='O')
	outtextxy(420,335,"O"); //Ninth Box

	}
void tic::print()
{
	int gdriver = DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
/*	setcolor(11);
	settextstyle(6,0,2);
	outtextxy(100,30,"Player - 1 [X]");
	setcolor(4);
	outtextxy(400,30,"Player - 2 [O]"); */
	linep();
	symp();
	display();
	/*while(get())
	{
		symp();
		display();
		}*/
	//get();
	}
int tic::get()
{
	print();
	linep();
	symp();
	if(turn=='X')
	{
		setcolor(11);
		//settextstyle(5,0,2);
		outtextxy(175,425,"Player 1's turn");
		}
	else
	{
		setcolor(RED);
		//settextstyle(5,0,2);
		outtextxy(175,425,"Player 2's turn");
		}
	input= getch();
	if(input==0)
	{
		input=getch();
		}
	switch (input)
	{
		case 72: if(r!=0) //Up arrow
				r--;
			break;
		case 80: if(r!=2) //Down arrow
				r++;
			break;
		case 75: if(c!=0) //Left arrow
				c--;
			break;
		case 77: if(c!=2) //Right arrow
				c++;
			break;
		case ' ':if(turn=='X' && t[r][c]!='X' && t[r][c]!='O')
				{
					t[r][c]='X';
					turn = 'O';
					}
			if(turn=='O' && t[r][c]!='O' && t[r][c]!='X')
				{
					t[r][c]='O';
					turn = 'X';
					}break;
		case 'e': cleardevice(); closegraph();
			 return 0;
		case 'E': cleardevice(); closegraph();
			 return 0;
		default : return 1;
		}
	return 1;
	}
void tic::display()
{
	cleardevice();
	setcolor(11);
	settextstyle(6,0,2);
	outtextxy(100,30,"Player - 1 [X]");
	setcolor(4);
	outtextxy(400,30,"Player - 2 [O]");
	linep();
	symp();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==r&&i==c)
			{
				if(turn=='X')
				{
					setcolor(11);
					if(r==0&&c==0)//1 Box
					circle(180,180,10);
					if(r==0&&c==1)//2
					circle(300,180,10);
					if(r==0&&c==2)//3
					circle(430,180,10);
					if(r==1&&c==0)//4
					circle(180,270,10);
					if(r==1&&c==1)//5
					circle(300,270,10);
					if(r==1&&c==2)//6
					circle(430,270,10);
					if(r==2&&c==0)//7
					circle(180,360,10);
					if(r==2&&c==1)//8
					circle(300,360,10);
					if(r==2&&c==2)//9
					circle(430,360,10);
				        }
				else
				{
					setcolor(RED);
					if(r==0&&c==0)//1 Box
					circle(180,180,10);
					if(r==0&&c==1)//2
					circle(300,180,10);
					if(r==0&&c==2)//3
					circle(430,180,10);
					if(r==1&&c==0)//4
					circle(180,270,10);
					if(r==1&&c==1)//5
					circle(300,270,10);
					if(r==1&&c==2)//6
					circle(430,270,10);
					if(r==2&&c==0)//7
					circle(180,360,10);
					if(r==2&&c==1)//8
					circle(300,360,10);
					if(r==2&&c==2)//9
					circle(430,360,10);
					}
			}
		}
	}
}
void tic::result()
{
	for(i=0;i<3;i++)
	{
		if(t[0][i]==t[1][i]&&t[1][i]==t[2][i] || t[i][0]==t[i][1] && t[i][1]==t[i][2])
			win= 1;
		}
	if(t[0][0]==t[1][1] && t[1][1] == t[2][2] || t[0][2]==t[1][1] && t[1][1]==t[0][0])
		win=1;
	/*for(i=0;i<3;i++)
	    {
		for(j=0;j<3;j++)
		{
			if(t[i][j]!='' && t[i][j]!='')
			  {
				draw++;

			}
		}*/

	}
int main()
{
	tic obj;
	clrscr();
	//obj.intro();
        //	cout<<"\t\t\tTic Tac Toe\n";
        //	obj.print();
        //obj.display();
        obj.print();
        while(obj.get())
	{
		obj.linep();
		obj.symp();
		obj.result();
		if(win==1&&draw==0)
		{
			if(turn=='O')
			  {
				cleardevice();
				closegraph();
				//cleardevice();
				cout<<"Working";
				}
			if(turn=='X')
			{
				cleardevice();
				closegraph;
				//cleardevice();
				cout<<"working";
				}
			}
		}

        /*	again1:
	if(turn=='X' && draw==0)
	{
		cout<<"Player 2 win's"<<endl;
			}
	else if(turn=='O' && draw==0)
	{
		cout<<"Player 1 win's"<<endl;
		}
	else if(draw==1)
	{
		   cout<<"Game draw \n\n";
		   }  */
	//cout<<"Press 0 for exit \n\n Press 1 for Rematch"<<endl;
	/*cin>>ex;
	switch (ex)
	{
		case 0 : cout<<"Working";break;
		case 1 : cout<<"working";goto rem;
		default: cout<<"Wrong input please try again"; getch(); goto again1; ;
		}*/
	getch();
	return 0;
	}