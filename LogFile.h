//---------------------------------------------------------------------------
#ifndef LogFileH
#define LogFileH
//---------------------------------------------------------------------------
#include <Classes.hpp>  // ��� ������������� ����������� �++ ����� (AnsiString)
#include <stdio.h>	// files i/o
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------
class LogFile
{
protected:

private:

public:
        __fastcall LogFile(void);       // ����������� ������
        __fastcall ~LogFile();          // ���������� ������

        // ����������
        AnsiString Path;        // ���� � ����� � �����������
        AnsiString FileName;    // �������� ���-�����

        // �������
        bool Add(AnsiString String);    // ���������� ������ � ���
        bool Clear();   // �������� ���� ������� �� ����
};
//---------------------------------------------------------------------------
#endif
