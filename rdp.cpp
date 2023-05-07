// Recursive descent parser

#include <iostream>
using namespace std;

// used to iterate the input to the next terminal symbol
char * lookahead; 
string str = "";

// Matches the character in the input
// Iterates to the next character in the string
void match(char c){
    lookahead += 1;
}

// parses input for A 
// Grammar rules: 
// A -> aA 
// A -> b 
void parse_A(){
    if(*lookahead == 'a'){
        match('a');
        parse_A();
    }
    else if(*lookahead == 'b'){
        match('b');
    }
    else{
        cout << "Error: invalid character found\n"; 
        exit(0); 
    }
}

// Initiates parsing 
void parse_S(){
    parse_A();
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
