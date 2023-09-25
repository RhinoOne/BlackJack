#include "data.h"

void GlobalEnumData::DeclareEnum()
{
    qmlRegisterType<GlobalEnumData>("ETypeWindow", 1, 0, "TypeWindow");
}
