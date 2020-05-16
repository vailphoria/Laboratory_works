#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int max(int a, int b)
{
	if (a > b)
		return a;
	else 
		return b;
}

enum Sex
{
	Male,
	Female
};

struct Passenger
{
	short passenger_id;
	bool survived;
	short p_class;
	std::string name;
	Sex sex;
	float age;
	short sibsp;
	short parch;
	std::string ticket;
	float fare;
	std::string cabin;
	char embarked;
};

short last;
std::string read(std::string string, std::string del)
{
	short start = last;
	int end = string.find(del, start);

	last = end + del.size();

	return string.substr(start, end - start);
}


float default_age(std::string age)
{
	if (age != "")
		return std::stod(age);
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<Passenger> passengers;
	std::ifstream fin("train.csv");
	std::string string;


	std::getline(fin, string, '\r');
	while (std::getline(fin, string, '\r'))
	{
		last = 0;
		Passenger passenger;
		
		passenger.passenger_id = std::stoi(read(string, ","));
		passenger.survived = std::stoi(read(string, ","));
		passenger.p_class = std::stoi(read(string, ",\""));
		passenger.name = read(string, "\",");
		passenger.sex = read(string, ",") == "male" ? Male: Female;
		passenger.age = default_age(read(string, ","));
		passenger.sibsp = std::stoi(read(string, ","));
		passenger.parch = std::stoi(read(string, ","));
		passenger.ticket = read(string, ",");				
		passenger.fare = std::stod(read(string, ","));
		passenger.cabin = read(string, ",");
		passenger.embarked = read(string, " ")[0];
		

		passengers.push_back(passenger);
	}

	short c_survive = 0, c_survive1 = 0, c_survive2 = 0, c_survive3 = 0, c_survive_woman = 0, c_survive_man = 0, c_people = 0, c_man = 0, c_woman = 0, c_em_C = 0, c_em_Q = 0, c_em_S = 0; // ы 
	double age_people = 0, age_man=0, age_woman = 0;
	std::vector<short> children_id;


	for (short i = 0; i < passengers.size(); i++)
	{
		if (passengers[i].embarked == 'S')
			c_em_S++;
		else if (passengers[i].embarked == 'C')
			c_em_C++;
		else if (passengers[i].embarked == 'Q')
			c_em_Q;

		if ((passengers[i].age != -1) && (passengers[i].age < 18))
			children_id.push_back(passengers[i].passenger_id);

		if (passengers[i].survived)
		{
			c_survive++;
			if (passengers[i].p_class == 1)
				c_survive1++;
			else if (passengers[i].p_class == 2)
				c_survive2++;
			else if (passengers[i].p_class == 3)
				c_survive3++;

			if (passengers[i].sex == Male)
				c_survive_man++;
			else
				c_survive_woman++;

			if (passengers[i].age != -1)
			{
				age_people += passengers[i].age;
				c_people++;

				if (passengers[i].sex == Male)
				{
					age_man += passengers[i].age;
					c_man++;
				}
				else
				{
					age_woman += passengers[i].age;
					c_woman++;
				}
			}
		}
	}

	std::ofstream fout("answer.txt");

	fout << "Общее число выживших: " << c_survive << '\n';
	fout << "Число выживших из 1 класса: " << c_survive1 << '\n';
	fout << "Число выживших из 2 класса: " << c_survive2 << '\n';
	fout << "Число выживших из 3 класса: " << c_survive3 << '\n';
	fout << "Количество выживших женщин: " << c_survive_woman << '\n';
	fout << "Количество выживших мужчин: " << c_survive_man << '\n';


	if (c_people)
	{ 
		fout << "Средний возраст пассажира: " << age_people / c_people << '\n';
	}
	if (c_man)
	{
		fout << "Средний возраст мужчин: "<< age_man / c_man <<'\n';
	}
	if (c_woman)
	{
		fout << "Средний возраст женщин: " << age_woman / c_woman << '\n';
	}

	fout << "Штат, в котором село больше всего пассажиров: ";

	short c_em_max = (max(c_em_C, max(c_em_Q, c_em_S)));
	if (c_em_max == c_em_C)
		fout << "Cherbourg\n";
	else if (c_em_max == c_em_Q)
		fout << "Queenstown\n";
	else if (c_em_max == c_em_S)
		fout << "Southampton\n";

	fout << "Список идентификаторов несовершеннолетних пассажиров: ";
	for (short i = 0; i < children_id.size(); i++)
		if (i != children_id.size()-1)
			fout << children_id[i] << ", ";
		else
			fout << children_id[i] << '.';

	
	fout.close();
	fin.close();
}
