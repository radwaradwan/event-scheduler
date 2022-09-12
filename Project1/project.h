#pragma once
#include<iostream>
#include<Windows.h> 
#include<string>
#include<unordered_map>
#include<map>
#include<stack>
#include<fstream>
#include<cctype>
using namespace std;
struct sdate
{
	int day, month, year;
	bool operator<(const sdate &a) const
	{
		return (a.year > year || (a.year == year && a.month>month) || (a.year == year && a.month==a.month &&a.day>day));
	}
};
class event
{
public:
	sdate startdate, enddate;
	string name, place;
	event();
};
class user
{
public:
	int id;
	string username, password;
	unordered_map<string, event> user0;
	unordered_map<string, event> user1;
	unordered_map<string, event> user2;
	multimap<string, event> mkan;
	multimap<sdate, event> m3d;
	multimap<string, event>::iterator n;
	multimap<sdate, event>::iterator ss;
	unordered_map<int, user> info;
	unordered_map<string, event>::iterator it;
	stack<event>Edone1;
	stack<event>Edone2;
	stack<event>Edone3;
	user();
	void getinfo();
	int login();
	void choese(unordered_map<string, event> &tmp, stack<event>& ptr);
	void add(unordered_map<string, event> &tmp, stack<event> &ptr);
	void display_place(unordered_map<string, event> &tmp, stack<event> &ptr);
	void remove(unordered_map<string, event> &tmp, stack<event> &ptr);
	void update(unordered_map<string, event> &tmp, stack<event> &ptr);
	void displaydoneevent(unordered_map<string, event> &tmp, stack<event> &ptr);
	void donebutton(unordered_map<string, event> &tmp, stack<event> &ptr);
	void letinfo();
	void remove_done(unordered_map<string, event> &tmp, stack<event> &ptr);
	void display_date(unordered_map<string, event> &tmp, stack<event> &ptr);
	void suggestion(unordered_map<string, event> &tmp, unordered_map<string, event>&tmp2);
};


