#include "lex.h" /* para verifica��o autom�tica */
//#include "input.h" /* for get_input() */

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define is_end_of_input(ch)    ((ch) == '\0')
#define is_layout(ch)          (!is_end_of_input(ch) && (ch) <= ' ')
#define is_comment_starter(ch) ((ch) == '#')
#define is_comment_stopper(ch) ((ch) == '#' || (ch) == '\n')

#define is_uc_letter(ch)       ('A' <= (ch) && (ch) <= 'Z')
#define is_lc_letter(ch)       ('a' <= (ch) && (ch) <= 'z')
#define is_letter(ch)          (is_uc_letter(ch) || is_lc_letter(ch))
#define is_digit(ch)           ('0' <= (ch) && (ch) <= '9')
#define is_letter_or_digit(ch) (is_letter(ch) || is_digit(ch))
#define is_underscore(ch)      ((ch) == '_')

#define is_operator(ch)        (strchr("+-*/", (ch)) != 0)
#define is_separator(ch)       (strchr(";,(){}", (ch)) != 0)


/* PRIVATE */
static char *input;
static int dot; /* dot position in input */
static int input_char; /* character at dot position */
#define next_char() (input_char = input[++dot])

char* get_input(char *init) {
    char *ch = (char *)malloc(50);

    if (!init) {
      printf ( "Informe o texto de entrada: ");
      scanf ( "%s", ch);
    } else
        strcpy ( ch, init );
    return ch;
}

char* input_to_zstring(int iStart,int iLength) {
    int i;
    char *ch = (char *)malloc(iLength+2);
    for (i=0; i<iLength; i++)
        ch[i] = input[i+iStart];
    ch[i] = '\0';
    return ch;
}

void recognize_identifier ( void ) {
    Token.classe = IDENTIFIER; next_char();

    while (is_letter_or_digit(input_char)) { next_char(); }

    while (is_underscore(input_char)
           && is_letter_or_digit(input[dot+1])) {
        next_char();
        while (is_letter_or_digit(input_char)) { next_char(); }
    }
}

void recognize_integer ( void ) {
    Token.classe = INTEGER; next_char();
    while (is_digit(input_char)) { next_char(); }
}

void skip_layout_and_comment(void)
{
    while(is_layout(input_char)) {
        next_char();
    }
    if (is_comment_starter(input_char))   {
        next_char();
        while(!is_comment_stopper(input_char))   {
            if(is_end_of_input(input_char))
                return;
            next_char();
        }
        next_char();
        while(is_layout(input_char))   {
            next_char();
        }
    }
}

void  note_token_position() {
    //Token.pos.file_name = in
    Token.pos.char_number = dot;
}

/* PUBLIC */
Token_Type Token;
void start_lex(char *ch) {
    input = get_input(ch);
    dot = 0; input_char = input[dot];
}

void get_next_token ( void ) {
    int start_dot;

    skip_layout_and_comment ();

    note_token_position();

    start_dot = dot;

    if (is_end_of_input(input_char)) {
        Token.classe = EOF;
        strcpy( Token.repr ,  "<EOF>" );
        return;
    }

    if (is_letter(input_char)) {
        recognize_identifier ();
    } else
        if (is_digit(input_char))  {
            recognize_integer();
        } else
            if (is_operator(input_char) || is_separator(input_char)) {
                Token.classe = input_char; next_char();
            } else {
                Token.classe = ERRONEOUS;
                next_char();
            }

    Token.repr = input_to_zstring ( start_dot, dot - start_dot );


}
