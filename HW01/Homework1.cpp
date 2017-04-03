#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	string title;
	string AuthorName;
	int characterCount;
	float characterFrq[26];
	int lineCount;

};

// Prototypes
void addtoCard(Book);
void displayLetterFreq(Book);
int countLetters(string, int);

int main()
{
	char another;
	do {
		string filename;
		cout << "Enter a file name to be processed" << endl;
		cin >> filename;

		fstream fin;
		fin.open(filename, ios::in);

		string output;
		Book newBook;
		if (fin.fail())
		{
			cout << "Error with finding the file" << endl;
			another = 'y';
			continue;

		}
		else
		{
			int count = 1;//only for the first line
			int contentLineCount = 0;
			newBook.characterCount = 0;
			newBook.characterFrq[26] = { 0 };
			for (int i = 0; i < 26; i++)
			{
				newBook.characterFrq[i] = 0;
			}
			while (!fin.eof())
			{
				if (count == 1)//if the first line get title then author
				{ //This is in the while loop because if the file is empty, it could cause errors (EOL)
					getline(fin, output);
					newBook.title = output;
					count++;
					getline(fin, output);
					newBook.AuthorName = output;
					continue;
				}
				else
				{
					getline(fin, output);
					if (output.empty() || (output == "Contents:"))
					{
						continue;
					}
					else
					{
						newBook.lineCount++;
						newBook.characterCount += output.length();

						for (int i = 0; i < 26; i++) // Get number of As in the line, then Bs, and so on...
						{
							newBook.characterFrq[i] += countLetters(output, i); // This isn't a frequency, it is only a count, it later becomes a freeequency
						}
					}
				}
				count++;
			}
		}
		float total = 0;
		for (int i = 0; i < 26; i++)
		{
			// Here the counts are turned into frequencies for each letter
			newBook.characterFrq[i] = 100 * (newBook.characterFrq[i] / newBook.characterCount);	// Frequencies won't add up to one hundred because "other" characters are counted
			total += newBook.characterFrq[i];
		}
		
		//Write to the file
		addtoCard(newBook);
		char answer;
		cout << "Would you like to see the letter frequency? y/n " << endl;
		cin >> answer;
		if ((answer == 'y') || (answer == 'Y'))
		{
			displayLetterFreq(newBook);
		}

		cout << "Would you like to read in another book? y/n" << endl;
		cin >> another;
	} while (another == 'y');
}

void addtoCard(Book bookCard)
{
	fstream data;
	data.open("CardCatalog.txt", ios::app);
	data << "Title: " << bookCard.title << endl;
	data << "Author Name: " << bookCard.AuthorName << endl;
	data << "Character Count: " << bookCard.characterCount << "\t";		// Character Count includes spaces because not specified in assignment
	data << "Line Count: " << bookCard.lineCount << endl;
}

int countLetters(string line, int letter)
{
	int length = line.length();
	int letterCount = 0;
	int lineCharNum;
	for (int i = 0; i < length; i++)
	{
		lineCharNum = int(line[i]);
		if (lineCharNum == (letter + 65) || (lineCharNum == (letter + 97)))//gets upper and lower case letters
		{
			
			letterCount += 1;
		}
	}
	//Return the number of the letter specified in the line
	return letterCount;
}

void displayLetterFreq(Book newBook)
{
	cout << "Letter Frequency for " << newBook.title << endl;
	for (int i = 0; i < 26; i++) {
		cout << char(i + 97) << ": " << newBook.characterFrq[i] << " %" << endl;
	}
}



