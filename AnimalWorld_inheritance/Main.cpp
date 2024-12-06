#pragma once
//#include "Being.h"
//#include "Fox.h"
//#include "Rabbit.h"
//#include "Plant.h"
//#include "Predator.h"
#include "AnimalWorld.h"

//#define gotoxy(x,y) SetConsoleCursorPosition(hStdOut, { x,y })

//void gotoxy(HANDLE hConsole, int x, int y)
//{
//    SetConsoleCursorPosition(hConsole, { (short)x, (short)y });
//}

int main()
{    
    /*HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    srand(time(0));
    AnimalWorld aw(hStdOut, gotoxy);*/
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    srand(time(0));
    AnimalWorld aw;
    aw.RunEmulation();

    return 0;

}
//   //std::wcout << L"Лиса 🦊🌳" << std::endl; 
 //   wchar_t animal[3];
 //  
 //   wchar_t fox[] = { 0xD83E, 0xDD8A, 0 }; // суррогатные пара U+1F98A
 //   system("cls");
 //   std::wcout << L"Лиса (через суррогатные пары) " << fox << std::endl; 
 //   uint32_t ch = 0x1F900;
 //   //U +  – U + 1F9FF
 //   for (int i = 0; i < 255; i++)
 //   {	
	//convertToSurrogate(ch, animal);ch++;
 //   }
 //   ch = 0x1F400;
 //   for (int i = 0; i < 255; i++)
 //   {
	//convertToSurrogate(ch, animal); ch++;
 //   }
 //   ch = 0x2600; 
 //   for (int i = 0; i < 255; i++)
 //   {
	//convertToSurrogate(ch, animal); ch++;
 //   }
 //   ch = 0x2700;
 //   for (int i = 0; i < 255; i++)
 //   {
	//convertToSurrogate(ch, animal); ch++;
 //   }
 //   ch = 0x1F200;
 //   for (int i = 0; i < 255; i++)
 //   {
	//convertToSurrogate(ch, animal); ch++;
 //   }
 //   ch = 0x1F700;
 //   for (int i = 0; i < 255; i++)
 //   {
	//convertToSurrogate(ch, animal); ch++;
 //   }
 //  // U +  – U + 1F4FF
 //   //convertToSurrogate(0x1F33F, animal);
 //   std::wcin.get();


//void convertToSurrogate(uint32_t ch, wchar_t var[3])
//{
//    if (ch < 0x10000 || ch >0x10ffff)
//    {
//	wcerr << L"недопустимый диапазон кодовой точки";
//	return;
//    }
//
//    uint32_t primary_code = ch - 0x10000;
//    //0xD800 + (uPrime >> 10);
//    wchar_t high_surr = 0xD800 + (primary_code >> 10); // 10 старших бит
//    wchar_t low_surr = 0xDC00 + (primary_code & 0x3ff); // 10 младших бит
//    /* wchar_t highSurrogate = 0xD800 + (primary_code >> 10);
//     wchar_t lowSurrogate = 0xDC00 + (primary_code & 0x3FF);*/
//    var[0] = high_surr;
//    var[1] = low_surr;
//    var[2] = 0;
//    wchar_t v[] = { high_surr, low_surr, 0 };
//    wcout << v;
//}
///*
//🐶	Собака	U+1F436
//🐱	Кошка	U+1F431
//🐭	Мышь	U+1F42D
//🐹	Хомяк	U+1F439
//🐰	Кролик	U+1F430
//🦊	Лиса	U+1F98A
//🐻	Медведь	U+1F43B
//🐼	Панда	U+1F43C
//🐨	Коала	U+1F428
//🐯	Тигр	U+1F42F
//🦁	Лев	U+1F981
//🐮	Корова	U+1F42E
//🐷	Свинья	U+1F437
//🐸	Лягушка	U+1F438
//🐵	Обезьяна	U+1F435
//🦓	Зебра	U+1F993
//🦒	Жираф	U+1F992
//🐘	Слон	U+1F418
//🦏	Носорог	U+1F98F
//🦛	Бегемот	U+1F99B
//🐪	Верблюд	U+1F42A
//🦙	Лама	U+1F999
//🐓	Петух	U+1F413
//🐕	Пёс	U+1F415
//🐿️	Белка	U+1F43F
//🦨	Скунс	U+1F9A8
//🦦	Выдра	U+1F9A6
//🦥	Ленивец	U+1F9A5
//*/

//#include <iostream>


//// Функция для вычисления суррогатной пары
//void ConvertToSurrogatePair(uint32_t unicode) {
//    if (unicode < 0x10000 || unicode > 0x10FFFF) {
//        std::wcerr << L"Кодовая точка вне допустимого диапазона (U+10000 - U+10FFFF)" << std::endl;
//        return;
//    }
//
//    // Шаг 1: Вычисляем базовый код
//    uint32_t uPrime = unicode - 0x10000;
//
//    // Шаг 2: Вычисляем высокий и низкий суррогаты
//    wchar_t highSurrogate = 0xD800 + (uPrime >> 10);
//    wchar_t lowSurrogate = 0xDC00 + (uPrime & 0x3FF);
//
//    // Шаг 3: Выводим результат
//    std::wcout << L"Unicode: U+" << std::hex << unicode << std::endl;
//    std::wcout << L"Высокий суррогат: 0x" << std::hex << highSurrogate << std::endl;
//    std::wcout << L"Низкий суррогат: 0x" << std::hex << lowSurrogate << std::endl;
//
//    // Пример использования
//    wchar_t surrogatePair[] = { highSurrogate, lowSurrogate, 0 };
//    std::wcout << L"Символ: " << surrogatePair << std::endl;
//}
//
//int main() {
//    _setmode(_fileno(stdout), _O_U16TEXT);
//    _setmode(_fileno(stdin), _O_U16TEXT);
//    // Пример: U+1F98A (🦊)
//    ConvertToSurrogatePair(0x1F98A);
//    return 0;
//}
