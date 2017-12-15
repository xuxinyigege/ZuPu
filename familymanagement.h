#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include <algorithm>
#include<time.h>
#include<fstream>
#include "Date.h"
using namespace std;

//妻子信息
struct Wife_Information {
	string name;
	bool divorce;
	Wife_Information() {
	  name = "";
      divorce = false;
	};
	Wife_Information(string name_) {
		name = name_;
      divorce = false;
	};
};

//成员信息
struct Member_Information{
	string Sex; //性别
	bool IsLife;
	vector<Wife_Information> wifves;
	string father_name;
	string mother_name;
	int generation;
	Date birth;
	Date death;
    string VIP_Information; // Èç¹ûÕâ¸öÈËÊÇ¸öÃûÈË»òÕßÊÇ¶Ô¼Ò×å¼°ÆäÖØÒªµÄÈË£¬ÐÂÔöÐÅÏ¢»º³åÇø£¬´æÈë¸ÃÈËÉúÆ½ÊÂ¼£ //

	Member_Information() {
		Sex = "undefine";
		VIP_Information = "";
		generation = 0;
		IsLife = true;
	};
	//ÏÈÁÐ»ù±¾ÐÅÏ¢£¬¸ü¶àµÄÐÅÏ¢¿ÉÒÔÒÔºóÔÙ¼Ó½øÈ¥
};

struct Tree{
	string name;
	Tree *left;    //¶ù×Ó»òÅ®¶ù
	Tree *right;   //ÐÖµÜ
	Tree *father; //¸¸Ç×
	Tree *brother;
	vector<Wife_Information> wifves;  //ÆÞ×Ó£¨ÃÇ£©µÄÐÅÏ¢
	Member_Information  self;   // ±¾ÈËÐÅÏ¢ 
    
	Tree() {
		name = "";
		left = right = father = brother = 0;
		self.generation = 0;
	};

    Tree(string name_,Member_Information s, Tree* left_=0, Tree* right_=0, Tree* father_=0, Tree* brother_=0) {
       name = name_;
	   left = left_;
	   right = right_;
	   father = father_;
  	   brother = brother_;
	   self = s;
   }; 
};

// fundamental operation //
void Create_Tree(Tree* &tr, string name);
Tree* Search(Tree *tr, string name);
int Count_Generation_All(Tree* tr);

// Insert //
string Insert_Wife(Tree* &tr, string name, string husband);
string Insert_Children(Tree* &tr, string name, string father);
string Insert_Brother_Or_Sister(Tree* &tr, string name,string brother_sister);

// add brief member informations or change informations //
void Change_Information(Tree* tr);
void Change_Name(Tree* &tr, string name, string new_name);
void Change_Wives_Information(Tree* &tr, string name, string wife);
void Change_Sex(Tree* &tr, string name, string sex );
void Change_IsLife(Tree* &tr, string name, bool islife);
void Change_Fathername(Tree* &tr, string name, string father_name);
void Change_Mothername(Tree* &tr, string name, string mother_name);
void Change_Birth(Tree* &tr, string name, string date);
void Change_Festa(Tree* &tr, string name, string date);
void Change_VIP(Tree* &tr, string name);  // file read and write //

// Delete //
string Divorce(Tree* &tr, string name, string husband);
string Delete_Member(Tree* &tr, string name);
void Delete_SubTree(Tree* &tr);

// User Search  (if user find someone and this person is VIP ,ask if there is need to print the VIP's information) //
bool Search_Oneself(Tree* tr, string name);
bool Search_One_Parents(Tree* tr, string name);
bool Search_One_Children(Tree* tr, string name);
bool Search_One_Wife(Tree* tr, string name);
bool Search_One_Brother_And_Sister(Tree* tr, string name);
int Count_Ones_Age(Tree* tr, string name);
void save(Tree * tr);
Tree* read();
// Print //
void Print_Information(Tree* tr);
void Print_VIP_Information(Tree* tr); // file read and write //
void Print_All(Tree* tr);
void Print_MainMenu();
void Print_Add_Information_Menu();
