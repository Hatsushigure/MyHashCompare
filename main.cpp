/**********************************************************************
**
** Compressed main.cpp file
** Copyright (C) 2022-2022 Hatsushigure
**
** This file would never be changed once created
**
**********************************************************************/

#include "MyHashCompare.h"

int main(int argc, char *argv[])
{
	MyHashCompare::theApp = new MyHashCompare(argc, argv);
	return MyHashCompare::theApp->exec();
}
