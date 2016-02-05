//Proj1 : Word, Number, and Character Usage Statistics
//By: Lauren Conniff
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

//struct to keep seperate words and their frequency
struct wordFrequency {
	string theWord;
	int freq;
};
//struct to keep seperate numbers and their frequency
struct numberFrequency {
	string theNumber;
	int frequency;
};
//struct to keep seperate characters and their frequency
struct charFrequency {
	char c;
	int cFreq;
};

bool compareWord(const wordFrequency& left, const wordFrequency& right);
bool compareNumber(const numberFrequency& left, const numberFrequency& right);
bool compareChar(charFrequency& left, charFrequency& right);
int main()
{

  wordFrequency tempval;			//temoporary object of word frequency struct
  numberFrequency tempv;			//temporary object of number frequency struct
  charFrequency temval;				//temporary object of character frequency struct
  vector<wordFrequency> wordFreq;		//vector of word frequency struct
  vector<numberFrequency> numberFreq;		//vector of number frequency struct
  vector<string> wordVector;			//vector of word strings
  vector<string> numberVector;			//vector of number strings
  int charCount[96] = {0};			//array of integers keeping characters
  int cCounter = 0;				//integer keeping track of how many characters
  string numbers;				//string for seperate numbers
  string words;					//string for seperate words
  string line;					//string for cin 
  int temp = 0;					//temp int used for displaying list at end
  int temp3 = 0;				//'					  '
  int temp4 = 0;				//'					  '
  int count = 0;				//temp int to keep count for structs

  //reading input into string line by line until the end of the file
  while  (getline(cin, line))
  {
	//loop that keeps track of frequency for each character
	 //and is kept in the charCount array
	for (int i=0; i < line.length(); i++){ 
		if (line[i] > ' ' && line[i] < '~')
		{
			cCounter++;
                        charCount[line[i] - ' ']++;
        	}
		line[i] = tolower(line[i]);
	}

	//pushing words and numbers onto correct vector unti \'n' is reached
	for(int i=0; i < line.length(); i++){
		if(isspace(line[i]) || line[i] == '\n'){
			if(!words.empty()){
                		wordVector.push_back(words);
				words.clear();
        		}
        		if (!numbers.empty()){
                		numberVector.push_back(numbers);
				numbers.clear();
        		}
		}
		if (isalpha(line[i])){
			words.push_back(line[i]);
			if (!numbers.empty()){
				numberVector.push_back(numbers);
				numbers.clear();
			}
 		}
        	if (isdigit(line[i])){
			 numbers.push_back(line[i]);
			 if (!words.empty()){
                		wordVector.push_back(words);
				words.clear();
            		}//end of nested if statement
        	}//end of if statement
        }//end of for loop

	if(!words.empty())
	{
                wordVector.push_back(words);
		words.clear();
        }
        if (!numbers.empty()){
                numberVector.push_back(numbers);
		numbers.clear();
        }
  }//end of while loop

	//pushing last words and numbers back onto their proper vector
	if(!words.empty()){
                wordVector.push_back(words);
        }
        if (!numbers.empty()){
                numberVector.push_back(numbers);
        }

        for (vector<string>::iterator i = wordVector.begin(); i != wordVector.end(); ++i){
        	string tempi = *i;
        	for(vector<string>::iterator y = wordVector.begin(); y != wordVector.end(); ++y){
                	//this inner loops compares all the words in the word array
                	string tempy = *y;
                	if (tempi.compare(tempy)==0){
                		//count is the frequency
                   		count +=1;
                	}
        	}
        	//assign the temp struct word value to the word
        	tempval.theWord = tempi;
        	// assign the freq value of the struct to count
        	tempval.freq = count;
        	//push the temp struct on the the vector of structs
        	wordFreq.push_back(tempval);
        	//reset count
        	count = 0;
	}

	for (vector<string>::iterator i = numberVector.begin(); i != numberVector.end(); ++i){
                string tempi = *i;
                for(vector<string>::iterator y = numberVector.begin(); y != numberVector.end(); ++y){
                        //this inner loops compares all the numbers in the number array
                        string tempy = *y;
                        if (tempi.compare(tempy)==0){
                                //count is the frequency
                                count +=1;
                        }
                }
                //assign the struct word value to the number
                tempv.theNumber = tempi;
		// assign the freq value of the struct to count
                tempv.frequency = count;
                //push the struct on the the vector of structs
                numberFreq.push_back(tempv);
                //reset count
                count = 0;
        }

	//Display the most used characters
        cout << "Total " << cCounter << " characters, ";
	if (cCounter >= 10){
                cout << "10 most used characters: " << endl;
        }else if (cCounter < 10){
                cout << cCounter << " most used character(s): " << endl;
	}
	//Iterate through character array of struct to display characters
	for (int i= 0; i < 96; i++)
        {
		temval.c = i + ' ';
        	temval.cFreq = charCount[i];
		//sort(charCount, charCount+97, compareChar);
		if(temval.cFreq > 0)
         	{
         		cout << "No. " << temp << ": " << temval.c << "\t\t" << temval.cFreq << endl;
         		temp++;
         	}
	}

	//Sorts word frequency in descending order
	stable_sort(wordFreq.begin(), wordFreq.end(), compareWord);
        //Display the most used words
	cout << endl << "Total " << wordVector.size() << " different words, ";
        if (wordVector.size() >= 10){
		cout << "10 most used words: " << endl;
	}else if (wordVector.size() < 10){
		cout << wordVector.size() << " most used word(s): " << endl;
	}
	//Iterate through word vector of struct to display words
	for (vector<wordFrequency>::iterator x = wordFreq.begin(); x != wordFreq.end(); ++x){
        	wordFrequency t = *x;
		if(t.freq > 0)
		{
			cout << "No. " << temp3 << ": " << t.theWord << "\t\t" << t.freq <<endl;
			temp3++;
		}
	}

	//Sorts number frequency in descending order
        stable_sort(numberFreq.begin(), numberFreq.end(), compareNumber);
	//Display the most used numbers
	cout << endl << "Total " << numberVector.size() << " different number, ";
	if (numberVector.size() >= 10){
                cout << "10 most used numbers: " << endl;
        }else if (numberVector.size() < 10){
                cout << numberVector.size() << " most used number(s): " << endl;
	}
	//Iterate through number vector of struct to display numbers
        for (vector<numberFrequency>::iterator x = numberFreq.begin(); x != numberFreq.end(); ++x){
                numberFrequency t = *x;
		if(t.frequency > 0)
                {
                        cout << "No. " << temp4 << ": " << t.theNumber << "\t\t" << t.frequency <<endl;
                        temp4++;
                }
        }

 return 0;
}

bool compareWord(const wordFrequency& left, const wordFrequency& right) {
	return left.freq > right.freq;
}

bool compareNumber(const numberFrequency& left, const numberFrequency& right) {
	return left.frequency > right.frequency;
}

bool compareChar(charFrequency& left, charFrequency& right) {
	return left.cFreq > right.cFreq;
}
