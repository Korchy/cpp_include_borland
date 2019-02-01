//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall Options::Options(void) {
        // Конструктор класса
File = "";
Data = NULL;
}
//---------------------------------------------------------------------------
__fastcall Options::~Options() {
        // Деструктор класса
        // Удаляем все структуры из списка настроек
while(Data!=NULL) {
        DataStruc* TmpStruc = Data->pr;
        delete Data;
        Data = TmpStruc;
        }
}
//---------------------------------------------------------------------------
bool Options::Load() {
        // Загрузка данных из файла
if(File=="") return false;
        // Получить данные из файла
TStringList *DataFile = new TStringList();
DataFile->LoadFromFile(File);
        // Загрузить их в структуру
DataStruc* TmpStruc1,* TmpStruc2;
for(int i=0; i<DataFile->Count; i++) {
        TmpStruc1 = new DataStruc();
        TmpStruc1->Name = DataFile->Strings[i].SubString(1,DataFile->Strings[i].Pos("=")-1);
        TmpStruc1->Value = DataFile->Strings[i].SubString(DataFile->Strings[i].Pos("=")+1,DataFile->Strings[i].Pos(";")-DataFile->Strings[i].Pos("=")-1);
        TmpStruc1->Comment = DataFile->Strings[i].SubString(DataFile->Strings[i].Pos(";"),DataFile->Strings[i].Length());
        TmpStruc1->pr = NULL;
        if(Data==NULL) Data = TmpStruc1;
        else TmpStruc2->pr = TmpStruc1;
        TmpStruc2 = TmpStruc1;
        }
        // Удалим файл с данными
delete DataFile;
return true;
}
//---------------------------------------------------------------------------
bool Options::Save() {
        // Сохранение данных в файл
if(File=="") return false;
        // Создать файл с данными
TStringList *DataFile = new TStringList();
DataFile->Clear();
        // Загрузить в него данные из структуры
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        DataFile->Add(TmpStruc->Name + "=" + TmpStruc->Value + TmpStruc->Comment);
        TmpStruc = TmpStruc->pr;
        }
        // Записать файл на диск
DataFile->SaveToFile(File);
        // Удалим файл с данными
delete DataFile;
return true;
}
//---------------------------------------------------------------------------
AnsiString Options::FindByName(AnsiString Name) {
        // Получить значение по имени
if(Data==NULL) return "";
        // Возвращаемое значение
AnsiString Rez = "";
        // Пробежать по всем структурам, проверяя имена
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        if(TmpStruc->Name==Name) {
                // Если это нужное - получить значение
                Rez = TmpStruc->Value;
                break;
                }
        TmpStruc = TmpStruc->pr;
        }
        // Возврат знайденного значения
return Rez;
}
//---------------------------------------------------------------------------
void Options::SetByName(AnsiString Name, AnsiString Value) {
        // Записать значение по его имени
if(Data==NULL) return;
        // Пробежать по всем структурам, проверяя имена
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        if(TmpStruc->Name==Name) {
                // Если это нужное - занести значение
                TmpStruc->Value = Value;
                break;
                }
        TmpStruc = TmpStruc->pr;
        }
}
//---------------------------------------------------------------------------

