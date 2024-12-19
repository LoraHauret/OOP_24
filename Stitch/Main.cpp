#pragma once
#include "Stitch.h"


//typedef void(*Position)(HANDLE, int, int);
//SetConsoleCursorPosition(console, { x, y });
int main()
{
    setlocale(0, "" );
    //CONSOLE_FONT_INFOEX cfi;
    //cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    //GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //wcscpy_s(cfi.FaceName, L"Stitch Regular"); // Название шрифта
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, { 0, 30 });

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd); //получаю холст консоли

    vector<Stitch> stitches;
   Stitch st("","Воздушная круглая петля",  "res//_a.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    stitches.push_back(st);    
    Stitch st1("", "Воздушная вытянутая петля", "res//_b.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st1.moveStitchX(st.get_shere());
    stitches.push_back(st1);    

    Stitch st2("", "Воздушная плотная петля", "res//_c.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st2.moveStitchX(st1.get_start_pos().X + st1.get_shere());
    stitches.push_back(st2);    

    Stitch st3("", "Лицевая петля", "res//_d.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st3.moveStitchX(st2.get_start_pos().X + st2.get_shere());
    stitches.push_back(st3);    

    Stitch st4("", "Полустолбик с накидом", "res//_e.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);    
    st4.moveStitchX(st3.get_start_pos().X + st3.get_shere());
    stitches.push_back(st4);

    Stitch st5("", "Столбик с накидом", "res//_f.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st5.moveStitchX(st4.get_start_pos().X + st4.get_shere());
    stitches.push_back(st5);

    Stitch st6("", "Столбик с двумя накидами", "res//_g.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st6.moveStitchX(st5.get_start_pos().X + st5.get_shere());
    stitches.push_back(st6);

    Stitch st7("", "Столбик с тремя накидами", "res//_h.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st7.moveStitchX(st6.get_start_pos().X + st6.get_shere());
    stitches.push_back(st7);

    Stitch st8("", "Полустолбик с накидом с ребром", "res//_i.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st8.moveStitchX(st7.get_start_pos().X + st7.get_shere());
    stitches.push_back(st8);

    Stitch st9("", "Столбик с накидом с ребром", "res//_j.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st9.moveStitchX(st8.get_start_pos().X + st8.get_shere());
    stitches.push_back(st9);    

    Stitch st10("", "Столбик без накида", "res//_k.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st10.moveStitchX(st9.get_start_pos().X + st9.get_shere());
    stitches.push_back(st10);

    Stitch st11("", "Два веерных полустолбика", "res//_l.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::TWO);
    st11.moveStitchX(st10.get_start_pos().X + st10.get_shere());
    stitches.push_back(st11);

    Stitch st12("", "Три веерных полустолбика", "res//_m.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::THREE);
    st12.moveStitchX(st11.get_start_pos().X + st11.get_shere());
    stitches.push_back(st12);

    Stitch st13("", "Вытянутая петля", "res//_n.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::ONE);
    st13.moveStitchX(st12.get_start_pos().X + st12.get_shere());
    stitches.push_back(st13);

    Stitch st14("", "Два веерных столбика с накидом", "res//_o.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::TWO);
    st14.moveStitchX(st13.get_start_pos().X + st13.get_shere());
    stitches.push_back(st14);

    Stitch st15("", "Три веерных столбика с накидом", "res//_p.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::THREE);
    st15.moveStitchX(st14.get_start_pos().X + st14.get_shere());
    stitches.push_back(st15);

    Stitch st16("", "Четыре веерных столбика с накидом", "res//_q.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FOUR);
    st16.moveStitchX(st15.get_start_pos().X + st15.get_shere());
    stitches.push_back(st16);

    Stitch st17("", "Снопик из двух столбиков", "res//_r.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::TWO);
    st17.moveStitchX(st16.get_start_pos().X + st16.get_shere());
    stitches.push_back(st17);

    Stitch st18("", "Снопик из трех столбиков", "res//_s.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::THREE);
    st18.moveStitchX(st17.get_start_pos().X + st17.get_shere());
    stitches.push_back(st18);

    Stitch st19("", "Снопик из четырех столбиков", "res//_t.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FOUR);
    st19.moveStitchX(st18.get_start_pos().X + st18.get_shere());
    stitches.push_back(st19);

    Stitch st20("", "Снопик из пяти столбиков", "res//_u.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st20.moveStitchX(st19.get_start_pos().X + st19.get_shere());
    stitches.push_back(st20);

    Stitch st21("", "Снопик из пяти столбиков", "res//A.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st21.set_start_pos({ 0,100 });
    st21.moveStitch(st20.get_start_pos().X + st20.get_shere(), 100);
    stitches.push_back(st21);

    Stitch st22("", "Снопик из пяти столбиков", "res//B.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st21.moveStitchX(st21.get_start_pos().X + st21.get_shere());
    stitches.push_back(st22);

    Stitch st23("", "Снопик из пяти столбиков", "res//C.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st23.moveStitchX(st22.get_start_pos().X + st22.get_shere());
    stitches.push_back(st23);

    Stitch st24("", "Снопик из пяти столбиков", "res//D.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st24.moveStitchX(st23.get_start_pos().X + st23.get_shere());
    stitches.push_back(st24);

    Stitch st25("", "Снопик из пяти столбиков", "res//A.svg", Stitch::BASIC, Stitch::CROCHETING, "", "", Stitch::FIVE);
    st25.moveStitchX(st24.get_start_pos().X + st24.get_shere());
    stitches.push_back(st25); 
    float scale = 0.1;
    for (int i = 0; i < stitches.size(); i++)
    {
	stitches[i].drawStitch(hdc, scale);
    }

    ReleaseDC(hwnd, hdc);
       
  
    //st.printStitchInfo();
   // st.drawStitch(hdc, 0.1);
   // double SCALE = 0.1;
   // string path = "res//_a.svg";//"testFile.xml";
   //

   // string text = drawingSvg::GetAllText(path);

   // string commands_line("MLCSQTAZHVmlcsqtazhv"); // Все возможные команды для рисования
   // vector<string> command_strings = drawingSvg::GetStringLines(text, commands_line);
   //// regex com_regex("-?\\d*\\.\\d+|-?\\d+"); // Все варианты числа типа дабл
   // vector<CMD> cmds = drawingSvg::GetCommands(command_strings);
   // vector<Figure*> commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE);

  

  

   // path = "res//_d.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE,90, 0);


    //path = "res//_e.svg";//"testFile.xml";
    //text.clear();
    //text = drawingSvg::GetAllText(path);
    //command_strings.clear();
    //command_strings = drawingSvg::GetStringLines(text, commands_line);
    //cmds.clear();
    //cmds = drawingSvg::GetCommands(command_strings);
    //commands.clear();
    //commands = drawingSvg::GetCommands(cmds);
    //drawingSvg::RecountCoord(commands);
    //drawingSvg::DrawSVG(hdc, commands, SCALE, 120, 0);

   // path = "res//_f.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 150, 0);

   // path = "res//_g.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 180, 0);

   // path = "res//_h.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 210, 0);

   // path = "res//_i.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 240, 0);

   // path = "res//_j.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 270, 0);

   // path = "res//_k.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 300, 0);

   // path = "res//_l.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 330, 0);//+60

   // path = "res//_m.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 390, 0); // +90

   // path = "res//_n.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 480, 0); //+90

   // path = "res//_o.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 510, 0); //+30

   // path = "res//_p.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 570, 0);// +60

   // path = "res//_q.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 660, 0); // +90
   // //Stitch st1(string("Chain stitch"), string("Воздушная петля"), string("./img/chain_stitch.svg"));

   // path = "res//_r.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 780, 0);

   // path = "res//_s.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 840, 0);

   // path = "res//_t.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 930, 0);

   // path = "res//_u.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 1050, 0);

   // path = "res//A.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 1200, 0);

   // path = "res//B.svg";//"testFile.xml";
   // text.clear();
   // text = drawingSvg::GetAllText(path);
   // command_strings.clear();
   // command_strings = drawingSvg::GetStringLines(text, commands_line);
   // cmds.clear();
   // cmds = drawingSvg::GetCommands(command_strings);
   // commands.clear();
   // commands = drawingSvg::GetCommands(cmds);
   // drawingSvg::RecountCoord(commands);
   // drawingSvg::DrawSVG(hdc, commands, SCALE, 1230, 0);

    // st1.printStitchInfo();
    // st1.drawStitch();
    // st1.moveStitchX(2);
    // st1.moveStitchY(3);
    // st1.moveStitch(1, 1);
    // st1.printStitchInfo();
    //cout << L"AaBbCcDd";

//const static vector< const int*> v = { new int (1), new int (2), new int (3), new int( 4), new int(5), new int(6), new int(7) };
//for (const int* el : v)
//{
//    cout << *el<<" ";
//}
//*v[1] = 8;
//for (const int* el : v)
//{
//    cout << *el << " ";
//}
//const int* ref = v[1];
//cout <<"\n"<< * ref << "\n";
//delete ref;
//for (const int* el : v)
//{
//    cout << *el << " ";
//}
//ref = v[2];
//int address =*v[2];
//cout << "\n" << v[2] <<" "<<*v[2] <<"\n";
//cout << "\n" << &address <<" "<<address<< "\n";
//address = 9;
//cout << "\n" << " " << address << "\n";
    return 0;
}