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
#include "MyHashCalculator.h"
#include <QThread>

MyHashCompare* MyHashCompare::theApp = nullptr;
MainWindow* MyHashCompare::mainWindow = nullptr;
MyHashCalculator* MyHashCompare::hashCalculator = nullptr;
QThread* MyHashCompare::calcThread = nullptr;

MyHashCompare::MyHashCompare(int argc, char* argv[])
	: QApplication(argc, argv)
{
	initMainWindow();
	initCalcThread();
	initCalcThread();
}

//Initialize mainWindow
void MyHashCompare::initMainWindow()
{
	mainWindow = new MainWindow;
	mainWindow->show();
}

//Initialize the calculator thread
void MyHashCompare::initCalcThread()
{
	calcThread = new QThread(this);
}

//Initialize the calculator
void MyHashCompare::initCalculator()
{
	hashCalculator = new MyHashCalculator;
	hashCalculator->moveToThread(calcThread);
}
