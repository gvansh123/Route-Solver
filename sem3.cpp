#include <iostream>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <cstring>
#include <map>
// H and W are used for printing purposes
#define H 7
#define W 10
using namespace std;
char usertype;
// Linked list to store route
class Route
{
public:
    string data;
    Route *next;
    Route(string a)
    {
        this->data = a;
        this->next = NULL;
    }
};
// Linked list to store cargo
class Cargo
{
public:
    string data;
    Cargo *next;
    Cargo(string a)
    {
        this->data = a;
        this->next = NULL;
    }
};
// Binary tree to store ship
// It contains data related to ship.
class Ship
{
public:
    int ship_id;
    string arrivalDate;
    string departureDate;
    int crewNumber;
    Route *route;
    string dock;
    Cargo *cargo;
    int clientId;
    Ship *left;
    Ship *right;
    // default crew number is assingned 60

    Ship(int sh_id, int cl_id, string arrive, string depart, string dok, Route *rout, Cargo *carg, int crew)
    {
        left = NULL;
        right = NULL;

        ship_id = sh_id;
        clientId = cl_id;
        arrivalDate = arrive;
        departureDate = depart;
        crewNumber = crew;
        dock = dok;
        route = rout;
        cargo = carg;
    }
    Ship(int sh_id, int crew = 60)
    {
        left = NULL;
        right = NULL;

        ship_id = sh_id;
        clientId = 0;
        arrivalDate = "";
        departureDate = "";
        crewNumber = 60;
        dock = "";
        route = NULL;
        cargo = NULL;
    }
};
// Linked list to store all ahip id.
class totalShip
{
public:
    int id;
    totalShip *next;
};
// The following functions are of route class
// Function to insert full route
int totalNumberOfRoute(Route *&head)
{
    int len = 0;
    Route *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertFullRoute(Route *&head, string data)
{
    Route *temp = new Route(data);
    Route *nptr = head;
    if (nptr == NULL)
    {
        head = temp;
    }
    else
    {
        while (nptr->next != NULL)
        {
            nptr = nptr->next;
        }
        nptr->next = temp;
    }
}
// Function to update full route
void updateRoute(Route *&head, int index, string data)
{
    Route *temp = new Route(data);
    Route *point = head;
    if (index < 0)
    {
        cout << "Cannot insert at negative index, please enter a valid one " << endl;
    }
    else
    {
        if (index == 0)
        {
            if (point == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
                return;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                point = point->next;
                if (point == NULL && i < index)
                {
                    cout << "Cannot add at invalid index,please enter a valid one " << endl;
                    return;
                }
            }
            if (point->next == NULL)
            {
                point->next = temp;
                return;
            }
            temp->next = point->next;
            point->next = temp;
        }
    }
}
// Function to print route
void printRoute(Route *&head)
{
    Route *temp = head;
    if (temp == NULL)
    {
        cout << "Currently,ship has no route" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                cout << temp->data << " .";
            }
            else
            {
                cout << temp->data << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}
// The following functions are of cargo class
// function to insert cargo
void insertFullCargo(Cargo *&head, string data)
{
    Cargo *temp = new Cargo(data);
    Cargo *nptr = head;
    if (nptr == NULL)
    {
        head = temp;
    }
    else
    {
        while (nptr->next != NULL)
        {
            nptr = nptr->next;
        }
        nptr->next = temp;
    }
}
// function to update cargo
void updateCargo(Cargo *&head, int index, string data)
{
    Cargo *temp = new Cargo(data);
    Cargo *point = head;
    if (index < 0)
    {
        cout << "Cannot insert at negative index, please enter a valid one " << endl;
    }
    else
    {
        if (index == 0)
        {
            if (point == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
                return;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                point = point->next;
                if (point == NULL && i < index)
                {
                    cout << "Cannot add at invalid index,please enter a valid one " << endl;
                    return;
                }
            }
            if (point->next == NULL)
            {
                point->next = temp;
                return;
            }
            temp->next = point->next;
            point->next = temp;
        }
    }
}
// function to print cargo
void printCargo(Cargo *&head)
{
    Cargo *temp = head;
    if (temp == NULL)
    {
        cout << "Currently,ship has no Cargo" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                cout << temp->data << " .";
            }
            else
            {
                cout << temp->data << " , ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}
// following functions are for the security purposes
// Following function is to check whether string a and b are equal or not
bool compare(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
// Function  to check username and password
int login(string username, string password, char type)
{
    string actual_owner_username = "Owner";
    string actual_owner_password = "Owner@1234";
    string actual_client_username = "Client";
    string actual_client_password = "Client@123";
    if (type == 'o' || type == 'O')
    {
        if (compare(username, actual_owner_username) && compare(password, actual_owner_password))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (compare(username, actual_client_username) && compare(password, actual_client_password))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
// function to take id and password as input and check it.
int check()
{
    cout << "\t\t\t\t\t\t\t\t\t                         \n\t\t\t\t\t\t\t   TO ACCESS THE SYSTEM, PLEASE YOU NEED TO LOGIN FIRST \n\t\t\t\t\t\t\t   ====================================================";
    cout << endl;
    char user_type;
    int count = 0;
    int r = 0;
    do
    {
        cout << "Enter o or O for Owner   and    c or C for Client" << endl;
        fflush(stdin);
        cin >> user_type;
        fflush(stdin);
        if (user_type == 'o' || user_type == 'O' || user_type == 'C' || user_type == 'c')
        {
            r = 1;
            break;
        }
        else
        {
            cout << "You have entered a wrong input.";
            if (count < 2)
            {
                cout << "Please enter a correct one." << endl;
            }
            if (count == 1)
            {
                cout << "This is your LAST CHANCE!" << endl;
            }
        }
        count++;
    } while (count != 3);
    if (count == 3)
    {
        cout << "\n\n*******ALL USER TYPE CHOICE LOGIN ATTEMPTS FAILED..PLEASE RESTART THE PROGRAM*******";
        getch();
        return 0;
    }
    else
    {

        count = 0;
        // User Login module
        do
        {
            // Take Username and Password from user to check it with admin
            r = 0;
            string username;
            string password;
            char c;
            cout << "\t\t\t\t\t           Enter Your Username:";
            fflush(stdin);
            getline(cin, username);
            cout << "\n\t\t\t\t\t\t\t   Enter Your Password:";
            fflush(stdin);
            for (int i = 0; i < 10; i++)
            {
                c = getch();
                password = password + c;
                cout << "*";
            }
            r = login(username, password, user_type);
            count++;
            // If entered username and password matches with that of admin
            if (r == 1)
            {
                cout << "\t\t\t\t\t\t\t\t\t                         \n\t\t\t\t\t\t\t   ==============================================\n\t\t\t\t\t\t\t\t#ACCESS GRANTED#\n\n\n";
                usertype = user_type;
                return 1;
            }
            // If entered username and password doesnot matches with that of admin
            else
            {
                cout << "\n\n\t\t\t\t\t\tWRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN :<\n\n\n\n";
            }
        } while (count != 3);
        if (count == 3)
        {
            cout << "\n\n*******ALL LOGIN ATTEMPTS FAILED..PLEASE RESTART THE PROGRAM*******";
            getch();
            return 0;
        }
        return 0;
    }
}
// following functions are to print the details of team members and about the topic
// function to print port
void print_larger_port()
{
    int j;
    int k;
    char zero[H][W] = {" ________",
                       "|       |",
                       "|       |",
                       "|_______|",
                       "|        ",
                       "|        ",
                       "|        "},

         one[H][W] = {" _______",
                      "|       |",
                      "|       |",
                      "|       |",
                      "|       |",
                      "|       |",
                      "|_______|"},

         two[H][W] = {" ________",
                      "|       /",
                      "|      / ",
                      "|_____/  ",
                      "|     \\  ",
                      "|      \\ ",
                      "|       \\"},

         three[H][W] = {"_________",
                        "   |     ",
                        "   |     ",
                        "   |     ",
                        "   |     ",
                        "   |     ",
                        "   |     "};

    k = 1;
    j = 0; // controls H of each character
    cout << endl;
    cout << endl;
    while (k <= 7) // controls height
    {
        cout << "\t\t\t\t\t\t\t\t";
        cout << "       " << zero[j];
        cout << "       " << one[j];
        cout << "       " << two[j];
        cout << "       " << three[j];
        cout << endl;
        k++;
        j++;
    }
    cout << endl;
    cout << "        ";
    cout << "\t\t\t\t\t\t\t\t----------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
// function to print management
void print_larger_size_management()
{
    int j, k;
    char zero[H][W] = {"         ",
                       "|\\    /|",
                       "| \\  / |",
                       "|  \\/  |",
                       "|      |",
                       "|      |",
                       "|      |"},
         one[H][W] = {"_______ ",
                      "|       |",
                      "|       |",
                      "|_______|",
                      "|       |",
                      "|       |",
                      "|       |"},

         two[H][W] = {"         ",
                      "|\\     |",
                      "| \\    |",
                      "|  \\   |",
                      "|   \\  |",
                      "|    \\ |",
                      "|     \\|"},

         three[H][W] = {"_______ ",
                        "|       |",
                        "|       |",
                        "|_______|",
                        "|       |",
                        "|       |",
                        "|       |"},

         four[H][W] = {"_________",
                       "|        ",
                       "|        ",
                       "|        ",
                       "|     --|",
                       "|       |",
                       "\\_______|"},

         five[H][W] = {" --------",
                       "|        ",
                       "|        ",
                       "|--------",
                       "|        ",
                       "|        ",
                       "|________"},
         six[H][W] = {"         ",
                      "|\\    /|",
                      "| \\  / |",
                      "|  \\/  |",
                      "|      |",
                      "|      |",
                      "|      |"},
         seven[H][W] = {"--------",
                        "|        ",
                        "|        ",
                        "|--------",
                        "|        ",
                        "|        ",
                        "|________"},
         eight[H][W] = {"         ",
                        "|\\     |",
                        "| \\    |",
                        "|  \\   |",
                        "|   \\  |",
                        "|    \\ |",
                        "|     \\|"},
         nine[H][W] = {"_________",
                       "     |  ",
                       "     |  ",
                       "     |  ",
                       "     |  ",
                       "     |  ",
                       "     |  "};

    k = 1;
    j = 0; // controls H of each digit
    cout << endl;
    cout << endl;
    while (k <= 7) // controls height
    {
        cout << "\t\t";
        cout << "       " << zero[j];
        cout << "       " << one[j];
        cout << "       " << two[j];
        cout << "       " << three[j];
        cout << "       " << four[j];
        cout << "       " << five[j];
        cout << "       " << six[j];
        cout << "       " << seven[j];
        cout << "       " << eight[j];
        cout << "       " << nine[j];

        cout << endl;
        k++;
        j++;
    }
    cout << endl;
    cout << "                    \t--------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
// function to print system
void print_larger_size_system()
{
    int j, k;
    char zero[H][W] = {"________",
                       "|        ",
                       "|        ",
                       "|_______ ",
                       "        |",
                       "        |",
                       " _______|"},
         one[H][W] = {"         ",
                      "\\     / ",
                      " \\   /  ",
                      "  \\ /   ",
                      "   |    ",
                      "   |    ",
                      "   |    "},

         two[H][W] = {"________",
                      "|        ",
                      "|        ",
                      "|_______ ",
                      "        |",
                      "        |",
                      " _______|"},

         three[H][W] = {"_________",
                        "    |   ",
                        "    |   ",
                        "    |   ",
                        "    |   ",
                        "    |   ",
                        "    |   "},

         four[H][W] = {" --------",
                       "|        ",
                       "|        ",
                       "|--------",
                       "|        ",
                       "|        ",
                       "|________"},

         five[H][W] = {"         ",
                       "|\\    /|",
                       "| \\  / |",
                       "|  \\/  |",
                       "|      |",
                       "|      |",
                       "|      |"};

    k = 1;
    j = 0; // controls H of each digit
    cout << endl;
    cout << endl;
    while (k <= 7) // controls height
    {
        cout << "\t\t\t\t\t\t";
        cout << "       " << zero[j];
        cout << "       " << one[j];
        cout << "       " << two[j];
        cout << "       " << three[j];
        cout << "       " << four[j];
        cout << "       " << five[j];
        cout << endl;
        k++;
        j++;
    }
    cout << endl;
    cout << "\t\t\t\t\t\t\t--------------------------------------------------------------------------------------------";
    cout << endl;
    getch();
}
// function to print team member details
void printTeamMembersDetails()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t| -------------------------------------------------------------------------------------------------------  |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t\t\t\tWELCOME TO THE PORT MANAGEMENT SYSTEM                            | |";
    cout << "\n\t\t\t\t\t\t\t| |\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                            | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |------------------------------------------------------------------------------------------------------| |" << endl;
    cout << "\t\t\t\t\t\t\t| |------------------------------------------------------------------------------------------------------| |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t MADE BY:-\t\t\t\t\t\t\t\t\t\t | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t ASHISH CHAUHAN     \t\t\t\t\t\t21103090\t\t | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t VANSH GUPTA       \t\t\t\t\t\t21103107\t\t | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t ARPIT GUPTA     \t\t\t\t\t\t21103108\t\t | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |\t\t ARYAN JOLLY        \t\t\t\t\t\t21103110\t\t | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                                                                                                      | |" << endl;
    cout << "\t\t\t\t\t\t\t| |------------------------------------------------------------------------------------------------------| |" << endl;
    cout << "\t\t\t\t\t\t\t|----------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    getch();
    system("cls");
}
// The following functions are of ship class
Ship *getDetailsOfShip(int temp_id)
{
    int temp_crew = 60;
    string temp_arrival, temp_departure, temp_dock, temp;
    Route *temp_route = NULL;
    Cargo *temp_cargo = NULL;
    int temp_clientId;
    cout << "Enter the client id : ";
    cin >> temp_clientId;
    fflush(stdin);
    cout << "Enter the arrival date : ";
    getline(cin, temp_arrival);
    fflush(stdin);
    cout << "Enter the departure date : ";
    getline(cin, temp_departure);
    fflush(stdin);
    if (usertype == 'o' || usertype == 'O')
    {
        cout << "Enter number of crew : ";
        cin >> temp_crew;
    }
    cout << "Enter the alloted dock name : ";
    cin >> temp_dock;
B:
    cout << "Enter the route \n Enter \'end\' to mark the end of route \n";
    cout << "Enter location : ";
    cin >> temp;
    while (compare(temp, "end") != true)
    {
        insertFullRoute(temp_route, temp);
        cout << "Enter next location" << endl;
        fflush(stdin);
        cin >> temp;
    }
    if (totalNumberOfRoute(temp_route) < 2)
    {
        temp_route = NULL;
        cout << "Route could not be stored successfully \nReason :";
        cout << "Minimum two locations required.Please enter again" << endl;
        goto B;
    }
    else
    {
        cout << "Route successfully entered" << endl;
    }
    fflush(stdin);

    cout << "Enter cargo list " << endl;
    cout << "Enter \'end\' to finish if all cargo item names are entered" << endl;
    cin >> temp;
    while (compare(temp, "end") != true)
    {
        insertFullCargo(temp_cargo, temp);
        cout << "Enter the next item" << endl;
        cin >> temp;
    }
    cout << "Cargo item list successfully entered!!" << endl;
    Ship *newShip = new Ship(temp_id, temp_clientId, temp_arrival, temp_departure, temp_dock, temp_route, temp_cargo, temp_crew);
    return newShip;
}
Ship *insertIntoShip(Ship *root, int d)
{
    if (root == NULL)
    {
        root = getDetailsOfShip(d);
        return root;
    }
    if (d > root->ship_id)
    {
        root->right = insertIntoShip(root->right, d);
    }
    else
    {
        root->left = insertIntoShip(root->left, d);
    }
    return root;
}
void takeInput(Ship *&root)
{
    int id;
    cout << "Enter ship details" << endl;
    cout << "Enter -1 if you do not want to enter more ship details ." << endl;
    cout << "Enter ship id : ";
    cin >> id;
    while (id != -1)
    {
        root = insertIntoShip(root, id);
        cout << "Enter next ship id : ";
        cin >> id;
    }
}

void displayShipdetails(Ship *ship)
{
    cout << endl;
    if (ship == NULL)
    {
        return;
    }
    cout << "Ship id               : " << ship->ship_id << endl;
    cout << "CLient Id             : " << ship->clientId << endl;
    cout << "Crew Number           : " << ship->crewNumber << endl;
    cout << "Arrival Date          : " << ship->arrivalDate << endl;
    cout << "Departure Date        : " << ship->departureDate << endl;
    cout << "Alloted Dock          : " << ship->dock << endl;
    cout << "Route                 : ";
    printRoute(ship->route);
    cout << "Cargo                 : ";
    printCargo(ship->cargo);
}
void inorder(Ship *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    displayShipdetails(root);
    inorder(root->right);
}
// check whether ship id is present or not
bool searchInShip(Ship *root, int x)
{
    Ship *temp = root;
    while (temp != NULL)
    {
        if (temp->ship_id == x)
            return true;
        if (temp->ship_id > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}
// returns pointer to the node of the ship
Ship *takeToShip(Ship *root, int key)
{
    if (root == NULL || root->ship_id == key)
        return root;
    // Key is greater than root's key
    if (root->ship_id < key)
        return takeToShip(root->right, key);
    // Key is smaller than root's key
    return takeToShip(root->left, key);
}
void updateShip(Ship *root)
{
    int sid;
    int choice = 1;
    cin >> sid;
    string temp;
    while (!searchInShip(root, sid))
    {
        cout << "You have entered a wrong loaded ship id.Please enter a correct one" << endl;
        cin >> sid;
    }
    Ship *shipToUpdate = takeToShip(root, sid);
    while (choice != 7)
    {
        fflush(stdin);
        cout << "Choose what you would like to update" << endl;
        cout << "1. Arrival date" << endl;
        cout << "2. Departure date" << endl;
        cout << "3. Crew Number" << endl;
        cout << "4. Route" << endl;
        cout << "5. Dock" << endl;
        cout << "6. Cargo" << endl;
        cout << "7. None" << endl;
        string temp_date;
        int temp_data;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new arrival date" << endl;
            cin >> temp_date;
            shipToUpdate->arrivalDate = temp_date;
            cout << "Arrival date updated successfully" << endl;
            break;
        case 2:
            cout << "Enter new departure date" << endl;
            cin >> temp_date;
            shipToUpdate->departureDate = temp_date;
            cout << "Departure date updated successfully" << endl;
            break;
        case 3:
            cout << "Enter new crew number" << endl;
            cin >> temp_data;
            shipToUpdate->crewNumber = temp_data;
            cout << "Crew Number updated successfully" << endl;
            break;
        case 4:
            printRoute(shipToUpdate->route);
            shipToUpdate->route = NULL;
            cout << "Enter the route \n Enter end to mark the end of route \n";
            cout << "Enter location : ";
            cin >> temp;
            while (compare(temp, "end") != true)
            {
                insertFullRoute(shipToUpdate->route, temp);
                cout << "Enter next location" << endl;
                fflush(stdin);
                cin >> temp;
            }
            cout << "Route successfully updated" << endl;
            break;
        case 5:
            cout << "Enter new dock name" << endl;
            cin >> temp_date;
            shipToUpdate->arrivalDate = temp_date;
            cout << "Dock updated successfully" << endl;
            break;
        case 6:
            cout << "Enter new cargo" << endl;
            cout << "Enter cargo list " << endl;
            cout << "Enter \'end\' to finish if all cargo item names are entered" << endl;
            cin >> temp;
            shipToUpdate->cargo = NULL;
            while (compare(temp, "end") != true)
            {
                insertFullCargo(shipToUpdate->cargo, temp);
                cout << "Enter the next item" << endl;
                cin >> temp;
            }
            cout << "Cargo item list successfully updated!!" << endl;
            break;
        case 7:
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
}
Ship *minValue(Ship *root)
{
    Ship *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Ship *deleteFromShip(Ship *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->ship_id == val)
        return NULL;
    if (root->ship_id == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Ship *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Ship *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->ship_id;
            root->ship_id = mini;
            root->right = deleteFromShip(root->right, mini);
        }
    }
    else if (root->ship_id > val)
    {
        root->left = deleteFromShip(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromShip(root->right, val);
        return root;
    }
    return NULL;
}
// the following functions are of totalShip
int totalNumberOfShip(totalShip *&head)
{
    int len = 0;
    totalShip *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int numberofUnloadedShips(Ship *root, totalShip *ship)
{
    int num = 0;
    totalShip *temp = ship;
    while (temp != NULL)
    {
        if (!searchInShip(root, temp->id))
        {
            num++;
        }
        temp = temp->next;
    }
    return num;
}
void insertNewShip(totalShip *&head, int data)
{
    totalShip *temp = new totalShip;
    temp->id = data;
    temp->next = NULL;
    totalShip *nptr = head;
    if (nptr == NULL)
    {
        head = temp;
    }
    else
    {
        while (nptr->next != NULL)
        {
            nptr = nptr->next;
        }
        nptr->next = temp;
    }
}
bool checkIfShipExists(totalShip *ts, int sid)
{
    totalShip *tamp = ts;
    while (ts != NULL)
    {
        if (ts->id == sid)
            return true;
        else
            ts = ts->next;
    }
    return false;
}
bool searchInClient(Ship *root, int x)
{
    Ship *temp = root;
    while (temp != NULL)
    {
        if (temp->clientId == x)
            return true;
        if (temp->clientId > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}
void getClientWise(Ship *root, map<int, int> &m)
{
    if (root == NULL)
        return;
    getClientWise(root->left, m);
    m[root->clientId]++;
    getClientWise(root->right, m);
}
void displayClientWise(Ship *root, int client)
{
    if (root == NULL)
        return;
    displayClientWise(root->left, client);
    if (root->clientId == client)
    {
        displayShipdetails(root);
    }
    displayClientWise(root->right, client);
}
void allShipDetailsClientWise(Ship *root, int client, int sno)
{
    if (root == NULL)
        return;
    allShipDetailsClientWise(root->left, client, sno);
    if (root->clientId == client)
    {
        cout << sno << "\t\t" << root->ship_id << endl;
        sno++;
    }
    allShipDetailsClientWise(root->right, client, sno);
}

// main function
int main()
{
    int numleft = 0, numrent;
    Ship *root = NULL;
    int sid = 0;
    int cnt = 0;
    totalShip *tship = NULL;
    map<int, int> ClientWiseShip;
    print_larger_port();
    cout << endl;
    cout << endl;
    cout << endl;
    print_larger_size_management();
    cout << endl;
    cout << endl;
    cout << endl;
    print_larger_size_system();
    system("cls");
    printTeamMembersDetails();
    int n, n1, id, mn, sno;
A:
    if (check())
    {
        getch();
        system("cls");
        switch (usertype)
        {
        case 'o':
        case 'O':
            n = 1;
            while (n != 5)
            {
                cout << "\n\n\n\t\t\t\t------------------------------------------MENU------------------------------------------";
                cout << "\n\t\t\t\t\t\t\t\t          ----";
                cout << endl;
                cout << endl;
                cout << "1. Show ship details";
                cout << endl;
                cout << endl;
                cout << "2. Update loaded ship details";
                cout << endl;
                cout << endl;
                cout << "3. Add ship details";
                cout << endl;
                cout << endl;
                cout << "4. Delete ship details";
                cout << endl;
                cout << endl;
                cout << "5. EXIT";
                cout << endl;
                cout << endl;
                fflush(stdin);
                cout << "\t\tENTER YOUR CHOICE : ";
                cin >> n;
                switch (n)
                {
                case 1:
                    cout << endl;
                    cout << endl;
                    cout << "1. Show client-wise ship details";
                    cout << endl;
                    cout << endl;
                    cout << "2. Show unloaded ship details";
                    cout << endl;
                    cout << endl;
                    cout << "\t\tENTER YOUR CHOICE : ";
                    cin >> n1;
                    switch (n1)
                    {
                    case 1:
                        if (root == NULL)
                        {
                            cout << "Currently,No client exist" << endl;
                            break;
                        }
                        cout << "No. of ships each client has : " << endl;

                        cout << "S.No"
                             << "\t\tClient Id"
                             << "\t\tNumber of Ships " << endl;
                        sno = 1;
                        getClientWise(root, ClientWiseShip);
                        for (auto i : ClientWiseShip)
                        {
                            cout << sno++ << "\t\t" << i.first << "\t\t\t" << i.second << endl;
                        }
                        cout << endl
                             << endl;
                        cout << "Enter client's id whose ship details you want : " << endl;
                        cin >> id;
                        cnt = 0;
                        for (auto i : ClientWiseShip)
                        {
                            if (i.first == id)
                            {
                                cnt = 1;
                                displayClientWise(root, id);
                                cout << endl;
                            }
                        }
                        if (cnt == 0)
                        {
                            cout << "No Client with given client id exists." << endl;
                            cout << "Please try again" << endl;
                        }
                        ClientWiseShip.clear();
                        break;
                    case 2:
                        cout << "No of unloaded ships : " << numberofUnloadedShips(root, tship) << endl;
                        break;
                    default:
                        cout << "Wrong choice!!";
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    if (root == NULL)
                    {
                        cout << "No ship exists." << endl;
                        cout << "Hence,no ship to update" << endl;
                    }
                    else
                    {
                        cout << "Enter the ship id to be updated : " << endl;
                        updateShip(root);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    int n2;
                    cout << endl;
                    cout << endl;
                    cout << "1. Add totally new ship ";

                    cout << endl;
                    cout << endl;
                    cout << "2. Add unloaded ship details";
                    cout << endl;
                    cout << endl;
                    cout << "\t\tENTER YOUR CHOICE : ";
                    cin >> n2;
                    switch (n2)
                    {
                    case 1:
                        cout << "Enter ship id : ";
                        cin >> id;
                        insertNewShip(tship, id);
                        cout<<"Ship added successfully"<<endl;
                        break;
                    case 2:
                        cout << "Enter ship id : ";
                        cin >> id;
                        if (checkIfShipExists(tship, id))
                        {
                            root = insertIntoShip(root, id);
                        }
                        else
                        {
                            cout << "No Ship with that id exists !!!" << endl;
                            cout << "Please try again" << endl;
                        }
                        break;
                    default:
                        cout << "Wrong choice ";
                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    if (root == NULL)
                    {
                        cout << "There are no ships to be deleted." << endl;
                    }
                    else
                    {
                        cout << "Enter the ship id to be deleted : " << endl;
                        cin >> id;
                        if (!searchInShip(root, id))
                        {
                            cout << "No ship with this id exists in the database." << endl;
                            break;
                        }
                        root = deleteFromShip(root, id);
                        cout << "Ship id deleted successfully " << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    break;
                default:
                    cout << "Wrong Choice" << endl;
                }
            }
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------";
            cout << "\n\n\n\t\t\t\t\t\t\t\t\tTHANK YOU\n\n\n";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------";
            getchar();
            if (usertype == 'o' || usertype == 'O')
            {
                system("cls");
                goto A;
            }
            break;
        case 'c':
        case 'C':
            n = 1;
            cout << "Enter client id" << endl;
            cin >> id;
            system("cls");
            while (n != 4)
            {
                cout << "--------------------------------------------------------------------------------------";
                cout << "------------------------------------------------------------------------------------------------------------------------------";
                cout << "------------------------------------------------------------------------------------------------------------------------------";
                cout << "\n\n\n\t\t\t\t------------------------------------------MENU------------------------------------------";
                cout << "\n\t\t\t\t\t\t\t\t          ----";
                cout << endl;
                cout << endl;
                cout << "1. All ship details";
                cout << endl;
                cout << endl;
                cout << "2. Specific ship details";
                cout << endl;
                cout << endl;
                cout << "3. Rent new ship";
                cout << endl;
                cout << endl;
                cout << "4. EXIT ";
                cout << endl;
                cout << endl;
                fflush(stdin);
                cout << "\t\tENTER YOUR CHOICE : ";
                cin >> n;
                switch (n)
                {
                case 1:
                    if (searchInClient(root, id))
                    {
                        cout << "Details of all the ships you rented : " << endl;
                        cout << "Sno\t\tShip id" << endl;
                        mn = 1;
                        allShipDetailsClientWise(root, id, mn);
                    }
                    else
                    {
                        cout << "Currently,No ships exist for you" << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                {
                    cout << "Enter the ship id whose details you want to see : " << endl;
                    cin >> sid;

                    Ship *myShip = takeToShip(root, sid);
                    if (myShip->clientId == id && myShip != NULL)
                    {
                        cout << "Details of ship with id " << sid << " are : " << endl;
                        displayShipdetails(myShip);
                    }
                    else
                    {
                        cout << "You have entered wrong details" << endl;
                        cout << "Please try again" << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    numleft = numberofUnloadedShips(root, tship);
                    cout << "No. of unloaded ships left : ";
                    cout << endl;
                    cout << numleft;
                    if (numleft == 0)
                    {
                        cout << "Sorry, no ships available to rent." << endl;
                        break;
                    }
                    cout << endl;
                    cout << "How many ships would you like to rent?";
                    cout << endl;
                    numrent = numleft + 1;
                    while (numrent > numleft)
                    {
                        cin >> numrent;
                        if (numrent > numleft)
                        {
                            cout << "Sorry,we cannot rent you the number of ships you demanded." << endl
                                 << "Reason : ";
                            cout << "No. of ships you want to rent exceeds no. of ships available to be rented.";
                            cout << endl;
                            cout << "Please enter a number less than or equal to the no. of ships available : ";
                            cout << endl;
                        }
                    }
                    cout << "Thank You for renting a ship from us! Please contact the owner for further details." << endl;
                    cout << "For further details, email at gupta.vansh3021@gmail.com" <<endl;
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                    break;
                default:
                    cout << "Wrong Choice" << endl;
                }
            }
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------";
            cout << "\n\n\n\t\t\t\t\t\t\t\t\tTHANK YOU\n\n\n";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------------------------------------------------------------";
            cout << "------------------------------------------------------------------------";
            getchar();
        }
    }
    else
    {
        exit(-1);
    }
    return 0;
}
