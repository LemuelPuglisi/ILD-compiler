#ifndef ILD_COMPILER_PARSER_H
#define ILD_COMPILER_PARSER_H

#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

namespace Parser {
    class Reader;

    const int
            INVALID_INPUT_FILE_UNSUPPORTED = 0,
            INVALID_INPUT_FILE_NOT_EXISTS = 1,
            INVALID_INPUT_FILE_EMPTY = 2;
    const string
            FILE_EXTENSION = ".ild",
            DECLARATION_SEC_ID = "declaration",
            DECLARATION_SEC_START_REGEX_PATTERN = "^[ ]*(?i)#declaration[ ]*$",
            DECLARATION_SEC_END_REGEX_PATTERN = "^[ ]*(?i)#declaration_end[ ]*$",
            CODE_SEC_START = "#code",
            CODE_SEC_END = "#code_end";
    /*const regex
        DECLARATION_RAW_DATA("^(?i)(intero|booleano|carattere)[ ]+[a-zA-Z][a-zA-Z0-9]*([ ]+[=][ ]*[a-zA-Z0-9()]+)?[;]$"),
        DECLARATION_RAW_ARRAY("^(?i)(intero|booleano|carattere)[[][0-9]+[]][ ]+[a-zA-Z][a-zA-Z0-9]*([ ]+[=][ ]*[{][a-zA-Z0-9,]+[}])?[;]$"),
        ASSIGNMENT_RAW_DATA("^[a-zA-Z][a-zA-Z0-9]*[ ]+[=][ ]*[a-zA-Z0-9(),]+[;]$"),
        ASSIGNMENT_RAW_ARRAY("^[a-zA-Z][a-zA-Z0-9]*[[][0-9]+[]][ ]+[=][ ]*[a-zA-Z0-9(),]+[;]$");
        ^[ ]*if[ ]*\([ ]*\)[ ]*(?s).{$
    */
}
class Parser::Reader {
private:
    static Reader *instance;

    Reader() = default;

    fstream input;

    bool isInputEmpty();

    void lookForSection(vector<string> &container, vector<string> &errors, const string section_id);

public:
    static Reader *getInstance();

    void parse(vector<string> declarations, vector<string> instructions, vector<string> errors);

    bool isInputFileSupported(const string &input_file);
};

#endif
