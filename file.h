#ifndef FILE_H
#define FILE_H

#include "headquarter.h"

namespace file{
  static std::string ReadFileData(const char* Address){
      std::ifstream FilePos(Address);
      std::string temp;
      std::string Data;
      if(FilePos.is_open())
          while(std::getline(FilePos,temp))
              Data += temp + '\n';
      else{
          FilePos.close();
          throw -1;
        }
      FilePos.close();
      return Data;
  }
  static bool WriteFileData(const char* Address,std::string value){
    std::ofstream FilePos(Address);
    if(FilePos.is_open()){
        FilePos << value;
        FilePos.close();
        return true;
      }
    return false;
  }
}

#endif // FILE_H
