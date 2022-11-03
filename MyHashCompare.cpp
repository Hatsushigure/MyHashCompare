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
#include "MyHashCalcThread.h"

MyHashCompare* MyHashCompare::theApp = nullptr;
MainWindow* MyHashCompare::mainWindow = nullptr;
MyHashCalcThread* MyHashCompare::lMD5Thread;
MyHashCalcThread* MyHashCompare::rMD5Thread;
MyHashCalcThread* MyHashCompare::lSHA1Thread;
MyHashCalcThread* MyHashCompare::rSHA1Thread;
MyHashCalcThread* MyHashCompare::lSHA256Thread;
MyHashCalcThread* MyHashCompare::rSHA256Thread;

MyHashCompare::MyHashCompare(int argc, char* argv[])
	: QApplication(argc, argv)
{
	initThread();
	initMainWindow();
}

//Initialize all threads
void MyHashCompare::initThread()
{
	lMD5Thread = new MyHashCalcThread(QCryptographicHash::Md5);
	rMD5Thread = new MyHashCalcThread(QCryptographicHash::Md5);
	lSHA1Thread = new MyHashCalcThread(QCryptographicHash::Sha1);
	rSHA1Thread = new MyHashCalcThread(QCryptographicHash::Sha1);
	lSHA256Thread = new MyHashCalcThread(QCryptographicHash::Sha256);
	rSHA256Thread = new MyHashCalcThread(QCryptographicHash::Sha256);
}

//Initialize mainWindow
void MyHashCompare::initMainWindow()
{
	mainWindow = new MainWindow;
	mainWindow->show();
}
