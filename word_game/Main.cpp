#pragma once
#include "word_game.h"

int main()
{
    setlocale(0, "");
    system("chcp 1251 > nul");// установка русской кодовой страницы в консоли
    srand(time(0));
    WordGame::PrintMenu();
    WordGame::Play();

    return 0;
}