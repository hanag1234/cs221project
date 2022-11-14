#include "matcher.h"
char question = '?';
char dash = '\\';
char plus = '+';
char period = '.';
char empty = '\0';

int matches_leading(char *partial_line, char *pattern) {
    char line1= *partial_line; //declaring variable line1 for the partial line
    char test = *pattern; //just to reference easier later when using the same name in the following function
  while (test == empty || line1 == test) {
    return 1;} //true
  return 0;} //false

int rgrep_matches(char *line, char *pattern) {
    char linevalue= *line; //to make it easier to know if I am dealing with the value or address
    char test = *pattern; //copy of the pattern
    if (test == empty) { //Base case
        return 1;}
    while (dash == test) { //has to be first check because if there is a dash, the next character loses it's purpose
        if (matches_leading(line, pattern+1)) {
            return rgrep_matches(line+1, pattern+2); //recursive call
        }
        if (*(pattern + 2) == question) {
          if (linevalue == *(pattern + 1)) {
              return rgrep_matches(line+1, pattern+3); //recursive call
          }
          if (!matches_leading(line+1,pattern+3) && matches_leading(line,pattern+3)) { //function call to check if test == empty || line1 == test
              return rgrep_matches(line, pattern+3); //recursive call
          }
          else {
              return rgrep_matches(line, pattern+3); //recursive call
          }
      }
        else {
          return 0;}}
    
    if (question == *(pattern + 1)) { //checking for question mark
        if (linevalue == test) {
      return rgrep_matches(line+1, pattern+2); //recursive call
    }
        if (matches_leading(line,pattern+2) && !matches_leading(line+1,pattern+2)) { //function call to check if test == empty || line1 == test
          return rgrep_matches(line,pattern+2); //recursive call
        }
        else {
      return rgrep_matches(line, pattern+2); //recursive call
    }
  }
    
    if (plus == *(pattern + 1)) { //checking for plus sign
      if ((linevalue == test) || (period == test && linevalue != empty)) {
          if (period == *(pattern + 2) || matches_leading(line + 1, pattern + 2)) { //function call to check if test == empty || line1 == test
            return rgrep_matches(line+1, pattern+2); //recursive call
          }
          if (dash == *(pattern + 2) && matches_leading(line + 1, pattern + 3)) {
          return rgrep_matches(line+1, pattern+2); //recursive call
        }
        else {
          return rgrep_matches(line+1, pattern); //recursive call
        }}
      else {
        return 0;}}
if ((period == test && linevalue != empty) || (linevalue == test)) {
  return rgrep_matches(line+1, pattern+1);} //recursive call
else {
  return 0;}}
