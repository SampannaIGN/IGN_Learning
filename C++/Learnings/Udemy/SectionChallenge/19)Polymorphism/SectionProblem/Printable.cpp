#include "Printable.h"

ostream& operator<<(ostream &sout,const Printable &printable){
    printable.print(sout);
    return sout;
}
