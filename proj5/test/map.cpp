#include <iostream>
#include <string>
#include <unordered_map>
 
int main()
{
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED",		"#FF0000"},
        {"GREEN",	"#00FF00"},
        {"BLUE",	"#0000FF"}
    };
 
 
    /*
	// Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "] Product ID:[" << n.third << "]" << std::endl;;
    }
	*/
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
	u["FUCK"] = "Sandler";
 
    // Output values by key
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["FUCK"] << "]\n";

    return 0;
}