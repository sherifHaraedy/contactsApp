#include <iostream>
#include <cctype>
#include <string>
#include ".\libs\cmds\add.h"
#include ".\libs\cmds\del.h"
using std::string;

void prompt() {

    string option { };

    cout << '\n';

    cout << R"(
               _____  _____                    _____  ______ _      ______ _______ ______ 
         /\   |  __ \|  __ \                  |  __ \|  ____| |    |  ____|__   __|  ____|
        /  \  | |  | | |  | |  ______ ______  | |  | | |__  | |    | |__     | |  | |__   
       / /\ \ | |  | | |  | | |______|______| | |  | |  __| | |    |  __|    | |  |  __|  
      / ____ \| |__| | |__| |                 | |__| | |____| |____| |____   | |  | |____ 
     /_/    \_\_____/|_____/                  |_____/|______|______|______|  |_|  |______|
    )";

    cout << "\n(Psst, type in, \"add,\" or \"del[ete]\"...)\n";

    cin >> option;

    while (!cin) {
        cin.clear();
        cout << "\nPlease, enter valid input...\n";

        cin >> option;
    }

    for (int i { 0 }; i < option.length(); ++i) {

        option[i] = tolower(option[i]);
    }

    if (option == "add") {

        cout << '\n';
        add();

        prompt();
    } else if (option == "del" || option == "delete") {

        cout << '\n';
        del();

        prompt();
    } else {

        cout << "\nOkay then...";
    }

}


int main() {

     cout << R"(
          _____  _    _  ____  _   _ ______   _   _ _    _ __  __ ____  ______ _____  
         |  __ \| |  | |/ __ \| \ | |  ____| | \ | | |  | |  \/  |  _ \|  ____|  __ \ 
         | |__) | |__| | |  | |  \| | |__    |  \| | |  | | \  / | |_) | |__  | |__) |
         |  ___/|  __  | |  | | . ` |  __|   | . ` | |  | | |\/| |  _ <|  __| |  _  / 
         | |    | |  | | |__| | |\  | |____  | |\  | |__| | |  | | |_) | |____| | \ \ 
         |_|    |_|  |_|\____/|_| \_|______| |_| \_|\____/|_|  |_|____/|______|_|  \_\
                                                                              )";

    if (affirm("\nDo you want to add a contact? [Y\\N]\n")) {

        add();
        prompt();
    } else {

        cout << "\nOkay... well, this is an app for storing contacts... so, do you actually want *not* to add a contact?\n";
        prompt();
    }

    return 0;
}

