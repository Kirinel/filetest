#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <regex>
#include <string>
using namespace std;

int main() {
    string name;
    string doc,tmplink,tmptit,tmppass;
    string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    ifstream infile;
    ofstream outfile("output.txt");
    list<string> link;
    list<string>::iterator linkIterator;
    list<string> title;
    list<string>::iterator titleIterator;
    list<string> passage;
    list<string>::iterator passageIterator;
    unsigned long pos1,pos2;
    unsigned long p1,p2;
    int count=0;


    name="/Users/yanchuanqi/ClionProjects/filetest/HDU题目分类.webarchive";
    infile.open(name);
    while (getline(infile,doc)) {
        if(doc.find("<!--")!=-1) continue;
        //标题
        pos1=doc.find("<title>");
        pos2=doc.find("</title>");
        if(pos1 != -1) {
            tmptit=doc.substr(pos1+7,pos2-pos1-7);
            title.push_back(tmptit);
        }
        //标题完

        //内容
        pos1=doc.find("<p>");
        pos2=doc.find("</p>");
        if(pos1 != -1&&pos2 != -1) {
            p1=p2=0;
            tmppass=doc.substr(pos1+3,pos2-pos1-3);
            while (p1!=-1&&p2!=-1) {
                p1=tmppass.find_first_of('<');
                p2=tmppass.find_first_of('>',p1+1);
                if(p1 != -1&&p2 != -1) {
                    tmppass.erase(p1,p2-p1+1);
                }
                p1=tmppass.find_last_of('<');
                p2=tmppass.find_last_of('>',p1+1);
                if(p1 != -1&&p2 != -1) {
                    tmppass.erase(p1,p2-p1+1);
                }
            }
            if(tmppass=="&nbsp;") continue;
            p1=tmppass.find_first_of('<');
            p2=tmppass.find_first_of('>',p1+1);
            if(p1 != -1&&p2 != -1) {
                tmppass.erase(p1,p2-p1+1);
            }
            passage.push_back(tmppass);
            count++;
        }
        //内容完


        //超链接
        pos1=doc.find("href=\"");
        pos2=doc.find_first_of("\"",pos1 + 6);
        if(pos1 != -1) {
            tmplink=doc.substr(pos1 + 6,pos2 - pos1 - 6);
            link.push_back(tmplink);
            count++;
        }
        pos1=doc.find("src=\"");
        pos2=doc.find_first_of("\"",pos1 + 5);
        if(pos1 != -1) {
            tmplink=doc.substr(pos1 + 5,pos2 - pos1 - 5);
            link.push_back(tmplink);
        }
        //超链接完
    }
    outfile<<"标题："<<endl;
    for (titleIterator = title.begin(); titleIterator != title.end() ; titleIterator++) {
        outfile<<*titleIterator<<endl;

    }
    outfile<<endl<<endl;

    outfile<<"正文："<<endl;
    for (passageIterator = passage.begin(); passageIterator != passage.end() ; passageIterator++) {
        outfile<<*passageIterator<<endl;
    }
    outfile<<endl<<endl;

    link.sort();
    link.unique();
    outfile<<"超链接地址："<<endl;
    for (linkIterator = link.begin(); linkIterator != link.end() ; linkIterator++) {
        outfile<<*linkIterator<<endl;
    }
    outfile<<endl<<endl;

    infile.close();


    return 0;
}


/*
 * 问题及解决日志：
 * 0.有关文件流的操作
 * 1.substr中两个参数后者是长度而非位置，且要减去pos1检索字符串的长度
 * 2.vector的pop是倒叙输出，换成list后如何遍历输出（iterator），排序及去重
 * 3.提取正文及去除字体，颜色等标签：截取<p>和</p>中间内容后成对去除首尾括号
 */