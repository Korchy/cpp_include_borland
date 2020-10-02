//---------------------------------------------------------------------------
#pragma hdrstop

#include "LogFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall LogFile::LogFile(void)
{
        // Конструктор класса
FileName = "Log";
Path = "c:";
}
//---------------------------------------------------------------------------
__fastcall LogFile::~LogFile()
{
        // Деструктор класса

}
//---------------------------------------------------------------------------
bool LogFile::Add(AnsiString String) {
        // Добавление строки в ЛОГ
std::ofstream LogPtr;
LogPtr.open((Path+"\\"+FileName+".log").c_str(), std::ios::app); // append instead of overwrite
LogPtr << (DateToStr(Date()) + ":" + TimeToStr(Time()) + " " + String + "\r").c_str();
return true;
}
//---------------------------------------------------------------------------
bool LogFile::Clear() {
        // Удаление всех записей из ЛОГа
std::ofstream LogPtr;
LogPtr.open((Path+"\\"+FileName+".log").c_str(), std::ofstream::out | std::ofstream::trunc);
LogPtr.close();
return true;
}
//---------------------------------------------------------------------------
