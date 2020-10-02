//---------------------------------------------------------------------------
#pragma hdrstop

#include "LogFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall LogFile::LogFile(void)
{
        // ����������� ������
FileName = "Log";
Path = "c:";
}
//---------------------------------------------------------------------------
__fastcall LogFile::~LogFile()
{
        // ���������� ������

}
//---------------------------------------------------------------------------
bool LogFile::Add(AnsiString String) {
        // ���������� ������ � ���
std::ofstream LogPtr;
LogPtr.open((Path+"\\"+FileName+".log").c_str(), std::ios::app); // append instead of overwrite
LogPtr << (DateToStr(Date()) + ":" + TimeToStr(Time()) + " " + String + "\r").c_str();
return true;
}
//---------------------------------------------------------------------------
bool LogFile::Clear() {
        // �������� ���� ������� �� ����
std::ofstream LogPtr;
LogPtr.open((Path+"\\"+FileName+".log").c_str(), std::ofstream::out | std::ofstream::trunc);
LogPtr.close();
return true;
}
//---------------------------------------------------------------------------
