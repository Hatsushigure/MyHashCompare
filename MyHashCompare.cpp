/**********************************************************************
**
** MyHashCompare.cpp
** Copyright (C) 2022-2022 Hatsushigure
**
** The cpp file of the main class.
** All static members SHOULD be defined here.
**
**********************************************************************/

#include "MyHashCompare.h"
#include "MainWindow.h"

MyHashCompare* MyHashCompare::theApp = nullptr;
MainWindow* MyHashCompare::mainWindow = nullptr;

MyHashCompare::MyHashCompare(int argc, char* argv[])
	: QApplication(argc, argv)
{
	initMainWindow();
}

//Initialize mainWindow
void MyHashCompare::initMainWindow()
{
	mainWindow = new MainWindow;
	mainWindow->show();
}
