#pragma once
#include "Book.h"

int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, { 0, 30 });
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    string path = "book.svg";//"testFile.xml";

    double SCALE = 0.8;

    string text = drawingSvg::GetAllText(path);

    string commands_line("MLCSQTAZHVmlcsqtazhv"); // Все возможные команды для рисования
    vector<string> command_strings = drawingSvg::GetStringLines(text, commands_line);
    regex com_regex("-?\\d*\\.\\d+|-?\\d+"); // Все варианты числа типа дабл
    vector<CMD> cmds = drawingSvg::GetCommands(command_strings, com_regex);
    vector<Figure*> commands = drawingSvg::GetCommands(cmds);
    drawingSvg::RecountCoord(commands);
    drawingSvg::DrawSVG(hdc, commands, SCALE);
    cout << "enter any key to continue...";
    cin.get();
    system("cls");

    size_t store1 = 1;

    Book b;
    b.set_store(&store1);
    b.PrintBook();
    string n = "Mistery of Dragon's life";
    string auth = "Charlz Cooper";
    string p = "Mistic & Co";
    string g = "fantasy";
    string l = "english";
    Book b1(n, auth, 2024, p, g, "underfined", l, 100, 1);
    b1.PrintBook();
    b1.RunBookOut(100);
    b1.PrintBook();
    b1.WritePages(30);
    b1.PrintBook();
    b1.SellBook(50);
    b1.PrintBook();
    b1.SellBook(60);
    b1.PrintBook();
    cout << b1;

    int* a = new int(8);
}