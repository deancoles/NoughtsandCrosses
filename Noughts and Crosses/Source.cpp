// Libraries
#include <stdio.h>                  // Supports input and output functions
#include <tchar.h>                  // Support for characters
#include <string>                   // Support for strings
#include <conio.h>                  // Supports console input and output
#include <iostream>                 // Supports input from keyboard and output to be displayed on screen
#include <windows.h>				// Supports the functions in the Windows API
#undef max                          // Undefines MAX macro from windows.h

using namespace std;                // Supports the use of names from objects and variables in standard library

// Global function declarations
void displayGrid();                 // Shows user the display grid
void displayInput();                // Shows user the input options
void FillSquare(int row, int col);  // Finds row and column of the square to fill during the game
void checkInput();                  // Looks at the input user gives and verifies its validity
void checkStatus();                 // Looks for a win or draw during game
void Init();                        // Clears grid and sets player to 1
void nameEntry();                   // Entry for player names
int mainMenu();                     // The main menu the player will interact with
int howToplay();                    // The rules of the game
int MusicManager();                 // Music Player
int musicChoice;                    // Selection in the Music Player
int menuChoice;                     // The choices the player makes on main menu
void ColourManager(int colourNum);  // The colours used throughout the program
void SoundManager(int soundNum);    // The music and sound used throughout the program

// Global variable declarations
const int ROWS = 3;			        // Number of rows, set as const because it will not need to be changed
const int COLS = 3;			        // Number of columns, set as const because it will not need to be changed
char grid[ROWS][COLS];		        // Noughts and crosses grid
int filledSquares = 0;		        // Number of squares filled
char input = ' ';			        // User Input
int currentPlayer = 1;		        // Current player
string playerOne = " ";             // Name of Player one
string playerTwo = " ";             // Name of Player two


int main()                          // Main function of the program, includes launch screen and main menu
{
	/* ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);      // Full screen windowed mode, disabled, remove first two characters from beginning and end of line to enable */

	bool runProg = true;            // Program is running

	SoundManager(6);                // Name introduction sound

	ColourManager(12);              // Changes text colour to Intense Red
	
	// Splash screen - uses of double backslash allow backslash characters appear in the console

	cout << "         _____                      _____      _             _____                          _         "  << endl; 
	cout << "        |  __ \\                    / ____|    | |           |     \\                        | |         " << endl;
	cout << "        | |  | | ___  ___  _ __   | |     ___ | | ___  ___  | |__) | __ ___  ___  ___ _ __ | |_ ___    " << endl;
	cout << "        | |  | |/ _ \\/  _`| '_ \\  | |    / _ \\| |/ _ \\/ __| |  ___/ '__/ _ \\/ __|/ _ \\ '_ \\| __/ __|   " << endl;
	cout << "        | |__| |  __/  (_|| | | | | |___| (_) | |  __/\\__ \\ | |   | | |  __/\\__ \\  __/ | | | |_\\__ \\     " << endl;
	cout << "        |_____/ \\___|\\__,_|_| |_|  \\_____\\___/|_|\\___||___/ |_|   |_|  \\___||___/\\___|_| |_|\\__|___/ " << endl;

	
	Sleep(2400);                    // Stops execution of program for 2.4 seconds

	system("cls");                  // Clears screen

	SoundManager(1);                // Music for the opening and main menu

	ColourManager(13);              // Sets text colour to Intense Magenta


	// Welcome menu and player name entry	
	cout << "\t\t" << "-----------------------------------------------------------" << endl;
	cout << "\t\t" << "|      XX    XX                         dd    OOOOO       |" << endl;
	cout << "\t\t" << "|       XX  XX     aa aa  nn nnn        dd   OO   OO      |" << endl;
	cout << "\t\t" << "|        XXXX     aa aaa  nnn  nn   dddddd   OO   OO      |" << endl;
	cout << "\t\t" << "|       XX  XX   aa  aaa  nn   nn  dd   dd   OO   OO      |" << endl;
	cout << "\t\t" << "|      XX    XX   aaa aa  nn   nn   dddddd    OOOOO       |" << endl;
	cout << "\t\t" << "-----------------------------------------------------------" << endl;
	cout << "\t\t" << "|      Welcome to Naughts and Crosses GOTY Edition!       |" << endl;
	cout << "\t\t" << "-----------------------------------------------------------" << endl;
	cout << " " << endl;            // Blank line used for spacing purposes
	ColourManager(15);              // Changes text colour to Intense White
	cout << "\t\t"; system("pause");// Pauses program until input is received



	Init();                         // Clear grid and set player 1

	do {                            // Do at least once
		mainMenu();                 // Main menu for player to interact with
		
		switch (menuChoice)         // Player makes choice
		{
		
		case 1:                     // What to do when option 1 is chosen 
			system("cls");
			nameEntry();            // Users enter their names
			SoundManager(2);        // Game Music
			do {
				system("cls");      // Clears console display
				displayGrid();      // Shows grid to user
				displayInput();     // Shows input options for the user
				checkInput();       // Checks user input and fills in square if valid
				checkStatus();      // Checks for a win or draw
				system("cls");
			} while (toupper(input) != 'F' && toupper(input) != 'M');
			break;                  // Ends loop and moves to next command that's outside of this loop
		
		case 2:					    // What to do when option 2 is chosen 
			howToplay();		    // Display the rules
			break;
		
		case 3:
			MusicManager();         // Music Player
			break;

		case 4:					    // What to do when option 3 is chosen
			runProg = false;	    // Sets program running to false
			return 0;			    // Stops program, the 0 indicates program has ran successfully
			break;

		default:				    // If an option is given that is not between 1-3
			SoundManager(4);        // Invalid choice sound
			cout << "Please enter a valid choice" << endl; // Error message
			SoundManager(1);        // Main music
		}
	} while (toupper(input) != 'F');

	return 0;                       


	system("pause");                

	do                              // Do at least once - contains 'game loop'
	{
		system("cls");
		cout << "Welcome to Noughts and Crosses!\n" << endl;
		displayGrid();
		displayInput();
		checkInput();
		checkStatus();

	} while (toupper(input) != 'F');// Checks that the player hasn't quit by typing F

}

void nameEntry()                    // Entry for player names
{
	SoundManager(3);                // Name entry music
	ColourManager(12);              // Sets text colour to Intense Red
	cout << "Can Player One please enter their name" << endl;
	cin >> playerOne;
	cout << " " << endl;
	cout << "Hello " << playerOne << ", good luck today!" << endl;
	cout << " " << endl;
	ColourManager(14);              // Sets text colour to Yellow
	cout << "Can Player Two please enter their name" << endl;
	cin >> playerTwo;
	cout << " " << endl;
	cout << "Hello " << playerTwo << ", good luck today!" << endl;
	cout << " " << endl;
	ColourManager(15);              // Sets text colour to White
	system("Pause");
	
}

void displayGrid()                  // Displays the grid to the user
{
	//displays the grid with current values
	cout << "\t\t\t\t\t" << "|" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "|" << endl;
	cout << "\t\t\t\t\t" << "|" << "-" << "|" << "-" << "|" << "-" << "|" << endl;
	cout << "\t\t\t\t\t" << "|" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "|" << endl;
	cout << "\t\t\t\t\t" << "|" << "-" << "|" << "-" << "|" << "-" << "|" << endl;
	cout << "\t\t\t\t\t" << "|" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "|" << endl;
	cout << endl;
}

void displayInput()                // Displays the input options and current player to the user
{
	if (currentPlayer == 1)        // If the current player is 1
	{
		cout << endl;
		ColourManager(12);         // Sets text colour to Intense Red
		cout << "\t\t|        " << playerOne << " it's your turn [your piece is X]                   | ";
		ColourManager(15);         // Sets text colour to White
		cout << endl;
	}
	
	else                           // If current player is not 1
	{
		cout << endl;
		ColourManager(14);         // Sets text colour to Yellow
		cout << "\t\t|        " << playerTwo << " it's your turn [your piece is O]                   | ";
		ColourManager(15);         // Sets text colour to White
		cout << endl;
	}

	// Shows players the required input for all squares
	cout << endl;
	cout << "Q" << "|" << "W" << "|" << "E" << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << "A" << "|" << "S" << "|" << "D" << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << "Z" << "|" << "X" << "|" << "C" << endl;
}

void FillSquare(int row, int col)  // The row and column of the square to be filled
{
	if (grid[row][col] != ' ')     // If the chosen square is not empty
	{
		cout << "That square is filled, please try again" << endl;
		checkInput();              // Enter input again
	}
	
	else                           // If chosen square is empty
	{
		if (currentPlayer == 1)
			grid[row][col] = 'X';  // If player is 1 fill square with X
		else
			grid[row][col] = 'O';  // If not fill square with O

		filledSquares++;           // Adds 1 to the variable tracking the filled squares
	}
}

static void checkInput()                     // Checks the user input character validity and attempts to fill a square
{

	cin >> input;                            // Gets the character entered (as a char)
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Prevents program from filling in more than 1 square at a time if user enters multiple characters
	

	if (cin.fail())                          // If the character given is invalid
	{
		cout << " " << endl;
		cout << "Invalid character, try again!" << endl;
		checkInput();
	}

	input = toupper(input);                  // Converts the character to upper case

	switch (input)                           // Checks input character given by player
	{
	case 'Q': FillSquare(0, 0); break;       // Fill top-left 
	case 'W': FillSquare(0, 1); break;       // Fill top-centre 
	case 'E': FillSquare(0, 2); break;       // Fill top-right 
	case 'A': FillSquare(1, 0); break;       // Fill middle-left
	case 'S': FillSquare(1, 1); break;       // Fill middle-centre
	case 'D': FillSquare(1, 2); break;       // Fill middle-right
	case 'Z': FillSquare(2, 0); break;       // Fill bottom-left
	case 'X': FillSquare(2, 1); break;       // Fill bottom-centre
	case 'C': FillSquare(2, 2); break;       // Fill bottom-right

	default:                                 // If an input is given that is considered invalid
	{
		
		ColourManager(4);                    // Sets text colour to Red
		cout << "Invalid character, try again!" << endl;
		ColourManager(7);                    // Sets text colour to White
		checkInput();
	}

	break;                                   

	}

}


static void checkStatus()                    // Checks for a win or a draw
{
	char xo = 'X';                           // Character to check (X for player 1, O for player 2)
	if (currentPlayer == 2)
		xo = 'O';

	bool inPlay = true;                      // Flag for play mode set to true, the game continues

	if                                       // Check for winning combination based on last player's char entered
	(
			// Row matches
			grid[0][0] == xo && grid[0][1] == xo && grid[0][2] == xo ||
			grid[1][0] == xo && grid[1][1] == xo && grid[1][2] == xo ||
			grid[2][0] == xo && grid[2][1] == xo && grid[2][2] == xo ||

			// Column matches
			grid[0][0] == xo && grid[1][0] == xo && grid[2][0] == xo ||
			grid[0][1] == xo && grid[1][1] == xo && grid[2][1] == xo ||
			grid[0][2] == xo && grid[1][2] == xo && grid[2][2] == xo ||

			// Diagonal matches
			grid[0][0] == xo && grid[1][1] == xo && grid[2][2] == xo ||
			grid[0][2] == xo && grid[1][1] == xo && grid[2][0] == xo

	)

	{	
	if (currentPlayer == 1) 
	{                                                     // This indicates there's a win, displays winning player and sets inPlay to false, which stops the game
		cout << " " << endl;
		ColourManager(12);                                // Changes text colour to Intense Red
		cout << playerOne << " wins!" << endl;
		ColourManager(15);                                // Changes text Colour to White
		inPlay = false;
	}
	
	else if (currentPlayer == 2) 
	{
		cout << " " << endl;
		ColourManager(14);                                // Changes text colour to Yellow
		cout << playerTwo << " wins!" << endl;
		ColourManager(15);                                // Changes text colour to White
		inPlay = false;
	}

	}

	
	else if (filledSquares == ROWS * COLS)                // If the game squares are all filled
	{
		cout << "It's a draw!" << endl;                   // Display draw message and set inPlay to false, stopping the game
		inPlay = false;
	}


	if (!inPlay)                                          // If inPlay is false

	{

		displayGrid();                                    // Shows complete grid
		Init();                                           
		cout << "Play again? Any key. F to quit" << endl; // If player presses F the app will close, any other key will play match again
		cin >> input;
	}

	else                                                  // If inPlay is true

	{

		if (currentPlayer == 1)                           // Switches player from 1 to 2 or 2 to 1
			currentPlayer = 2;
		else
			currentPlayer = 1;
	}

}


static void Init()                                        // Clears the grid squares in preparation for a new game with player 1 set as current player


{
	currentPlayer = 1;
	filledSquares = 0;


	for (int row = 0; row < ROWS; row++)                 // Loop that assigns each grid square to a space char

	{
		for (int col = 0; col < COLS; col++)

		{
			grid[row][col] = ' ';
		}

	}

}


int mainMenu() {                                                  // The design of the main menu and the option selection

	system("cls");                                                // Clears screen

	ColourManager(6);                                             // Sets text colour to Brown
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(11);                                            // Sets text colour to Intense Cyan
	cout << "\t\t" << "|               Welcome to the game              |" << endl;
	cout << "\t\t" << "|                                                |" << endl;
	cout << "\t\t" << "|               1. Play a game                   |" << endl;
	cout << "\t\t" << "|               2. Learn how to play             |" << endl;
	cout << "\t\t" << "|               3. Music Player                  |" << endl;
	cout << "\t\t" << "|               4. Quit the game                 |" << endl;	
	ColourManager(6);                                             // Sets text colour to Brown
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(15);                                            // Changes text colour to Intense White
	cout << "\t\t" << ">> ";

	cin >> menuChoice;                                            // Input menu choice

	return menuChoice;                                            // Returns the value given
}


int howToplay() {                                                 // The how to play section

	system("cls");
	SoundManager(5);

	ColourManager(15);                                            // Sets text colour to Intense White
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << "|This is the game of naughts and crosses the aim |" << endl;
	cout << "\t\t" << "|of the game is to place your piece on the board |" << endl;
	cout << "\t\t" << "|in a pattern of three like the examples shown.  |" << endl;
	cout << "\t\t" << "|There are eight winning conditions and the      |" << endl;
	cout << "\t\t" << "|first to meet one is the winner.                |" << endl;
	cout << "\t\t" << "|                                                |" << endl;
	ColourManager(3);                                             // Sets text colour to Cyan
	cout << "\t\t" << "|Horizontal                                      |" << endl;
	cout << "\t\t" << "| | 1 | 2 | 3 | / |   |   |   | / |   |   |   |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << "| |   |   |   | / | 1 | 2 | 3 | / |   |   |   |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << "| |   |   |   | / |   |   |   | / | 1 | 2 | 3 |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(10);                                            // Sets text colour to Intense Green
	cout << "\t\t" << "|Vertical                                        |" << endl;
	cout << "\t\t" << "| | 1 |   |   | / |   | 1 |   | / |   |   | 1 |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << "| | 2 |   |   | / |   | 2 |   | / |   |   | 2 |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << "| | 3 |   |   | / |   | 3 |   | / |   |   | 3 |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(13);                                            // Sets text colour to Intense Magenta
	cout << "\t\t" << "|Diagonal                                        |" << endl;
	cout << "\t\t" << "| | 1 |   |   | /               / |   |   | 1 |  |" << endl;
	cout << "\t\t" << "| |   | 2 |   | /               / |   | 2 |   |  |" << endl;
	cout << "\t\t" << "| |   |   | 3 | /               / | 3 |   |   |  |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(14);                                            // Sets text colour to Yellow
	cout << "\t\t" << "|A tie                                           |" << endl;
	cout << "\t\t" << "|when none of these conditions are met the game  |" << endl;
	cout << "\t\t" << "|will end in a tie                               |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	ColourManager(15);                                            // Sets text colour to Intense White
	cout << "\t\t" << "|Press any key to return back to the menu        |" << endl;
	cout << "\t\t" << "|or F to quit                                    |" << endl;
	cout << "\t\t" << "--------------------------------------------------" << endl;
	cout << "\t\t" << ">> ";

	cin >> input;

	return input;
}

void ColourManager(int colourNum)  // The text colours used in the program
{
	switch (colourNum)
	{
	case 1:                        // Blue
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		break;
	case 2:                        // Green
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		break;
	case 3:                        // Cyan
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		break;
	case 4:                        // Red
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		break; 
	case 5:                        // Magenta
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		break;
	case 6:                        // Brown
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		break;
	case 7:                        // White
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case 8:                        // Gray
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		break;
	case 9:                        // Intense Blue
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		break;
	case 10:                       // Intense Green
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		break;
	case 11:                       // Intense Cyan
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		break;
	case 12:                       // Intense Red
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;
	case 13:                       // Intense Magenta
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		break;
	case 14:                       // Yellow
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		break;
	case 15:                       // Intense White
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		break;
	}
}

void SoundManager(int soundNum)  // The sounds used in the program
{
	switch (soundNum)
	{
	case 1:                      // Main Menu
		PlaySound(TEXT("mark"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 2:                      // Game play
		PlaySound(TEXT("noughts"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 3:                      // Name entry
		PlaySound(TEXT("battle"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 4:                      // Invalid character sound
		PlaySound(TEXT("hold"), NULL, SND_SYNC);
		break;
	case 5:                     // How To Play
		PlaySound(TEXT("jeopardy"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 6:                     // Splash Screen Sound
		PlaySound(TEXT("dean"), NULL, SND_ASYNC);
		break;
	}
}

int MusicManager()              // The music player on the main menu
{
	system("cls");

	ColourManager(14);          // Sets text colour to yellow

	cout << "\t\t" << "-----------------------------------------------------------" << endl;
	ColourManager(2);           // Sets text colour to green
	cout << "\t\t" << "|      Take a break from the game and listen to a         |" << endl;
	cout << "\t\t" << "|      selection of sounds from this program as well      |" << endl;
	cout << "\t\t" << "|      as some that didn't make the final cut.            |" << endl;
	cout << "\t\t" << "|                                                         |" << endl;
	cout << "\t\t" << "|      1. Main Menu                                       |" << endl;
	cout << "\t\t" << "|      2. Game                                            |" << endl;
	cout << "\t\t" << "|      3. Name Entry                                      |" << endl;
	cout << "\t\t" << "|      4. Invalid Character                               |" << endl;
	cout << "\t\t" << "|      5. How To Play                                     |" << endl;
	cout << "\t\t" << "|      6. Dean Coles Presents                             |" << endl;
	cout << "\t\t" << "|      7. Exit (Unused)                                   |" << endl;
	cout << "\t\t" << "|      8. Pre Match (Unused)                              |" << endl;
	cout << "\t\t" << "|      9. Draw (Unused)                                   |" << endl;
	cout << "\t\t" << "|     10. Main Menu (Unused)                              |" << endl;
	cout << "\t\t" << "|     11. Game (Unused)                                   |" << endl;
	cout << "\t\t" << "|     12. Name Entry (Unused)                             |" << endl;
	cout << "\t\t" << "|     13. How to Play (Unused)                            |" << endl;
	ColourManager(14);            // Sets text colour to yellow
	cout << "\t\t" << "-----------------------------------------------------------" << endl;
	ColourManager(15);            // Sets text colour to intense white
	cout << " " << endl;          // Blank line used for spacing purposes
	
	string playing = " ";         // Declares a string for the sound current being played

	cout << "Enter a number above to select sound or press any other key to return to the main menu" << endl;
	
	cin >> musicChoice;           // User chooses an option from the menu

	cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Makes any input outside of 1-13 send user back to main menu, prevents program from being stuck in a loop
	
	if (cin.fail())               // If the character given is invalid
	{
		mainMenu();
	}

	switch (musicChoice)
	{

	case 1:                       // Main Menu
		PlaySound(TEXT("mark"), NULL, SND_LOOP | SND_ASYNC);
		playing = " Meet Mark by Marvin Hamlisch";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 2:                       // Game play
		PlaySound(TEXT("noughts"), NULL, SND_LOOP | SND_ASYNC);
		playing = " Noughts and Crosses by George Formby";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 3:                       // Name entry
		PlaySound(TEXT("battle"), NULL, SND_LOOP | SND_ASYNC);
		playing = " Before the Battle";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 4:                       // Invalid character sound
		PlaySound(TEXT("hold"), NULL, SND_ASYNC);
		playing = " 'Hold It!' from Phoenix Wright Series";
		cout << "Just played: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 5:                       // How To Play
		PlaySound(TEXT("jeopardy"), NULL, SND_LOOP | SND_ASYNC);
		playing = " Jeopardy Theme";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 6:                       // Splash Screen Sound
		PlaySound(TEXT("dean"), NULL, SND_ASYNC);
		playing = " Howard Finkel AI voice";
		cout << "Just played: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 7:                       // Exit music (unused)
		PlaySound(TEXT("goodbye"), NULL, SND_ASYNC);
		playing = " Goodbye So Soon by Vincent Price";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 8:                       // Pre Match (unused)
		PlaySound(TEXT("rumble"), NULL, SND_ASYNC);
		playing = " Michael Buffer WCW Introduction";
		cout << "Just played: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 9:                       // Draw (unused)
		PlaySound(TEXT("draw"), NULL, SND_ASYNC);
		playing = " Howard Finkel AI voice";
		cout << "Just played: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 10:                      // Main Menu Alternate (unused)
		PlaySound(TEXT("disco"), NULL, SND_ASYNC);
		playing = " Disco by Phil Disco";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 11:                      // Game Alternate (unused)
		PlaySound(TEXT("distance"), NULL, SND_ASYNC);
		playing = " Going the Distance by Bill Conti";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	case 12:                      // Name Entry Alternate (unused)
		PlaySound(TEXT("orchis"), NULL, SND_ASYNC);
		playing = " Orchis Tower from Legend of Heroes Trails to Azure";
		cout << "Just played: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager(); 
	case 13:                       // How to Play Alternate (unused)
		PlaySound(TEXT("crossbell"), NULL, SND_ASYNC);
		playing = " Afternoon in Crossbell from Legend of Heroes Trails from Zero";
		cout << "Currently playing: " << playing << endl;
		cout << " " << endl;
		system("pause");
		MusicManager();
	default:
		break;
		return musicChoice;
	}
}