/* Alarm app.cpp : Program to run the program as an alarm by setting the time and selecting a song for the alarm tone
This program is to be customized by the user as the paths will vary from one person to another person's systems
pdb files are required to run this program. 

For downloading them automatically in Microsoft Visual Studio, 
go to Tools->Options->Debugging->Symbols and select checkbox "Microsoft Symbol Servers", 
Visual Studio will download PDBs automatically. PDB is a debug information file used by Visual Studio.

In case of error : argument of type "char *" is incompatible with parameter of type "LPCWSTR" in Microsoft Visual Studio,
go to Project -> Properties -> General -> Character Set option to Use Multi-Byte Character Set
*/
#include "stdafx.h"		//for running the program in Visual Studio. Remove the line to run the program in other compilers
#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <Mmsystem.h>
#include <string>
#include <mciapi.h>
#include <cstdlib>

#pragma comment(lib, "Winmm.lib")
using namespace std;


int main() {
	const char *filename[100] = { "path_1", "path_2", "path_3", "path_4", "path_5" };	//Path format.: (Drive_name):\\(Directory, if any)\\file_name.mp3 Change the contents within the bracket and then remove the brackets 
	const char *appname = "C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe";			//Typical path to VLC media player in Windows 10. Edit in case of different OS
	cout << "Song List : " << endl;
	cout << "Song 1 : song_1" << endl;
	cout << "Song 2 : song_2" << endl;
	cout << "Song 3 : song_3" << endl;
	cout << "Song 4 : song_4" << endl;
	cout << "Song 5 : song_5" << endl;
	int choice;
	cout << "Enter song choice : ";						//Determines the choice from the above user list
	cin >> choice;
	cout << endl;
	cout << "Enter the amount of time before the alarm runs : ";
	int n;							//For pausing the program. Enter time in seconds. eg: 30 minutes = 1800 secs. Therefore enter 1800 as the input
	cin >> n;
	Sleep(n*1000);
	
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	memset(&pi, 0, sizeof(pi));

	char buf[MAX_PATH + 300];
	wsprintfA(buf, "%s \"%s\" --play-and-exit", appname, filename[choice]);
	CreateProcessA(0, buf, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		
	return 0;
}
