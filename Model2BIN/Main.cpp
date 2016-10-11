#include "MainForm.h"                    //            The header file of the form
using namespace Model2BIN;            //            The name of the namespace in MyForm.h
[STAThreadAttribute]                   //            Run this program in STA mode
int main() {
	MainForm fm;                     //            The form to be created and shown
	fm.ShowDialog();             //            Show the form
	return 0;
}