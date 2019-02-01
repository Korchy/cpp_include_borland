//---------------------------------------------------------------------------
#ifndef OptionsH
#define OptionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>  // ��� ������������� ����������� �++ ����� (AnsiString)
//---------------------------------------------------------------------------
class Options
{
protected:

private:

public:
        __fastcall Options(void);       // ����������� ������
        __fastcall ~Options();          // ���������� ������

        // ����������
        AnsiString File;                // ���� � ����� � �����������
        struct DataStruc {              // ��������� � ������� �� ����������
                AnsiString Name;
                AnsiString Value;
                AnsiString Comment;
                DataStruc* pr;
        };
        DataStruc* Data;                // ��������� �� ��������� � �������

        // �������
        bool Load();                                            // ������� ������ �� ����� � ���������
        bool Save();                                            // ���������� ������ � �����
        AnsiString FindByName(AnsiString Name);                 // �������� �������� �� �������� �� ��� �����
        void SetByName(AnsiString Name, AnsiString Value);      // ������� �������� � ��������� �� ��� �����

};
//---------------------------------------------------------------------------
#endif
