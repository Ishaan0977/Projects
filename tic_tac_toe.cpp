#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
int temp[9];
class ttt
{
	public:
	char t[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int turn=0;
	int input;
	void print(void);
	bool get(void);
	void result(void);
	};
void ttt::print()
{
	for(int i =0;i<3;i++)
	{
		for(int j =0;j<3;j++)
		{
			cout<<"\t"<<t[i][j];
			}
		cout<<endl;
		}
	}
bool ttt::get()
{
	retry:
	print();
	if(turn!=9)
	{
		if(turn%2==0)
		{
			cout<<"Player 1's turn \n Symbol = O"<<endl;
			cin>>input;
			switch (input)
			{
				case 1 : t[0][0]='O';temp[turn]=1; break;
				case 2 : t[0][1]='O';temp[turn]=2;break;  
				case 3 : t[0][2]='O';temp[turn]=3;break; 
				case 4 : t[1][0]='O';temp[turn]=4;break; 
				case 5 : t[1][1]='O';temp[turn]=5;break; 
				case 6 : t[1][2]='O';temp[turn]=6;break; 
				case 7 : t[2][0]='O';temp[turn]=7;break; 
				case 8 : t[2][1]='O';temp[turn]=8;break; 
				case 9 : t[2][2]='O';temp[turn]=9;break;
				default : cout<<"Wrong input please try again"<<endl;
						getch();
						goto retry; 
				}
			turn++;
			}
		else if(turn%2!=0)
		{
			cout<<"Player 2's turn \n Symbol = X"<<endl;
			cin>>input;
			switch (input)
			{
				case 1 : t[0][0]='X';temp[turn]=1; break;
				case 2 : t[0][1]='X';temp[turn]=2;break;  
				case 3 : t[0][2]='X';temp[turn]=3;break; 
				case 4 : t[1][0]='X';temp[turn]=4;break; 
				case 5 : t[1][1]='X';temp[turn]=5;break; 
				case 6 : t[1][2]='X';temp[turn]=6;break; 
				case 7 : t[2][0]='X';temp[turn]=7;break; 
				case 8 : t[2][1]='X';temp[turn]=8;break; 
				case 9 : t[2][2]='X';temp[turn]=9;break;
				default : cout<<"Wrong input please try again"<<endl;
						getch();
						goto retry;
				}
			turn++;
			}
		system("cls");
		return true;
		}
	if(turn==9)
	{
		return false;
		}
	}
void ttt::result()
{
/*	if(t[0][0]==t[1][0]==t[2][0]=='O'
		|t[2][0]==t[2][1]==t[2][2]=='O'
		|t[2][2]==t[1][2]==t[0][2]=='O'
		|t[0][0]==t[0][1]==t[0][2]=='O'
		|t[0][0]==t[1][1]==t[2][2]=='O'
		|t[0][2]==t[1][1]==t[2][0]=='O')
	{
		cout<<"Player 1 is winner"<<endl;
		}
	}*/
//	if(t[0][0]==t[1][0]==t[2][0])
//	cout<<"Working";
	for(int i=0;i<9;i++)
	{   
		if(temp[i]==1&&temp[i]==2&&temp[i]==3)
		{
			cout<<"working"<<endl;             
		}
		i++;
		}
	}
int main()
{
	ttt obj;
//	obj.print();
	while(obj.get())
	{
		obj.get();
		}
	for(int i=0;i<9;i++)
	cout<<temp[i]<<endl;
	obj.result();
	return 0;
	}
	
