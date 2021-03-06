#include "stdafx.h"
#include "KxExplorer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString exepath = QApplication::instance()->applicationDirPath();
	QString respath = exepath + "/../";
	respath = QDir::cleanPath(respath);	
	KResource::addSearchPath("res", respath);
	KResource::addSearchPath("res", exepath);

	QString dllpath = KUtility::osExeInstancePath() + "\\imageformats";
	KUtility::CopyVS2008ManifestFiles(dllpath);

	KXmlUI::initSkin("res:/Resources/layout/skins.xml");

	/*MessageBox界面*/
	KMessageBox::setBackgroundColor(QColor(70,185,240));
	KMessageBox::setFrameImage("qrcimg:/Resources/image/frameimage.png");
	KMessageBox::setMaskImage("qrcimg:/Resources/image/maskimage.png");
	KMessageBox::setMaskMargins(QMargins(0,0,0,0));
	KMessageBox::setButtonImage("qrcimg:/Resources/image/msgboxbtn1.png|qrcimg:/Resources/image/msgboxbtn2.png|qrcimg:/Resources/image/msgboxbtn3.png");
	KMessageBox::setCloseButtonImage("qrcimg:/Resources/image/loginclose_normal.png|qrcimg:/Resources/image/loginclose_hover.png|qrcimg:/Resources/image/loginclose_down.png");
	KMessageBox::setQuestionSymbol("qrcimg:/Resources/image/msgquestion.png");
	KMessageBox::setWarningSymbol("qrcimg:/Resources/image/msgwarning.png");
	KMessageBox::setInfomationSymbol("qrcimg:/Resources/image/msginfomation.png");
	KMessageBox::setCriticalSymbol("qrcimg:/Resources/image/msgwarning.png");

	KxExplorer explorer;
	QMetaObject::invokeMethod(&explorer, "execute", Qt::QueuedConnection);
	int retval = a.exec();
	return retval;
}