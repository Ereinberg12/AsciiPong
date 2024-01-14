//LargeTextLibrary.cpp
#include "Alphabet.h"
#include "LargeTextLibrary.h"
#include <iostream>

//Letter ctors
Letter::Letter(char symbol){
    this->symbol = symbol;

    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 13; ++j){
            pixels[i][j] = ' ';
        }
    }
}

Letter::Letter(){

}

void Letter::print(){
    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 13; ++j){
            std::cout << pixels[i][j];
        }
        std::cout << '\n';
    }
}

//Alphabet ctor
Alphabet::Alphabet(){
    char dot = 'o';
    initializeLetters(dot);
    initializeSymbols(dot);
    initializeNumbers(dot);
}

void Alphabet::initializeLetters(char dot){
    //initialize A
    Letter A = Letter('A');
    A.pixels[6][0] = dot;
    A.pixels[6][12] = dot;
    A.pixels[5][1] = dot;
    A.pixels[5][11] = dot;
    A.pixels[4][2] = dot;
    A.pixels[4][10] = dot;
    A.pixels[3][3] = dot;
    A.pixels[3][3] = dot;
    A.pixels[3][4] = dot;
    A.pixels[3][5] = dot;
    A.pixels[3][6] = dot;
    A.pixels[3][7] = dot;
    A.pixels[3][8] = dot;
    A.pixels[3][9] = dot;
    A.pixels[2][4] = dot;
    A.pixels[2][8] = dot;
    A.pixels[1][5] = dot;
    A.pixels[1][7] = dot;
    A.pixels[0][6] = dot;
    Letters[letterKey::A] = A;

    //initialize B
    Letter B = Letter('B');
    B.pixels[0][0] = dot;
    B.pixels[0][1] = dot;
    B.pixels[0][2] = dot;
    B.pixels[0][3] = dot;
    B.pixels[0][4] = dot;
    B.pixels[0][5] = dot;
    B.pixels[0][6] = dot;
    B.pixels[0][7] = dot;
    B.pixels[0][8] = dot;
    B.pixels[0][9] = dot;
    B.pixels[0][10] = dot;
    B.pixels[1][0] = dot;
    B.pixels[1][11] = dot;
    B.pixels[1][12] = dot;
    B.pixels[2][0] = dot;
    B.pixels[2][10] = dot;
    B.pixels[2][11] = dot;
    B.pixels[2][12] = dot;
    B.pixels[3][0] = dot;
    B.pixels[3][1] = dot;
    B.pixels[3][2] = dot;
    B.pixels[3][3] = dot;
    B.pixels[3][4] = dot;
    B.pixels[3][5] = dot;
    B.pixels[3][6] = dot;
    B.pixels[3][7] = dot;
    B.pixels[3][8] = dot;
    B.pixels[3][9] = dot;
    B.pixels[3][10] = dot;
    B.pixels[4][0] = dot;
    B.pixels[4][11] = dot;
    B.pixels[4][12] = dot;
    B.pixels[5][0] = dot;
    B.pixels[4][10] = dot;
    B.pixels[5][11] = dot;
    B.pixels[5][12] = dot;
    B.pixels[6][0] = dot;
    B.pixels[6][1] = dot;
    B.pixels[6][2] = dot;
    B.pixels[6][3] = dot;
    B.pixels[6][4] = dot;
    B.pixels[6][5] = dot;
    B.pixels[6][6] = dot;
    B.pixels[6][7] = dot;
    B.pixels[6][8] = dot;
    B.pixels[6][9] = dot;
    B.pixels[6][10] = dot;
    Letters[letterKey::B] = B;

    //Initialize C
    Letter C = Letter('C');
    C.pixels[0][3] = dot;
    C.pixels[0][4] = dot;
    C.pixels[0][5] = dot;
    C.pixels[0][6] = dot;
    C.pixels[0][7] = dot;
    C.pixels[0][8] = dot;
    C.pixels[0][9] = dot;
    C.pixels[0][10] = dot;
    C.pixels[1][1] = dot;
    C.pixels[1][2] = dot;
    C.pixels[1][11] = dot;
    C.pixels[1][12] = dot;
    C.pixels[2][0] = dot;
    C.pixels[3][0] = dot;
    C.pixels[4][0] = dot;
    C.pixels[5][1] = dot;
    C.pixels[5][2] = dot;
    C.pixels[5][11] = dot;
    C.pixels[5][12] = dot;
    C.pixels[6][3] = dot;
    C.pixels[6][4] = dot;
    C.pixels[6][5] = dot;
    C.pixels[6][6] = dot;
    C.pixels[6][7] = dot;
    C.pixels[6][8] = dot;
    C.pixels[6][9] = dot;
    C.pixels[6][10] = dot;
    Letters[letterKey::C] = C;

    //initialize D
    Letter D = Letter('D');
    D.pixels[0][0] = dot;
    D.pixels[0][1] = dot;
    D.pixels[0][2] = dot;
    D.pixels[0][3] = dot;
    D.pixels[0][4] = dot;
    D.pixels[0][5] = dot;
    D.pixels[0][6] = dot;
    D.pixels[0][7] = dot;
    D.pixels[0][8] = dot;
    D.pixels[0][9] = dot;
    D.pixels[1][10] = dot;
    D.pixels[1][11] = dot;
    D.pixels[1][0] = dot;
    D.pixels[2][0] = dot;
    D.pixels[2][12] = dot;
    D.pixels[3][0] = dot;
    D.pixels[3][12] = dot;
    D.pixels[4][0] = dot;
    D.pixels[4][12] = dot;
    D.pixels[5][0] = dot;
    D.pixels[5][10] = dot;
    D.pixels[5][11] = dot;
    D.pixels[6][0] = dot;
    D.pixels[6][1] = dot;
    D.pixels[6][2] = dot;
    D.pixels[6][3] = dot;
    D.pixels[6][4] = dot;
    D.pixels[6][5] = dot;
    D.pixels[6][6] = dot;
    D.pixels[6][7] = dot;
    D.pixels[6][8] = dot;
    D.pixels[6][9] = dot;
    Letters[letterKey::D] = D;

    //Initialize E
    Letter E = Letter('E');
    E.pixels[0][0] = dot;
    E.pixels[0][1] = dot;
    E.pixels[0][2] = dot;
    E.pixels[0][3] = dot;
    E.pixels[0][4] = dot;
    E.pixels[0][5] = dot;
    E.pixels[0][6] = dot;
    E.pixels[0][7] = dot;
    E.pixels[0][8] = dot;
    E.pixels[0][9] = dot;
    E.pixels[0][10] = dot;
    E.pixels[0][11] = dot;
    E.pixels[0][12] = dot;
    E.pixels[1][0] = dot;
    E.pixels[2][0] = dot;
    E.pixels[3][0] = dot;
    E.pixels[3][1] = dot;
    E.pixels[3][2] = dot;
    E.pixels[3][3] = dot;
    E.pixels[3][4] = dot;
    E.pixels[3][5] = dot;
    E.pixels[3][6] = dot;
    E.pixels[3][7] = dot;
    E.pixels[3][8] = dot;
    E.pixels[3][9] = dot;
    E.pixels[3][10] = dot;
    E.pixels[3][11] = dot;
    E.pixels[3][12] = dot;
    E.pixels[4][0] = dot;
    E.pixels[5][0] = dot;
    E.pixels[6][0] = dot;
    E.pixels[6][1] = dot;
    E.pixels[6][2] = dot;
    E.pixels[6][3] = dot;
    E.pixels[6][4] = dot;
    E.pixels[6][5] = dot;
    E.pixels[6][6] = dot;
    E.pixels[6][7] = dot;
    E.pixels[6][8] = dot;
    E.pixels[6][9] = dot;
    E.pixels[6][10] = dot;
    E.pixels[6][11] = dot;
    E.pixels[6][12] = dot;
    Letters[letterKey::E] = E;

    //Initialize F
    Letter F = Letter('F');
    F.pixels[0][0] = dot;
    F.pixels[0][1] = dot;
    F.pixels[0][2] = dot;
    F.pixels[0][3] = dot;
    F.pixels[0][4] = dot;
    F.pixels[0][5] = dot;
    F.pixels[0][6] = dot;
    F.pixels[0][7] = dot;
    F.pixels[0][8] = dot;
    F.pixels[0][9] = dot;
    F.pixels[0][10] = dot;
    F.pixels[0][11] = dot;
    F.pixels[0][12] = dot;
    F.pixels[1][0] = dot;
    F.pixels[2][0] = dot;
    F.pixels[3][0] = dot;
    F.pixels[3][1] = dot;
    F.pixels[3][2] = dot;
    F.pixels[3][3] = dot;
    F.pixels[3][4] = dot;
    F.pixels[3][5] = dot;
    F.pixels[3][6] = dot;
    F.pixels[3][7] = dot;
    F.pixels[3][8] = dot;
    F.pixels[3][9] = dot;
    F.pixels[3][10] = dot;
    F.pixels[3][11] = dot;
    F.pixels[3][12] = dot;
    F.pixels[4][0] = dot;
    F.pixels[5][0] = dot;
    F.pixels[6][0] = dot;
    Letters[letterKey::F] = F;

    //initialize G
    Letter G = Letter('G');
    G.pixels[0][3] = dot;
    G.pixels[0][4] = dot;
    G.pixels[0][5] = dot;
    G.pixels[0][6] = dot;
    G.pixels[0][7] = dot;
    G.pixels[0][8] = dot;
    G.pixels[0][9] = dot;
    G.pixels[0][10] = dot;
    G.pixels[1][1] = dot;
    G.pixels[1][2] = dot;
    G.pixels[1][11] = dot;
    G.pixels[1][12] = dot;
    G.pixels[2][0] = dot;
    G.pixels[3][0] = dot;
    G.pixels[4][0] = dot;
    G.pixels[5][1] = dot;
    G.pixels[5][2] = dot;
    G.pixels[4][9] = dot;
    G.pixels[4][10] = dot;
    G.pixels[4][11] = dot;
    G.pixels[4][12] = dot;
    G.pixels[5][11] = dot;
    G.pixels[5][12] = dot;
    G.pixels[6][3] = dot;
    G.pixels[6][4] = dot;
    G.pixels[6][5] = dot;
    G.pixels[6][6] = dot;
    G.pixels[6][7] = dot;
    G.pixels[6][8] = dot;
    G.pixels[6][9] = dot;
    G.pixels[6][10] = dot;
    G.pixels[6][11] = dot;
    Letters[letterKey::G] = G;

    //initialize H
    Letter H = Letter('H');
    H.pixels[0][0] = dot;
    H.pixels[0][12] = dot;
    H.pixels[1][0] = dot;
    H.pixels[1][12] = dot;
    H.pixels[2][0] = dot;
    H.pixels[2][12] = dot;
    H.pixels[3][0] = dot;
    H.pixels[3][1] = dot;
    H.pixels[3][2] = dot;
    H.pixels[3][3] = dot;
    H.pixels[3][4] = dot;
    H.pixels[3][5] = dot;
    H.pixels[3][6] = dot;
    H.pixels[3][7] = dot;
    H.pixels[3][8] = dot;
    H.pixels[3][9] = dot;
    H.pixels[3][10] = dot;
    H.pixels[3][11] = dot;
    H.pixels[3][12] = dot;
    H.pixels[4][0] = dot;
    H.pixels[4][12] = dot;
    H.pixels[5][0] = dot;
    H.pixels[5][12] = dot;
    H.pixels[6][0] = dot;
    H.pixels[6][12] = dot;
    Letters[letterKey::H] = H;

    //initialize I
    Letter I = Letter('I');
    I.pixels[0][0] = dot;
    I.pixels[0][1] = dot;
    I.pixels[0][2] = dot;
    I.pixels[0][3] = dot;
    I.pixels[0][4] = dot;
    I.pixels[0][5] = dot;
    I.pixels[0][6] = dot;
    I.pixels[0][7] = dot;
    I.pixels[0][8] = dot;
    I.pixels[0][9] = dot;
    I.pixels[0][10] = dot;
    I.pixels[0][11] = dot;
    I.pixels[0][12] = dot;
    I.pixels[1][6] = dot;
    I.pixels[2][6] = dot;
    I.pixels[3][6] = dot;
    I.pixels[4][6] = dot;
    I.pixels[5][6] = dot;
    I.pixels[6][0] = dot;
    I.pixels[6][1] = dot;
    I.pixels[6][2] = dot;
    I.pixels[6][3] = dot;
    I.pixels[6][4] = dot;
    I.pixels[6][5] = dot;
    I.pixels[6][6] = dot;
    I.pixels[6][7] = dot;
    I.pixels[6][8] = dot;
    I.pixels[6][9] = dot;
    I.pixels[6][10] = dot;
    I.pixels[6][11] = dot;
    I.pixels[6][12] = dot;
    Letters[letterKey::I] = I;

    //initialize J
    Letter J = Letter('J');
    J.pixels[0][0] = dot;
    J.pixels[0][1] = dot;
    J.pixels[0][2] = dot;
    J.pixels[0][3] = dot;
    J.pixels[0][4] = dot;
    J.pixels[0][5] = dot;
    J.pixels[0][6] = dot;
    J.pixels[0][7] = dot;
    J.pixels[0][8] = dot;
    J.pixels[0][9] = dot;
    J.pixels[0][10] = dot;
    J.pixels[0][11] = dot;
    J.pixels[0][12] = dot;
    J.pixels[1][6] = dot;
    J.pixels[2][6] = dot;
    J.pixels[3][6] = dot;
    J.pixels[4][6] = dot;
    J.pixels[5][1] = dot;
    J.pixels[5][5] = dot;
    J.pixels[6][2] = dot;
    J.pixels[6][3] = dot;
    J.pixels[6][4] = dot;
    Letters[letterKey::J] = J;

    //initialize K
    Letter K = Letter('K');
    K.pixels[0][0] = dot;
    K.pixels[0][11] = dot;
    K.pixels[0][12] = dot;
    K.pixels[1][0] = dot;
    K.pixels[1][8] = dot;
    K.pixels[1][9] = dot;
    K.pixels[1][10] = dot;
    K.pixels[2][0] = dot;
    K.pixels[2][4] = dot;
    K.pixels[2][5] = dot;
    K.pixels[2][6] = dot;
    K.pixels[3][0] = dot;
    K.pixels[3][1] = dot;
    K.pixels[3][2] = dot;
    K.pixels[3][3] = dot;
    K.pixels[4][0] = dot;
    K.pixels[4][4] = dot;
    K.pixels[4][5] = dot;
    K.pixels[4][6] = dot;
    K.pixels[5][0] = dot;
    K.pixels[5][8] = dot;
    K.pixels[5][9] = dot;
    K.pixels[5][10] = dot;
    K.pixels[6][0] = dot;
    K.pixels[6][11] = dot;
    K.pixels[6][12] = dot;
    Letters[letterKey::K] = K;

    //initialize L
    Letter L = Letter('L');
    L.pixels[0][0] = dot;
    L.pixels[1][0] = dot;
    L.pixels[2][0] = dot;
    L.pixels[3][0] = dot;
    L.pixels[4][0] = dot;
    L.pixels[5][0] = dot;
    L.pixels[6][0] = dot;
    L.pixels[6][1] = dot;
    L.pixels[6][2] = dot;
    L.pixels[6][3] = dot;
    L.pixels[6][4] = dot;
    L.pixels[6][5] = dot;
    L.pixels[6][6] = dot;
    L.pixels[6][7] = dot;
    L.pixels[6][8] = dot;
    L.pixels[6][9] = dot;
    L.pixels[6][10] = dot;
    L.pixels[6][11] = dot;
    L.pixels[6][12] = dot;
    Letters[letterKey::L] = L;

    //initialize M
    Letter M = Letter('M');
    M.pixels[0][0] = dot;
    M.pixels[0][1] = dot;
    M.pixels[0][11] = dot;
    M.pixels[0][12] = dot;
    M.pixels[1][0] = dot;
    M.pixels[1][2] = dot;
    M.pixels[1][10] = dot;
    M.pixels[1][12] = dot;
    M.pixels[2][0] = dot;
    M.pixels[2][3] = dot;
    M.pixels[2][9] = dot;
    M.pixels[2][12] = dot;
    M.pixels[3][0] = dot;
    M.pixels[3][4] = dot;
    M.pixels[3][8] = dot;
    M.pixels[3][12] = dot;
    M.pixels[4][0] = dot;
    M.pixels[4][5] = dot;
    M.pixels[4][7] = dot;
    M.pixels[4][12] = dot;
    M.pixels[5][0] = dot;
    M.pixels[5][12] = dot;
    M.pixels[5][6] = dot;
    M.pixels[6][0] = dot;
    M.pixels[6][12] = dot;
    Letters[letterKey::M] = M;

    //initialize N
    Letter N = Letter('N');
    N.pixels[0][0] = dot;
    N.pixels[0][1] = dot;
    N.pixels[0][12] = dot;
    N.pixels[1][0] = dot;
    N.pixels[1][2] = dot;
    N.pixels[1][3] = dot;
    N.pixels[1][12] = dot;
    N.pixels[2][0] = dot;
    N.pixels[2][4] = dot;
    N.pixels[2][5] = dot;
    N.pixels[2][12] = dot;
    N.pixels[3][0] = dot;
    N.pixels[3][6] = dot;
    N.pixels[3][7] = dot;
    N.pixels[3][12] = dot;
    N.pixels[4][0] = dot;
    N.pixels[4][8] = dot;
    N.pixels[4][9] = dot;
    N.pixels[4][12] = dot;
    N.pixels[5][0] = dot;
    N.pixels[5][9] = dot;
    N.pixels[5][10] = dot;
    N.pixels[5][12] = dot;
    N.pixels[6][0] = dot;
    N.pixels[6][11] = dot;
    N.pixels[6][12] = dot;
    Letters[letterKey::N] = N;

    //initialize O
    Letter O = Letter('O');
    O.pixels[0][3] = dot;
    O.pixels[0][4] = dot;
    O.pixels[0][5] = dot;
    O.pixels[0][6] = dot;
    O.pixels[0][7] = dot;
    O.pixels[0][8] = dot;
    O.pixels[0][9] = dot;
    O.pixels[1][1] = dot;
    O.pixels[1][2] = dot;
    O.pixels[1][3] = dot;
    O.pixels[1][9] = dot;
    O.pixels[1][10] = dot;
    O.pixels[1][11] = dot;
    O.pixels[2][0] = dot;
    O.pixels[2][1] = dot;
    O.pixels[2][11] = dot;
    O.pixels[2][12] = dot;
    O.pixels[3][0] = dot;
    O.pixels[3][12] = dot;
    O.pixels[4][0] = dot;
    O.pixels[4][1] = dot;
    O.pixels[4][11] = dot;
    O.pixels[4][12] = dot;
    O.pixels[5][1] = dot;
    O.pixels[5][2] = dot;
    O.pixels[5][3] = dot;
    O.pixels[5][9] = dot;
    O.pixels[5][10] = dot;
    O.pixels[5][11] = dot;
    O.pixels[6][3] = dot;
    O.pixels[6][4] = dot;
    O.pixels[6][5] = dot;
    O.pixels[6][6] = dot;
    O.pixels[6][7] = dot;
    O.pixels[6][8] = dot;
    O.pixels[6][9] = dot;
    Letters[letterKey::O] = O;

    //initialize P
    Letter P = Letter('P');
    P.pixels[0][1] = dot;
    P.pixels[0][2] = dot;
    P.pixels[0][3] = dot;
    P.pixels[0][4] = dot;
    P.pixels[0][5] = dot;
    P.pixels[0][6] = dot;
    P.pixels[0][7] = dot;
    P.pixels[0][8] = dot;
    P.pixels[0][9] = dot;
    P.pixels[1][0] = dot;
    P.pixels[1][10] = dot;
    P.pixels[1][11] = dot;
    P.pixels[2][0] = dot;
    P.pixels[2][11] = dot;
    P.pixels[2][12] = dot;
    P.pixels[3][0] = dot;
    P.pixels[3][9] = dot;
    P.pixels[3][10] = dot;
    P.pixels[4][0] = dot;
    P.pixels[4][1] = dot;
    P.pixels[4][2] = dot;
    P.pixels[4][3] = dot;
    P.pixels[4][4] = dot;
    P.pixels[4][5] = dot;
    P.pixels[4][6] = dot;
    P.pixels[4][7] = dot;
    P.pixels[4][8] = dot;
    P.pixels[4][9] = dot;
    P.pixels[5][0] = dot;
    P.pixels[6][0] = dot;
    Letters[letterKey::P] = P;

    //initialize Q
    Letter Q = Letter('Q');
    Q.pixels[0][3] = dot;
    Q.pixels[0][4] = dot;
    Q.pixels[0][5] = dot;
    Q.pixels[0][6] = dot;
    Q.pixels[0][7] = dot;
    Q.pixels[0][8] = dot;
    Q.pixels[0][9] = dot;
    Q.pixels[1][1] = dot;
    Q.pixels[1][2] = dot;
    Q.pixels[1][3] = dot;
    Q.pixels[1][9] = dot;
    Q.pixels[1][10] = dot;
    Q.pixels[1][11] = dot;
    Q.pixels[2][0] = dot;
    Q.pixels[2][1] = dot;
    Q.pixels[2][11] = dot;
    Q.pixels[2][12] = dot;
    Q.pixels[3][0] = dot;
    Q.pixels[3][12] = dot;
    Q.pixels[4][0] = dot;
    Q.pixels[4][1] = dot;
    Q.pixels[4][11] = dot;
    Q.pixels[4][12] = dot;
    Q.pixels[5][1] = dot;
    Q.pixels[5][2] = dot;
    Q.pixels[5][3] = dot;
    Q.pixels[5][9] = dot;
    Q.pixels[5][10] = dot;
    Q.pixels[5][11] = dot;
    Q.pixels[6][3] = dot;
    Q.pixels[6][4] = dot;
    Q.pixels[6][5] = dot;
    Q.pixels[6][6] = dot;
    Q.pixels[6][7] = dot;
    Q.pixels[6][8] = dot;
    Q.pixels[6][9] = dot;
    Q.pixels[6][12] = dot;
    Letters[letterKey::Q] = Q;

    //initialize R
    Letter R = Letter('R');
    R.pixels[0][1] = dot;
    R.pixels[0][2] = dot;
    R.pixels[0][3] = dot;
    R.pixels[0][4] = dot;
    R.pixels[0][5] = dot;
    R.pixels[0][6] = dot;
    R.pixels[0][7] = dot;
    R.pixels[0][8] = dot;
    R.pixels[0][8] = dot;
    R.pixels[1][0] = dot;
    R.pixels[1][9] = dot;
    R.pixels[1][10] = dot;
    R.pixels[2][0] = dot;
    R.pixels[2][11] = dot;
    R.pixels[2][12] = dot;
    R.pixels[3][0] = dot;
    R.pixels[3][9] = dot;
    R.pixels[3][10] = dot;
    R.pixels[4][0] = dot;
    R.pixels[4][1] = dot;
    R.pixels[4][2] = dot;
    R.pixels[4][3] = dot;
    R.pixels[4][4] = dot;
    R.pixels[4][5] = dot;
    R.pixels[4][6] = dot;
    R.pixels[4][7] = dot;
    R.pixels[4][8] = dot;
    R.pixels[4][9] = dot;
    R.pixels[5][0] = dot;
    R.pixels[5][9] = dot;
    R.pixels[5][10] = dot;
    R.pixels[6][0] = dot;
    R.pixels[6][11] = dot;
    R.pixels[6][12] = dot;
    Letters[letterKey::R] = R;

    //initialize S
    Letter S = Letter('S');
    S.pixels[0][4] = dot;
    S.pixels[0][5] = dot;
    S.pixels[0][6] = dot;
    S.pixels[0][7] = dot;
    S.pixels[0][8] = dot;
    S.pixels[0][9] = dot;
    S.pixels[0][10] = dot;
    S.pixels[0][11] = dot;
    S.pixels[1][2] = dot;
    S.pixels[1][3] = dot;
    S.pixels[1][12] = dot;
    S.pixels[2][0] = dot;
    S.pixels[2][1] = dot;
    S.pixels[3][2] = dot;
    S.pixels[3][3] = dot;
    S.pixels[3][4] = dot;
    S.pixels[3][5] = dot;
    S.pixels[3][6] = dot;
    S.pixels[4][7] = dot;
    S.pixels[4][8] = dot;
    S.pixels[4][9] = dot;
    S.pixels[4][10] = dot;
    S.pixels[5][0] = dot;
    S.pixels[5][1] = dot;
    S.pixels[5][11] = dot;
    S.pixels[5][12] = dot;
    S.pixels[6][1] = dot;
    S.pixels[6][2] = dot;
    S.pixels[6][3] = dot;
    S.pixels[6][4] = dot;
    S.pixels[6][5] = dot;
    S.pixels[6][6] = dot;
    S.pixels[6][7] = dot;
    S.pixels[6][8] = dot;
    S.pixels[6][9] = dot;
    S.pixels[6][10] = dot;
    Letters[letterKey::S] = S;

    //Initialize T
    Letter T = Letter('T');
    T.pixels[0][0] = dot;
    T.pixels[0][1] = dot;
    T.pixels[0][2] = dot;
    T.pixels[0][3] = dot;
    T.pixels[0][4] = dot;
    T.pixels[0][5] = dot;
    T.pixels[0][6] = dot;
    T.pixels[0][7] = dot;
    T.pixels[0][8] = dot;
    T.pixels[0][9] = dot;
    T.pixels[0][10] = dot;
    T.pixels[0][11] = dot;
    T.pixels[0][12] = dot;
    T.pixels[1][6] = dot;
    T.pixels[2][6] = dot;
    T.pixels[3][6] = dot;
    T.pixels[4][6] = dot;
    T.pixels[5][6] = dot;
    T.pixels[6][6] = dot;
    Letters[letterKey::T] = T;

    //initialize U
    Letter U = Letter('U');
    U.pixels[0][0] = dot; 
    U.pixels[0][12] = dot;
    U.pixels[1][0] = dot; 
    U.pixels[1][12] = dot;
    U.pixels[2][0] = dot; 
    U.pixels[2][12] = dot;
    U.pixels[3][0] = dot; 
    U.pixels[3][12] = dot;
    U.pixels[4][0] = dot;
    U.pixels[4][1] = dot; 
    U.pixels[4][11] = dot;
    U.pixels[4][12] = dot;
    U.pixels[5][1] = dot;
    U.pixels[5][2] = dot; 
    U.pixels[5][10] = dot; 
    U.pixels[5][11] = dot;
    U.pixels[6][2] = dot; 
    U.pixels[6][3] = dot;
    U.pixels[6][4] = dot; 
    U.pixels[6][5] = dot;
    U.pixels[6][6] = dot; 
    U.pixels[6][7] = dot;
    U.pixels[6][8] = dot; 
    U.pixels[6][9] = dot; 
    U.pixels[6][10] = dot;
    Letters[letterKey::U] = U;

    //initialize V
    Letter V = Letter('V');
    V.pixels[0][0] = dot; 
    V.pixels[0][12] = dot;
    V.pixels[1][1] = dot; 
    V.pixels[1][11] = dot;
    V.pixels[2][2] = dot; 
    V.pixels[2][10] = dot;
    V.pixels[3][3] = dot; 
    V.pixels[3][9] = dot;
    V.pixels[4][4] = dot; 
    V.pixels[4][8] = dot;
    V.pixels[5][5] = dot; 
    V.pixels[5][7] = dot;
    V.pixels[6][6] = dot;
    Letters[letterKey::V] = V;

    //initialize W
    Letter W = Letter('W');
    W.pixels[0][0] = dot; 
    W.pixels[0][12] = dot;
    W.pixels[1][0] = dot; 
    W.pixels[1][12] = dot;
    W.pixels[2][0] = dot; 
    W.pixels[2][12] = dot;
    W.pixels[3][0] = dot; 
    W.pixels[3][6] = dot; 
    W.pixels[3][12] = dot;
    W.pixels[4][0] = dot; 
    W.pixels[4][6] = dot; 
    W.pixels[4][12] = dot;
    W.pixels[5][1] = dot; 
    W.pixels[5][5] = dot; 
    W.pixels[5][7] = dot; 
    W.pixels[5][11] = dot;
    W.pixels[6][2] = dot; 
    W.pixels[6][4] = dot; 
    W.pixels[6][8] = dot; 
    W.pixels[6][10] = dot;
    Letters[letterKey::W] = W;

    //initialize X
    Letter X = Letter('X');
    X.pixels[0][0] = dot; 
    X.pixels[0][1] = dot; 
    X.pixels[0][11] = dot;
    X.pixels[0][12] = dot;
    X.pixels[1][2] = dot;
    X.pixels[1][3] = dot;
    X.pixels[1][9] = dot;  
    X.pixels[1][10] = dot;
    X.pixels[2][4] = dot;
    X.pixels[2][5] = dot; 
    X.pixels[2][7] = dot; 
    X.pixels[2][8] = dot;
    X.pixels[3][6] = dot;
    X.pixels[4][7] = dot; 
    X.pixels[4][8] = dot; 
    X.pixels[4][4] = dot;
    X.pixels[4][5] = dot;
    X.pixels[5][10] = dot; 
    X.pixels[5][9] = dot;
    X.pixels[5][2] = dot;
    X.pixels[5][3] = dot; 
    X.pixels[6][0] = dot;
    X.pixels[6][1] = dot;
    X.pixels[6][11] = dot;
    X.pixels[6][12] = dot;
    Letters[letterKey::X] = X;

    // Initialize Y
    Letter Y = Letter('Y');
    Y.pixels[0][0] = dot; 
    Y.pixels[0][1] = dot; 
    Y.pixels[0][11] = dot;
    Y.pixels[0][12] = dot;
    Y.pixels[1][1] = dot;
    Y.pixels[1][2] = dot;  
    Y.pixels[1][10] = dot;
    Y.pixels[1][11] = dot;
    Y.pixels[2][2] = dot; 
    Y.pixels[2][3] = dot;
    Y.pixels[2][9] = dot;
    Y.pixels[2][10] = dot;
    Y.pixels[3][4] = dot; 
    Y.pixels[3][5] = dot; 
    Y.pixels[3][7] = dot; 
    Y.pixels[3][8] = dot;
    Y.pixels[4][6] = dot;
    Y.pixels[5][6] = dot;
    Y.pixels[6][6] = dot;
    Letters[letterKey::Y] = Y;

    // Initialize Z
    Letter Z = Letter('Z');
    Z.pixels[0][0] = dot; 
    Z.pixels[0][1] = dot; 
    Z.pixels[0][2] = dot;
    Z.pixels[0][3] = dot; 
    Z.pixels[0][4] = dot; 
    Z.pixels[0][5] = dot;
    Z.pixels[0][6] = dot; 
    Z.pixels[0][7] = dot; 
    Z.pixels[0][8] = dot;
    Z.pixels[0][9] = dot; 
    Z.pixels[0][10] = dot; 
    Z.pixels[0][11] = dot; 
    Z.pixels[0][12] = dot;
    Z.pixels[1][11] = dot;
    Z.pixels[1][12] = dot;
    Z.pixels[2][8] = dot;
    Z.pixels[2][9] = dot;
    Z.pixels[2][10] = dot;
    Z.pixels[3][5] = dot;
    Z.pixels[3][6] = dot;
    Z.pixels[3][7] = dot;
    Z.pixels[4][2] = dot;
    Z.pixels[4][3] = dot;
    Z.pixels[4][4] = dot;
    Z.pixels[5][0] = dot;
    Z.pixels[5][1] = dot;
    Z.pixels[6][0] = dot; 
    Z.pixels[6][1] = dot; 
    Z.pixels[6][2] = dot;
    Z.pixels[6][3] = dot; 
    Z.pixels[6][4] = dot; 
    Z.pixels[6][5] = dot;
    Z.pixels[6][6] = dot; 
    Z.pixels[6][7] = dot; 
    Z.pixels[6][8] = dot;
    Z.pixels[6][9] = dot; 
    Z.pixels[6][10] = dot; 
    Z.pixels[6][11] = dot; 
    Z.pixels[6][12] = dot;
    Letters[letterKey::Z] = Z;
}

void Alphabet::initializeNumbers(char dot){
    //Initialize zero
    Letter Zero('0');
    Zero.pixels[0][3] = dot;
    Zero.pixels[0][4] = dot;
    Zero.pixels[0][5] = dot;
    Zero.pixels[0][6] = dot;
    Zero.pixels[0][7] = dot;
    Zero.pixels[0][8] = dot;
    Zero.pixels[0][9] = dot;
    Zero.pixels[1][1] = dot;
    Zero.pixels[1][2] = dot;
    Zero.pixels[1][3] = dot;
    Zero.pixels[1][9] = dot;
    Zero.pixels[1][10] = dot;
    Zero.pixels[1][11] = dot;
    Zero.pixels[2][0] = dot;
    Zero.pixels[2][1] = dot;
    Zero.pixels[2][11] = dot;
    Zero.pixels[2][12] = dot;
    Zero.pixels[3][0] = dot;
    Zero.pixels[3][12] = dot;
    Zero.pixels[4][0] = dot;
    Zero.pixels[4][1] = dot;
    Zero.pixels[4][11] = dot;
    Zero.pixels[4][12] = dot;
    Zero.pixels[5][1] = dot;
    Zero.pixels[5][2] = dot;
    Zero.pixels[5][3] = dot;
    Zero.pixels[5][9] = dot;
    Zero.pixels[5][10] = dot;
    Zero.pixels[5][11] = dot;
    Zero.pixels[6][3] = dot;
    Zero.pixels[6][4] = dot;
    Zero.pixels[6][5] = dot;
    Zero.pixels[6][6] = dot;
    Zero.pixels[6][7] = dot;
    Zero.pixels[6][8] = dot;
    Zero.pixels[6][9] = dot;
    Numbers[0] = Zero;

    //initialize one
    Letter One = Letter('1');
    One.pixels[0][4] = dot;
    One.pixels[0][5] = dot;
    One.pixels[0][6] = dot;
    One.pixels[0][7] = dot;
    One.pixels[1][2] = dot;
    One.pixels[1][3] = dot;
    One.pixels[1][4] = dot;
    One.pixels[1][6] = dot;
    One.pixels[1][7] = dot;
    One.pixels[2][0] = dot;
    One.pixels[2][1] = dot;
    One.pixels[2][2] = dot;
    One.pixels[2][6] = dot;
    One.pixels[2][7] = dot;
    One.pixels[3][6] = dot;
    One.pixels[3][7] = dot;
    One.pixels[4][6] = dot;
    One.pixels[4][7] = dot;
    One.pixels[5][6] = dot;
    One.pixels[5][7] = dot;
    One.pixels[6][0] = dot;
    One.pixels[6][1] = dot;
    One.pixels[6][2] = dot;
    One.pixels[6][3] = dot;
    One.pixels[6][4] = dot;
    One.pixels[6][5] = dot;
    One.pixels[6][6] = dot;
    One.pixels[6][7] = dot;
    One.pixels[6][8] = dot;
    One.pixels[6][9] = dot;
    One.pixels[6][10] = dot;
    One.pixels[6][11] = dot;
    One.pixels[6][12] = dot;
    Numbers[1] = One;

    //initialize two
    Letter Two = Letter('2');
    Two.pixels[0][4] = dot;
    Two.pixels[0][5] = dot;
    Two.pixels[0][6] = dot;
    Two.pixels[0][7] = dot;
    Two.pixels[0][8] = dot;
    Two.pixels[1][2] = dot;
    Two.pixels[1][3] = dot;
    Two.pixels[1][9] = dot;
    Two.pixels[1][10] = dot;
    Two.pixels[2][0] = dot;
    Two.pixels[2][1] = dot;
    Two.pixels[2][11] = dot;
    Two.pixels[2][12] = dot;
    Two.pixels[3][6] = dot;
    Two.pixels[3][7] = dot;
    Two.pixels[3][8] = dot;
    Two.pixels[3][9] = dot;
    Two.pixels[3][10] = dot;
    Two.pixels[4][3] = dot;
    Two.pixels[4][4] = dot;
    Two.pixels[4][5] = dot;
    Two.pixels[4][6] = dot;
    Two.pixels[5][1] = dot;
    Two.pixels[5][2] = dot;
    Two.pixels[6][0] = dot;
    Two.pixels[6][1] = dot;
    Two.pixels[6][2] = dot;
    Two.pixels[6][3] = dot;
    Two.pixels[6][4] = dot;
    Two.pixels[6][5] = dot;
    Two.pixels[6][6] = dot;
    Two.pixels[6][7] = dot;
    Two.pixels[6][8] = dot;
    Two.pixels[6][9] = dot;
    Two.pixels[6][10] = dot;
    Two.pixels[6][11] = dot;
    Two.pixels[6][12] = dot;
    Numbers[2] = Two;

    //initialize three
    Letter Three = Letter('3');
    Three.pixels[0][0] = dot;
    Three.pixels[0][1] = dot;
    Three.pixels[0][2] = dot;
    Three.pixels[0][3] = dot;
    Three.pixels[0][4] = dot;
    Three.pixels[0][5] = dot;
    Three.pixels[0][6] = dot;
    Three.pixels[0][7] = dot;
    Three.pixels[0][8] = dot;
    Three.pixels[1][8] = dot;
    Three.pixels[1][9] = dot;
    Three.pixels[1][10] = dot;
    Three.pixels[2][11] = dot;
    Three.pixels[2][12] = dot;
    Three.pixels[3][4] = dot;
    Three.pixels[3][5] = dot;
    Three.pixels[3][6] = dot;
    Three.pixels[3][7] = dot;
    Three.pixels[3][8] = dot;
    Three.pixels[3][9] = dot;
    Three.pixels[3][10] = dot;
    Three.pixels[4][9] = dot;
    Three.pixels[4][10] = dot;
    Three.pixels[4][11] = dot;
    Three.pixels[5][11] = dot;
    Three.pixels[5][12] = dot;
    Three.pixels[6][0] = dot;
    Three.pixels[6][1] = dot;
    Three.pixels[6][2] = dot;
    Three.pixels[6][3] = dot;
    Three.pixels[6][4] = dot;
    Three.pixels[6][5] = dot;
    Three.pixels[6][6] = dot;
    Three.pixels[6][7] = dot;
    Three.pixels[6][8] = dot;
    Three.pixels[6][9] = dot;
    Three.pixels[6][10] = dot;
    Three.pixels[6][11] = dot;
    Numbers[3] = Three;

    //initialize 4
    Letter Four = Letter('4');
    Four.pixels[0][0] = dot;
    Four.pixels[0][1] = dot;
    Four.pixels[0][9] = dot;
    Four.pixels[0][10] = dot;
    Four.pixels[1][0] = dot;
    Four.pixels[1][1] = dot;
    Four.pixels[1][9] = dot;
    Four.pixels[1][10] = dot;
    Four.pixels[2][0] = dot;
    Four.pixels[2][1] = dot;
    Four.pixels[2][9] = dot;
    Four.pixels[2][10] = dot;
    Four.pixels[3][0] = dot;
    Four.pixels[3][1] = dot;
    Four.pixels[3][9] = dot;
    Four.pixels[3][10] = dot;
    Four.pixels[4][0] = dot;
    Four.pixels[4][1] = dot;
    Four.pixels[4][2] = dot;
    Four.pixels[4][3] = dot;
    Four.pixels[4][4] = dot;
    Four.pixels[4][5] = dot;
    Four.pixels[4][6] = dot;
    Four.pixels[4][7] = dot;
    Four.pixels[4][8] = dot;
    Four.pixels[4][9] = dot;
    Four.pixels[4][10] = dot;
    Four.pixels[4][11] = dot;
    Four.pixels[4][12] = dot;
    Four.pixels[5][9] = dot;
    Four.pixels[5][10] = dot;
    Four.pixels[6][9] = dot;
    Four.pixels[6][10] = dot;
    Numbers[4] = Four;

    //initialize 5
    Letter Five = Letter('5');
    Five.pixels[0][0] = dot;
    Five.pixels[0][1] = dot;
    Five.pixels[0][2] = dot;
    Five.pixels[0][3] = dot;
    Five.pixels[0][4] = dot;
    Five.pixels[0][5] = dot;
    Five.pixels[0][6] = dot;
    Five.pixels[0][7] = dot;
    Five.pixels[0][8] = dot;
    Five.pixels[0][9] = dot;
    Five.pixels[0][10] = dot;
    Five.pixels[0][11] = dot;
    Five.pixels[0][12] = dot;
    Five.pixels[1][0] = dot;
    Five.pixels[1][1] = dot;
    Five.pixels[2][0] = dot;
    Five.pixels[2][1] = dot;
    Five.pixels[3][0] = dot;
    Five.pixels[3][1] = dot;
    Five.pixels[3][2] = dot;
    Five.pixels[3][3] = dot;
    Five.pixels[3][4] = dot;
    Five.pixels[3][5] = dot;
    Five.pixels[3][6] = dot;
    Five.pixels[3][7] = dot;
    Five.pixels[3][8] = dot;
    Five.pixels[3][9] = dot;
    Five.pixels[3][10] = dot;
    Five.pixels[4][10] = dot;
    Five.pixels[4][11] = dot;
    Five.pixels[4][12] = dot;
    Five.pixels[5][9] = dot;
    Five.pixels[5][10] = dot;
    Five.pixels[6][0] = dot;
    Five.pixels[6][1] = dot;
    Five.pixels[6][2] = dot;
    Five.pixels[6][3] = dot;
    Five.pixels[6][4] = dot;
    Five.pixels[6][5] = dot;
    Five.pixels[6][6] = dot;
    Five.pixels[6][7] = dot;
    Five.pixels[6][8] = dot;
    Five.pixels[6][9] = dot;
    Numbers[5] = Five;

    //initialize 6
    Letter Six('6');
    Six.pixels[0][3] = dot;
    Six.pixels[0][4] = dot;
    Six.pixels[0][5] = dot;
    Six.pixels[0][6] = dot;
    Six.pixels[0][7] = dot;
    Six.pixels[0][8] = dot;
    Six.pixels[0][9] = dot;
    Six.pixels[1][1] = dot;
    Six.pixels[1][2] = dot;
    Six.pixels[1][3] = dot;
    Six.pixels[1][9] = dot;
    Six.pixels[1][10] = dot;
    Six.pixels[1][11] = dot;
    Six.pixels[2][0] = dot;
    Six.pixels[2][1] = dot;
    Six.pixels[3][0] = dot;
    Six.pixels[3][1] = dot;
    Six.pixels[3][3] = dot;
    Six.pixels[3][4] = dot;
    Six.pixels[3][5] = dot;
    Six.pixels[3][6] = dot;
    Six.pixels[3][7] = dot;
    Six.pixels[3][8] = dot;
    Six.pixels[3][9] = dot;
    Six.pixels[3][10] = dot;
    Six.pixels[4][0] = dot;
    Six.pixels[4][1] = dot;
    Six.pixels[4][2] = dot;
    Six.pixels[4][11] = dot;
    Six.pixels[4][12] = dot;
    Six.pixels[5][1] = dot;
    Six.pixels[5][2] = dot;
    Six.pixels[5][3] = dot;
    Six.pixels[5][9] = dot;
    Six.pixels[5][10] = dot;
    Six.pixels[5][11] = dot;
    Six.pixels[6][3] = dot;
    Six.pixels[6][4] = dot;
    Six.pixels[6][5] = dot;
    Six.pixels[6][6] = dot;
    Six.pixels[6][7] = dot;
    Six.pixels[6][8] = dot;
    Six.pixels[6][9] = dot;
    Numbers[6] = Six;

    //initialize 7
    Letter Seven = Letter('7');
    Seven.pixels[0][0] = dot;
    Seven.pixels[0][1] = dot;
    Seven.pixels[0][2] = dot;
    Seven.pixels[0][3] = dot;
    Seven.pixels[0][4] = dot;
    Seven.pixels[0][5] = dot;
    Seven.pixels[0][6] = dot;
    Seven.pixels[0][7] = dot;
    Seven.pixels[0][8] = dot;
    Seven.pixels[0][9] = dot;
    Seven.pixels[0][10] = dot;
    Seven.pixels[0][11] = dot;
    Seven.pixels[0][12] = dot;
    Seven.pixels[1][11] = dot;
    Seven.pixels[1][12] = dot;
    Seven.pixels[2][10] = dot;
    Seven.pixels[2][11] = dot;
    Seven.pixels[3][9] = dot;
    Seven.pixels[3][10] = dot;
    Seven.pixels[4][8] = dot;
    Seven.pixels[4][9] = dot;
    Seven.pixels[5][7] = dot;
    Seven.pixels[5][8] = dot;
    Seven.pixels[6][6] = dot;
    Seven.pixels[6][7] = dot;
    Numbers[7] = Seven;

    //initialize 8
    Letter Eight = Letter('8');
    Eight.pixels[0][2] = dot;
    Eight.pixels[0][3] = dot;
    Eight.pixels[0][4] = dot;
    Eight.pixels[0][5] = dot;
    Eight.pixels[0][6] = dot;
    Eight.pixels[0][7] = dot;
    Eight.pixels[0][8] = dot;
    Eight.pixels[0][9] = dot;
    Eight.pixels[0][10] = dot;
    Eight.pixels[1][0] = dot;
    Eight.pixels[1][1] = dot;
    Eight.pixels[1][11] = dot;
    Eight.pixels[1][12] = dot;
    Eight.pixels[2][0] = dot;
    Eight.pixels[2][1] = dot;
    Eight.pixels[2][2] = dot;
    Eight.pixels[2][10] = dot;
    Eight.pixels[2][11] = dot;
    Eight.pixels[2][12] = dot;
    Eight.pixels[3][2] = dot;
    Eight.pixels[3][3] = dot;
    Eight.pixels[3][4] = dot;
    Eight.pixels[3][5] = dot;
    Eight.pixels[3][6] = dot;
    Eight.pixels[3][7] = dot;
    Eight.pixels[3][8] = dot;
    Eight.pixels[3][9] = dot;
    Eight.pixels[3][10] = dot;
    Eight.pixels[4][0] = dot;
    Eight.pixels[4][1] = dot;
    Eight.pixels[4][2] = dot;
    Eight.pixels[4][10] = dot;
    Eight.pixels[4][11] = dot;
    Eight.pixels[4][12] = dot;
    Eight.pixels[5][0] = dot;
    Eight.pixels[5][1] = dot;
    Eight.pixels[5][11] = dot;
    Eight.pixels[5][12] = dot;
    Eight.pixels[6][2] = dot;
    Eight.pixels[6][3] = dot;
    Eight.pixels[6][4] = dot;
    Eight.pixels[6][5] = dot;
    Eight.pixels[6][6] = dot;
    Eight.pixels[6][7] = dot;
    Eight.pixels[6][8] = dot;
    Eight.pixels[6][9] = dot;
    Eight.pixels[6][10] = dot;
    Numbers[8] = Eight;

    //initialize 9
    Letter Nine = Letter('9');
    Nine.pixels[0][2] = dot;
    Nine.pixels[0][3] = dot;
    Nine.pixels[0][4] = dot;
    Nine.pixels[0][5] = dot;
    Nine.pixels[0][6] = dot;
    Nine.pixels[0][7] = dot;
    Nine.pixels[0][8] = dot;
    Nine.pixels[0][9] = dot;
    Nine.pixels[0][10] = dot;
    Nine.pixels[1][0] = dot;
    Nine.pixels[1][1] = dot;
    Nine.pixels[1][11] = dot;
    Nine.pixels[1][12] = dot;
    Nine.pixels[2][0] = dot;
    Nine.pixels[2][1] = dot;
    Nine.pixels[2][11] = dot;
    Nine.pixels[2][12] = dot;
    Nine.pixels[3][2] = dot;
    Nine.pixels[3][3] = dot;
    Nine.pixels[3][4] = dot;
    Nine.pixels[3][5] = dot;
    Nine.pixels[3][6] = dot;
    Nine.pixels[3][7] = dot;
    Nine.pixels[3][8] = dot;
    Nine.pixels[3][9] = dot;
    Nine.pixels[3][10] = dot;
    Nine.pixels[3][11] = dot;
    Nine.pixels[3][12] = dot;
    Nine.pixels[4][11] = dot;
    Nine.pixels[4][12] = dot;
    Nine.pixels[5][11] = dot;
    Nine.pixels[5][12] = dot;
    Nine.pixels[6][11] = dot;
    Nine.pixels[6][12] = dot;
    Numbers[9] = Nine;
}

void Alphabet::initializeSymbols(char dot){
    //initialize Space
    Letter Space(' ');
    Symbols[SPACE] = Space;

    //Initialize Period
    Letter Period('.');
    Period.pixels[6][0] = dot;
    Symbols[PERIOD] = Period;

    //Initialize Exclamation
    Letter Exclamation('!');
    Exclamation.pixels[0][0] = dot;
    Exclamation.pixels[1][0] = dot;
    Exclamation.pixels[2][0] = dot;
    Exclamation.pixels[3][0] = dot;
    Exclamation.pixels[4][0] = dot;
    Exclamation.pixels[6][0] = dot;
    Symbols[EXCLAMATION] = Exclamation;

    //Initialize plus
    Letter Plus('+');
    Plus.pixels[1][6] = dot;
    Plus.pixels[2][6] = dot;
    Plus.pixels[3][2] = dot;
    Plus.pixels[3][3] = dot;
    Plus.pixels[3][4] = dot;
    Plus.pixels[3][5] = dot;
    Plus.pixels[3][6] = dot;
    Plus.pixels[3][7] = dot;
    Plus.pixels[3][8] = dot;
    Plus.pixels[3][9] = dot;
    Plus.pixels[3][10] = dot;
    Plus.pixels[4][6] = dot;
    Plus.pixels[5][6] = dot;
    Symbols[PLUS] = Plus;

    //initialize minus
    Letter Minus('-');
    Minus.pixels[3][2] = dot;
    Minus.pixels[3][3] = dot;
    Minus.pixels[3][4] = dot;
    Minus.pixels[3][5] = dot;
    Minus.pixels[3][6] = dot;
    Minus.pixels[3][7] = dot;
    Minus.pixels[3][8] = dot;
    Minus.pixels[3][9] = dot;
    Minus.pixels[3][10] = dot;
    Symbols[MINUS] = Minus;

    //initialize division
    Letter Division('/');
    Division.pixels[1][6] = dot;
    Division.pixels[3][2] = dot;
    Division.pixels[3][3] = dot;
    Division.pixels[3][4] = dot;
    Division.pixels[3][5] = dot;
    Division.pixels[3][6] = dot;
    Division.pixels[3][7] = dot;
    Division.pixels[3][8] = dot;
    Division.pixels[3][9] = dot;
    Division.pixels[3][10] = dot;
    Division.pixels[5][6] = dot;
    Symbols[DIVISION] = Division;

    //initialize equals
    Letter Equals('=');
    Equals.pixels[2][2] = dot;
    Equals.pixels[2][3] = dot;
    Equals.pixels[2][4] = dot;
    Equals.pixels[2][5] = dot;
    Equals.pixels[2][6] = dot;
    Equals.pixels[2][7] = dot;
    Equals.pixels[2][8] = dot;
    Equals.pixels[2][9] = dot;
    Equals.pixels[2][10] = dot;
    Equals.pixels[4][2] = dot;
    Equals.pixels[4][3] = dot;
    Equals.pixels[4][4] = dot;
    Equals.pixels[4][5] = dot;
    Equals.pixels[4][6] = dot;
    Equals.pixels[4][7] = dot;
    Equals.pixels[4][8] = dot;
    Equals.pixels[4][9] = dot;
    Equals.pixels[4][10] = dot;
    Symbols[EQUALS] = Equals;

    //initialize asterisk
    Letter Asterisk('*');
    Asterisk.pixels[1][4] = dot;
    Asterisk.pixels[1][8] = dot;
    Asterisk.pixels[2][5] = dot;
    Asterisk.pixels[2][7] = dot;
    Asterisk.pixels[3][6] = dot;
    Asterisk.pixels[4][5] = dot;
    Asterisk.pixels[4][7] = dot;
    Asterisk.pixels[5][4] = dot;
    Asterisk.pixels[5][8] = dot;
    Symbols[ASTERISK] = Asterisk;

    //initialize Question Mark (?)
    Letter QuestionMark('?');
    QuestionMark.pixels[0][4] = dot;
    QuestionMark.pixels[0][5] = dot;
    QuestionMark.pixels[0][6] = dot;
    QuestionMark.pixels[0][7] = dot;
    QuestionMark.pixels[0][8] = dot;
    QuestionMark.pixels[1][2] = dot;
    QuestionMark.pixels[1][3] = dot;
    QuestionMark.pixels[1][9] = dot;
    QuestionMark.pixels[2][2] = dot;
    QuestionMark.pixels[2][9] = dot;
    QuestionMark.pixels[2][10] = dot;
    QuestionMark.pixels[3][8] = dot;
    QuestionMark.pixels[3][9] = dot;
    QuestionMark.pixels[4][6] = dot;
    QuestionMark.pixels[4][7] = dot;
    QuestionMark.pixels[6][6] = dot;
    Symbols[QUESTION] = QuestionMark;

    //initialize Comma (,)
    Letter Comma(',');
    Comma.pixels[5][1] = dot;
    Comma.pixels[6][0] = dot;
    Symbols[COMMA] = Comma;

    //initialize apostrophe
    Letter Apostrophe('\'');
    Apostrophe.pixels[0][2] = dot;
    Apostrophe.pixels[1][2] = dot;
    Symbols[APOSTROPHE] = Apostrophe;

    //initialize Quotations ("")
    Letter Quotations('"');
    Quotations.pixels[0][5] = dot;
    Quotations.pixels[0][7] = dot;
    Quotations.pixels[1][5] = dot;
    Quotations.pixels[1][7] = dot;
    Symbols[QUOTATIONS] = Quotations;

    //initialize Open Parenthesis (()
    Letter OpenParenthesis('(');
    OpenParenthesis.pixels[1][6] = dot;
    OpenParenthesis.pixels[2][5] = dot;
    OpenParenthesis.pixels[3][4] = dot;
    OpenParenthesis.pixels[4][4] = dot;
    OpenParenthesis.pixels[5][5] = dot;
    OpenParenthesis.pixels[6][6] = dot;
    Symbols[OPEN_PARENTHESIS] = OpenParenthesis;

    //initialize Close Parenthesis ())
    Letter CloseParenthesis(')');
    CloseParenthesis.pixels[1][6] = dot;
    CloseParenthesis.pixels[2][7] = dot;
    CloseParenthesis.pixels[3][8] = dot;
    CloseParenthesis.pixels[4][8] = dot;
    CloseParenthesis.pixels[5][7] = dot;
    CloseParenthesis.pixels[6][6] = dot;
    Symbols[CLOSED_PARENTHESIS] = CloseParenthesis;

    //initialize Semicolon (;)
    Letter Semicolon(';');
    Semicolon.pixels[2][1] = dot;
    Semicolon.pixels[5][1] = dot;
    Semicolon.pixels[6][0] = dot;
    Symbols[SEMICOLON] = Semicolon;

}

//prints a word with letters of size 7x13 ascii characters
void printLargeWord(std::string word){
    //TO DO: convert the word to only capital letters
    Alphabet alphabet;

    for(int i = 0; i < 7; ++i){//loop through all rows of pixels
        for(int j = 0; j < (int) word.length(); ++j){ //loop through all letters in the word
            char currLetter = word[j];
            for(int k = 0; k < 13; ++k){//loop through all columns of pixels
                std::cout << alphabet.Letters[currLetter - 'A'].pixels[i][k];
            }
            if(j != (int) word.length() - 1){//ignore the space on the last letter
                std::cout << ' ';
            }
        
        }
        std::cout << '\n';
    }
}

void printLargeWordTest(){
    Alphabet alphabet;

    alphabet.Letters[0].print();
    std::cout << '\n';
    alphabet.Letters[1].print();
    std::cout << '\n';
    alphabet.Letters[2].print();
    std::cout << '\n';
    alphabet.Letters[3].print();
    std::cout << '\n';
    alphabet.Letters[4].print();
    std::cout << '\n';
    alphabet.Letters[5].print();
    std::cout << '\n';
    alphabet.Letters[6].print();
    std::cout << '\n';
    alphabet.Letters[7].print();
    std::cout << '\n';
    alphabet.Letters[8].print();
    std::cout << '\n';
    alphabet.Letters[9].print();
    std::cout << '\n';
    alphabet.Letters[10].print();
    std::cout << '\n';
    alphabet.Letters[11].print();
    std::cout << '\n';
    alphabet.Letters[12].print();
    std::cout << '\n';
    alphabet.Letters[13].print();
    std::cout << '\n';
    alphabet.Letters[14].print();
    std::cout << '\n';
    alphabet.Letters[15].print();
    std::cout << '\n';
    alphabet.Letters[16].print();
    std::cout << '\n';
    alphabet.Letters[17].print();
    std::cout << '\n';
    alphabet.Letters[18].print();
    std::cout << '\n';
    alphabet.Letters[19].print();
    std::cout << '\n';
    alphabet.Letters[20].print();
    std::cout << '\n';
    alphabet.Letters[21].print();
    std::cout << '\n';
    alphabet.Letters[22].print();
    std::cout << '\n';
    alphabet.Letters[23].print();
    std::cout << '\n';
    alphabet.Letters[24].print();
    std::cout << '\n';
    alphabet.Letters[25].print();

    printLargeWord("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}







