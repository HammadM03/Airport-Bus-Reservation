#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//goble variables used in key functions
int BusNo[100];
string drivername[100];
string arrivatime[100];
string departtime[100];
string from[100];
string to[100];
string Name[32];
string seats[32];
int B = 0;
int BusNumber = 0;
int total = 32;
string N;
int Seatnumber[32];
int index = 0;
int counter = 0;
int handler;
ofstream fout;

//funcation to add new bus
void InstallBus()
{
	cout << "Enter Bus No: ";
	cin >> BusNo[counter];
	cout << "Enter Driver's Name: ";
	cin >> drivername[counter];
	cout << "Arrival Time: ";
	cin >> arrivatime[counter];
	cout << "Departure Time: ";
	cin >> departtime[counter];
	cout << "From: ";
	cin >> from[counter];
	cout << "To: ";
	cin >> to[counter];
	fout << endl;
	fout << BusNo[counter] << " " << drivername[counter] << " " << arrivatime[counter] << " " << departtime[counter] << " " << from[counter] << " " << to[counter];
	counter++;
}
//function to book a seat in a bus
void Reservation(int sum)
{
	ifstream f;
	f.open("Passenger.txt");
	while (!f.eof())
	{
		f >> Seatnumber[handler];
		f >> Name[handler];
		handler++;
	}
	cout << "Enter the Bus Number to Box Seat: ";
	cin >> BusNumber;
	B = Seatnumber[sum];
	N = Name[sum];
	for (int i = 0; i < counter; i++)
	{
		if (BusNumber == BusNo[i])
		{
			seats[B] = N;
		}
	}
	cout << "Seat is Reserved...!!!" << endl;
}
//function to display the Reservation of the bus
void ShowReservation()
{
	int input;
	cout << "Enter Bus Number: ";
	cin >> input;
	cout << endl;
	for (int i = 0; i < counter; i++)
	{
		if (input == BusNo[i])
		{
			cout << "************************************************************************************************************" << endl;
			cout << "Bus Number: " << BusNo[i] << endl;
			cout << "Bus Driver Name: " << drivername[i];
			cout << "\tArrival Time: " << arrivatime[i];
			cout << "\tDeparture Time: " << departtime[i] << endl;
			cout << "From: " << from[i];
			cout << "\tTo: " << to[i] << endl;
			cout << "***************************************************************************************************************" << endl << endl;
			cout << "1" << "\t" << seats[0] << "\t2" << "\t" << seats[1] << "\t3" << "\t" << seats[2] << "\t4" << "\t" << seats[3] << endl;
			cout << "5" << "\t" << seats[4] << "\t6" << "\t" << seats[5] << "\t7" << "\t" << seats[6] << "\t8" << "\t" << seats[7] << endl;
			cout << "9" << "\t" << seats[8] << "\t10" << "\t" << seats[9] << "\t11" << "\t" << seats[10] << "\t12" << "\t" << seats[11] << endl;
			cout << "13" << "\t" << seats[12] << "\t14" << "\t" << seats[13] << "\t15" << "\t" << seats[14] << "\t17" << "\t" << seats[15] << endl;
			cout << "17" << "\t" << seats[16] << "\t18" << "\t" << seats[17] << "\t19" << "\t" << seats[18] << "\t20" << "\t" << seats[19] << endl;
			cout << "21" << "\t" << seats[20] << "\t22" << "\t" << seats[21] << "\t23" << "\t" << seats[22] << "\t24" << "\t" << seats[23] << endl;
			cout << "25" << "\t" << seats[24] << "\t26" << "\t" << seats[25] << "\t27" << "\t" << seats[26] << "\t28" << "\t" << seats[27] << endl;
			cout << "29" << "\t" << seats[28] << "\t30" << "\t" << seats[29] << "\t31" << "\t" << seats[30] << "\t32" << "\t" << seats[31] << endl << endl;

		}
	}
}
//function to display all buses avaiable
void BusesAvaiable()
{
	for (int i = 0; i < counter; i++)
	{
		cout << endl;
		cout << "Bus Number: " << BusNo[i] << endl;
		cout << "Bus Driver Name: " << drivername[i] << endl;
		cout << "Arrival Time: " << arrivatime[i] << endl;
		cout << "Departure Time: " << departtime[i] << endl;
		cout << "Destination " << endl;
		cout << "From: " << from[i] << endl;
		cout << "To: " << to[i] << endl;
		cout << endl;
	}

}

int main()
{
	int choice = 0, sum = 0;
	ifstream fin;
	//reading bus information from a file
	fin.open("Buses.txt");
	fout.open("Buses.txt", ios::app);
	while (!fin.eof())
	{
		fin >> BusNo[index];
		fin >> drivername[index];
		fin >> arrivatime[index];
		fin >> departtime[index];
		fin >> from[index];
		fin >> to[index];
		index++;
	}
	counter = index;
	for (int i = 0; i < 32; i++)
	{
		seats[i] = "Empty";
	}
	//menu
	while (choice != 5)
	{
		cout << "\t\t\t\t1.Install" << endl;
		cout << "\t\t\t\t2.Reservation" << endl;
		cout << "\t\t\t\t3.Show" << endl;
		cout << "\t\t\t\t4.Buses Avaiable" << endl;
		cout << "\t\t\t\t5.Exit" << endl;
		cout << "\t\t\t\tEnter Your Choice :-> ";
		cin >> choice;
		//display menu using switch
		switch (choice)
		{
		case 1:
			InstallBus();
			break;
		case 2:
			Reservation(sum);
			sum++;

			break;
		case 3:
			ShowReservation();
			cout << "There is " << total - sum << " seats empty in bus no " << BusNumber << endl;
			cout << "The seat no " << B + 1 << " is reserved for " << N << endl;
			break;
		case 4:
			BusesAvaiable();
			break;
		}

	}
	cout << "Thanks for using our system...!!!" << endl;
}