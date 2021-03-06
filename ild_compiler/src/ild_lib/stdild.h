#ifndef ILD_COMPILER_STDILD_H
#define ILD_COMPILER_STDILD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../Structures/Data/Data.h"

using namespace std;
using namespace Data;

/* PRINTABLE */

void initReg(fstream &file, string reg, short value);

void initVar(fstream &file, Data_Node *node);

void callForSub(string fun_code, fstream &file, int sp, int pc, int params, Data_Node **buffer);

void exitForSub(fstream &file);

void sum(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void sub(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void mod(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void isEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void isNotEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void isGreater(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2, bool isEqual = false);

void isGreaterEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void isLess(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2, bool isEqual = false);

void isLessEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

void pow(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2);

/* SUBROUTINE */

void mul(fstream &file);

#endif
