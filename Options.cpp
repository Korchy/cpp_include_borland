//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall Options::Options(void) {
        // ����������� ������
File = "";
Data = NULL;
}
//---------------------------------------------------------------------------
__fastcall Options::~Options() {
        // ���������� ������
        // ������� ��� ��������� �� ������ ��������
while(Data!=NULL) {
        DataStruc* TmpStruc = Data->pr;
        delete Data;
        Data = TmpStruc;
        }
}
//---------------------------------------------------------------------------
bool Options::Load() {
        // �������� ������ �� �����
if(File=="") return false;
        // �������� ������ �� �����
TStringList *DataFile = new TStringList();
DataFile->LoadFromFile(File);
        // ��������� �� � ���������
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
        // ������ ���� � �������
delete DataFile;
return true;
}
//---------------------------------------------------------------------------
bool Options::Save() {
        // ���������� ������ � ����
if(File=="") return false;
        // ������� ���� � �������
TStringList *DataFile = new TStringList();
DataFile->Clear();
        // ��������� � ���� ������ �� ���������
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        DataFile->Add(TmpStruc->Name + "=" + TmpStruc->Value + TmpStruc->Comment);
        TmpStruc = TmpStruc->pr;
        }
        // �������� ���� �� ����
DataFile->SaveToFile(File);
        // ������ ���� � �������
delete DataFile;
return true;
}
//---------------------------------------------------------------------------
AnsiString Options::FindByName(AnsiString Name) {
        // �������� �������� �� �����
if(Data==NULL) return "";
        // ������������ ��������
AnsiString Rez = "";
        // ��������� �� ���� ����������, �������� �����
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        if(TmpStruc->Name==Name) {
                // ���� ��� ������ - �������� ��������
                Rez = TmpStruc->Value;
                break;
                }
        TmpStruc = TmpStruc->pr;
        }
        // ������� ����������� ��������
return Rez;
}
//---------------------------------------------------------------------------
void Options::SetByName(AnsiString Name, AnsiString Value) {
        // �������� �������� �� ��� �����
if(Data==NULL) return;
        // ��������� �� ���� ����������, �������� �����
DataStruc* TmpStruc = Data;
while(TmpStruc!=NULL) {
        if(TmpStruc->Name==Name) {
                // ���� ��� ������ - ������� ��������
                TmpStruc->Value = Value;
                break;
                }
        TmpStruc = TmpStruc->pr;
        }
}
//---------------------------------------------------------------------------

