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
bool LogFile::Add(AnsiString String)
{
        // ���������� ������ � ���
if(String!="") {
        TStringList* Log = new TStringList();
        if(FileExists(Path+"\\"+FileName+".log")==true) Log->LoadFromFile(Path+"\\"+FileName+".log");
        else Log->Clear();
        Log->Add(DateToStr(Date()) + ":" + TimeToStr(Time()) + " " + String);
        Log->SaveToFile(Path+"\\"+FileName+".log");
        delete Log;
        }
return true;
}
//---------------------------------------------------------------------------
bool LogFile::Clear()
{
        // �������� ���� ������� �� ����
TStringList* Log = new TStringList();
Log->Clear();
Log->SaveToFile(Path+"\\"+FileName+".log");
delete Log;
return true;
}
//---------------------------------------------------------------------------
