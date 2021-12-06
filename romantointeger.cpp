#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

const string REG_EXP_VI3 = "VI{1,3}";
const string REG_EXP_IV = "IV";
const string REG_EXP_IX = "IX";
const string REG_EXP_I3 = "I{1,3}";
const string REG_EXP_V = "V";

const string REG_EXP_LX3 = "LX{1,3}";
const string REG_EXP_XL = "XL";
const string REG_EXP_XC = "XC";
const string REG_EXP_X3 = "X{1,3}";
const string REG_EXP_L = "L";

const string REG_EXP_DC3 = "DC{1,3}";
const string REG_EXP_CD = "CD";
const string REG_EXP_CM = "CM";
const string REG_EXP_C3 = "C{1,3}";
const string REG_EXP_D = "D";

const string REG_EXP_M3 = "M{1,3}";

const vector<vector<string>> vect{
    {
        REG_EXP_VI3,
        REG_EXP_IV,
        REG_EXP_IX,
        REG_EXP_I3,
        REG_EXP_V
    },
    {
        REG_EXP_LX3,
        REG_EXP_XL,
        REG_EXP_XC,
        REG_EXP_X3,
        REG_EXP_L
    },
    {
        REG_EXP_DC3,
        REG_EXP_CD,
        REG_EXP_CM,
        REG_EXP_C3,
        REG_EXP_D
    },
    {
        REG_EXP_M3,
        "",
        "",
        ""
    }
};

const map<string, int> parsemap{
    {REG_EXP_VI3, 5},
    {REG_EXP_I3, 0},
    {REG_EXP_IV, 4},
    {REG_EXP_IX, 9},
    {REG_EXP_V, 5},
    {REG_EXP_LX3, 5},
    {REG_EXP_X3, 0},
    {REG_EXP_XL, 4},
    {REG_EXP_XC, 9},
    {REG_EXP_L, 5},
    {REG_EXP_DC3, 5},
    {REG_EXP_C3, 0},
    {REG_EXP_CD, 4},
    {REG_EXP_CM, 9},
    {REG_EXP_D, 5},
    {REG_EXP_M3, 0},
};

int process_result(string str, string reg_exp, int num_place) {
    int result = parsemap.at(reg_exp);
    char search_char = 
        num_place == 0 ? 'I' :
        num_place == 1 ? 'X' :
        num_place == 2 ? 'C' :
        num_place == 3 ? 'M' : 'X';

    size_t n = count(str.begin(), str.end(), search_char);
    return (result == 0 || result == 5) ? result + n : result; 
}

int soln1(string str) {
    int result = 0;
    int exp = 1;
    int i = 0;
    for (auto v : vect) {
        for (auto s : v) {
            cout << "string is " << str << " " << s << endl;
            regex regexp(s);
            smatch sm;
            if (regex_search(str, sm, regexp) && !s.empty()) {
                result += process_result(sm[0], s, i) * pow(10, i);
                str = regex_replace(str, regexp, "");
                break;
            }
        }
        i++;
    }
    return result;
}

int soln2(string str) {
    int result = 0;
    char previous_char;
    for (auto i : str) {
        switch(i) {
            case 'M' :
                result += previous_char == 'C' ? 800 : 1000;
            break;
            case 'D' : 
                result += previous_char == 'C' ? 300 : 500;
            break;
            case 'C' :
                result += previous_char == 'X' ? 80 : 100;
            break;
            case 'L' :
                result += previous_char == 'X' ? 30 : 50;
            break;
            case 'X' :
                result += previous_char == 'I' ? 8 : 10;
            break;
            case 'V' :
                result += previous_char == 'I' ? 3 : 5;
            break;
            case 'I' :
                result += 1;
            break;
        }
        previous_char = i;
        cout << previous_char << " " << result << endl;
    }
    return result;
}

int main() {
    string input = "MCMXCIV";
    cout << soln2(input) << endl;
    return 0;
}

