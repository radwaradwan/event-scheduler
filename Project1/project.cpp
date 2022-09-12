#include "project.h"
event::event()
{
	name = ' ';
	place = " ";
}
user::user()
{
	username = ' ';
	password = ' ';
}
void user::getinfo()
{
	event s;
	ifstream in1, in2, in3, in4, in5, in6, in7;
	in1.open("user0.txt");
	while (in1 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		user0.insert({ s.name, s });

	}
	in1.close();
	in2.open("user1.txt");
	while (in2 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		user1.insert({ s.name, s });
	}
	in2.close();
	in3.open("user2.txt");
	while (in3 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		user2.insert({ s.name, s });
	}
	in3.close();
	in4.open("users.txt");
	user q;
	while (in4 >> q.username >> q.password >> id)
	{
		info.insert({ id, q });
	}
	in4.close();
	in5.open("eventdone1.txt");
	while (in5 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		Edone1.push(s);
	}
	in5.close();
	in6.open("eventdone2.txt");
	while (in6 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		Edone2.push(s);
	}
	in6.close();
	in7.open("eventdone3.txt");
	while (in7 >> s.name >> s.startdate.day >> s.startdate.month >> s.startdate.year >> s.enddate.day >> s.enddate.month >> s.enddate.year >> s.place)
	{
		Edone3.push(s);
	}
	in7.close();
}
int user::login()
{
	while (true) {
		string uname, pass;
		int id = -1;
		cout << "please enter your username :";
		cin >> uname;
		cout << "please enter your password : ";
		cin >> pass;
		for (int i = 0; i < 3; i++)
		{
			if (info[i + 1].username == uname && info[i + 1].password == pass)
				id = i + 1;
		}

		if (id == -1)
		{
			cout << "ERROR Please enter correct username and password" << endl;
			continue;
		}
		else
			return id;
	}

}
void user::choese(unordered_map<string, event> &tmp, stack<event> &ptr)
{
	string chose;
	cout << endl<<"please press 1 to add Event " << endl;
	cout << "please press 2 to delete Event " << endl;
	cout << "please press 3 to update Event " << endl;
	cout << "please press 4 to display your Event by place " << endl;
	cout << "please press 5to display your Event by date " << endl;
	cout << "please press 6 to display your done Event " << endl;
	cout << "please press 7 if you done event  " << endl;
	cout << "please press 8 to exist " << endl;
	cin >> chose;
	int x = atoi(chose.c_str());
	switch (x)
		{
		case 1:
			add(tmp, ptr);
			break;
		case 2:
			remove(tmp, ptr);
			break;
		case 3:
			update(tmp, ptr);
			break;
		case 4:
			display_place(tmp, ptr);
			break;
		case 5:
			display_date(tmp, ptr);
			break;
		case 6:
			displaydoneevent(tmp, ptr);
			break;
		case 7:
			donebutton(tmp, ptr);
			break;

		case 8:
			letinfo();
			break;
		default:
			cout << "Please enter correct chose";
			choese(tmp, ptr);
			break;
		}
}
void user::add(unordered_map<string, event> &tmp, stack<event> &ptr)
{
	event s;
	SYSTEMTIME a;
	GetLocalTime(&a);
	while (true)
	{
		int x = -1;
		cout << "please enter eventname :";
		cin >> s.name;
		cout << "please enter startdate day/month/year :";
		cin >> s.startdate.day;
		cin >> s.startdate.month;
		cin >> s.startdate.year;
		cout << "please enter place :";
		cin >> s.place;
		cout << "please enter enddate day/month/year :";
		cin >> s.enddate.day;
		cin >> s.enddate.month;
		cin >> s.enddate.year;
		if ((s.startdate.day > 31) || (s.startdate.month > 12) || (a.wYear > s.startdate.year) || (a.wYear == s.startdate.year && a.wMonth > s.startdate.month) || (a.wYear == s.startdate.year && a.wMonth == s.startdate.month &&a.wDay > s.startdate.day))
		{
			cout << "please enter correct start date" << endl;
			x = 1;
		}
		 if ((s.enddate.day > 31) || (s.enddate.month > 12) || (s.startdate.year > s.enddate.year) || (s.startdate.year == s.enddate.year && s.startdate.month > s.enddate.month) || (s.startdate.year == s.enddate.year && s.startdate.month == s.enddate.month && s.startdate.day > s.enddate.day))
		{
			cout << "please enter correct enddate date" << endl;
			x = 1;
		}
	   if (tmp.find(s.name) != tmp.end())
		{
			cout << "You have event with this name";
			x = 1;
		}
		if (x != 1){
			for (it = tmp.begin(); it != tmp.end(); it++)
			{
				if (s.place == it->second.place ||  toupper(s.place[1]) == toupper(it->second.place[1]))
				{
					if ((s.startdate.year >= it->second.startdate.year && s.startdate.month >= it->second.startdate.month && s.startdate.day >= it->second.startdate.day) && (s.enddate.year <= it->second.enddate.year &&  s.enddate.month <= it->second.enddate.month &&  s.enddate.day <= it->second.enddate.day))
					{
						cout << "you can not make event in this time and place" << endl;
						x = 1;
					}

				}
			}
		}
	 if (x == -1)
		{
			tmp.insert({ s.name, s });
			cout << "done" << endl;
			break;
		}
	}
	choese(tmp, ptr);
}
void user::display_place(unordered_map<string, event> &tmp, stack<event> &ptr)
{
	if (!tmp.empty()){
		for (it = tmp.begin(); it != tmp.end(); it++)
		{
			mkan.insert({ it->second.place, it->second });
		}
		for (n = mkan.begin(); n != mkan.end(); n++)
		{
			cout << n->second.name << endl << n->second.startdate.day << "/" << n->second.startdate.month << "/" << n->second.startdate.year << endl << n->second.place << endl << n->second.enddate.day << "/" << n->second.enddate.month << "/" << n->second.enddate.year << endl;
		}
		mkan.clear();
	}
	else
		cout << "yo have not  events" << endl;
	choese(tmp, ptr);

}
void user::remove(unordered_map<string, event>&tmp, stack<event> &ptr)
{
	string name;
	cout << "please Enter name for event you want delete it : ";
	cin >> name;
	if (tmp.find(name) != tmp.end())
	{
		tmp.erase(name);
		cout << "Done" << endl;
	}
	else
	{
		cout << "you  have not event have this name"<<endl;
	}
	choese(tmp, ptr);
}
void user::update(unordered_map<string, event > &tmp, stack<event> &ptr)
{
	string name;
	cout << "please Enter name for event you want update it :";
	cin >> name;
	if (tmp.find(name) != tmp.end())
	{
		tmp.erase(name);
		add(tmp, ptr);
	}
	else
	{
		cout << "you not have event have this name"<<endl;
	}

	choese(tmp, ptr);

}
void user::displaydoneevent(unordered_map<string, event> &tmp, stack<event> &ptr)
{
	for (int i = 0; i < ptr.size();i++)
	{

		cout << ptr.top().name << endl << ptr.top().startdate.day << "/" << ptr.top().startdate.month << "/" << ptr.top().startdate.year << endl << ptr.top().enddate.day << "/" << ptr.top().enddate.month << "/" << ptr.top().enddate.year << endl << ptr.top().place<<endl;

	}
	choese(tmp, ptr);
}
void user::letinfo()
{
	ofstream in1, in2, in3, in4, in5, in6, in7;
	in1.open("user0.txt");
	for (it = user0.begin(); it != user0.end(); it++)
	{
		in1 << it->second.name << "  " << it->second.startdate.day << " " << it->second.startdate.month << " " << it->second.startdate.year << "  " << "  " << it->second.enddate.day << "  " << it->second.enddate.month << " " << it->second.enddate.year <<"  " << it->second.place << endl;

	}
	in1.close();
	in2.open("user1.txt");
	for (it = user1.begin(); it != user1.end(); it++)
	{
		in2 << it->second.name << "  " << it->second.startdate.day << " " << it->second.startdate.month << " " << it->second.startdate.year << "  " << it->second.enddate.day << "  " << it->second.enddate.month << "  " << it->second.enddate.year << "  " << it->second.place << endl;

	}
	in2.close();
	in3.open("user2.txt");
	for (it = user2.begin(); it != user2.end(); it++)
	{
		in3 << it->second.name << "  " << it->second.startdate.day << " " << it->second.startdate.month << " " << it->second.startdate.year << "  " << it->second.enddate.day << " " << it->second.enddate.month << "  " << it->second.enddate.year << "  " << it->second.place << endl;

	}
	in3.close();
	in5.open("eventdone1.txt");
	for (int i = 0; i< Edone1.size(); i++)
	{
		in5 << Edone1.top().name << endl << Edone1.top().startdate.day << " " << Edone1.top().startdate.month << " " << Edone1.top().startdate.year << "  " << Edone1.top().enddate.day << " " << Edone1.top().enddate.month << " " << Edone1.top().enddate.year << " " << Edone1.top().place << endl;

	}
	in5.close();
	in6.open("eventdone2.txt");
	for (int i = 0; i< Edone2.size(); i++)
	{
		in6 << Edone2.top().name << endl << Edone2.top().startdate.day << " " << Edone2.top().startdate.month << " " << Edone2.top().startdate.year << "  " << Edone2.top().enddate.day << " " << Edone2.top().enddate.month << " " << Edone2.top().enddate.year << " " << Edone2.top().place << endl;

	}
	in6.close();
	in7.open("eventdone3.txt");
	for (int i = 0; i< Edone3.size(); i++)
	{
		in7 << Edone3.top().name << endl << Edone3.top().startdate.day << " " << Edone3.top().startdate.month << " " << Edone3.top().startdate.year << "  " << Edone3.top().enddate.day << " " << Edone3.top().enddate.month << " " << Edone3.top().enddate.year << " " << Edone3.top().place << endl;

	}
	in7.close();


}
void user::donebutton(unordered_map<string, event> &tmp, stack<event> &ptr)
{
	string name;
	cout << "please Enter name for event you done  it :";
	cin >> name;
	if (tmp.find(name) != tmp.end())
	{
		ptr.push( tmp[name]);
		tmp.erase(name);
		cout << "DONE" << endl;
	}
	else
		cout << "please enter correct name"<<endl;
	choese(tmp, ptr);
}
void user::remove_done(unordered_map<string, event> &tmp, stack<event>  &ptr) {
	SYSTEMTIME a;
	GetLocalTime(&a);
	unordered_map<string, event> temp;
	string name;
	for (it = tmp.begin(); it != tmp.end(); it++) {
		name = it->second.name;
		if (a.wYear > it->second.enddate.year) {
			temp.insert({ name, tmp[name] });
		}
		else if (a.wYear == it->second.enddate.year) {
			if (a.wMonth > it->second.enddate.month) {
				temp.insert({ name, tmp[name] });
			}
			else if (a.wMonth == it->second.enddate.month){
				if (a.wDay > it->second.enddate.day) {
					temp.insert({ name, tmp[name] });
				}
			}
		}
	}
	for (it = temp.begin(); it != temp.end(); it++)
	{
		ptr.push(it->second);
		tmp.erase(it->first);
	 
	}
	temp.clear();
}
void user::display_date(unordered_map<string, event> &tmp, stack<event>  &ptr)
{
	if (!tmp.empty()){
		for (it = tmp.begin(); it != tmp.end(); it++)
		{
			m3d.insert({ it->second.startdate, it->second });
		}
		for (ss = m3d.begin(); ss != m3d.end(); ss++)
		{
			cout << ss->second.name << endl << ss->second.startdate.day << "/" << ss->second.startdate.month << "/" << ss->second.startdate.year << endl << ss->second.place << endl << ss->second.enddate.day << "/" << ss->second.enddate.month << "/" << ss->second.enddate.year << endl;
		}
		m3d.clear();
	}
	else
		cout << "yo do not have events" << endl;
	choese(tmp, ptr);
}
void user::suggestion(unordered_map<string, event> &tmp, unordered_map<string, event> &tmp2)
{
	string place;
	string chose;
	while (true)
	{
		cout << "if you want to suggest for you an event close to you please enter yes or no :";
		cin >> chose;
		if (chose == "yes" || chose == "YES"){
			int x = -1;
			cout << " please enter  the place " << ":";
			cin >> place;
			for (it = tmp.begin(); it != tmp.end(); it++)
			{
				if (place == it->second.place)
				{
					cout << it->second.name << endl << it->second.startdate.day << "/" << it->second.startdate.month << "/" << it->second.startdate.year << "/" << endl << it->second.enddate.day << "/" << it->second.enddate.month << "/" << it->second.enddate.year << "/" << endl << it->second.place << endl;
					x = 1;
				}
			}
			for (it = tmp2.begin(); it != tmp2.end(); it++)
			{
				if (place == it->second.place)
				{
					cout << it->second.name << endl << it->second.startdate.day << "/" << it->second.startdate.month << "/" << it->second.startdate.year << "/" << endl << it->second.enddate.day << "/" << it->second.enddate.month << "/" << it->second.enddate.year << "/" << endl << it->second.place << endl;
					x = 1;
				}
			}
			if (x != 1)
			{
				cout << "We have not any event close to this place " << endl;
			}
			break;
		}
		if (chose == "no" || chose == "NO")
			break;
	}

}
