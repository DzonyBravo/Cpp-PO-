#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class StringOperator{
    friend class Generator;
	public:
		char *charArray;
		int sizeOfArray;
		void setSizeOfArray(size_t size)
		{
		    this->sizeOfArray = size;
		}
		void findElement(char element, size_t size)
		{
            int counter=0;
            for(int i=0;i<size; i++)
            {
                if(charArray[i]==element)
                    counter++;
            }
            cout << "\nOccurences of this element: " << counter;
        };
		void reverseArray(size_t size)
		{
		    cout << "\nArray reversed: ";
            for(int i=size-1; i>= 0; i--)
            {
                cout << charArray[i];
            }
        };
		void range(int a, int b)
		{
            cout << "\nElements of string from " << a << " to " << b << ": ";
            for(int i = a; i < b; i++)
            {
                cout << charArray[i];
            }
        };
		StringOperator(char *str)
		{
			this->charArray = str;
		}
		virtual ~StringOperator()
		{
			delete[] this->charArray;
		}
};
class Generator{
	public:
		static StringOperator generateArray(size_t size)
		{
		    const unsigned int seed = time(0);
            mt19937_64 rng(seed);
            uniform_int_distribution<int> uniform_dist(65,90);
		    char *tmpArr = new char[size];
			for(int i=0; i<size; i++)
            {
				tmpArr[i] = uniform_dist(rng);
			}
			StringOperator tmpObject(tmpArr);
			tmpArr = nullptr;
			return tmpObject;
		}
};
int operator*(StringOperator basicFirstString, StringOperator basicSecondString) //WORKING
{
    return basicFirstString.sizeOfArray * basicSecondString.sizeOfArray;
}

string operator~(StringOperator basicFirstString) //WORKING
{
    string tmpString;
    int tmpSizeOfArray=basicFirstString.sizeOfArray;
    for (int i=0; i<tmpSizeOfArray; i++)
    {
        tmpString += basicFirstString.charArray[i];
        tmpString += '/';
    }
    return tmpString;
}

int operator%(StringOperator basicFirstString, StringOperator basicSecondString) //WORKING
{
    return basicFirstString.sizeOfArray%basicSecondString.sizeOfArray;
}
string operator!(StringOperator basicFirstString) //WORKING
{
    string tmpString=basicFirstString.charArray;
    int i=0;
    int j = basicFirstString.sizeOfArray-1;
    do
    {
        tmpString[i] = basicFirstString.charArray[j];
        i++;
        j--;
    } while (j>=0);
    return tmpString;
}

string operator++(StringOperator basicFirstString, int) //WORKING
{
    string tmpString=basicFirstString.charArray;
    int tmpArrayLength = basicFirstString.sizeOfArray;
    basicFirstString.charArray[tmpArrayLength] = '*';
    tmpString=basicFirstString.charArray;
    return tmpString;
}

string operator--(StringOperator basicFirstString, int) //WORKING
{
    string tmpString=basicFirstString.charArray;
    int tmpArrayLength=basicFirstString.sizeOfArray;
    basicFirstString.charArray[tmpArrayLength] = '.';
    tmpString=basicFirstString.charArray;
    return tmpString;
}

string operator+(StringOperator basicFirstString, StringOperator basicSecondString)
{
    string tmpString=basicFirstString.charArray;
    string tmpString2=basicSecondString.charArray;
    tmpString += tmpString2;
    return tmpString;
}
int main(){
    int firstArraySize, secondArraySize;
    int startOfRange, endOfRange;
    char wantedElement;
    bool good;
    cout << "Enter size of the 1st array: ";
    cin >> firstArraySize;
        if (firstArraySize > 10000)
        {
            cout << "I think that's too big, all I can do is 1000!";
            firstArraySize = 1000;
        }
        if (firstArraySize <=0)
        {
            cout << "You can't have minus length string! 10 will be better";
        }
    cout << "Enter size of the 2nd array: ";
    cin >> secondArraySize;
    if (secondArraySize > 10000)
        {
            cout << "I think that's too big, all I can do is 1000!";
            secondArraySize = 1000;
        }
    if (secondArraySize <= 0)
        {
            cout << "You can't have minus length string! 10 will be better";
            secondArraySize = 10;
        }
	auto a = Generator::generateArray(firstArraySize);
	auto b = Generator::generateArray(secondArraySize);
	a.setSizeOfArray(firstArraySize);
	b.setSizeOfArray(secondArraySize);
    cout << "Enter the element to look for, in the first array: ";
	cin >> wantedElement;
	cout << "Enter start of the range you want to search: ";
	cin >> startOfRange;
        if (startOfRange > a.sizeOfArray || startOfRange < 0)
        {
            cout << "Whoops, you can't search out of bounds, take care!\n";
            startOfRange = a.sizeOfArray;
        }
	cout << "Enter end of the range you want to search: ";
	cin >> endOfRange;
        if (endOfRange > a.sizeOfArray || startOfRange < 0)
        {
            cout << "Whoops, you can't search out of bounds, take care!\n";
            endOfRange = a.sizeOfArray;
        }
	cout << "Origin string A: " << a.charArray << "\n";
	cout << "Origin string B: " << b.charArray << "\n";
	a.findElement(toupper(wantedElement), firstArraySize);
	a.range(startOfRange, endOfRange);
	a.reverseArray(firstArraySize);
    cout << "\nMultiply    [*]  (multiply length of 2 strings)                     : " <<a*b;
    cout << "\nDivide      [~]  (divides string one by one char using backslash)   : " <<~a;
    cout << "\nModulo      [%]  (divides modulo length of 2 strings)               : " <<a%b;
    cout << "\nNegation    [!]  (revert existing string)                           : " <<!a;
    cout << "\nIncrement   [++] (adds '*' at the end of existing string)           : " <<a++;
    cout << "\nDecrement   [--] (adds '.' at the end of existing string)           : " <<a--;
    cout << "\nAdd         [+]  (adds string to another string)                    : " <<a+b;
}
