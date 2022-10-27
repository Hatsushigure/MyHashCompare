#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QFileDialog>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_lastVisitedDir = QDir::homePath();

	initConnections();
}

MainWindow::~MainWindow()
{
	delete ui;
}

//Connect all signal and slots
void MainWindow::initConnections()
{
	connect(ui->actionOpenLeft, &QAction::triggered, this, &MainWindow::onOpenLeftFile);
	connect(ui->actionOpenRight, &QAction::triggered, this, &MainWindow::onOpenRightFile);
	connect(ui->actionCalc, &QAction::triggered, this, &MainWindow::onCalcHash);
}

void MainWindow::onOpenLeftFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "打开左侧文件", m_lastVisitedDir, "所有文件(*);;aaa(*.aaa)");
	if (!QFile::exists(fileName))
		return;
	m_leftFile.setFileName(fileName);
	qDebug() << m_leftFile.fileName();
	QFileInfo info(m_leftFile);
	m_lastVisitedDir = info.dir().path();
}

void MainWindow::onOpenRightFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "打开右侧文件", m_lastVisitedDir, "所有文件(*);;aaa(*.aaa)");
	if (!QFile::exists(fileName))
		return;
	m_rightFile.setFileName(fileName);
	qDebug() << m_rightFile.fileName();
	QFileInfo info(m_rightFile);
	m_lastVisitedDir = info.dir().path();
}

void MainWindow::onCalcHash()
{
	if(!m_leftFile.exists() || !m_rightFile.exists())
	{
		qDebug() << "At least a file does not exist";
		return;
	}
	m_leftFile.open(QFile::ReadOnly);
	m_rightFile.open(QFile::ReadOnly);
	QByteArray lSHA256 = QCryptographicHash::hash(m_leftFile.readAll(), QCryptographicHash::Sha256);
	QByteArray rSHA256 = QCryptographicHash::hash(m_rightFile.readAll(), QCryptographicHash::Sha256);
	m_leftFile.close();
	m_rightFile.close();
	ui->leftSHA256Edit->setText(lSHA256.toHex());
	ui->rightSHA256Edit->setText(rSHA256.toHex());
	if (lSHA256 == rSHA256)
		ui->SHA256Status->setText("<span style=\"color:green;font-size:14pt;\">√</span>");
	else
		ui->SHA256Status->setText("<span style=\"color:red;font-size:14pt;\">×</span>");
}

