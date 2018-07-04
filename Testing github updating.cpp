#include<iostream> // Using for input & output stream
#include<string>   // Using for string operations
#include<fstream>  // Using for file operations
#include<conio.h>  // Using for input & output stream associated with iostream
#include <stdlib.h>  // Using for data conversions such as atoi function 


using namespace std;

// Create a struct data structure to store the students details.
struct student
{
	int StudentID, Age;
	string Firstname, Surname, Coursename, Address;
	long Contactnumber;
};


student k[100];
int studentcount = 0, i;
string t;


int autoID(string display)	//Auto Increment ID code
{
	int tempID = 0;
	cout << display;
	for (int i = 0; i <= studentcount; i++)
	{
		tempID++;
	}
	return tempID;
}

// Store the students info to file aka save the details
void Struct2File()

{
	ofstream myfile("student.txt");
	for (int i = 0; i<studentcount; i++)
		{
			myfile << k[i].StudentID << endl;
			myfile << k[i].Firstname << endl;
			myfile << k[i].Surname << endl;
			myfile << k[i].Age << endl;
			myfile << k[i].Address << endl;
			myfile << k[i].Contactnumber << endl;
			myfile << k[i].Coursename << endl;
		}
	myfile.close();
}

// Load th students details into struct
void File2Struct()
{
	ifstream myfile("student.txt");
	string t;
	int a = 1;
	if (myfile.is_open())
	{

		while (getline(myfile, t))
		{
			if (a == 1)
			{
				k[studentcount].StudentID = atoi(t.c_str());
				a++;
			}

			else if (a == 2)
			{
				k[studentcount].Firstname = t;
				a++;
			}

			else if (a == 3)
			{
				k[studentcount].Surname = t;
				a++;
			}

			else if (a == 4)
			{
				k[studentcount].Age = atoi(t.c_str());
				a++;
			}

			else if (a == 5)
			{
				k[studentcount].Address = t;
				a++;
			}

			else if (a == 6)
			{
				k[studentcount].Contactnumber = atoi(t.c_str());
				a++;
			}
			else if (a == 7)
			{
				k[studentcount].Coursename = t;
				a = 1;
				studentcount++;
			}

		}
	}

	else
	{
		cout << "File not found";
	}

}


void header()	//header

{
	system("cls");	//Screen clear
	cout << "\n\n\n\t\t\t\t\t========================================";
	cout << "\n\t\t\t\t\t[UNIVERSITY STUDENT'S MANAGEMENT SYSTEM]\n";
	cout << "\t\t\t\t\t========================================\n\n";
}

void footer()	//Footer

{	
	cout << "\n\t\t\t\n\t\t\tThanks for using UNIVERSITY STUDENT'S MANAGEMENT SYSTEM. ";
	cout << "\n\t\t\tDesigned by P.ARTHITHAN";
	cout << "\n\t\t\tPress ENTER to continue...";
}


void Addnewstudent()	//ADD STUDENT function
{
	
	header();	//header
	cout << "\t\n\n\t\tADD NEW STUDENT";	//Title

			int temp = autoID("\t\n\n\t\tStudent ID		: ");	//Auto increment ID
			cout << temp << "\n";	//display ID
			k[studentcount].StudentID = temp;	//save autoID in StudentID

	
	cout << "\t\n\t\tEnter the First name	: ";
	cin >> k[studentcount].Firstname;

	cout << "\t\n\t\tEnter the Surname	: ";
	cin >> k[studentcount].Surname;

here:
	cout << "\t\n\t\tEnter the Age		: ";
	int age;
	cin >> age;

	if (atoi(t.c_str()))	// Atoi pre-defined function will be performed the data coversion
	{
		
		if (age >60 )	//Age validation code (It checks whether the Age is greater than 60)
		
			{
			
				cout << "\n\n\t\t\t\tInvalid Age & insert it again...!!!";
				getchar();
				getchar();
				goto here;
			}

		else if (age < 16)	//Age validation code (It checks whether the Age is lesser than 16)
			{
				cout << "\n\n\t\t\t\tInvalid Age & insert it again...!!!";
				getchar();
				getchar();
				goto here;
			}

		else

			{
				k[studentcount].Age = age;		
				
				cout << "\t\n\t\tEnter the Address	: ";
				cin >> k[studentcount].Address;
			
				cout << "\t\n\t\tEnter the Contact number: ";
				cin >> k[studentcount].Contactnumber;
			
				cout << "\t\n\t\tEnter the Course name	: ";
				cin >> k[studentcount].Coursename;
			
			
				header();	//header
				cout << "\n\n\t\t\tStudent Added successfully!!!";	//The message
				cout << "\n\t\t\tPress ENTER to Main Menu ";
				studentcount++;	//Student count increment
				Struct2File();	// Store the struck info into flle
				getchar();
				
		
			} 

	}
	else

	{
		cout << "\nInvalid number";
	}


}


void Displaystudent()	//DISPLAY STUDENT function
{
	header();	//header
	cout << "\t\n\n\t\tSTUDENT'S PROFILE\n";	//Title
	cout << "\n\n\t\t\t\t\t\tTotal Students : " << studentcount;	//Showing total student count

	if (studentcount != 0)	//if statement
	{

		for (int i = 0; i < studentcount; i++)	//for loop
			
			{
				cout << "\n\n\n\n\t\t" << "Student ID	:" << k[i].StudentID;
				cout << "\n\n\t\t" << "Name		:" << k[i].Firstname << " " << k[i].Surname;
				cout << "\n\n\t\t" << "Age		:" << k[i].Age;
				cout << "\n\n\t\t" << "Address		:" << k[i].Address;
				cout << "\n\n\t\t" << "Contact number  :" << k[i].Contactnumber;
				cout << "\n\n\t\t" << "Course name	:" << k[i].Coursename << "\n\n\n";
			}

		getchar();

	}

	else

	{
		cout << "\n\n\t\tNo Students Data exist!";	//message
		cout << "\n\t\tPress ENTER to Main Menu ";
		getchar();
	}
	
}



void Modifystudent(int q)	//VOID MODIFY STUDENT function
{
	int flag = 0;
	header();	//header
	cout << "\n\n\t\t\tMODIFY STUDENT";		//title

	char cch;
	
	do	//do while control

		{
			cout << "\n\n\n\t\t\tCHOICE BOX";
			cout << "\n\n\t\t\t1-Firstname";
			cout << "\n\t\t\t2-Surname";
			cout << "\n\t\t\t3-Age";
			cout << "\n\t\t\t4-Address";
			cout << "\n\t\t\t5-Contact number";
			cout << "\n\t\t\t6-Course name";
			cout << "\n\t\t\t7-Exit";

			cout << "\n\n\t\t\tEnter the Choice   :";
			cin >> cch;

					
			header();		//header	
			switch (cch)	//switch control

			{
				case '1':cout << "\n\n\t\tEnter the Firstname	: ";
					cin >> k[q].Firstname;
					flag =1;
					break;
				case '2':cout << "\n\n\t\tEnter the Surname	: ";
					cin >> k[q].Surname;
					flag =1;
					break;
				case '3':cout << "\n\n\t\tEnter the Age	: ";
					cin >> k[q].Age;
					flag =1;
					break;
				case '4':cout << "\n\n\t\tEnter the Address	: ";
					cin >> k[q].Address;
					flag =1;
					break;
				case '5':cout << "\n\n\t\tEnter the Contact number	: ";
					cin >> k[q].Contactnumber;
					flag =1;
					break;
				case '6':cout << "\n\n\t\tEnter the Course name	: ";
					cin >> k[q].Coursename;
					flag =1;
					break;
				case '7': cch = 7;
				break;
					
					default: cout << "\n\n\n\t\t\tInvalid choice has been made!!!";	//message
			}

			if(flag ==1 )
			{
					header();	//header	
					cout << "\n\n\n\t\t\tUpdated Successfully!!!";	//message
					cout << "\n\t\t\tPress ENTER to Main Menu ";
					getchar();
					break;
					Struct2File();
			}
		}
	
	while (cch == '7');
	
}



bool Modifystudent()	//BOOL MODIFY STUDENT function
{
	header();		//header
	cout << "\t\n\n\t\t\tModify student";	//title

	int modifyid;
	cout << "\n\n\n\t\t\tEnter the student ID to modify  :";
	cin >> modifyid;

	for (int i = 0; i<studentcount; i++)	//for loop
		{
			if (modifyid == k[i].StudentID)	//if statement
			{
	
				Modifystudent(i);
				return true;
	
			}

		}

	header();	//header
	cout << "\n\n\t\t\tSorry Student ID Not Found!!!";	//message
	cout << "\n\t\t\tPress ENTER to Main Menu ";
	
	getchar();

}



void Searchstudentbyid()	//BOOL SEARCH STUDENT BY ID function

{

	header();		//header
	cout << "\t\n\n\t\tSEARCH STUDENT BY ID\n\n";	//title

	int searchid;
	cout << "\n\t\tEnter the Student ID    :";
	cin >> searchid;


	header();		//header

	bool flag = false;		//
	for (int i = 0; i<studentcount; i++)	//for loop

	{
		if (k[i].StudentID == searchid)		//if statement

		{
			cout << "\n\n\t\t" << "Student ID	:" << k[i].StudentID;
			cout << "\n\n\t\t" << "Name		:" << k[i].Firstname << " " << k[i].Surname;
			cout << "\n\n\t\t" << "Age		:" << k[i].Age;
			cout << "\n\n\t\t" << "Address		:" << k[i].Address;
			cout << "\n\n\t\t" << "Contact number  :" << k[i].Contactnumber;
			cout << "\n\n\t\t" << "Course name	:" << k[i].Coursename << "\n\n";

			cout << "\n\n\n\n\t\tPress ENTER to Main Menu :";

			flag = true;
			break;
		
		}

	}

	if (!flag)		// Error message will be shown if the flag was false.
	
	{
		cout << "\n\t\tSorry Studdent ID not found!!!";	//message
		cout << "\n\n\t\tPress ENTER to Main Menu :";
	}

	getchar();
	
}



void Searchstudentbycourse()	//VOID SEARCH STUDENT BY COURSE function

{
	header();		//header
	cout << "\t\n\n\t\tSEARCH STUDENT BY COURSE\n\n";	//title

	string searchcourse;
	cout << "\n\t\tEnter the Course name    :";
	cin >> searchcourse;


	header();		//header


	bool flag = false;		//
	for (int i = 0; i < studentcount; i++)		//for loop
		{

			for (int i = 0; i < studentcount; i++)		//for loop
			{

				if (k[i].Coursename == searchcourse)	//if statement

				{
					cout << "\n\n\t\t" << "Student ID	:" << k[i].StudentID;
					cout << "\n\n\t\t" << "Name		:" << k[i].Firstname << " " << k[i].Surname;
					cout << "\n\n\t\t" << "Age		:" << k[i].Age;
					cout << "\n\n\t\t" << "Address		:" << k[i].Address;
					cout << "\n\n\t\t" << "Contact number  :" << k[i].Contactnumber;
					cout << "\n\n\t\t" << "Course name	:" << k[i].Coursename << "\n\n";
					flag = true;
				}

			}

		}

	if (!flag)		// Showing an error message when flag is not true.

	{
		cout << "\n\t\tSorry Student Course not found!!!";
		cout << "\n\n\t\tPress ENTER to Main Menu :";
	}

	getchar();

}



void Deletestudent()	//DELETE STUDENT function

{
	header();		//header	
	cout << "\t\n\n\t\tDELETE STUDENT\n\n";		//title

	int deleteID;
	cout << "\t\tEnter the Student ID to delete	:";
	cin >> deleteID;

	char ccch;
	char x;
	ofstream myfile("student.txt");		// Storing the student details into file.

	for (int i = 0; i < studentcount; i++)	//for loop

		{
			if (deleteID == k[i].StudentID)
			{
				header();			//header	
				
				cout << "\n\n\t\tDo you want to delete Student ID " << deleteID << " ? ";	//message
				cout << "\n\n\t\tpress '1' to delete and '2' to abort	: ";
				cin >> ccch;

				if (ccch == '1')	//if statement
				{
					
					header();		//header
					cout << "\n\n\t\t\tStudent Data deleted successfully!";	//message
					cout << "\n\t\t\tPress ENTER to Main Menu :";

				}

				else if (ccch=='2')	

				{
						
					header();	//header
					cout << "\n\t\t\tStudent Data not deleted!";	//message
					cout << "\n\t\t\tPress ENTER to Main Menu :";

					myfile << k[i].StudentID << endl;
					myfile << k[i].Firstname << endl;
					myfile << k[i].Surname << endl;
					myfile << k[i].Age << endl;
					myfile << k[i].Address << endl;
					myfile << k[i].Contactnumber << endl;
					myfile << k[i].Coursename << endl;

				}

				else

				{

					header();		//header
					cout << "\n\t\t\tInvalid Choice";	//message
					cout << "\n\t\t\tStudent Data not deleted!";
					cout << "\n\t\t\tPress ENTER to Main Menu :";

					myfile << k[i].StudentID << endl;
					myfile << k[i].Firstname << endl;
					myfile << k[i].Surname << endl;
					myfile << k[i].Age << endl;
					myfile << k[i].Address << endl;
					myfile << k[i].Contactnumber << endl;
					myfile << k[i].Coursename << endl;

				}

			}

			else

			{
				myfile << k[i].StudentID << endl;
				myfile << k[i].Firstname << endl;
				myfile << k[i].Surname << endl;
				myfile << k[i].Age << endl;
				myfile << k[i].Address << endl;
				myfile << k[i].Contactnumber << endl;
				myfile << k[i].Coursename << endl;

				header();	//header
				cout << "\n\t\t\tStudent ID not found!!!";	//message
				cout << "\n\t\t\tPress ENTER to Main Menu :";

			}


		}

	studentcount = 0;
	File2Struct();
	getchar();

}



void Help()		//HELP function

{
	header();	//header	

	cout << "\t\n\t\tHELP";		
	cout << "\n\n\n\t\t1)Press 1 and Enter to Add a new student to the University Database";
	cout << "\n\n\t\t2)Press 2 and Enter to Update a student information";
	cout << "\n\n\t\t3)Press 3 and Enter to View all student information";
	cout << "\n\n\t\t4)Press 4 and Enter to Search a student by ID";
	cout << "\n\n\t\t5)Press 5 and Enter to Search a student by Course";
	cout << "\n\n\t\t6)Press 6 and Enter to Delete a student's information from the University Database";
	cout << "\n\n\t\t7)Press 8 and Enter to Exit";

	cout << "\n\n\n\t\tPress ENTER to Main Menu :";
	getchar();

}



int main()		//MAIN CODING

{
	int times = 2;
	{
	
	loop : 
	
	header();//header

		//login code

		int count=0;
		
		int astrick;
		string name = "";	//user name
		string pass = "";	//password

		cout << "\n\t\t\t\tPLEASE LOGIN TO USE THIS SYSTEM";

		cout << "\n\n\n\t\t\t\tEnter the User name : ";
		cin >> name;
		cout << "\n\t\t\t\tEnter the Password  : ";

		astrick = getch();		//astrick code

		while (astrick != 13)	//
		{
			if (astrick != 8)	//if statement

			{
				pass.push_back(astrick);	// Masking the input characters with astericks
				cout << "*";
			}

			else

			{
			//	pass.pop_back();	//  Using for perform backspace operation
			}

			astrick = getch();
		}


		if (name == "1" && pass == "1")	//if statement

		{
			cout << "\n\n\t\t\t\tlogin success!!! Press enter to Main menu : ";
			getchar();
			getchar();

			int ch;

			do	
			{

				header();	//header
				cout << "\t\n\t\t\t\tMAIN MENU\n";	//title

				cout << "\t\n\t\t\t\t1 - ADD NEW STUDENT";
				cout << "\t\n\t\t\t\t2 - MODIFY STUDENT";
				cout << "\t\n\t\t\t\t3 - DISPLAY STUDENT";
				cout << "\t\n\t\t\t\t4 - SEARCH STUDENT BY ID";
				cout << "\t\n\t\t\t\t5 - SEARCH STUDENT BY COURSE";
				cout << "\t\n\t\t\t\t6 - DELETE STUDENT";
				cout << "\t\n\t\t\t\t7 - Help";
				cout << "\n\t\t\t\t8 - EXIT";


				while (1)	// Running the infinitive loop

				{
					cout << "\n\n\t\t\t\tEnter your choice : ";
					cin >> t;

					if (atoi(t.c_str()))	// Validating the input

					{
						ch = atoi(t.c_str());	
						break;
					}

					else

					{
						cout << "\n\t\t\t\tInvalid Choice! Enter your choice again.";	//message
					}

				}


				switch (ch)		//switch control

				{

				case 1:Addnewstudent(); break;
				case 2:Modifystudent(); break;
				case 3:Displaystudent(); break;
				case 4:Searchstudentbyid(); break;
				case 5:Searchstudentbycourse(); break;
				case 6:Deletestudent(); break;
				case 7:Help(); break;
				case 8: break;
				default: cout << "\n\t\t\t\tInvalid Choice! Enter your choice again.";	//message
					getchar();

				}

				getchar();

			}

			while (ch != 8);

			header();		//header	
			footer();		//footer
			getchar();

		}

		else

		{
			
			
			header();	//header
			cout << "\n\n\t\t\t\tInvalid user name or password ";		//message
			cout << "\n\t\t\t\tYou have "<<times<<" more chances! Dont miss it!!! ";
			times--;
			cout << "\n\n\t\t\t\tTo try again, press Enter key ";

			
			getchar();
			getchar();
			
			if(times > -1)
			goto loop;
			else
			{
				system("CLS");
				header();
				cout << "\n\n\t\t\t\t\t\tYou have reached maximum try \n\n\n\n\n\n";
				exit(0);		
			}
			
		}
	}
	

}


