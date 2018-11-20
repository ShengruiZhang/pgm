#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
 
class followers
{
	private:

	public:
		std::vector<std::string> follower;
		unsigned int count;
};

using namespace std;

int main()
{
	unordered_map <string, followers> test1;
	//unordered_map <string, int> test1;

	string subA = "microsoft";
	string subB = "apple";
	string subC = "amazon";
	string subD = "zowie";
	string subE = "acer";

	followers follow1;
	follow1.count = 1005;
	follow1.follower.push_back(subA);
	follow1.follower.push_back(subB);
	follow1.follower.push_back(subC);
	follow1.follower.push_back(subD);
	follow1.follower.push_back(subE);

	test1.insert( {"Surface", follow1} );

	followers output;
	output = test1.at("Surface");

	cout << output.follower.at(1) << endl;

	for(int i = 0; i < output.follower.size(); ++i)
	{
		cout << output.follower.at(i) << endl;
	}

	return 0;
}
