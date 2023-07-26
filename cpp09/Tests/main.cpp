// #include <iostream>

// #include <algorithm>
// #include <string>

// #include <map>
// #include <unordered_map>

// int main(void)
// {
// 	std::unordered_map<std::string, int> container;

// 	container["one"] = 1;
// 	container["two"] = 2;
// 	container["three"] = 3;

// 	std::unordered_map<std::string, int>::iterator start = container.begin();
// 	std::unordered_map<std::string, int>::iterator end = container.end();

// 	for (; start != end; start++)
// 	{
// 		std::cout << "Key: " << start->first << ", Value: " << start->second << std::endl;

// 	}


// 	return (0);
// }
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 3;
    myMap["banana"] = 2;
    myMap["orange"] = 5;

    // Using std::map<std::string, int>::iterator for the iterator type
    for (std::map<std::string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        // 'it' is a pair of key-value elements, so you can access the key using 'it->first'
        // and the value using 'it->second'.
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}