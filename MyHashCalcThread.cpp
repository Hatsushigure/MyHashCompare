/**********************************************************************
**
** MyHashCalcThread.cpp
** Copyright (C) 2022-2022 Hatsushigure
**
** The thread used to calculate hash
**
**********************************************************************/

#include "MyHashCalcThread.h"
#include <QFile>
#include <QDebug>

MyHashCalcThread::MyHashCalcThread(QCryptographicHash::Algorithm algo, const QString& fileName, QObject *parent)
	: QThread{parent},
	  m_fileName(fileName)
{
	m_hasher = new QCryptographicHash(algo);
}

MyHashCalcThread::~MyHashCalcThread()
{
	delete m_hasher;
}

//Overrides the run function
void MyHashCalcThread::run()
{
	QByteArray hexRet;
	QFile file(m_fileName);

	//Check whether the file can be opened
	if (!file.exists() || file.open(QFile::ReadOnly))
	{
		qDebug() << "The file to be hashed cannot be opened!";
		hexRet.clear();
		file.close();
	}

	file.close();
	m_hasher->addData(&file);
	hexRet = m_hasher->result().toHex().toUpper();

	emit resultReady(hexRet);
}
