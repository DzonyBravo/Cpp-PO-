#include <iostream>
#include <string>

using namespace std;
class Complex
{
public:
    void introduction()
    {
        {
            int complexChoice;
            cout << "Hello, welcome to my Library Complex! Where you want to go from there?\n1. Library\n2. Cafeteria\3. Use our services";
            cin >> complexChoice;
            switch (complexChoice)
            {
            case 1:
                {
                    this->library();
                } break;
            case 2:
                {
                    this->cafeteria();
                } break;
            case 3:
                {
                    this->services();
                } break;
            default:
                {
                    break;
                }
            }
        } while (true);
    }

    void library()
    {
        int libraryChoice;
        cout << "Welcome in library. Would you like to see our offer for today?\n1. Yes\2. No : ";
        cin >> libraryChoice;
        switch(libraryChoice)
        {
        case 1:
            {
                ReadingMaterial firstBook;
                firstBook::addReadingMaterial("Dzieci z Bullerbyn", 1, "Jan Brzechwa", "10/10/1990", "Children", "Fantasy", "on Shelf", 250, 1, "ZNAK");
            }
        }
    }
    void cafeteria()
    {
        int cafeteriaChoice;
        cout << "Welcome to the cafeteria. What would you like to have?\n1. Drink\2. Meal\n3. Snack";
        cin >> cafeteriaChoice;
        switch(cafeteriaChoice)
        {
        case 1:
            {

            }
        }
    }
    void services()
    {
        int servicesChoice;
        cout << "Welcome to the services room. What kind of service would you like?\n1. Printing\n2. Scanning\3. Use the web";
        cin >> servicesChoice;
        switch (servicesChoice)
        {
        case 1:
            {

            }
        }
    }
};
class Product : public Complex
{
	public:
	    string name;
	    int id;
	    float price;

	    virtual void showPrice()=0;
	    virtual void showName()=0;
	    virtual void showId()=0;
		Product(){}
		~Product(){}
};
class Food: public Product
{
public:
    int calorieCount;
    string expireDate;
    void virtual showSize()=0;
    void virtual consume()=0;
    void showId()
    {
        cout << "\nID of your food is [ " << this->id << " ]";
    }
    void checkExpireDate()
    {
        cout << "\nExpire date of this product is [ " << this->expireDate << " ]. Do not consume after this date!";
    }
    void checkCalorieCount()
    {
        cout << "\nCalorie count of this product is [ " << this->calorieCount << " ]";
    }
};
class Drink final: public Food
{
public:
    bool containsSugar;
    int sizeOfDrink;
    void consume()
    {
        cout << "\nYou drank your " << this->sizeOfDrink <<" ml " << this->name;
        if (containsSugar == true)
            cout << ", with sugar.";
        else
            cout << ".";
        cout << " Your calorie count has been raised by " << this->calorieCount << " calories";
    }
    void showSize()
    {
        cout << "\nYour drink is [ " << this->sizeOfDrink << " ] ml big";
    }
    void showName()
    {
        cout << "\nName of your drink is [ " << this->name << " ]";
    }
    void showPrice()
    {
        cout << "\nPrice per 500ml is [ " << this->price << " ]";
    }
    bool checkSugar()
    {
        return this->containsSugar;
    }
    Drink(){}
    ~Drink(){}
};
class Meal final: public Food
{
public:
    //Plate *singlePlate;
    bool vegan;
    string sizeOfMeal;
    void consume()
    {
        cout << "\nYou ate ";
        if (this->vegan == true)
            cout << "vegan ";
        cout << this->name << ", " << this->sizeOfMeal << " size. Your calorie count was raised by " << this->calorieCount;
    }
    void showSize()
    {
        cout << "\nYour meal is [ " << this->sizeOfMeal << " ] size";
    }
    void showPrice()
    {
        cout << "\nPrice for small portion is [ " << this->price << " ]";
        cout << "\nPrice for medium portion is [ " << this->price *2 << " ]";
        cout << "\nPrice for big portion is [ " << this->price *3 << " ]";
    }
    void showName()
    {
        cout << "\nName of this dish is [ " << this->name << " ]";
    }
    bool isVegan()
    {
        return this->vegan;
    }
    Meal(){}
    ~Meal(){}
};
class Snack final: public Food
{
public:
//    PlasticPackage *singlePackage;
    bool saturatedFat;
    string sizeOfSnack;

    void consume()
    {
        cout << "\nYou ate your " << this->sizeOfSnack << " sized " << this->name;
        if (saturatedFat == true)
            cout << ", with saturated fat.";
        else
            cout << ".";
        cout << " Your calorie count was raised by " << this->calorieCount;
    }
    void showSize()
    {
        cout << "\nYour snack is [ " << this->sizeOfSnack << " ] size";
    }
    void showName()
    {
        cout << "\nName of your snack is [ " << this->name << " ]";
    }
    void showPrice()
    {
        cout << "\nPrice for small snack is [ " << this->price << " ]";
        cout << "\nPrice for medium snack is [ " << this->price * 2 << " ]";
        cout << "\nPrice for large snack is [ " << this->price * 3 << " ]";
    }
    bool checkForSaturatedFat()
    {
        return saturatedFat;
    }
    Snack(){}
    ~Snack(){}
};
class Service: public Product
{
public:
    virtual void doService() = 0;
    virtual void showName()
    {
        cout << "\nName of this service is [ " << this->name << " ]";
    }
    virtual void showId()
    {
        cout << "\nId of this service is [ " << this->id << " ]";
    }
};
class Printing: public Service
{
public:
//    PrinterDevice *printer;
    bool color;
    int numberOfPagesToPrint;
    bool twoSidedPrinting;
    string sizeType;

    void doService()
    {
        int colorChoice, sizeTypeChoice, twoSidedChoice;
        cout << "\nPlease specify how many pages you want to print: ";
        cin >> this->numberOfPagesToPrint;
        cout << "1. Black/white / 2. Color : ";
        cin >> colorChoice;
        switch (colorChoice)
        {
        case 1:
            {
                this->color = false;
            } break;
        case 2:
            {
                this->color = true;
            } break;
        default:
            {
                break;
            }
        }
        cout << "Two sided? 1. Yes / 2. No : ";
        cin >> twoSidedChoice;
        switch (twoSidedChoice)
        {
        case 1:
            {
                this->twoSidedPrinting = true;
            }break;
        case 2:
            {
                this->twoSidedPrinting = false;
            }break;
        default:
            {
                break;
            }
        }
        cout << "Size Type ? 1. A1  / 2. A2 / 3. A3 / 4. A4 / 5. A5 : ";
        cin >> sizeTypeChoice;
        switch (sizeTypeChoice)
        {
        case 1:
            {
                this->sizeType = "A1";
            }break;
        case 2:
            {
                this->sizeType = "A2";
            }break;
        case 3:
            {
                this->sizeType = "A3";
            }break;
        case 4:
            {
                this->sizeType = "A4";
            }break;
        case 5:
            {
                this->sizeType = "A5";
            }break;
        default:
            {
                break;
            }
        }
        cout << "Great! Your " << this->numberOfPagesToPrint << " pages are going to be printed ";
            if (this->color == true)
                cout << "black/white,";
            else
                cout << "in color,";
        cout << " in " << this->sizeType << " size type";
            if (this->twoSidedPrinting == true)
                cout << ", two sided";
            else
                cout << ".";
    }
    void showPrice()
    {
        cout << "\nPrice of single black/white page is " << this->price << " PLN";
        cout << "\nPrice of single color page is " << this->price * 2 << " PLN";
    }
    Printing()
    {
    }
    ~Printing()
    {
    }
};
class Scanning: public Service
{
public:
//    PrinterDevice *printer;
    string sizeType;
    string extension;
    int numberOfPagesToScan;

    void doService()
    {
        cout << "\nPlease specify how many pages you want to scan: ";
        cin >> this->numberOfPagesToScan;
        cout << "\nPlease enter extension you want your file to be saved in: (ex. .pdf): ";
        cin >> this->extension;
        cout << "\nPlease enter size type (A4/A3/A2/A1) you want your document to be saved in: ";
        cin >> this->sizeType;
        cout << "\nGreat! Your " << this->numberOfPagesToScan << " are going to be scanned in " << this->sizeType << " size type and saved with " << this->extension << " extension!";
    }

    void showPrice()
    {
        int tmp;
        tmp = this->price / 8;
        cout << "\nPrice of scanning single page is [ " << tmp << " ] PLN";
    }
    Scanning()
    {
    }
    ~Scanning()
    {
    }
};
class WebUsing: public Service
{
public:
//    Computer *singlePc;
    int usageLength;
    int connectionSpeed;
    int maxConnectionSpeed;

    void doService()
    {
        cout << "\nPlease specify how many hours you want to spend browsing web: ";
        cin >> this->usageLength;
        cout << "\nPlease enter desired connection speed (in Mb/s): ";
        cin >> this->connectionSpeed;
        if (this->connectionSpeed > this->maxConnectionSpeed)
            cout << "\nSorry, best we can do is " << this->maxConnectionSpeed << " Mb/s.";
        cout << "\nGreat! You will be using Internet for " << this->usageLength << " with " << this->connectionSpeed << " Mb/s connection!";
    }
    void showPrice()
    {
        cout << "\nPrice of 1 hour usage is " << this->price << " PLN";
    }
    void checkMaxConnectionSpeed()
    {
        cout << "\nYour connection speed is [ " << this->connectionSpeed << " Mb/s";
        cout << "\nMax connection speed is [ " << this->maxConnectionSpeed << " Mb/s";
    }
    WebUsing()
    {
        this->maxConnectionSpeed = 1000;
    }
    ~WebUsing(){}
};
class ReadingMaterial : public Product
{
	public:
		string storageType;
		string author;
		string publisher;
		string contentType;
		string target;
		string dateOfPublishing;
		int numberOfPages;
		int amountAvailable;

		virtual void borrow()=0;
		virtual void aboutAuthor()
		{
		    cout << "\nHe was a cool guy!";
		}
		virtual void isAvailable()
        {
            if (amountAvailable > 0)
                cout << "\nIt is available!";
            else
                cout << "\nIt is not currently available, sorry!";
        }
        virtual void checkStorageType()
        {
            cout << "Reading material is currently stored [ " << this->storageType << " ]";
        }
        virtual void showDateOfPublishing()
        {
            cout << "\nThis was published on [ " << this->dateOfPublishing << " ]";
        }
        virtual void showTarget()
        {
            cout << "\nThis reading material is targeted to [ " << this->target << " ] audience";
        }
        virtual void showContentType()
        {
            cout << "\nThis reading material is focused around [ " << this->contentType << " ]";
        }
        virtual void howManyPages()
        {
            cout << "\nThis reading material has [ " << this->numberOfPages << "] pages";
        }
        void showName()
        {
            cout << "\nThis reading material name is [ " << this->name << " ]";
        }
        void showId()
        {
            cout << "\nThis reading material id is [ " << this->id << " ]";
        }
        void showPrice()
        {
            cout << "\nBorrowing this reading material for month costs [ " << this->price << " ] PLN";
        }
    private:
        void addReadingMaterial(string name, int price, string author, string dateOfPublishing, string target, string contentType, string storageType, int numberOfPages, int id, string publisher)
        {
            this->name = name;
            this->price = price;
            this->author = author;
            this->dateOfPublishing = dateOfPublishing;
            this->target = target;
            this->contentType = contentType;
            this->storageType = storageType;
            this->numberOfPages = numberOfPages;
            this->id = id;
            this->publisher = publisher;
        }
};
class PaperBook final: public ReadingMaterial
{
	public:
//	    Pages *page;
		string coverType;
		void borrow()
		{
		    if (this->amountAvailable < 0)
		    {
                cout << "\nSorry, you can't borrow this book, because it is currently unavailable! Try again next time";
		    } else
		    {
		        cout << "\nYou borrowed '" << this->name << "', written by " << this->author << " and published by " << this->publisher << ". This book has " << this->coverType << " cover.";
		        cout << "\nCost of borrowing this book is " << this->price << " per month!";
		        this->amountAvailable--;
		        cout << " Amount of this book in library is now " << this->amountAvailable << ".";
		    }
		}
		void checkCoverType()
		{
		    cout << "\nThis book is in " << this->coverType << " cover";
        }
        PaperBook(){}
        ~PaperBook(){}
};
class EBook final: public ReadingMaterial
{
	public:
//	    Pages *page;
		string extension;
		void borrow()
		{
		    cout << "\nYou borrowed a digital copy of '" << this->name << "' written by " << this->author << " and published by " << this->publisher << ". It has " << this->extension << " extension.";
		    cout << "\nCost of borrowing this copy is " << this->price << " per month!";
		}
		void checkExtension()
		{
		    cout << "Extension of this file is " << this->extension;
		}
		EBook(){}
        ~EBook(){}
};
class Newspaper final: public ReadingMaterial
{
    public:
//        Pages *page;
        bool color;
        void borrow()
        {
            cout << "\nYou borrowed a newspaper '" << this->name << "' from [" << this->dateOfPublishing << "] published by " << this->publisher << ".";
        }
        bool checkIfColored()
        {
            return color;
        }
        Newspaper(){}
        ~Newspaper(){}
};

int main()
{
    Complex start;
    start.introduction();
    return 0;
}
