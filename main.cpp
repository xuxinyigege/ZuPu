#include "familymanagement.h"
#include "Date.h"
#include<string>
using namespace std;
// main//
int main(int argc, char* argv[]){
	int choice, choice2;
	string name;
	Wife_Information wife;
	Member_Information man;
	string husband;
	string father;
	Tree *tr;
	string sex, father_name, mother_name;
	Date birth;
	Date death;
	tr=read();
	while(1) {
		Print_MainMenu();
		cin >> choice;

		if(choice==1){
			cout << "Please input a name:";
			cin >> name;
			Create_Tree(tr, name);
			cout << "Would you like to add some information for this people? 1.Yes 2.No: ";
			cin >> choice2;
			if ( choice2 == 1 )
				Change_Information(tr);
		}
		else{
    		fstream file("member.txt");
		string line;
                if(getline(file,line)){
                        file.close();
  			tr=read();
		}
  		switch(choice) {
		case 2:
			cout << "Please input the wife's name and her husband's name: ";
			cin >> name >> husband;
			wife.name = name;
			cout << Insert_Wife(tr, name, husband) << endl;
			cout << "Would you like to add some information for this people? 1.Yes 2.No: ";
			cin >> choice2;
			if ( choice2 == 1 )
				Change_Information(tr);
			break;
		case 3:
			cout << "Please input the children's name and his/her father's name: ";
			cin >> name >> father;
			cout << Insert_Children(tr, name, father) << endl;
			cout << "Would you like to add some information for this people? 1.Yes 2.No: ";
			cin >> choice2;
			if ( choice2 == 1 )
				Change_Information(tr);
			break;
		case 4:
			Change_Information(tr);
			break;
		case 5:
			cout << "Please input a name:";
			cin >> name;
			Search_Oneself(tr, name);
			break;
		case 6:
			cout << "Please input a name:";
			cin >> name;
			Search_One_Parents(tr, name);
			break;
		case 7:
			cout << "Please input a name:";
			cin >> name;
			Search_One_Wife(tr, name);
			break;
		case 8:
			cout << "Please input a name:";
			cin >> name;
			Search_One_Children(tr, name);
			break;
		case 9:
			cout << "Please input a name:";
			cin >> name;
			Search_One_Brother_And_Sister(tr, name);
			break;
		case 10:
			cout << "Please input a name:";
			cin >> name;
			cout << Delete_Member(tr, name) << endl;
			break;
		case 11:
			cout << "Please input the wife's name and her husband's name:";
			cin >> name >> husband;
			cout << Divorce(tr, name, husband) << endl;
			break;
		case 12:
			cout << Count_Generation_All(tr) << endl;
			break;
		case 13:
			Print_All(tr);
			break;
		case 14:
			cout << "Please input a name:";
			cin >> name;
			cout << Count_Ones_Age(tr, name) << endl;
			break;
	    default:
                    tr->self.father_name="no";
                    ofstream f("member.txt",ios::trunc);
                    f.close();
                    save(tr);
                    return 0;
		    //cout << "Error:The invalid input!" << endl;
		}
		}

	}
}
