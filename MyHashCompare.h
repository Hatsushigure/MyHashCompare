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

class MyHashCompare : public QApplication
{
	Q_OBJECT
public:
	//Global variants
	static MyHashCompare* theApp;
	static MainWindow* mainWindow;
public:
	MyHashCompare(int argc, char *argv[]);
	//Initialize mainWindow
	void initMainWindow();
};

