#include <iostream>
#include "util/tinyxml2.h"
 
//tinyxml2的类在tinyxml2命名空间
using namespace tinyxml2;

#define LOG_INFO(format, ...) printf("[INFO ] " format "\n", ##__VA_ARGS__)
#define LOG_ERROR(format, ...) printf("[ERROR] " format "\n", ##__VA_ARGS__)

//xml文件路径
const char* xmlPath = "/workspaces/tinyxml2/xml/test.xml";

int main(int argc, char* argv[])
{
    //构造一个xml文档类
    XMLDocument doc;
    //读取文件
    //从磁盘加载XML文件。成功返回XML_SUCCESS（0），或者返回errorID。
    doc.LoadFile(xmlPath);

    XMLElement* root = doc.FirstChildElement("cfg");
    XMLElement* ele = root;

    LOG_INFO("next sibling element name: %s", ele->Name());
    ele = ele->FirstChildElement();
    LOG_INFO("cfg element name: %s", ele->Name());

    doc.SaveFile(xmlPath);
    return 0;
}