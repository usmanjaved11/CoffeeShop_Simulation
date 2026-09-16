#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;
struct coffeeshop{
    string name[20];
    int pricebill[20];
    int count[20];
    int n=0,type;
    char ch;
    char coffee,tea,snacks;
    string name1,str1,userpass,employeename;
    double totalbill=0,discountedbill,discount,customeramount;
    int coffeestock[6]={10,10,10,10,10,10};
    int teastock[6]={10,10,10,10,10,10};
    int snacksstock[6]={10,10,10,10,10,10};
    double coffeeprice[6]={250,250,250,450,350,350};
    double teaprice[6]={250,250,250,250,250,250};
    double snacksprice[6]={50,150,100,100,150,150};
};
struct admin{
	int accountcontrol,accountregistering,deleteaccounttype,infotype;
	string SalesFile;
};
void adminregisteringaccount(){
    string user_name,filename;
    cout<<"Create Your username:";
    cin>>user_name;
    filename=user_name+"admin.txt";
    ofstream user_pass(filename.c_str());
    string password;
    cout<<"Enter Your Password:";
    cin>>password;
    user_pass<<password;
    user_pass.close();
}

void customerregisteringaccount(){
    string user_name,filename;
    cout<<"Create Your username:";
    cin>>user_name;
    filename=user_name+".txt";
    ofstream user_pass(filename.c_str());
    string password;
    cout<<"Enter Your Password:";
    cin>>password;
    user_pass<<password;
    user_pass.close();
}
bool adminlogin(coffeeshop &shop){
    string filename1,userid;
    cout<<"Enter Your userId:";
    cin>>userid;
    filename1=userid+"admin.txt";
    ifstream check(filename1.c_str());
    if(!check){
        cout<<"Admin Username Doesn't Exist:\n";
        return false;
    }
    check >> shop.str1;
    check.close();

    cout<<"Enter Your Password:";
    cin>>shop.userpass;

    if(shop.userpass == shop.str1){
        cout << "Admin Login Successful\n";
        return true;
    } else {
        cout << "Wrong Password\n";
        return false;
    }
}
bool login(coffeeshop &shop){
    string filename1,userid;
    cout<<"Enter Your userId:";
    cin>>userid;
    filename1=userid+".txt";
    ifstream check(filename1.c_str());
    if(!check){
        cout<<"Username Doesn't Exist:\n";
        return false;
    }
    check >> shop.str1;
    check.close();

    cout<<"Enter Your Password:";
    cin>>shop.userpass;

    if(shop.userpass == shop.str1){
        cout << "Login Successful\n";
        shop.employeename=userid;
        return true;
    } else {
        cout << "Wrong Password\n";
        return false;
    }
}
bool customerdeleteaccount() {
    string delUser, filename;
    cout << "Enter username to delete: ";
    cin >> delUser;

    filename = delUser + ".txt";

    if (remove(filename.c_str()) == 0) {
        cout << "Account deleted successfully.\n";
        return true;
    } 
    else {
        cout << "Account does not exist or could not be deleted.\n";
        return false;
    }
}
bool admindeleteaccount() {
    string delUser, filename;
    cout << "Enter username to delete: ";
    cin >> delUser;

    filename = delUser + "admin.txt";

    if (remove(filename.c_str()) == 0) {
        cout << "Account deleted successfully.\n";
        return true;
    } 
    else {
        cout << "Account does not exist or could not be deleted.\n";
        return false;
    }
}
void adminblock(admin &adm){ 
        	system("cls");
            cout<<"1.Register account     2.Delete account"<<"\nEnter:";
            cin>>adm.accountcontrol;
            if(adm.accountcontrol==1){
                cout<<"1.Admin Account    2.Customer Account"<<"\nEnter:";
                cin>>adm.accountregistering;
                if(adm.accountregistering==1){
                    adminregisteringaccount();
                } else {
                    customerregisteringaccount();
                }
            }
            else if(adm.accountcontrol==2){
            	cout<<"1.Admin Account    2.Customer Account"<<"\nEnter:";
            	cin>>adm.deleteaccounttype;
            	if(adm.deleteaccounttype==1){
            		admindeleteaccount();
				}
                else if(adm.deleteaccounttype==2){
                	customerdeleteaccount(); 
				}
    }
        }
void addemployeesinfo(){
	string filename5,employeename,emailaddress,address,designation,fathername,gender;
	int age;
	long long CNIC;
	cout<<"Enter Employee Name:";
	cin>>employeename;
	filename5=employeename+"data.txt";
	ofstream employeedata(filename5.c_str());
	employeedata<<"Date : "<<__DATE__<<endl;
	employeedata<<"Time : "<< __TIME__<<endl;
	employeedata<<"__________________________________"<<endl;
	cout<<"Enter Father Name:";
	cin>>fathername;
	employeedata<<"Enter Father Name:"<<fathername<<endl;
	cout<<"Enter Age:";
	cin>>age;
	cout<<"Enter Gender(M/F):";
	cin>>gender;
	employeedata<<"Gender:"<<gender<<endl;
	employeedata<<"Age:"<<age<<endl;
	cout<<"Enter Cnic Number(without Dashes):";
	cin>>CNIC;
	employeedata<<"Cnic Number(without Dashes):"<<CNIC<<endl;
	cout<<"Eamil Address:";
	cin>>emailaddress;
	employeedata<<"Eamil Address:"<<emailaddress<<endl;
	cout<<"Enter Address:";
	cin.ignore();
	getline(cin,address);
	employeedata<<"Address:"<<address<<endl;
	cout<<"Enter Designation:";
	cin>>designation;
	employeedata<<"Designation:"<<designation<<endl;
	employeedata<<"__________________________________"<<endl;
	employeedata.close();
}
void seeemployeesinfo(){
	string filename6,Employeename;
	cout<<"Enter Employee's Name:";
	cin>>Employeename;
	filename6=Employeename+"data.txt";
	ifstream openfile(filename6.c_str());
	if(!openfile){
		cout<<"Incorrect Employee's name:";
	}
		 string line;
    while (getline(openfile, line)) { 
        cout << line << endl;         
    }
    openfile.close();
}

void saveStock(coffeeshop &shop) {
    ofstream file("stock.txt");
    if(!file) return;

    file << "CoffeeStock: ";
    for(int i=0;i<6;i++) file << shop.coffeestock[i] << " ";
    file << "\nTeaStock: ";
    for(int i=0;i<6;i++) file << shop.teastock[i] << " ";
    file << "\nSnacksStock: ";
    for(int i=0;i<6;i++) file << shop.snacksstock[i] << " ";
    file << "\nCoffeePrice: ";
    for(int i=0;i<6;i++) file << shop.coffeeprice[i] << " ";
    file << "\nTeaPrice: ";
    for(int i=0;i<6;i++) file << shop.teaprice[i] << " ";
    file << "\nSnacksPrice: ";
    for(int i=0;i<6;i++) file << shop.snacksprice[i] << " ";
    file.close();
}

void loadStock(coffeeshop &shop) {
    ifstream file("stock.txt");
    if(!file) return;

    string label;
    file >> label; for(int i=0;i<6;i++) file >> shop.coffeestock[i];
    file >> label; for(int i=0;i<6;i++) file >> shop.teastock[i];
    file >> label; for(int i=0;i<6;i++) file >> shop.snacksstock[i];
    file >> label; for(int i=0;i<6;i++) file >> shop.coffeeprice[i];
    file >> label; for(int i=0;i<6;i++) file >> shop.teaprice[i];
    file >> label; for(int i=0;i<6;i++) file >> shop.snacksprice[i];
    file.close();
}

void menu(coffeeshop &shop) {
    cout << "                                  COFFEE SHOP\n\n";
    cout << "1.Coffee                   2.Tea                  3.Snacks\n";

    // Row 1
    cout << "B.Black Coffee=" << shop.coffeeprice[0] 
         << "         B.Black Tea=" << shop.teaprice[0] 
         << "         B.Biscuits=" << shop.snacksprice[0] << "\n";

    // Row 2
    cout << "L.Latte=" << shop.coffeeprice[1] 
         << "                W.White Tea=" << shop.teaprice[1] 
         << "         P.Pastries=" << shop.snacksprice[1] << "\n";

    // Row 3
    cout << "C.Cappuccino=" << shop.coffeeprice[2] 
         << "           Y.Yellow Tea=" << shop.teaprice[2] 
         << "        M.Muffins=" << shop.snacksprice[5] << "\n";

    // Row 4
    cout << "E.Espresso=" << shop.coffeeprice[3] 
         << "             O.Oolong Tea=" << shop.teaprice[3] 
         << "        G.Gummies=" << shop.snacksprice[2] << "\n";

    // Row 5
    cout << "A.American=" << shop.coffeeprice[4] 
         << "             G.Green Tea=" << shop.teaprice[4] 
         << "         D.Donuts=" << shop.snacksprice[3] << "\n";

    // Row 6
    cout << "M.Mocha=" << shop.coffeeprice[5] 
         << "                D.Dark Tea=" << shop.teaprice[5] 
         << "          S.Sandwiches=" << shop.snacksprice[4] << "\n";

    cout << "\n                                      0.Exit\n";
}



void selectcoffee(coffeeshop &shop){
    int index=-1;
    cout << "\nYou selected Coffee\n";
    cout<<"Select Coffee:";
    cin>>shop.coffee;
    switch(shop.coffee)
    {
        case'b':
        case'B':
            cout<<"\nYou've Selected Black Coffee";
            shop.name[shop.n]="Black coffe";
            index=0;
            break;
        case'l':
        case'L':
            cout<<"\nYou've Selected Latte Coffee";
            shop.name[shop.n]="Latte Coffee";
            index=1;
            break;
        case'c':
        case'C':
            cout<<"\nYou've Selected Cappuccino Coffee";
            shop.name[shop.n]="Cappuccino Coffee";
            index=2;
            break;
        case'e':
        case'E':
            cout<<"\nYou've Selected Espresso Coffee";
            shop.name[shop.n]="Espresso Coffee";
            index=3;
            break;
        case'a':
        case'A':
            cout<<"\nYou've Selected American Coffee";
            shop.name[shop.n]="American Coffee";
            index=4;
            break;
        case'm':
        case'M':
            cout<<"\nYou've Selected Mocha Coffee";
            shop.name[shop.n]="Mocha Coffee";
            index=5;
            break;
        default:
            cout<<"\nInvalid Choice";
            return;
    }
    cout<<"\nEnter Quantity:";
    cin>>shop.count[shop.n];
    if(shop.count[shop.n]>shop.coffeestock[index]){
    	cout<<"only "<<shop.coffeestock[index]<<"avalible\n";
		return;
	}
	shop.coffeestock[index]-=shop.count[shop.n];
    shop.pricebill[shop.n] = shop.coffeeprice[index];
    shop.totalbill += shop.coffeeprice[index] * shop.count[shop.n];
    shop.n++;
    saveStock(shop);
}

void selecttea(coffeeshop &shop){
    double price;
    cout << "\nYou selected Tea\n";
    cout<<"Select Tea:";
    cin>>shop.tea;
    int index=-1;
    switch(shop.tea)
    {
        case'b':
        case'B':
            cout<<"\nYou've Selected Black Tea";
            shop.name[shop.n]="Black Tea";
            index=0;
            break;
        case'w':
        case'W':
            cout<<"\nYou've Selected White Tea";
            shop.name[shop.n]="White Tea";
            index=1;
            break;
        case'Y':
        case'y':
            cout<<"\nYou've Selected Yellow Tea";
            shop.name[shop.n]="Yellow Tea";
            index=2;
            break;
        case'o':
        case'O':
            cout<<"\nYou've Selected Oolong Tea";
            shop.name[shop.n]="Oolong Tea";
            index=3;
            break;
        case'g':
        case'G':
            cout<<"\nYou've Selected Green Tea";
            shop.name[shop.n]="Green Tea";
            index=4;
            break;
        case'd':
        case'D':
            cout<<"\nYou've Selected Dark Tea";
            shop.name[shop.n]="Dark Tea";
            index=5;
            break;
        default:
            cout<<"\nInvalid Choice";
            return;
    }
    cout<<"\nEnter Quantity:";
    cin>>shop.count[shop.n];
    if(shop.count[shop.n]>shop.teastock[index]){
    	cout<<"only "<<shop.teastock[index]<<"avalible\n";
		return;
	}
	shop.teastock[index]-=shop.count[shop.n];
    shop.pricebill[shop.n]=shop.teaprice[index];
    shop.totalbill += shop.teaprice[index] * shop.count[shop.n];
    shop.n++;
    saveStock(shop);
}

void selectsnacks(coffeeshop &shop){
    double price;
    cout << "You selected Snacks\n";
    cout<<"Select Snacks:";
    cin>>shop.snacks;
    int index=-1;
    switch(shop.snacks)
    {
        case'b':
        case'B':
            cout<<"\nYou've Selected Biscuits";
            shop.name[shop.n]="Biscuits";
            price=50;
            index=0;
            break;
        case'p':
        case'P':
            cout<<"\nYou've Selected Pastries";
            shop.name[shop.n]="Pastries";
            index=1;
            break;
        case'G':
        case'g':
            cout<<"\nYou've Selected Gummies";
            shop.name[shop.n]="Gummies";
            index=2;
            break;
        case'D':
        case'd':
            cout<<"\nYou've Selected Donuts";
            shop.name[shop.n]="Donuts";
            index=3;
            break;
        case's':
        case'S':
            cout<<"\nYou've Selected Sandwiches";
            shop.name[shop.n]="Sandwiches";
            index=4;
            break;
        case'm':
        case'M':
            cout<<"\nYou've Selected Muffins";
            shop.name[shop.n]="Muffins";
            index=5;
            break;
        default:
            cout<<"\nInvalid Choice";
            return;
    }
    cout<<"\nEnter Quantity:";
    cin>>shop.count[shop.n];
    if(shop.count[shop.n]>shop.snacksstock[index]){
    	cout<<"only "<<shop.snacksstock[index]<<"avalible\n";
    	return;
	}
	shop.snacksstock[index]-=shop.count[shop.n];
    shop.pricebill[shop.n]=shop.snacksprice[index];
    shop.totalbill+=shop.snacksprice[index]*shop.count[shop.n];
    shop.n++;
    saveStock(shop);
}
void printBill(coffeeshop &shop);
void billsummary(coffeeshop &shop){
    cout<<"Enter The Name of Customer:";
    cin.ignore();
    getline(cin,shop.name1);
    system("cls");
    cout << "\n                                                =============================\n";
    cout << "                                                          BILL SUMMARY        \n";
    cout << "                                                =============================\n";
	string filename2=shop.employeename + "_sales.txt";
	ofstream salesdata(filename2.c_str(), ios::app);
	cout << "Date : " << __DATE__ << endl;
	salesdata<<"Date : "<<__DATE__ << endl;
    cout << "Time : " << __TIME__<<endl;
    salesdata << "Time : " << __TIME__<<endl;
	cout<<"Employee name:"<<shop.employeename<<endl; 
    salesdata<< "Items Sold:\n";
    cout << "\nCustomer Name: " << shop.name1 << endl << endl;
    salesdata<<"Customer Name:"<<shop.name1 << endl;
    for (int i = 0; i < shop.n; i++) {
        cout << shop.name[i] << " X " << shop.count[i] << " = " << shop.pricebill[i]*shop.count[i] << " PKR\n";
        salesdata<<shop.name[i] << " X " << shop.count[i] << " = " << shop.pricebill[i]*shop.count[i] << " PKR\n";
    }
    cout<<"Bill = "<<shop.totalbill;
    salesdata<<"Total bill = "<<shop.totalbill;
    cout<<"\nEnter Discount:";
    cin>>shop.discount;
    shop.discountedbill=shop.totalbill-(shop.totalbill*shop.discount/100);
    cout<<"Your Total Bill After Discount = "<<shop.discountedbill<<"PKR"<<endl;
    salesdata<<"Total Bill After "<<shop.discount<<" discount = "<<shop.discountedbill<<"PKR"<<endl;
    cout<<"Enter the Amount Customer Given:";
    cin>>shop.customeramount;
     salesdata<<"Customer Given Amount = "<<shop.customeramount<<endl;
    shop.customeramount=shop.customeramount-shop.discountedbill;
    cout<<"Amount Return To Customer = "<<shop.customeramount;
    salesdata<<"Amount Return To Customer = "<<shop.customeramount;
    salesdata.close();
    string totalfilename=shop.employeename + "_totalsales.txt";
    double totalfilebill=0;
    ifstream infile(totalfilename.c_str());
    if(infile.is_open()){
    	infile>>totalfilebill;
    	infile.close();
	}
	totalfilebill+=shop.discountedbill;
	ofstream outfile(totalfilename.c_str());
	outfile<<totalfilebill;
	outfile.close();
	char p;
cout << "\nPress P to print bill: ";
cin >> p;

if(p == 'P' || p == 'p'){
    printBill(shop);
}

}
void printBill(coffeeshop &shop) {
    system("cls");

    cout << "\n==================== COFFEE SHOP ====================\n";
    cout << "                         OFFICIAL RECEIPT\n";
    cout << "===============================================================\n\n";

    cout << "Date: " << __DATE__ << "        Time: " << __TIME__ << "\n";
    cout << "Employee: " << shop.employeename << "\n";
    cout << "Customer: " << shop.name1 << "\n";

    cout << "---------------------------------------------------------------\n";
    cout << " Item                     Qty        Total\n";
    cout << "---------------------------------------------------------------\n";

    for(int i = 0; i < shop.n; i++){
        cout << " " << shop.name[i];
        
        int len = shop.name[i].length();
        for(int s = 0; s < 25 - len; s++) cout << " ";

        cout << shop.count[i];

        if(shop.count[i] < 10) cout << "    ";
        else cout << "   ";

        cout << shop.pricebill[i] * shop.count[i] << " PKR\n";
    }

    cout << "---------------------------------------------------------------\n";
    cout << " Gross Total:                      " << shop.totalbill << " PKR\n";
    cout << " Discount:                         " << shop.discount << "%\n";
    cout << " Final Total:                      " << shop.discountedbill << " PKR\n";
    cout << " Paid Amount:                      " << shop.customeramount + shop.discountedbill << " PKR\n";
    cout << " Return Amount:                    " << shop.customeramount << " PKR\n";
    cout << "---------------------------------------------------------------\n";

    cout << "\n            THANK YOU FOR VISITING OUR'S COFFEE SHOP!\n";
    cout << "===============================================================\n\n";
}
void saleschecking() {
    string Userid;
    cout << "Enter UserId of That Employee: ";
    cin >> Userid;

    string filename3 = Userid + "_sales.txt";
    string filename4 = Userid + "_totalsales.txt";

    ifstream salesFile(filename3);

    if (!salesFile) {
        cout << "Wrong UserId or No Sales File Found!\n";
        return; 
    }

    cout << "\n--- SALES RECORD (" << Userid << ") ---\n";
    string line;
    while (getline(salesFile, line)) {
        cout << line << endl;
    }
    salesFile.close();

    ifstream infile(filename4);
    if (!infile) {
        cout << "\nNo Total Sales File Found!\n";
        return;
    }

    double totalfileamount;
    infile >> totalfileamount;
    infile.close();

    cout << "--------------------------------------\n";
    cout << "Total Amount = " << totalfileamount << endl;
}


void restock(coffeeshop &shop){
    int choice, index, amount;

    cout << "Restock Menu:\n1.Coffee\n2.Tea\n3.Snacks\nEnter choice: ";
    cin >> choice;

    if(choice < 1 || choice > 3){
        cout << "Invalid menu choice!\n";
        return;
    }

    cout << "Enter item index (0-5): ";
    cin >> index;
    if(index < 0 || index > 5){
        cout << "Invalid item index! Must be 0-5.\n";
        return;
    }

    cout << "Enter amount to add: ";
    cin >> amount;
    if(amount <= 0){
        cout << "Amount must be positive!\n";
        return;
    }

    if(choice == 1){
        shop.coffeestock[index] += amount;
        cout << "New coffee stock for this item: " << shop.coffeestock[index] << endl;
    }
    else if(choice == 2){
        shop.teastock[index] += amount;
        cout << "New tea stock for this item: " << shop.teastock[index] << endl;
    }
    else if(choice == 3){
        shop.snacksstock[index] += amount;
        cout << "New snack stock for this item: " << shop.snacksstock[index] << endl;
    }
    saveStock(shop);
}
void updatePrices(coffeeshop &shop) {
    int choice, index;
    double newPrice;
    cout << "Update Prices:\n";
    cout << "1. Coffee\n2. Tea\n3. Snacks\nEnter category: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Select Coffee to Update Price (0-5): ";
            cin >> index;
            if(index>=0 && index<6){
                cout << "Current Price: " << shop.coffeeprice[index] << "\nNew Price: ";
                cin >> newPrice;
                shop.coffeeprice[index] = newPrice;
                cout << "Price Updated!\n";
            }
            break;
        case 2:
            cout << "Select Tea to Update Price (0-5): ";
            cin >> index;
            if(index>=0 && index<6){
                cout << "Current Price: " << shop.teaprice[index] << "\nNew Price: ";
                cin >> newPrice;
                shop.teaprice[index] = newPrice;
                cout << "Price Updated!\n";
            }
            break;
        case 3:
            cout << "Select Snack to Update Price (0-5): ";
            cin >> index;
            if(index>=0 && index<6){
                cout << "Current Price: " << shop.snacksprice[index] << "\nNew Price: ";
                cin >> newPrice;
                shop.snacksprice[index] = newPrice;
                cout << "Price Updated!\n";
            }
            break;
        default:
            cout << "Invalid Choice!\n";
    }
    saveStock(shop);
}

void checkStock(coffeeshop &shop) {
    cout << "                              ABDULLAH'S COFFEE SHOP STOCK\n\n";
    cout << "Coffee Stock:\n";
    cout << "B.Black Coffee: " << shop.coffeestock[0] 
         << "  L.Latte: " << shop.coffeestock[1] 
         << "  C.Cappuccino: " << shop.coffeestock[2] << "\n";
    cout << "E.Espresso: " << shop.coffeestock[3] 
         << "  A.American: " << shop.coffeestock[4] 
         << "  M.Mocha: " << shop.coffeestock[5] << "\n\n";

    cout << "Tea Stock:\n";
    cout << "B.Black Tea: " << shop.teastock[0] 
         << "  W.White Tea: " << shop.teastock[1] 
         << "  Y.Yellow Tea: " << shop.teastock[2] << "\n";
    cout << "O.Oolong Tea: " << shop.teastock[3] 
         << "  G.Green Tea: " << shop.teastock[4] 
         << "  D.Dark Tea: " << shop.teastock[5] << "\n\n";

    cout << "Snacks Stock:\n";
    cout << "B.Biscuits: " << shop.snacksstock[0] 
         << "  P.Pastries: " << shop.snacksstock[1] 
         << "  G.Gummies: " << shop.snacksstock[2] << "\n";
    cout << "D.Donuts: " << shop.snacksstock[3] 
         << "  S.Sandwiches: " << shop.snacksstock[4] 
         << "  M.Muffins: " << shop.snacksstock[5] << "\n\n";
}


int main(){
    coffeeshop shop;
    admin adm;
    loadStock(shop);
    shop.n=0;
    shop.totalbill=0;
       cout << "============================================================\n";
       cout << "                       C O F F E E  S H O P\n";
       cout << "============================================================\n";
       cout << "                          L O G I N\n";
       cout << "------------------------------------------------------------\n";

    cout<<"1.Saler Employee Block"<<"\n2.Administration Block"<<"\nEnter:";
    cin>>shop.type;
    if(shop.type==1){
        if (!login(shop)) {
            return 0;
        }
        if(shop.userpass==shop.str1){
            system("cls");
            menu(shop);
            while(true){
                cout<<"\nEnter:";
                cin>>shop.ch;
                if(shop.ch=='1'){
                    selectcoffee(shop);
                }
                else if(shop.ch=='2'){
                    selecttea(shop);
                }
                else if(shop.ch=='3'){
                    selectsnacks(shop);
                }
                else if(shop.ch=='0'){
                    billsummary(shop);
                    break;
                }
                else{
                    cout<<"\nInvalid";
                }
            }
        }
    }
     else if(shop.type==2){
        if (!adminlogin(shop)) return 0;
        if(shop.userpass==shop.str1){
            int adminOption;
            system("cls");
            cout<<"                         Administration Block"<<endl;
                while(true){
            cout << "1. Manage Accounts (Register/Delete)\n";
            cout << "2. Check Sales\n";
            cout << "3. Employees Information\n"; 
            cout << "4. Restock Items\n";
            cout << "5. Check Avalible Stock\n";
            cout << "6. Update Prices\n";
            cout << "0. Exit Administration\n";
            cout << "Enter choice: ";
                cin >> adminOption;
                if(adminOption==0){
                	cout << "Exiting Administration Block...\n";
					 break;
				}
                switch(adminOption){
                case 1: 
                adminblock(adm); 
                 cout<<"[Press any key to continue]";
                getch();
                system("cls");
                break;
                case 2: 
                saleschecking(); 
                cout<<"[Press any key to continue]";
                getch();
                system("cls");
                
                break;
                case 3:
                cout<<"1.Add Employees Personal Data     2.See Employees Personal Data"<<"\nEnter: ";
                cin>>adm.infotype;
                if(adm.infotype==1){
                addemployeesinfo();
                 cout<<"[Press any key to continue]";
                getch();
                system("cls");
                }
                else if(adm.infotype==2){
                seeemployeesinfo();
                 cout<<"[Press any key to continue]";
                getch();
                system("cls");
                }
                else{
                cout<<"Invalid\n";
                }
                break;
                case 4:
                restock(shop);
				 cout<<"[Press any key to continue]";
                getch();
                system("cls");   
                break;
                case 5:
                checkStock(shop); 
				 cout<<"[Press any key to continue]";
                getch();
                system("cls");  
                break;
                case 6:
                updatePrices(shop);
                 cout<<"[Press any key to continue]";
                getch();
                system("cls");
                break;
                default: 
                cout << "Invalid choice!\n";
                }
				}
        }
    }
    else{
        cout<<"invalid";
    }
    return 0;
}
