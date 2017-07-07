//
// Created by Zhuojia on 7/7/17.
//

#ifndef FILETEST_REGEXTOOL_H
#define FILETEST_REGEXTOOL_H

/**
 * 这个类用于处理所有Regex操作
 */

#include <string>
#include <list>

using namespace std;

class RegexTool {


    list<string> findStringByRegex(string inputString, string regex);

};


#endif //FILETEST_REGEXTOOL_H
