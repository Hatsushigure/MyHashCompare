/**********************************************************************
**
** MyHashCalculator.cpp
** Copyright (C) 2022-2022 Hatsushigure
**
** The cpp file of the calculator class.
**
**********************************************************************/

#include "MyHashCalculator.h"
#include <QFile>
#include <QCryptographicHash>

MyHashCalculator::MyHashCalculator(QObject *parent)
	: QObject{parent}
{

}

//Calculates the hash. Make sure the file exists!
void MyHashCalculator::calc(HashType calcType, const QString& fileName)
{
	QFile tmpFile(fileName);
	QByteArray hash;
	switch (calcType)
	{
	case HashType::MD5:
		tmpFile.open(QFile::ReadOnly);
		hash = QCryptographicHash::hash(tmpFile.readAll(), QCryptographicHash::Md5).toHex();
		break;
	default:
		break;
	}
	emit finished(calcType, hash);
}
