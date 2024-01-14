#ifndef LETTER
#define LETTER


//Letter Struct
struct Letter{

    Letter();
    Letter(char symbol); //ctor
    void print();

    //variables
    char symbol;
    char pixels[7][13];
};

#endif