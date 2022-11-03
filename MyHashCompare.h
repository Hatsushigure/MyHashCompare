/**********************************************************************
**
** MyHashCompare.h
** Copyright (C) 2022-2022 Hatsushigure
**
** This file contains the definitions of the application's main class.
** Global variants, constants, and global functions will also be
** included in the class' public part.
** For example, use MyHashCompare::theApp to access the app itself.
**
**********************************************************************/

#pragma once
#include <QApplication>

class MainWindow;
class MyHashCalcThread;

class MyHashCompare : public QApplication
{
	Q_OBJECT
public:
	//Global variants
	static MyHashCompare* theApp;
	static MainWindow* mainWindow;
	static MyHashCalcThread* lMD5Thread;
	static MyHashCalcThread* rMD5Thread;
	static MyHashCalcThread* lSHA1Thread;
	static MyHashCalcThread* rSHA1Thread;
	static MyHashCalcThread* lSHA256Thread;
	static MyHashCalcThread* rSHA256Thread;
public:
	MyHashCompare(int argc, char *argv[]);
	//Initialize all threads
	void initThread();
	//Initialize mainWindow
	void initMainWindow();
};

