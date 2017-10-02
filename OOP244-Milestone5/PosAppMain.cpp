#include "PosApp.h"
using namespace std;
using namespace ict;

int main(){
  ict::PosApp app("posapp.txt", "bill.txt");
  app.run();
  return 0;
}