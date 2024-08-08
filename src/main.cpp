#include <iostream>
#include "util/tinyxml2.h"
 
using namespace tinyxml2;

const char* outputFile = "/workspaces/tinyxml2/xml/output.xml";

void test_1()
{
    const char* xmlFile = "/workspaces/tinyxml2/xml/test_1.xml";
    XMLDocument doc;
    doc.LoadFile(xmlFile);

// ***********************************************************************************
    XMLElement* cmdEle = doc.FirstChildElement("root")->FirstChildElement("convOpenMold");


    XMLElement* cmdParentELe = cmdEle->Parent()->ToElement();
    XMLElement* callELe = cmdEle->FirstChildElement("call");
    callELe = callELe->DeepClone(&doc)->ToElement();
    cmdParentELe->InsertAfterChild(cmdEle->PreviousSibling(), callELe);
    cmdParentELe->DeleteChild(cmdEle);


    printf("%s\n", callELe->NextSiblingElement()->Name());


// ***********************************************************************************
    doc.SaveFile(outputFile);
}

int main() {
    test_1();
    return 0;
}