#include <stdio.h>
#include <string>
#include <vector>

#define foreach(p, c) for (auto p = c.begin(); p != c.end(); p++)

int main()
{
	std::string str = "hello world";
	foreach(p, str) {
		::printf("%c\n", *p);
	}
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	foreach(p, v) {
		::printf("%d\n", *p);
	}
	return 0;
}
