#include <iostream>
#include <limits>
using namespace std;

void registration (string account[], int pass[],  int acc_num[], int SIZE){
	cout <<"REGISTER AN ACCOUNT"<<endl<<endl;
	for (int i = 0; i < SIZE; i++){
		if (acc_num[i] == 0){
		cout <<"Enter your Username: ";
		cin >> account[i];
		cout <<"Enter a Password: ";
		cin >> pass[i];
		acc_num[i] = 1;
		break;
		}
	}
}

void log_in (string account[], int pass[],  int acc_num[], int SIZE, int& used){
	cout <<"LOG-IN AN ACCOUNT"<<endl<<endl;
	string username;
	int password, i;
	cout <<"Username: ";
	cin >>username;
	cout <<"Password: ";
	cin >>password;
	
	for (i = 0; i < SIZE; i++){
		if (username == account[i] && password == pass[i]){
			cout <<"You have Succesfully loged in!!!"<<endl;
			used = i;
			i = 20;
			break;
		}
	}
	if (i != 20){
		cout<<"Account doesn't exist'!"<<endl<<endl;
		used = i;
	}
}

void display (string item[][100],int price[][100], int SIZE, int used, int& limit){
	int j = 0;
	for (int i = used; i == used; i++){
		for (j = 0; j < SIZE; j++){
			
			cin >> item [i][j] >> price [i][j];
			if (price [i][j] == 0 || item[i][j] == "end"){
				limit = j;
				break;
			}
		}
	}
	
}

void print(string item[][100], int price[][100], int SIZE, int used, int& limit){
	for (int i = used; i == used; i++){
		for (int j = 0; j < limit && item[i][j] != ""; j++){
			cout <<j+1<<". "<< item[i][j]<<"\t\t\t"<<price[i][j]<<endl;
		}
	}
}

void home(string item[][100], int price[][100], int SIZE, int used){
	int choice, limit;
	string decision;
	do{
		cout <<"Do you want to \n[1] Print your available items\n[2] Display items"<<endl;
		cout <<"Choice: ";
		cin >>choice;
		
		switch (choice){
			case 1:
				cout <<"your items are: "<<endl;
				print(item, price, SIZE, used, limit);
				break;
			case 2: 
				cout <<"Enter your items and its price: "<<endl;	
				display(item, price, SIZE, used, limit);
		}
		
		
	cout <<"\n\nDo you want to go back to home menu? (yes or no)"<<endl;
	cout <<"Choice: ";
	cin >> decision;	
	system("cls");	
	}while(decision == "YES" || decision == "Yes" || decision == "yes");
}

void choice (string item[][100], int price[][100], string account[], int pass[],  int acc_num[], int SIZE, int& used){
	int choice;
	cout <<"WELCOME TO HOME MENU"<<endl;
	cout <<"Do you want  to\n[1] Log-in \n[2] Register"<<endl;
	cout <<"Choice: ";
	cin >> choice;
	
	switch (choice){
		case 1:
			system("cls");
			log_in(account, pass, acc_num, SIZE, used);
			if(used < SIZE){
				home(item, price, SIZE, used);
			}
			break;
		case 2:
			system("cls");
			registration(account, pass, acc_num, SIZE);
	}	
}

int main(){
	const int SIZE = 10;
	string acc_name[SIZE], decision, item[SIZE][100];
	int password[SIZE], acc_num[SIZE] = {11}, used, price[SIZE][100];
	
	do{
		choice (item, price, acc_name, password, acc_num, SIZE, used);
		
		cout <<"Do you want to go back to main menu?(yes or no)"<<endl;
		cout <<"Choice: ";
		cin >> decision;
		system("cls");
	}while(decision == "YES" || decision == "Yes" || decision == "yes");
	
	return 0;
}