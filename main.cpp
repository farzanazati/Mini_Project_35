/*                         GROUP 35
  ______________________________________________________________
  |                                         |                   |
  |                  NAME                   |      Matric No    |
  |_________________________________________|___________________|
  |                                         |                   |
  |             TANG JIN SHEN               |      23301943     |
  |         GARETT KHOO BOO ZHENG           |      23301528     |
  |  NUR FARZANA IZZATI BINTI BARZAN SHAH   |      23303059     |
  |                                         |                   | 
  |                                         |                   |
  |                                         |                   |
  |_________________________________________|___________________|

  TITLE: AIRLINE RESERVATION SYSTEM  
*/

#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include <iostream>

using namespace std;

int main() {
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);
    return 0;
}
