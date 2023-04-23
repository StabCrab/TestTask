#include <iostream>
#include "LinkedList.h"
int main()
{
    ListRand list;

    std::fstream f;

    f.open("filei");
    if (!f.is_open() || f.eof())
        return 2;

    list.Deserialize(f);

    f.close();
    f.open("fileo");

    list.Serialize(f);
    std::cout <<"LOL";
}