#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;
#include"2015595_Thuvien.h"
#include"2015595_Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
    LIST list;
    int menu, soMenu = 5;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, list);
    } while (menu > 0);
    _getch();
}
