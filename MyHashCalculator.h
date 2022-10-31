/**********************************************************************
**
** MyHashCalculator.h
** Copyright (C) 2022-2022 Hatsushigure
**
** This file defines the calculator class, which is based on QObject to
** be moved to a new thread and prevent the widget from being stuck.
** All methods are called using signals and slots.
**
**********************************************************************/

#pragma once
#include <QObject>

class MyHashCalculator : public QObject
{
	Q_OBJECT
public:
	typedef enum {MD5, SHA1, SHA256} HashType;
public:
	explicit MyHashCalculator(QObject *parent = nullptr);
signals:
	void finished(MyHashCalculator::HashType finishType, QByteArray decData);
public slots:
	//Calculates the hash. Make sure the file exists!
	void calc(HashType calcType, const QString& fileName);
};

