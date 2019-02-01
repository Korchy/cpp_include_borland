//---------------------------------------------------------------------------
#ifndef OptionsH
#define OptionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>  // Для использования стандартных С++ типов (AnsiString)
//---------------------------------------------------------------------------
class Options
{
protected:

private:

public:
        __fastcall Options(void);       // Конструктор класса
        __fastcall ~Options();          // Деструктор класса

        // Переменные
        AnsiString File;                // Путь к файлу с настройками
        struct DataStruc {              // Структура с данными по настройкам
                AnsiString Name;
                AnsiString Value;
                AnsiString Comment;
                DataStruc* pr;
        };
        DataStruc* Data;                // Указатель на структуру с данными

        // Функции
        bool Load();                                            // Зарузка данных из файла в структуру
        bool Save();                                            // Сохранение данных в файле
        AnsiString FindByName(AnsiString Name);                 // Получить значение из настроек по его имени
        void SetByName(AnsiString Name, AnsiString Value);      // Занести значение в настройки по его имени

};
//---------------------------------------------------------------------------
#endif
