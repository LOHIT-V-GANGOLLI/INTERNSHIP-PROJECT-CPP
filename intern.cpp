#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class People
{
	private:
		string number;
		string name;
		string surname;
		string department;
		string email;
		string phone;
	public:
		string getNumber()
		{
			return this->number;
		};
		void setNumber(string _number)
		{
			this->number = _number;
		};
		string getName()
		{
			return this->name;
		};
		void setName(string _name)
		{
			this->name = _name;
		};
		string getSurname()
		{
			return this->surname;
		};
		void setSurname(string _surname)
		{
			this->surname = _surname;
		};
		string getDepartment()
		{
			return this->department;
		};
		void setDepartment(string _department)
		{
			this->department = _department;
		};
		string getEmail()
		{
			return this->email;
		};
		void setEmail(string _email)
		{
			this->email = _email;
		};
		string getPhone()
		{
			return this->phone;
		};
		void setPhone(string _phone)
		{
			this->phone = _phone;
		};
};
class Student : public People
{
	private:
		string year;
	public:
		Student(){};
		Student(string *_temp);
		string getYear()
		{
			return this->year;
		};
		void setYear(string _year)
		{
			this->year = _year;
		};
		//display students
		void display()
		{
			cout<<getNumber()<<" - ";
			cout<<getName()<<" - ";
			cout<<getSurname()<<" - ";
			cout<<getDepartment()<<" - ";
			cout<<getYear()<<" - ";
			cout<<getEmail()<<" - ";
			cout<<getPhone()<<endl;
		};
};

Student :: Student(string *_temp)
{
	setNumber(_temp[0]);
	setName(_temp[1]);
	setSurname(_temp[2]);
	setDepartment(_temp[3]);
	setYear(_temp[4]);
	setEmail(_temp[5]);
	setPhone(_temp[6]);
};
class Provider : public People
{
	private:
		string chair;
	public:
		Provider(){};
		Provider(string *_temp);
		string getChair()
		{
			return this->chair;
		};
		void setChair(string _chair)
		{
			this->chair = _chair;
		};
		//display Providers
		void display()
		{
			cout<<getNumber()<<" - ";
			cout<<getName()<<" - ";
			cout<<getSurname()<<" - ";
			cout<<getDepartment()<<" - ";
			cout<<getEmail()<<" - ";
			cout<<getPhone()<<" - ";
			cout<<getChair()<<endl;
		};
};

Provider :: Provider(string *_temp)
{
	//construct Provider object using the line in the given file
	setNumber(_temp[0]);
	setName(_temp[1]);
	setSurname(_temp[2]);
	setDepartment(_temp[3]);
	setEmail(_temp[4]);
	setPhone(_temp[5]);
	setChair(_temp[6]);
};

//composite Internship class from Student and Provider classes
class Internship
{
	private:
		//Internship properties
		string date;
		string start;
		string end;
	public:
		//composition
		Provider L;
		Student S;
		//constructor
		Internship(){};
		Internship(string *_temp);
		string getDate()
		{
			return this->date;
		};
		void setDate(string _date)
		{
			this->date = _date;
		};
		string getStart()
		{
			return this->start;
		}
		void setStart(string _start)
		{
			this->start = _start;
		}
		string getEnd()
		{
			return this->end;
		}
		void setEnd(string _end)
		{
			this->end = _end;
		};
		//display Internships
		void display()
		{
			cout<<S.getNumber()<<" - ";
			cout<<L.getNumber()<<" - ";
			cout<<getDate()<<" - ";
			cout<<getStart()<<" - ";
			cout<<getEnd()<<endl;
		};
};

Internship :: Internship(string *_temp)
{
	S.setNumber(_temp[0]);
	L.setNumber(_temp[1]);
	setDate(_temp[2]);
	setStart(_temp[3]);
	setEnd(_temp[4]);
};
int main()
{
	Student _S[100];
	Provider _L[100];
	Internship _A[100];
	int menuLoop = 0;
	int menu=0;
	int i;
	int x=0;
	int y=0;
	int z=0;

	while(menuLoop!=5)
	{
		cout<<endl<<"Student - Provider Internship System"<<endl<<endl;
		cout<<"Menu:"<<endl;
		cout<<"1 - Student Menu"<<endl;
		cout<<"2 - Provider Menu"<<endl;
		cout<<"3 - Internship Menu"<<endl;
		cout<<"4 - Exit"<<endl;
		cin>>menuLoop;

		//display detailed menu
		if(menuLoop==1)
		{
			//student menu is chosen
			cout<<"1 - Add Student"<<endl;
			cout<<"2 - List Students"<<endl;
			cout<<"3 - Remove Student"<<endl;
			cout<<"4 - Update Student"<<endl;
			cin>>menu;

			if(menu==1)
			{
				//student addition is chosen
				string temp_;
				Student newS;
				cout<<"Student No:"<<endl;
				cin>>temp_;
				newS.setNumber(temp_);
				cout<<"Student Name:"<<endl;
				cin>>temp_;
				newS.setName(temp_);
				cout<<"Student Last Name:"<<endl;
				cin>>temp_;
				newS.setSurname(temp_);
				cout<<"Student Department:"<<endl;
				cin>>temp_;
				newS.setDepartment(temp_);
				cout<<"Student Starting Year:"<<endl;
				cin>>temp_;
				newS.setYear(temp_);
				cout<<"Student E-Mail:"<<endl;
				cin>>temp_;
				newS.setEmail(temp_);
				cout<<"Student Phone Number:"<<endl;
				cin>>temp_;
				newS.setPhone(temp_);

				_S[x] = newS;
				x++;
			}
			else if(menu==2)
			{
				//student display is chosen
				cout<<endl;
				for(i=0; i<x; i++)
				{
					_S[i].display();
				}
			}
			else if(menu==3)
			{
				//student deletion is chosen
				string temp_;
				int deleted;
				cout<<"Enter the Student No to remove:"<<endl;
				cin>>temp_;
				i=0;
				while(i<x)
				{
					if(_S[i].getNumber()==temp_) deleted = i;
					i++;
				}
				for(i=deleted; i<x; i++)
				{
					_S[i] = _S[i+1];
				}
			}
			else if(menu==4)
			{
				//student update is chosen
				string temp_;
				int updated;
				cout<<"Enter the Student No to update:"<<endl;
				cin>>temp_;
				i=0;
				while(i<x)
				{
					if(_S[i].getNumber()==temp_) updated = i;
					i++;
				}
				cout<<"Updated Student Name:"<<endl;
				cin>>temp_;
				_S[updated].setName(temp_);
				cout<<"Updated Student Last Name:"<<endl;
				cin>>temp_;
				_S[updated].setSurname(temp_);
				cout<<"Updated Student Department:"<<endl;
				cin>>temp_;
				_S[updated].setDepartment(temp_);
				cout<<"Updated Student Starting Year:"<<endl;
				cin>>temp_;
				_S[updated].setYear(temp_);
				cout<<"Updated Student E-Mail:"<<endl;
				cin>>temp_;
				_S[updated].setEmail(temp_);
				cout<<"Updated Student Phone Number:"<<endl;
				cin>>temp_;
				_S[updated].setPhone(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==2)
		{
			//Provider menu is chosen
			cout<<"1 - Add Provider"<<endl;
			cout<<"2 - List Providers"<<endl;
			cout<<"3 - Remove Provider"<<endl;
			cout<<"4 - Update Provider"<<endl;
			cin>>menu;

			if(menu==1)
			{
				//Provider addition is chosen
				string temp_;
				Provider newL;
				cout<<"Provider No:"<<endl;
				cin>>temp_;
				newL.setNumber(temp_);
				cout<<"Provider Name:"<<endl;
				cin>>temp_;
				newL.setName(temp_);
				cout<<"Provider Last Name:"<<endl;
				cin>>temp_;
				newL.setSurname(temp_);
				cout<<"Provider Department:"<<endl;
				cin>>temp_;
				newL.setDepartment(temp_);
				cout<<"Provider E-Mail:"<<endl;
				cin>>temp_;
				newL.setEmail(temp_);
				cout<<"Provider Phone Number:"<<endl;
				cin>>temp_;
				newL.setPhone(temp_);
				cout<<"Provider Title:"<<endl;
				cin>>temp_;
				newL.setChair(temp_);

				_L[y] = newL;
				y++;

			}
			else if(menu==2)
			{
				//Provider display is chosen
				cout<<endl;
				for(i=0; i<y; i++)
				{
					_L[i].display();
				}

			}
			else if(menu==3)
			{
				//Provider deletion is chosen
				string temp_;
				int deleted;
				cout<<"Enter the Provider No to remove:"<<endl;
				cin>>temp_;
				i=0;
				while(i<y)
				{
					if(_L[i].getNumber()==temp_) deleted = i;
					i++;
				}
				for(i=deleted; i<y; i++)
				{
					_L[i] = _L[i+1];
				}
			}
			else if(menu==4)
			{
				//Provider update is chosen
				string temp_;
				int updated;
				cout<<"Enter the Provider No to update:"<<endl;
				cin>>temp_;
				i=0;
				while(i<y)
				{
					if(_L[i].getNumber()==temp_) updated = i;
					i++;
				}
				cout<<"Updated Provider Name:"<<endl;
				cin>>temp_;
				_L[updated].setName(temp_);
				cout<<"Updated Provider Last Name:"<<endl;
				cin>>temp_;
				_L[updated].setSurname(temp_);
				cout<<"Updated Provider Department:"<<endl;
				cin>>temp_;
				_L[updated].setDepartment(temp_);
				cout<<"Updated Provider E-Mail:"<<endl;
				cin>>temp_;
				_L[updated].setEmail(temp_);
				cout<<"Updated Provider Phone Number:"<<endl;
				cin>>temp_;
				_L[updated].setPhone(temp_);
				cout<<"Updated Provider title:"<<endl;
				cin>>temp_;
				_L[updated].setChair(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==3)
		{
			//Internship menu is chosen
			cout<<"1 - Add Internship"<<endl;
			cout<<"2 - List Internships"<<endl;
			cout<<"3 - Remove Internship"<<endl;
			cout<<"4 - Update Internship"<<endl;
			cin>>menu;

			if(menu==1)
			{
				//Internship addition is chosen
				string temp_;
				Internship newA;
				cout<<"Student No:"<<endl;
				cin>>temp_;
				newA.S.setNumber(temp_);
				cout<<"Provider No:"<<endl;
				cin>>temp_;
				newA.L.setNumber(temp_);
				cout<<"Internship Date:"<<endl;
				cin>>temp_;
				newA.setDate(temp_);
				cout<<"Starting Hour:"<<endl;
				cin>>temp_;
				newA.setStart(temp_);
				cout<<"Ending Hour:"<<endl;
				cin>>temp_;
				newA.setEnd(temp_);

				_A[z] = newA;
				z++;

			}
			else if(menu==2)
			{
				//Internship display is chosen
				cout<<endl;
				for(i=0; i<z; i++)
				{
					_A[i].display();
				}

			}
			else if(menu==3)
			{
				//Internship deletion is chosen
				string temp_, temp_2;
				int deleted;
				cout<<"Enter the Student No to remove:"<<endl;
				cin>>temp_;
				cout<<"Enter the Provider No to remove:"<<endl;
				cin>>temp_2;
				i=0;
				while(i<z)
				{
					if(_A[i].S.getNumber()==temp_ && _A[i].L.getNumber()==temp_2) deleted = i;
					i++;
				}
				for(i=deleted; i<z; i++)
				{
					_A[i] = _A[i+1];
				}
			}
			else if(menu==4)
			{
				//Internship update is chosen
				string temp_, temp_2;
				int updated;
				cout<<"Enter the Student No to update:"<<endl;
				cin>>temp_;
				cout<<"Enter the Provider No to update:"<<endl;
				cin>>temp_2;
				i=0;
				while(i<z)
				{
					if(_A[i].S.getNumber()==temp_ && _A[i].L.getNumber()==temp_2) updated = i;
					i++;
				}
				cout<<"Updated Internship Date:"<<endl;
				cin>>temp_;
				_A[updated].setDate(temp_);
				cout<<"Updated Starting Hour:"<<endl;
				cin>>temp_;
				_A[updated].setStart(temp_);
				cout<<"Updated Ending Hour:"<<endl;
				cin>>temp_;
				_A[updated].setEnd(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==4)
		{
			cout<<"Program terminated."<<endl;
			return 0;
		}
		else
		{
			cout<<"Error."<<endl;
		}
	}

	return 0;
}
