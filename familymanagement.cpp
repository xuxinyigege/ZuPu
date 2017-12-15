#include "familymanagement.h"
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int Max_Generation = 0;

void save(Tree *tr){
        if(tr!=NULL){
        //out("member.txt",ios::trunc);
        fstream file("member.txt",ios::app);
        if(!file)
        {
             cerr<<"open main.dat error!"<<endl;
             //exit(1);
         }
        
        file<<(tr->self.father_name)<<endl; 
        file<<(tr->name)<<endl;
        file<<(tr->self.Sex)<<endl;
        file<<(tr->self.IsLife)<<endl;
        file<<(tr->self.generation)<<endl;
        file.close();
        
        save(tr->left);
        save(tr->right);
            
              
        }
       
}


Tree* read(){
        queue<Tree* > q;
        Tree *tr;
       Tree *q_t;
	Tree *tr_t;
        fstream file("member.txt");
        if(!file)
        {
             cerr<<"open main.dat error!"<<endl;
             //exit(1);
         }
        //file.open("member.txt",ios::in);
        string line;
        tr=new(Tree);
        
	if(getline(file,line))
		tr->self.father_name=line;


	if(getline(file,line))
		tr->name=line;
	if(getline(file,line))
		tr->self.Sex=line;
	if(getline(file,line)){
                if(line=="0")
		tr->self.IsLife=0;
		else
		tr->self.IsLife=1;
	}
	if(getline(file,line)){
                stringstream s(line);
		s>>tr->self.generation;
        }

        q.push(tr);

        while(getline(file,line)){
  		
             	tr_t=new(Tree);
			
		tr_t->self.father_name=line;
	if(getline(file,line))
		tr_t->name=line;
	if(getline(file,line))
		tr_t->self.Sex=line;
	if(getline(file,line)){
                if(line=="0")
		tr_t->self.IsLife=0;
		else
		tr_t->self.IsLife=1;
	}
	if(getline(file,line)){
                stringstream s(line);
		s>>tr_t->self.generation;
        }
        if(tr_t->self.father_name==q.back()->name)
        {
       		q.back()->left=tr_t;
		tr_t->father=q.back();
		tr_t->brother=q.back();
		q.push(tr_t);
	}
	else{
  		if(q.back()->self.generation>Max_Generation)
				Max_Generation=q.back()->self.generation;
                
                q_t=new(Tree);
                q_t=q.back();
		while(q_t->self.father_name!=tr_t->self.father_name)
			q_t=q_t->father;
        	tr_t->brother=q_t;
		q_t->right=tr_t;
                tr_t->father=q_t->father;
		q.push(tr_t);
		//delete q_t;
	}
	 //delete tr_t;
        }
 	
        
        file.close();
        return tr;
}
void Create_Tree(Tree* &tr, string name) {
	tr = new Tree;
	tr->name = name;
	tr->self.generation = 1;
	cout << "Success!" << endl;
}

Tree* Search(Tree *tr, string name) {
	queue<Tree* > q;
	if (tr != 0) {
		if (tr->name == name)
			return tr;
        q.push(tr);
		while (q.empty() == false ) {
			if(q.front() -> left != 0) {
				if (q.front()->left->name == name)
					return q.front()->left;
				else
					q.push(q.front()->left);
			}
			if(q.front() -> right != 0) {
				if (q.front()->right->name == name)
					return q.front()->right;
				else
					q.push(q.front()->right);
			}
			q.pop();
		}
	}
	return 0;
}

// All generations //
int Count_Generation_All(Tree* tr) {
	return Max_Generation;
}

// insert //
string Insert_Wife(Tree* &tr, string name, string husband) {
	Tree* t;
	Wife_Information wife;
	wife.name = name;
	t = Search(tr, husband);
	if (t != 0) {
		t->wifves.push_back(wife);
		return "Success!";
	}
	return "Error: The husband is not in this family!";

}

string Insert_Children(Tree* &tr, string name, string father) {
	Tree* t;
	Tree* insert;
	Member_Information children;
	insert = new Tree;
	t = Search(tr,father);
	if (t != 0) {
	insert->self = children;
	insert->self.generation=t->self.generation+1;
	insert->self.father_name = father;
	if ( insert->self.generation > Max_Generation )
		Max_Generation = insert->self.generation;
	insert->name = name;
	insert->father = t;

	if(t->left == 0) {
		t->left = insert;
		insert->brother = t;
           
	}
	else {
		t = t->left;
		while ( t->right != 0)
			t = t->right;
		t->right=insert;
		insert->brother=t;
	}
	 return "Success!";
	}
	return "Error: The father may is in this family!";
}

string Insert_Brother_Or_Sister(Tree* &tr, string name, string brother_sister) {
	Tree* t;
	Tree* insert;
	Member_Information brother_or_sister;
	insert=new Tree;
	t=Search(tr,brother_sister);
	if (t != 0) {
	insert->self = brother_or_sister;
	insert->self.generation=t->self.generation;
	insert->name=name;
	insert->father=t->father;
	while (t->right != 0)
		t=t->right;

	t->right=insert;
	insert->brother=t;
    return "Success!";
	}
	return "Error: The brother(sister) is not in this family!";
}

// delete or remove //
string Divorce(Tree* &tr, string name, string husband) {
	Tree* t;
	t=Search(tr,husband);
	if (t != 0) {
		for ( int i = 0; i < t->wifves.size(); i++ ) {
			if ( name == t->wifves[i].name ) {
				t->wifves[i].divorce = true;
				return "Success!";
			}
		}
	}
	return "Error:The husband is not in the family!";
}

string Delete_Member(Tree* &tr, string name) {
	Tree* t;
	t=Search(tr,name);
	if (t != 0) {
		if ( t->father == t->brother ) {
			t->father->left = t->right;
			// 增加判断 //
			if (t->right != 0) { 
		      t->right->brother = t->father;
			}
		}
		else {
			if ( t->right != 0) {
				t->brother->right = t->right;
				t->right->brother = t->brother;
			}
			else
				t->brother->right = NULL;
		}
		Delete_SubTree(t);
		return "Success!";
	}
	return "Error: The member is not in the family!";
}


void Delete_SubTree(Tree* &tr) {
	queue<Tree*> q;
	Tree* d;
	Tree* x;
	x = tr->left;
	tr->brother = tr->father = tr->left = tr->right = 0;
	delete tr;
	tr = 0;
	if ( x!= 0 ) {
        q.push(x);
		while (q.empty() == false ) {
			if(q.front() -> left != 0)
				q.push(q.front()->left);
			if(q.front() -> right != 0)
				q.push(q.front()->right);
			d=q.front();
			q.pop();
			d->brother=d->father=d->left=d->right=0;
			delete d;
			d=0;
		}
   }
}

// change information //
void Change_Information(Tree* tr) {
	int choice;
	string name;
	string new_name, sex, mother_name, father_name, date, wife, husband;
	Date birth;
	bool islife;
	cout << "Please input the person's name:";
	cin >> name;
	while (1)
	{
	Print_Add_Information_Menu();
	cin >>choice;
	if ( choice == 10 )
		break;
	switch (choice)
	{
	case 1: 
		cout << "Please input current name:";
	    cin >>new_name;
		Change_Name(tr, name, new_name);
	case 2:
	    cout << "Please input current sex, Male/Female:";
	    cin >> sex;
		Change_Sex(tr, name, sex);
		break;
	case 3:
		cout << "Please input current state: '1' for alive, '0' for dead";
	    cin >> islife;
		Change_IsLife(tr, name, islife);
		break;
	case 4:
	    cout << "Please input current mother's name:";
	    cin >> mother_name;
		Change_Mothername(tr, name, mother_name);
		break;
	case 5:
	   cout << "Please input current father's name:";
	   cin >> father_name;
		Change_Fathername(tr, name, father_name);
		break;
	case 6:
		cout << "Please input the new birthday(xxxx-xx-xx):";
		cin >> date;
		Change_Birth(tr, name, date);
		break;
    case 7: 
		cout << "Please input the new Festa(xxxx-xx-xx):";
		cin >> date;
		Change_Festa(tr, name, date);
		break;
	case 8:
		Change_VIP(tr, name);  // add //
		break;
	case 9:
		cout << "Please input the wife's name: ";
		cin >> wife;
		Change_Wives_Information(tr, name, wife);
		break;
	default:
		break;
	}
	}
}

void Change_Name(Tree* &tr, string name, string new_name) {
	Tree *p = Search(tr, name);
	if ( p != 0 ) {
		p->name = new_name;
	cout << "Success!";
	}
	else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Sex(Tree*& tr, string name, string sex) {
	Tree *p = Search(tr, name);
	if ( p != 0 ) {
		p->self.Sex = sex;
	cout << "Success ";
	}
	else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_IsLife(Tree* &tr, string name, bool islife) {
	Tree *p = Search(tr, name);
	if ( p != 0 ) {
		if ( islife == 0 ) {
			tr->self.IsLife = false;
			cout << "Please input the dead date:";

		}
		else
		{
			tr->self.IsLife = true;
		}
		cout << "Success!";
	}
	else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Fathername(Tree* &tr, string name, string father_name) {
	if (tr != 0) {
		tr->self.father_name = father_name;
		cout << "Success!";
	}
	else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Mothername(Tree* &tr, string name, string mother_name) {
	if (tr != 0) {
		tr->self.mother_name=name;
	cout << "Success!";
	}
	else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Birth(Tree* &tr, string name, string date) {
	Date birth;
	Tree *p = Search(tr, name);
	if (p != 0 ) {
		p->self.birth = birth.stringToDate(date);
		cout << "Success!";
	}
    else
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Festa(Tree* &tr, string name, string date) {
	Date festa;
	Tree *p = Search(tr, name);
	if (p != 0 ) {
		p->self.death = festa.stringToDate(date);
		cout << "Success!";
	}
    else
		cout << "Error: can't find the person";
	cout << endl;
}

// 已完成 //
void Change_VIP(Tree*& tr,string name) {
	Tree *p = Search(tr, name);
	ofstream outfile;
	char* message;
	message=new char[400];
	string x;
	if (p !=0 ) {  
		p->self.VIP_Information=p->name;
		cout << "please  input the VIP informations " << endl;
		outfile.open(tr->self.VIP_Information.c_str());
		cin >> message;
		outfile << message;
        outfile.close();
    cout << "Success!";
	}
	else 
		cout << "Error: can't find the person";
	cout << endl;
}

void Change_Wives_Information(Tree* &tr, string name, string wife) {
	Tree *p = Search(tr, name);
	if (p !=0 ) {
		int i;
		for ( i = 0; i < p->wifves.size(); i++ ) {
		if (wife == p->wifves[i].name ) {
			int choice;
			cout << "Please input the information you want to change . '1' for change name ,'2' for change state" << endl;
			cin >> choice;
			if (choice == 1 ) {
				string newname;
				cout << "Please input the new name" << endl;
				cin >> newname;
				p->wifves[i].name=newname;
			}
			else if (choice == 2) {
				int state;
				cout << "Please input the new state '1' for not divorce ,'0' for divorce" << endl;
				cin >>state;
				if (state == 1) {
					p->wifves[i].divorce = false;
				}
				else if (state == 0) {
					p->wifves[i].divorce = true;
				}
			}
			break;
	    }
		if (i == p->wifves.size())
			cout <<"Can't find the wife" << endl;
     }
	}
	else
		cout << "Error: can't find the person "<< endl;
}

// Search //
// Search one by oneself's name //
bool Search_Oneself(Tree* tr, string name) {
	 Tree* t;
	 t = Search(tr,name);
	 if(t==NULL){
		cout<<"no this person"<<endl;
		return false;
	}
	 if (t != 0) {
		 cout << "Name: " << t->name <<endl << "Birthday and Festa: ";
		 cout <<  t->self.birth.dateToString(t->self.birth );
		 cout << " ";
		 cout << t->self.death.dateToString(t->self.death ) ;
		 cout << endl;
		 cout << "Sex: " << t->self.Sex << endl;
		 cout << "Father: " << t->self.father_name << endl;
		 cout << "Mother: " << t->self.mother_name << endl;
		 cout <<"Wife: ";
		 for ( int i = 0; i < t->self.wifves.size(); i++ )
			 cout << t->self.wifves[i].name << ' ';
		 cout << endl;
		 cout << "Generations: " << t->self.generation << endl;

		 // ask if there is need to print VIP information //
		 if (t->self.VIP_Information != "") {
			 char answer;
			 cout << "Do you want to print the VIP's information? 'Y' for yes, others for no"<< endl;
			 cin >> answer;
			 if (answer == 'Y') {
				 Print_VIP_Information(t);
			 }
		 }

		 // if the person is male,ask if there is need to print his wives informations //
		 if ( t->self.Sex == "Male") {
			 char choice;
			 cout  << "Do you need  to print the person's wives informations? input Y/N" << endl;
			 cin >> choice;
			 if (choice == 'Y') {
				 int i;
				 if ( t->wifves.empty() )
					 cout << "He has no wife!" << endl;
				 else
				 {
				 for( i=0; i<t->wifves.size();i++) {
					 cout <<"Name : " << t->wifves[i].name << "  Divorce: "<<t->wifves[i].divorce<<endl;
				 }
				 }
			 }
		 }
		 return true;
	 }
	 cout << "Can't find the person you want,sorry" << endl;
	 return false;
}

 // Search one's parents by himself name //
bool Search_One_Parents(Tree* tr, string name) {
	 Tree* t;
	 Tree* father;
	 string mama;
	 t = Search(tr,name);
	 if(t==NULL){
		cout<<"no this person"<<endl;
		return false;
	}
	 if (t != 0) {
		 mama = t->self.mother_name;
		 if ( t->father != 0 ) {
			 t = t->father;
			 cout << "Father's information: "<<endl;
			 cout << "Name: " << t -> name << endl << "Birthday and Festa: ";
			 cout <<  t->self.birth.dateToString(t->self.birth);
			 cout << " to  ";
			 cout << t->self.death.dateToString(t->self.death) ;
			 cout << endl;
			 cout << "Generations: " << t->self.generation << endl;
			 // ask if there is need to print VIP information //
			 if ( t->self.VIP_Information != "" ) {
				 char answer;
				 cout << "Do you want to print the VIP's information? 'Y' for yes, others for no"<< endl;
				 cin >> answer;
				 if (answer == 'Y') {
					 Print_VIP_Information(t);
				 }
			 }

			 // if the person is male,ask if there is need to print his wives informations //
			 if ( t->self.Sex == "Male") {
				  char choice;
				 cout  << "Do you need to print the person's wives informations? input Y/N" << endl;
				 cin >> choice;
				 if (choice == 'Y') {
					 int i;
					 for( i=0; i<t->wifves.size();i++) {
						 cout <<t->wifves[i].name << " Divorce: "<<t->wifves[i].divorce<<endl;
					 }
				 }
			 }

			int i;
			for ( i = 0; i < t->wifves.size(); i++ ) {
			if ( mama == t->wifves[i].name ) {
			     cout << "Mother's information: " << endl; 
				 cout << "Name: " << t->wifves[i].name << endl;
			     cout << endl;
				 cout << "Divorce: " << t->wifves[i].divorce << endl;
				break;
			   }
		     }
			 if (i == t->wifves.size() )
	           cout << "Can't find the person's mother's information " << endl;
             return true;
		  }

		 else {
			 cout << "Can't find the person's parents(This person may be the ancestor)" << endl;
			 cout << "The person himself's information is shown as follows :" << endl;
			 cout << "Name: " << t->name <<endl << "Birthday and Festa: ";
			 cout <<  t->self.birth.dateToString(t->self.birth );
			 cout << " to ";
			 cout << t->self.death.dateToString(t->self.death ) ;
			 cout << endl;
			 cout << "Sex: " << t->self.Sex << endl;
			 cout << "Father: " << t->self.father_name << " Mother: " << t->self.mother_name << endl;
			 cout << "Generations: " << t->self.generation << endl;

			 // ask if there is need to print VIP information //
			 if (t->self.VIP_Information != "") {
				 char answer;
				 cout << "Do you want to print the VIP's information? 'Y' for yes, others for no"<< endl;
				 cin >> answer;
				 if (answer == 'Y') {
					 Print_VIP_Information(t);
				 }
			 }
			 return true;
			 }
	 }
	 cout << "Can't find the person,sorry" << endl;
	 return false;
}


// Search one's children and print the basic information  //
bool Search_One_Children(Tree* tr, string name) {
    Tree* t;
	t=Search(tr, name);
	if(t==NULL){
		cout<<"no this person"<<endl;
		return false;
	}
	if (t->left != 0) {
		t=t->left;
		int i=0;
		while (t != 0) {
			Print_Information(t);
			i++;
			t=t->right;
		}
		cout << "There are "<<i<<" children in total."<< endl;
		return true;
	}
	else {
		cout << "There is no child."<< endl;
		return false;
	}
}

// Search one's wives and print the basic information  //
bool Search_One_Wife(Tree* tr, string name) {
	Tree* t;
	t=Search(tr, name);
	if (t->wifves.empty() == false ) {
		int i;
		for (i=0;i<t->wifves.size(); i++) {
				cout << "Name : "<<t->wifves[i].name << endl;
				if ( t->wifves[i].divorce == true )
					cout << name << " has been divorced with " << t->wifves[i].name << endl;
		}
		return true;
	}
	cout << "Can't find wives' informations."<< endl;
		return false;
}

// Search one's brothers and sisters and print the basic information  //
bool Search_One_Brother_And_Sister(Tree* tr, string name) {
	Tree* t;
	Tree* r;
	int i=0;
	t=Search(tr, name);
	 if(t==NULL){
		cout<<"no this person"<<endl;
		return false;
	}
	if (t != 0) {
		r=t;
		while(t->brother != t->father) {
			t=t->brother;
			Print_Information(t);
			i++;
		}

		r=r->right;
		while (r != 0) {
			Print_Information(r);
			r=r->right;
			i++;
		}
		cout << "There are "<<i<<" brothers os sisters in total."<< endl;
		return true;
	}
	cout << "Can't find brothers' or sisters' informations."<< endl;
	return false;
}

int Count_Ones_Age(Tree* tr, string name) {
	Tree* t;
	t=Search(tr, name);
	if (t !=0) {
		return tr->self.death.getYear()-tr->self.birth.getYear();
	}
	else 
		return -1;
}

// print //
void Print_MainMenu() {
        cout << "-----------------主界面------------------" << endl;
		cout << "1.Create a family" << endl;
		cout << "2.Insert One's Wife" << endl;
		cout << "3.Insert One's Children" << endl;
		cout << "4.Change One's Information" << endl;
		cout << "5.Search Member" << endl;
		cout << "6.Search Member's parents" << endl;
		cout << "7.Search Menmber's wife" << endl;
		cout << "8.Search Member's children" << endl;
		cout << "9.Search Member's brothers and sisters" << endl;
		cout << "10.Delete Member" << endl;
		cout << "11.Divorce with wife" << endl;
		cout << "12.Count the generation of the family" << endl;
		cout << "13.Print the whole family" << endl;
		cout << "14.Print one's alive age" << endl;
		cout << "Please input your choice:";
}

void Print_Add_Information_Menu() {
	 cout << "-----------------修改信息------------------" << endl;
		cout << "1.Change Name" << endl;
		cout << "2.Change Sex" << endl;
		cout << "3.Change Islive" << endl;
		cout << "4.Change Mother's name" << endl;
		cout << "5.Change Father's name" << endl;
		cout << "6.Change Birthday" << endl;
		cout << "7.Change Festa" << endl;
		cout << "8.Change VIP Informations" << endl;
		cout << "9.change wife's information " << endl;
		cout << "10.back" << endl;
		cout << "Please input you choice:";
}

void Print_Information(Tree* tr) {
	cout << "Name : "<< tr->name << "   "<<"Sex: "<< tr->self.Sex <<"  "<<"Islive:  ";
	if ( tr->self.IsLife == true )
		cout << "Still Alive" << endl;
	else
		cout << "Dead" << endl;
}

void Print_All(Tree *tr) {
	if ( tr != NULL )
	{
		for ( int j = 1; j < tr->self.generation; j++ )
			cout << "  ";
		cout << tr->name;
		if ( !tr->wifves.empty() )
		{
			cout << "(";
			cout << tr->wifves[0].name;
			for ( int i = 1; i < tr->wifves.size(); i++ )
				cout << "," << tr->wifves[i].name;
			cout << ")";
		}
		cout << endl;
		Print_All(tr->left);
		Print_All(tr->right);
	}
}

// 已完成 //
void Print_VIP_Information(Tree* tr) {
	ifstream infile;
	string temp;
	infile.open(tr->self.VIP_Information.c_str(), ifstream::in);
	while(getline(infile,temp) ) { 
	cout << temp << endl;
    }
  infile.close();
}
