#include <seat.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string fileToString(const string& filename)
{
    ifstream myFileStream(filename);
    if (myFileStream.fail())
    {
        //error file not found/openend,...
        return "";
    }
    stringstream ss;
    myFileStream >> ss.rdbuf();

    if (myFileStream.fail())
    {
        //error reading file
        return "";
    }
    return ss.str();
}

bool stringToFile(const string& filename, const string& content)
{
    ofstream myStream(filename);
    if (myStream.fail())
    {
        //file not opened
        return false;
    }
    myStream << content;

    return true;
}

bool loadSTUvector(const string& filename, STU_vector& studentsList)
{
    studentsList.clear();
    string content = fileToString(filename);
    if (content.length() == 0)
    {
        return false;
    }
    istringstream iss(content);
    iss >> studentsList;

    return true;

}

bool saveSTUvector(const string& filename, STU_vector& studentsList)
{
    if (studentsList.size() == 0)
    {
        //do not store to file
        return false;
    }
    stringstream ss;
    ss << studentsList;
    string content = ss.str();

    bool ret = stringToFile(filename, content);

    return ret;
}

int main()
{

    ifstream inputFile("test.csv");

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file!" << endl;
        return 1;  // Rückgabe eines Fehlercodes
    }


    STU_vector seat;

    inputFile >> seat;

    //input
    //for (auto& item : seat)
    //{
    //    cout << "name: " << item.name << " row: " << item.row << " column: " << item.column << endl;
    //}


    int rows = 6;
    int columns = 8;
    int totalSeats = rows * columns;

    if (seat.size() > totalSeats) {
        cerr << "Not enough seats for all students!" << endl;
        return 1;
    }

    vector<vector<int>> seatMap(rows, vector<int>(columns, 0));
    int studentIndex = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col = col + 2) {
            if (seatMap[row][col] == 0) {
                if (studentIndex < seat.size()) {
                    seat[studentIndex].row = to_string(row);
                    seat[studentIndex].column = to_string(col);
                    seatMap[row][col] = 1;
                    studentIndex++;
                }
                else {
                    break;
                }
            }
        }
    }



    string filename = "./out.csv";




    bool ret = saveSTUvector(filename, seat);
    if (ret)
    {
        cout << "file written succesfully" << endl;
    }
    else
    {
        cout << "error when writing file" << endl;
    }

    STU_vector copy;
    ret = loadSTUvector(filename, copy);


    //cout << "Entry: " << e0.name << " " << e0.row << " is born on " << e0.column << endl;

    //output

    for (auto& item : seat)
    {
        cout << "name: " << item.name << " row: " << item.row << " column: " << item.column << endl;
    }

    return 0;
}