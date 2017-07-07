//
// Created by Zhuojia on 7/7/17.
//

#ifndef FILETEST_WEBTOOL_H
#define FILETEST_WEBTOOL_H

/**
 * 这个类用于处理Web->String的操作
 */

#include <string>
#include <fstream>

using namespace std;

class WebTool {

    string readWebFileAsString(filebuf file);

};


#endif //FILETEST_WEBTOOL_H
