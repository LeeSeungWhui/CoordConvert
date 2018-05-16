#include <iostream>
#include "../lib/CoordConvert.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>


using namespace std;

void open_data(vector<string*>* data, string filename);
void print_data(vector<string*>* data, ostream* fout);
void calc_coord(vector<string*>* data);
static inline void rtrim(std::string &s);

int main() {
	vector<string*> data;

	open_data(&data, "grid.csv");

	calc_coord(&data);

	ofstream o("data.csv");
	print_data(&data, &o);
	o.close();

	return 0;
}

void open_data(vector<string*>* data, string filename)
{
	ifstream is(filename);
	string line;
	getline(is, line);
	while (is.good() == true)	// 첫번째 줄부터 데이터 읽어옴
	{
		char delim = ';';
		stringstream f(line);
		string s;
		string* temp = new string[7];
		int i = 0;
		while (getline(f, s, delim))
		{
			int idx;
			while ((idx = s.find("\"")) != -1)
			{
				s.erase(idx, 1);
			}
			//cout << s << endl;
			temp[i] = s;
			++i;
		}
		data->push_back(temp);
		getline(is, line);
	}
}

void print_data(vector<string*>* data, ostream* fout)
{
	for(int i = 0; i < data->size(); i++)
	{
		string addr = data->at(i)[0] + " " + data->at(i)[1] + " " + data->at(i)[2];
		rtrim(addr);
		*fout << "\"" << addr << "\",\"" << data->at(i)[3] << "\",\"" <<  data->at(i)[4] << "\",\"" <<  data->at(i)[5] << "\",\"" << data->at(i)[6] << "\"" << endl;
	}
}

void calc_coord(vector<string*>* data)
{
	data->at(0)[5] = "X_POS";
	data->at(0)[6] = "Y_POS";
	for(int i = 1; i < data->size(); i++)
	{
		int x = atoi(data->at(i)[3].c_str());
		int y = atoi(data->at(i)[4].c_str());
		float x_pos = 0;
		float y_pos = 0;
		GridToWgs84(x, y, &x_pos, &y_pos);
		data->at(i)[5] = to_string(x_pos);
		data->at(i)[6] = to_string(y_pos);
	}
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}


