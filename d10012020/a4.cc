#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

int main() {
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen("bin/gawk -f gawk.code numbers.txt","r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
        	while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            		result += buffer;
        	}
    	} catch (...) {
        	pclose(pipe);
        	throw;
    	}
    	pclose(pipe);
	std::cout<<result;
}
