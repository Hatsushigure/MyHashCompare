/**********************************************************************
**
** MyHashCalcThread.h
** Copyright (C) 2022-2022 Hatsushigure
**
** The thread used to calculate hash
**
**********************************************************************/

#pragma once
#include <QThread>
#include <QCryptographicHash>

class MyHashCalcThread : public QThread
{
	Q_OBJECT
private:
	QString m_fileName;
	QCryptographicHash* m_hasher;
	QByteArray m_result;
public:
	MyHashCalcThread(QCryptographicHash::Algorithm algo, const QString& fileName = "", QObject *parent = nullptr);
	~MyHashCalcThread();
	QByteArray hexRet() const {return m_result;}
	void setFileName(const QString& fileName) {m_fileName = fileName;}
	//Overrides the run function
	void run() override;
signals:
	void resultReady(QByteArray hexRet);
};

