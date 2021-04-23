// Author: Qian Ruiling
// UID: 3035767827
// ENGG1340/COMP2113 Individual Project
// Worriers Versus Boss

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

// build boss struct (public class)
struct boss {
    string name;
    int blood;
    string ski_1_name;
    int ski_1_power;
    string ski_2_name;
    int ski_2_power;
    string ski_3_name;
    int ski_3_power;
    string ski_4_name;
    int ski_4_power;
};

// build worrier structure (public class)
struct worrier {
    string name;
    int blood;
    string ski_1_name;
    int ski_1_power;
    string ski_2_name;
    int ski_2_power;
    string ski_3_name;
    int ski_3_power;
    string ski_4_name;
    string ski_4_detail;
};

void game_core();

// set the user interface when they first see this game
void user_interface(bool times) {

    // clear the screen before the game
    system("clear");
    // user interface
    cout << "****************************** Boss Versus Worrier **********************************" << endl;
    cout << "                     **************************************                          " << endl;
    cout << "                      *                                  *" << endl;
    cout << "                       *                                *" << endl;
    cout << "                        *                              *" << endl;
    cout << "                         *                            *" << endl;
    cout << "                          *        Welcome!!!        *" << endl;
    cout << "                           *                        *" << endl;
    cout << "                            *                      *" << endl;
    cout << "                             *   ENJOY (￣︶￣)   *" << endl;
    cout << "                              *                  *" << endl;
    cout << "                               *                *" << endl;
    cout << "                                *              *" << endl;
    cout << "                                 *            *" << endl;
    cout << "                                  *          *" << endl;
    cout << "                                   *        *" << endl;
    cout << "                                    ********" << endl;
    cout << "*************************************************************************************" << endl;
    // enter your interface design here...
    if (times == false) {
        // if not the first time reached this function, move to the core game function directly
        game_core();
    }
    // if first time, let user input code 'o' and return to main function to open the game 
    cout << "\n\ninput 'o' to open this game" << endl;
    cout << "input any other characters to quit" << endl;
}

// this is the special round
void specialRound() {
    system("clear");//clear the screen
    cout << "What you need to do is to solve a math question" << endl;
    cout << "\nQuestion: " << endl;
    cout << "If cosθ = 3/5, find 10cos⁡(θ + π/6)." << endl;
    cout << "\n\nPlease input your answer in three significant figures " << endl;
    double ans;
    cin >> ans;
    if (ans == 1.20) {
        cout << "\n\nYour are right !!!" << endl;
        cout << "You are successfully entered into a pool" << endl;
        cout << "We will annonced the final results of whether you receive the gift several days later" << endl;
        cout << "\n\nThanks for your playing" << endl;
        cout << "Game Author: Qian Ruiling" << endl;
        cout << "Good Bye" << endl;
        // exit the game when necessary
        exit(1);
    }
    else {
        cout << "Sorry you are wrong..." << endl;
        cout << "\n\nThanks for your playing" << endl;
        cout << "Game Author: Qian Ruiling" << endl;
        cout << "Good Bye" << endl;
        // exit the game when necessary
        exit(1);
    }
}

// if success in this game , the program will call this function
void finished_success() {
    system("clear"); // clear the screen
    // enter your interface design here...
    char n;
    cout << "Congratulations!!! You successfully pass all rounds!!!\n" << endl;
    cout << "\n\nDo you think the game is so easy ???" << endl;
    cout << "Do you want to try some hard to enter in a pool to receive our gifts ?" << endl;
    cout << "\n\n***************************************************************************************" << endl;
    // let player to choose whether to enter a pool for rewards
    cout << "Please input 'g' to enter to this pool or any other characters to quit the game" << endl;
    cin >> n;
    if (n == 'g') {
        // if yes, go to special round
        specialRound();
    }
    else {
        cout << "Game Author: Qian Ruiling" << endl;
        cout << "Thank you for your playing" << endl;
    }
    // exit the game when necessary
    exit(1);   
}

// if failed the game, the program will call this function
void finished_fail() {
    system("clear"); // clear the screen
    char code_;
    
    bool first_time = false;
    
    // enter your interface design here...
    // tell player that he or she is lost and ask them whether they want to play second time
    cout << "Sorry you lost... Do you want to play again?" << endl;
    cout << "Enter 'a' to play again or enter any other characters to quit" << endl;
    cin >> code_;
    if (code_ == 'a') {
        // if yes, then move to the user_interface again, and indicate that this is not the first time to call this function
        user_interface(first_time);
    }
    else {
        // exit the game 
        cout << "Thanks for your playing" << endl;
        cout << "Game Author: Qian Ruiling" << endl;
        cout << "Good Bye" << endl;
        exit(1);
    }
    
}

// functions for each round
bool play_ground(worrier w, boss b, int num) {

    // give player some instructions
    cout << "\n\nEvery times the damage dealed by the boss are random between 0 - 70 or 0 - 500" << endl;
    int skillChoose;
    int currentWorrierBlood = w.blood;
    int currentBossBlood = b.blood;
    // random variable 'ra' will generate a number 0 or 1 to control whether player or boss go first in this round
    srand((unsigned)time(NULL));
    int ra = rand() % 2; 
    // give players some instructions
    cout << "The boss you will face in this round is " << b.name << endl;
    cout << "This boss contains " << b.blood << endl;
    cout << "Kill the boss to win this round" << endl;
    cout << "\n\nLets find who will start first..." << endl;
    cout << "Press enter to continue..." << endl;
    // pause the game to give player some preparation time
    getchar();
    if (ra == 0) {
        // PLAYER first when ra == 0
        cout << "You go first!" << endl;
        while (true) {
            cout << "Your turn" << endl;
            cout << "Please input number 1 - 4 to use your skills" << endl;
            cin >> skillChoose;
            // for each skill, perform the results
            switch (skillChoose) {
            case 1: 
                currentBossBlood = currentBossBlood - w.ski_1_power;
                //cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 2:
                currentBossBlood = currentBossBlood - w.ski_2_power;
                //cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 3:
                currentBossBlood = currentBossBlood - w.ski_3_power;
               // cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 4:
                // skill four of each worrier is sepcial skill, which can kill a boss immediately
                if (w.ski_4_name == "DeadFire" && num == 3) {
                    system("clear");
                    cout << "You win in this round" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
                else if (w.ski_4_name == "HighPressureWaterGun" && num == 2) {
                    system("clear");
                    cout << "You win in this round" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
                else if (w.ski_4_name == "KILL" && num == 1) {
                    system("clear");
                    cout << "You win in this round" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
            default:
                cout << "\n\nYour input a wrong number, so you deal 0 damage to the boss in your turn" << endl;
                continue;
            }
            // print current blood to player
            cout << "Your current blood is " << currentWorrierBlood << endl;
            cout << "Boss current blood is " << currentBossBlood <<"\n"<< endl;
            if (currentBossBlood <= 0) {
                system("clear"); //clear the screen
                cout << "You win in this round" << endl;            
                cout << w.name << "\n" << "blood: " << w.blood << endl;
                cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                return true;
            }
            // IF your blood is less then or equal to zero, then you lost in this round
            if (currentWorrierBlood <= 0) {
                cout << "You fail in this round" << endl;
                return false;
            }
            cout << "boss trun" << endl;
            // boss will rondomly select a skill between 1 - 4 to use
            srand((unsigned)time(NULL));
            int bossSelectSkill = rand() % 4 + 1;
            if (bossSelectSkill == 1) {
                cout << "boss choose skill " << b.ski_1_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_1_power;
            }
            else if (bossSelectSkill == 2) {
                cout << "boss choose skill " << b.ski_2_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_2_power;
            }
            else if (bossSelectSkill == 3) {
                cout << "boss choose skill " << b.ski_3_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_3_power;
            }
            else if (bossSelectSkill == 4) {
                cout << "boss choose skill " << b.ski_4_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_4_power;
            }
            if (currentBossBlood <= 0) {
                system("clear");
                cout << "You win in this round" << endl;               
                cout << w.name << "\n" << "blood: " << w.blood << endl;
                cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                return true;
            }
            if (currentWorrierBlood <= 0) {
                cout << "You fail in this round" << endl;
                return false;
            }
            cout << "Your current blood is " << currentWorrierBlood << endl;
            cout << "Boss current blood is " << currentBossBlood << "\n"<< endl;
        }
    }
    // when ra == 1, boss will start first
    else if (ra == 1) {
        cout << "Boss go first!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        while (true) {
            cout << "boss trun" << endl;
            srand((unsigned)time(NULL));
            int bossSelectSkill = rand() % 4 + 1;
            if (bossSelectSkill == 1) {
                cout << "boss choose skill " << b.ski_1_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_1_power;
            }
            else if (bossSelectSkill == 2) {
                cout << "boss choose skill " << b.ski_2_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_2_power;
            }
            else if (bossSelectSkill == 3) {
                cout << "boss choose skill " << b.ski_3_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_3_power;
            }
            else if (bossSelectSkill == 4) {
                cout << "boss choose skill " << b.ski_4_name << endl;
                currentWorrierBlood = currentWorrierBlood - b.ski_4_power;
            }
            if (currentBossBlood <= 0) {
                cout << "You win in this round" << endl;
                return true;
            }
            if (currentWorrierBlood <= 0) {
                cout << "You fail in this round" << endl;
                return false;
            }
            cout << "Your current blood is " << currentWorrierBlood << endl;
            cout << "Boss current blood is " << currentBossBlood << endl;
            if (currentBossBlood <= 0) {
                system("clear");
                cout << "You win in this round\n" << endl;               
                cout << w.name << "\n" << "blood: " << w.blood << endl;
                cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                return true;
            }
            if (currentWorrierBlood <= 0) {
                cout << "You fail in this round" << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                return false;
            }
            cout << "Your turn" << endl;
            cout << "Please input number 1 - 4 to use your skills" << endl;
            cin >> skillChoose;
            switch (skillChoose) {
            case 1:
                currentBossBlood = currentBossBlood - w.ski_1_power;
                //cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 2:
                currentBossBlood = currentBossBlood - w.ski_2_power;
                //cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 3:
                currentBossBlood = currentBossBlood - w.ski_3_power;
                //cout << "Boss current blood is " << currentBossBlood << endl;
                break;
            case 4:
                if (w.ski_4_name == "DeadFire" && num == 3) {         
                    system("clear");
                    cout << "You win in this round\n" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
                else if (w.ski_4_name == "HighPressureWaterGun" && num == 2) {
                    system("clear");
                    cout << "You win in this round\n" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
                else if (w.ski_4_name == "KILL" && num == 1) {
                    system("clear");
                    cout << "You win in this round" << endl;
                    cout << w.name << "\n" << "blood: " << w.blood << endl;
                    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                    return true;
                }
            default:
                cout << "\n\nYour input a wrong number, so you deal 0 damage to the boss in your turn" << endl;
                continue;
            }
            cout << "Your current blood is " << currentWorrierBlood << endl;
            cout << "Boss current blood is " << currentBossBlood << "\n" << endl;
            if (currentBossBlood <= 0) {          
                system("clear");
                cout << "You win in this round\n" << endl;
                cout << w.name << "\n" << "blood: " << w.blood << endl;
                cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
                cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
                cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
                cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
                return true;
            }
            if (currentWorrierBlood <= 0) {
                cout << "You fail in this round" << endl;
                cout << "Press enter to continue..." << endl;
                // pause the game here
                getchar();
                return false;
            }
        }

    }
    else {
        // exit the program immediately if detected some error to prevent run-time error later
        cout << "Error" << endl;
        exit(1);
    }
    return false;
}

// Constructor of the boss class (struct)
boss setBossData() {
    // ALL BOSS SKILLS CAN DEAL RANDOM DAMAGE TO EACH WORRIERS
    // BOSS WILL ALSO RANDOM USE THERE SKILLS 1 - 4
    boss reBoss;
    reBoss.name = "null";
    srand((unsigned)time(NULL));
    reBoss.blood = 200;
    int n[4];
    for (int i = 0; i < 4; i++) {
        if (i != 4) {
            // Boss skill 1-3, deal 0-70 damage to worrier
            n[i] = rand() % 70 + 1;
        }
        else {
            // Boss skill 4, deal 1-500 damage to worrier
            n[i] = rand() % 500 + 1;
        }
        
    }
    reBoss.ski_1_name = "Crash";
    reBoss.ski_1_power = n[0];
    reBoss.ski_2_name = "Smash";
    reBoss.ski_2_power = n[1];
    reBoss.ski_3_name = "Become Crazy";
    reBoss.ski_3_power = n[2];
    reBoss.ski_4_name = "Destory the World";
    reBoss.ski_4_power = n[3];
    return reBoss;
}

bool round(worrier w) {
    system("clear");//clear the screen
    int ran[4] = { 1,2,3,4 };
    int n[4];
    int i;
    int n1, n2, n3, n4;
    int num;
    int len = sizeof(ran) / sizeof(ran[0]);
    bool sus = false;
    bool each[4];
    // output manu of the Worrier skills and details
    cout << w.name << "\n" << "blood: " << w.blood << endl;
    cout << "1: " << w.ski_1_name << "\nDetails: Deal " << w.ski_1_power << " to the boss" << endl;
    cout << "2: " << w.ski_2_name << "\nDetails: Deal " << w.ski_2_power << " to the boss" << endl;
    cout << "3: " << w.ski_3_name << "\nDetails: Deal " << w.ski_3_power << " to the boss" << endl;
    cout << "4: " << w.ski_4_name << "\nDetails: " << w.ski_4_detail << endl;
    //cout << "Press any buttom to open the game" << endl;
    cout << "\nPress enter to open this game..." << endl;
    getchar();                                       // pause the game and give user some preparation time
    // define four bosses and set data to them
    boss b1;
    boss b2;
    boss b3;
    boss b4;
    boss temp;
    for (int i = 0; i < 4; i++) {
        // set boss data
        temp = setBossData();
        if (i == 0) {
            // set boss names
            temp.name = "Boss ONE";
            b1 = temp;
        }
        else if (i == 1) {
            temp.name = "Boss TWO";
            b2 = temp;
        }
        else if (i == 2) {
            temp.name = "Boss THREE";
            b3 = temp;
        }
        else {
            temp.name = "Boss FOUR";
            b4 = temp;
        }
    }
    // use rondom number to ramdomly assign boss 1 - 4 to player in each turn
    srand((unsigned)time(NULL));    
    // STL containers ensure that each time, the rondom number generated will be different
    // e.g. 1 3 2 4 or 4 1 3 2                  NOT 1 1 2 3 or something like 4 4 3 1 
    vector<int> numbers;
    n1 = rand() % 4 + 1;  
    numbers.push_back(n1);
    n2 = rand() % 4 + 1;
    while (n2 == numbers[0]) {
        n2 = rand() % 4 + 1;
    }
    numbers.push_back(n2);
    n3 = rand() % 4 + 1;
    while (n3 == numbers[0] || n3 == numbers[1]) {
        n3 = rand() % 4 + 1;
    }
    numbers.push_back(n3);
    n4 = rand() % 4 + 1;
    while (n4 == numbers[0] || n4 == numbers[1] || n4 == numbers[2]) {
        n4 = rand() % 4 + 1;
    }
    numbers.push_back(n4);
    // output the sequence of bosses taht will be faced by player 
    cout << "Sequence of bosses you will face in this game is "<< n1 << " " << n2 << " " << n3 << " " << n4 << " " << endl;
    n[0] = n1;
    n[1] = n2;
    n[2] = n3;
    n[3] = n4;
    for (i = 0; i < 4; i++) {
        // array to store boss number
        switch (n[i]) {
        case 1: {
            if (play_ground(w, b1, n[i]) == true) {
                each[i] = true;
            }
            else {
                // ANY ROUND FAIL will leads to FAIL in the whole game 
                each[i] = false;
                finished_fail();
            }
            break;
        }
        case 2: {
            if (play_ground(w, b2, n[i]) == true) {
                each[i] = true;
            }
            else {
                each[i] = false;
                finished_fail();
            }
            break;
        }
        case 3: {
            if (play_ground(w, b3, n[i]) == true) {
                each[i] = true;
            }
            else {
                each[i] = false;
                finished_fail();
            }
            break;
        }
        case 4: {
            if (play_ground(w, b4, n[i]) == true) {
                each[i] = true;
            }
            else {
                each[i] = false;
                finished_fail();
            }
            break;
        }
        default:
            cout << "Error" << endl;
            exit(1);

        }
    }
    // if all four round are passed, we can consider the player win this game
    sus = true;
    for (i = 0; i < 4; i++) {
        if (each[i] == false) {
            sus = false;
        }
    }
    // return success or fail in this game
    if (sus == true) {
        return true;
    }
    else {
        return false;
    }
}

// main game function starts here
void game_core() {
    system("clear");    // clear the screen
    //system("color 1F");  // change color of the console (not available in linux)
    int playerNum = 0;
    bool isSuccess = false;
    // use files input as a constructor of the Worrier class (structure) 
    ifstream fin;
    // let user to choose which Worrier they want
    cout << "Welcome to play this game..." << endl;
    cout << "Please enter the number of the Worrier you want: 1 or 2" << endl;
    cout << "If you enter another number, you should bear unexpected risks by your own" << endl;
    cin >> playerNum;
    switch (playerNum) {
    case 1: {
        // open corresdponding files
        cout << "Thanks, you choose player 1" << endl;
        fin.open("1.txt");
        if (fin.fail()) {
            // exit the program immediately if detected some error to prevent run-time error later
            cout << "File open error, the game is terminated immediately." << endl;
            exit(1);
        }
        break;
    }
    case 2: {
        cout << "Thanks, you choose player 2" << endl;
        fin.open("2.txt");
        if (fin.fail()) {
            cout << "File open error, the game is terminated immediately." << endl;
            exit(1);
        }
        break;
    }
    default:
        //cout << "Thanks, you choose player 2" << endl;
        // calling for special Worrier (Worrier 3)
        cout << "I already told you to enter a number between 1 or 2. What are you doing?????" << endl;
        cout << "You do NOT have another chance to choose. I will assign Worrier 3 to you" << endl;
        cout << "\nPress enter to continue..." << endl;
        getchar();
        fin.open("3.txt");
        if (fin.fail()) {
            cout << "File open error, the game is terminated immediately." << endl;
            exit(1);
        }
    }
    // input from files 
    worrier w;
    int t = 1, temp;
    string s;
    while (fin >> s) {
        switch (t) {
        case 1: {
            w.name = s;
            t++;
            break;
        }
        case 2: {
            // change string data type to integer
            istringstream inss(s);
            inss >> w.blood;
            t++;
            break;
        }
        case 3: {
            //istringstream inss(s);
            //inss >> w.blood;
            w.ski_1_name = s;
            t++;
            break;
        }
        case 4: {
            istringstream inss(s);
            inss >> w.ski_1_power;
            t++;
            break;
        }
        case 5: {
            w.ski_2_name = s;
            t++;
            break;
        }
        case 6: {
            istringstream inss(s);
            inss >> w.ski_2_power;
            t++;
            break;
        }
        case 7: {
            w.ski_3_name = s;
            t++;
            break;
        }
        case 8: {
            istringstream inss(s);
            inss >> w.ski_3_power;
            t++;
            break;
        }
        case 9: {
            w.ski_4_name = s;
            t++;
            break;
        }
        case 10: {
            w.ski_4_detail = s;
            t++;
            break;
        }
        default: {
            // exit the program immediately if detected some error to prevent run-time error later
            cout << "Error, the game terminated here...";
            t++;
            exit(1);
        }
        }    
    }
    // if fail in each round, then the game ends
    if (round(w) == false) {
            finished_fail();
    }else {
            finished_success();
    }
}

void leaveFirstTime() {
    cout << "Thanks for your interesting !!" << endl;
    cout << "Game Author: Qian Ruiling" << endl;
    cout << "Good Bye" << endl;
    exit(1);
}

// main function starts here
int main()
{
    //system("color 2F");
    //getchar();
    bool first_time = true;
    char game_code;
    // print the user interface first
    user_interface(first_time);
    cin >> game_code;
    //system("pause");
    // let user to choose whether to open the game or exit
    if (game_code == 'o') {
        system("clear");                  //clear the screen
        // open the game
        game_core();
    }
    else {
        system("clear");                  //clear the screen
        // exit by calling the leaveFirstTime funtion to indicate this is an exit by user before playing the game
        leaveFirstTime();
    }

}