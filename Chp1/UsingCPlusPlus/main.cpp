#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	char word[4] = { 0 };

	for (int i = 0; i < str.length(); i++) {
		word[i] = str[i];
	}
	int carry[4] = { 25 + 25 * 25 + 25 * 25 * 25,	//第一个字母进位所乘的比例
		25 + 25 * 25,								//第二个字母进位所乘的比例
		25,											//第三个字母进位所乘比例
		1											//第四个字母进位所乘比例
	};

	int answer = 0;
	if (word[0] - 'a' >= 0 && word[0] - 'z' < 0)
		answer += (word[0] - 'a')*carry[0];
	if (word[1] - 'a' >= 0 && word[1] - 'z' < 0)
		answer += (word[1] - 'a')*carry[1] + 1;
	if (word[2] - 'a' >= 0 && word[2] - 'z' < 0)
		answer += (word[2] - 'a')*carry[2] + 1;
	if (word[3] - 'a' >= 0 && word[2] - 'z' < 0)
		answer += (word[3] - 'a')*carry[3] + 1;

	cout << answer << endl;
	return 0;
}