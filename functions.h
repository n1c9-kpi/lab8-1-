#include <iostream>
#include <string>
#include <fstream>
using namespace std;
typedef double TE;
struct element
{
    TE dbl;
    element* next;

};
void file(element* L,element* L1,element* L2);
element* L2del(element* first);
void Ldel(element* first);
element* razdelenie(element* first, int i);
element* EnterList();
int SizeList(element* first);
element* SortList(element* first);
