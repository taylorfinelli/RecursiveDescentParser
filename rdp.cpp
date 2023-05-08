// Recursive descent parser

// Grammar rules  |     Non-terminals  |     Terminals
// A -> aA        |     A              |    a
// A -> bB        |     B              |    b
// B -> c         |                    |    c

#include <iostream>
using namespace std;

// used to iterate the input to the next terminal symbol
char *lookahead; 
string str = "";

// Matches the character in the input
// Iterates to the next character in the string
void match(char c){
    if(c == *lookahead){
        lookahead += 1;
    }
    else{
        cout << "Error: invalid match\n";
        exit(0);
    }
}

// Parse input for B non-terminal
void parse_B(){
    if(*lookahead == 'b'){
        match('b');
        parse_B();
    }
    else if(*lookahead == 'c'){
        match('c');
    }
    else{
        cout << "Error: invalid character found\n"; 
        exit(0); 
    }
}

// Parse input for A non-terminal
void parse_A(){
    if(*lookahead == 'a'){
        match('a');
        parse_A();
    }
    else if(*lookahead == 'b'){
        match('b');
        parse_B();
    }
    else{
        cout << "Error: invalid character found\n"; 
        exit(0); 
    }
}

// Initiates parsing 
void parse_S(){
    if(*lookahead == 'a'){
        match('a');
        parse_A();
    }
    else if(*lookahead == 'b'){
        match('b');
        parse_B();
    }
    else if(*lookahead == 'c'){
        match('c');
    }
    // Should be at end of string by now
    if(*lookahead != '$'){
        cout << "Error: too much input\n"; 
        exit(0);
    }
}

int main(){
    cout << "Enter a string to parse: ";
    cin >> str; 
    str = str + "$";
    lookahead = &str[0];
    parse_S();
    // if error has not been generated through parsing, then the syntax is correct
    cout << "Syntax is correct" << endl;
}
