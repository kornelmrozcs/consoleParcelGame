#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

void divider(char symbol, int lenght) {
    for (int i = 0; i <= lenght; i++) {
        cout << symbol << "\t";
    }
    cout << endl;
}
void truck() {
    cout << R"(
                   _________________________________________________
           /|     |                                                 |
           ||     |                                                 |
      .----|-----,| Welcome in simple Paul' s Premier Parcels game. |
      ||  ||   ==||                                                 |
 .-----'--'|   ==||                    Have fun!                    |
 |)-      ~|     ||_________________________________________________|
 | ___     |     |____...==..._  >\______________________________|
[_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
  ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
   '-'                '-'  '-'                       '-'  '-'
        )" << endl;
}
int newTruck() {
    const string frames[] = {
        R"(
                                   _________________________________________________
                           /|     |                                                 |
                           ||     |                                                 |
                      .----|-----,|                                                 |
                      ||  ||   ==||                                                 |
                 .-----'--'|   ==||                                                 |
                 |)-      ~|     ||_________________________________________________|
                 | ___     |     |____...==..._  >\______________________________|
                [_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
                  ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
                   '-'                '-'  '-'                       '-'  '-'
        )",
        R"(
                               _________________________________________________
                       /|     |                                                 |
                       ||     |                                                 |
                  .----|-----,|                                                 |
                  ||  ||   ==||                                                 |
             .-----'--'|   ==||                                                 |
             |)-      ~|     ||_________________________________________________|
             | ___     |     |____...==..._  >\______________________________|
            [_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
              ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
               '-'                '-'  '-'                       '-'  '-'
        )",
        R"(
                           _________________________________________________
                   /|     |                                                 |
                   ||     |                                                 |
              .----|-----,|                                                 |
              ||  ||   ==||                                                 |
         .-----'--'|   ==||                                                 |
         |)-      ~|     ||_________________________________________________|
         | ___     |     |____...==..._  >\______________________________|
        [_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
          ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
           '-'                '-'  '-'                       '-'  '-'
        )",

        R"(
                       _________________________________________________
               /|     |                                                 |
               ||     |                                                 |
          .----|-----,|                                                 |
          ||  ||   ==||                                                 |
     .-----'--'|   ==||                                                 |
     |)-      ~|     ||_________________________________________________|
     | ___     |     |____...==..._  >\______________________________|
    [_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
      ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
       '-'                '-'  '-'                       '-'  '-'
        )",
        R"(
                   _________________________________________________
           /|     |                                                 |
           ||     |                                                 |
      .----|-----,|                                                 |
      ||  ||   ==||                                                 |
 .-----'--'|   ==||                                                 |
 |)-      ~|     ||_________________________________________________|
 | ___     |     |____...==..._  >\______________________________|
[_/.-.\"--"-------- //.-.  .-.\\/   |/            \\ .-.  .-. //
  ( o )`==="""""""""`( o )( o )     o              `( o )( o )`
   '-'                '-'  '-'                       '-'  '-'
        )"
    };

    for (int i = 0; i < 5; ++i) {
        system("cls");
        cout << frames[i % 5] << std::endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    int count = 1;
    return count;
}

vector<int> parcelGenerator() {
    srand((unsigned)time(NULL));
    int amountParcel = 20 + (rand() % 31);
    cout << "You have a total of " << amountParcel << " parcels to load." << endl;
    vector<int> belt(amountParcel);
    for (int i = 0; i < amountParcel; i++) {
        belt[i] = 40 + (rand() % 81);
    }
    /*
    for (int i = 0; i < amountParcel; ++i) {
        cout << "Variable" << i + 1 << " = " << belt[i] << endl;
    }
    */
    return belt;



}

void game() {
    int days = 1;
    int score = 0;
    bool gameLoop = true;


    vector<int> belt = parcelGenerator();
    system("cls");
    int truckNumber = newTruck() - 1;
    truck();
    cout << "Let's start" << endl;
    int truckCapacity = 750;
    int payload = 0;
    int waitingArea = 0;
    int heaviestTruck = 0;
    while (days < 30) {
        while (!belt.empty()) {
            system("cls");
            cout << "DAY: " << days << endl;
            truck();
            cout << "There are " << belt.size() << " parcels to load." << endl;
            cout << "Parcel weight: " << belt.back() << " KG" << endl;
            cout << "How much more can you load into the truck: " << truckCapacity << " KG" << endl;
            cout << "Parcel in waiting area: " << waitingArea << " KG" << endl;
            char loadInput;

            while (true) {
                cout << "Do you want to:" << endl;
                cout << "a) Load it." << endl;
                if (waitingArea > 0) {
                    cout << "b) Load from the waiting area." << endl;
                }
                else {
                    cout << "b) Put it in the waiting area." << endl;
                }
                cout << "c) Release the truck." << endl;
                cin >> loadInput;

                if (loadInput == 'a' || loadInput == 'A') {
                    payload += belt.back();
                    truckCapacity -= belt.back();
                    belt.pop_back();
                    break;
                }
                else if ((loadInput == 'b' || loadInput == 'B') && waitingArea > 0) {
                    payload += waitingArea;
                    truckCapacity -= waitingArea;
                    waitingArea = 0;
                    break;
                }
                else if (loadInput == 'b' || loadInput == 'B') {
                    waitingArea += belt.back();
                    belt.pop_back();
                    break;
                }
                else if (loadInput == 'c' || loadInput == 'C') {
                    if (payload > 750) {
                        system("cls");
                        truck();
                        cout << "Parcel weight: " << belt.back() << " KG" << endl;
                        cout << "How much more can you load into the truck: " << truckCapacity << " KG" << endl;
                        cout << "Parcel in waiting area: " << waitingArea << " KG" << endl;
                        cout << "GAME OVER - Truck overloaded!" << endl;
                        return;
                    }
                    if (payload > heaviestTruck) {
                        heaviestTruck = payload;
                    }
                    payload = 0;
                    truckNumber++;
                    truckCapacity = 750;
                    break;
                }
                else {
                    cout << "Invalid input. Please choose a, b, or c." << endl;
                }
            }

            if (payload > 750) {
                system("cls");
                truck();
                cout << "Parcel weight: " << belt.back() << " KG" << endl;
                cout << "How much more can you load into the truck: " << truckCapacity << " KG" << endl;
                cout << "Parcel in waiting area: " << waitingArea << " KG" << endl;
                cout << "GAME OVER - Truck overloaded!" << endl;
                return;
            }


            if (waitingArea + payload > 750 && belt.back() + payload > 750) {
                if (truckCapacity < 0) {
                    system("cls");
                    truck();
                    cout << "Parcel weight: " << belt.back() << " KG" << endl;
                    cout << "How much more can you load into the truck: " << truckCapacity << " KG" << endl;
                    cout << "Parcel in waiting area: " << waitingArea << " KG" << endl;
                    cout << "GAME OVER - You stopped the traffic!" << endl;
                }
                else {
                    system("cls");
                    truck();
                    cout << "Parcel weight: " << belt.back() << " KG" << endl;
                    cout << "How much more can you load into the truck: " << truckCapacity << " KG" << endl;
                    cout << "Parcel in waiting area: " << waitingArea << " KG" << endl;
                    cout << "GAME OVER - You stopped the traffic!" << endl;
                    return;
                }
            }
        }
        truckNumber++;
        system("cls");
        truck();
        cout << "Good job! You loaded: " << truckNumber << " trucks!" << endl;
        cout << "The heaviest truck of " << days << " day: " << heaviestTruck << "KG!" << endl;
    }
    days++;

}

void printMenu() {
    system("cls");
    truck();
    char iInput;

    while (true) {
        cout << "Menu" << endl;
        cout << "a) Start" << endl;
        cout << "b) Rules" << endl;
        cout << "c) Exit the program" << endl;
        cin >> iInput;
        if (iInput == 'a' || iInput == 'A') {
            game();
        }
        else if (iInput == 'b' || iInput == 'B') {
            system("cls");
            truck();
            cout << "Each truck can hold a maximum of 750 KG." << endl;
            cout << "Single parcel can weight a maximum of 120 KG." << endl;
            cout << "Load as few trucks as possible when packing all the parcels." << endl;
            cout << "You can put one parcel in waiting zone. " << endl;
        }
        else if (iInput == 'c' || iInput == 'C') {
            break;
        }
        else {
            cout << "Invalid input. Please choose a, b, or c." << endl;
        }
    }
    system("cls");
    truck();
    cout << "Program exiting, goodbye." << endl;
    //Exit
}

int main()
{
    newTruck();
    printMenu();
    return 0;
}

