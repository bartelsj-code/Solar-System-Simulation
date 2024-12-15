#include "mathStuff.h"
#include "sstream"


string sciNo(string rawNum){
    if (rawNum == "0"){
        return rawNum;
    }
    stringstream ss;
    char pre = rawNum[0];
    string rest = rawNum.substr(1);
    string exp = to_string(rest.length());
    rest.erase(rest.find_last_not_of('0') + 1);
    ss << pre << "." << rest << "e" << exp;
    return ss.str();
}

