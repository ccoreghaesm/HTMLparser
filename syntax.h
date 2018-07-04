#ifndef SYNTAX_H
#define SYNTAX_H

#include "headquarter.h"
#include "file.h"


namespace syntax{
  bool CheckBaseSyntax(const std::string Code){
    bool state = false;
    for(int_u line=0;line < Code.length();line++){
        if(Code[line] == '<'){
            for(int_u Char=line+1;Char < Code.length();Char++){
                if(Code[Char] == '>'){
                    state = true;
                    break;
                  }
                else if(Code[Char] == '<'){
                    state = false;
                    break;
                  }
              }
            if(!state)
              return false;
            state = false;
          }
      }
    return true;
  }
  std::string EraseString(const std::string input,const int_u range_1,const int_u range_2){
    std::string result;
    for(int_u i=0;i<input.length();i++){
        if(i < range_1 || i > range_2){
            result+=input[i];
          }
      }
    return result;
  }
  std::string RemoveAdditions(std::string input){
    std::string result;
    for(int_u i=0;i< input.length();i++){
        if((input[i] == ' ' && input[i+1] == ' ') || input[i] == '\n' )
          continue;
        else
            result += input[i];
      }
    return result;
  }
  static std::string WordSpliter(std::string input){
    int_u first=0;
    int_u end=0;
    std::string Result;
    for(int_u count=0;count < input.length();count++){
        if(input[count] == '<')
          first = count;
        else if(input[count] == '>'){
            end = count;
            if(first < end)
              input = EraseString(input,first,end);
            first=end=0;
            count=0;
          }
      }
    return input;
  }
  static bool RunCode(const char* const FileName){
    std::string FileData = file::ReadFileData(FileName);
    bool Syntax = CheckBaseSyntax(FileData);
    if(!Syntax){
        std::cout << " -----[ Unfortunately,your Program is having trouble. ]-----\n";
        std::cout << "   [Type of Error]         ~> Wrong HTML Syntax\n";
        return false;
      }
    std::string result = WordSpliter(FileData);
    std::cout << "The Operation Was Completed Successfully .\n";
    std::cout << "Input ~>\n" << FileData << std::endl;
    std::cout << "-----------------------------------------------------\n";
    std::cout << "Output ~>\n" << RemoveAdditions(result) << std::endl;
    return true;
  }
}

#endif // SYNTAX_H
