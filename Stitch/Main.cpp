#pragma once
#include "Stitch.h"

int main()
{
    setlocale(0, "");
    Stitch st1(string("Chain stitch"), string("Воздушная петля"), string("./img/chain_stitch.svg"));
    st1.printStitchInfo();
    st1.drawStitch();
    st1.moveStitchX(2);
    st1.moveStitchY(3);
    st1.moveStitch(1, 1);
    st1.printStitchInfo();
    return 0;
}