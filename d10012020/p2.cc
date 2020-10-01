#include <string>
#include <iostream>
#include <tclap/CmdLine.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

	// Wrap everything in a try block.  Do this every time, 
	// because exceptions will be thrown for problems.
	try {  

	// Define the command line object, and insert a message
	// that describes the program. The "Command description message" 
	// is printed last in the help text. The second argument is the 
	// delimiter (usually space) and the last one is the version number. 
	// The CmdLine object parses the argv array based on the Arg objects
	// that it contains. 
	TCLAP::CmdLine cmd("Assignment 2 program", ' ', "0.1");

	// Define a value argument and add it to the command line.
	// A value arg defines a flag and a type of value that it expects,
	// such as "-n Bishop".
	TCLAP::ValueArg<std::string> nameArg("o","outfile","output file",true,"homer","output file");

	// Add the argument nameArg to the CmdLine object. The CmdLine object
	// uses this Arg to parse the command line.
	cmd.add( nameArg );

	// Define a switch and add it to the command line.
	// A switch arg is a boolean argument and only defines a flag that
	// indicates true or false.  In this example the SwitchArg adds itself
	// to the CmdLine object as part of the constructor.  This eliminates
	// the need to call the cmd.add() method.  All args have support in
	// their constructors to add themselves directly to the CmdLine object.
	// It doesn't matter which idiom you choose, they accomplish the same thing.
	TCLAP::SwitchArg lowerSwitch("l","lower","convert to lower", cmd, false);
	TCLAP::SwitchArg upperSwitch("u","upper","convert to upper", cmd, false);

	// input file
	TCLAP::UnlabeledValueArg<std::string> nolabel("inputfile","Input file",true,"","input filename");
	cmd.add(nolabel);

	// Parse the argv array.
	cmd.parse( argc, argv );

	// Get the value parsed by each arg. 
	std::string outputfilename = nameArg.getValue();
	bool lowerName = lowerSwitch.getValue();
	bool upperName = upperSwitch.getValue();
	std::string inputfilename = nolabel.getValue();
	// main program task
	std::ifstream inputfilestream;
	std::ofstream outputfilestream;
	char inputChar;
	inputfilestream.open(inputfilename);
	if(!inputfilestream) 
	{
		std::cout<<"Error in opening input file.\n";
		exit(1);
	}
	outputfilestream.open(outputfilename);
	if(!outputfilestream)
	{
		std::cout<<"Error in opening output file.\n";
	}
	while(inputfilestream.eof()==0)
	{
		inputfilestream>>inputChar;
		outputfilestream<<inputChar;
	}
	inputfilestream.close();
	outputfilestream.close();
	std::cout<<"File copy completed\n";
	} catch (TCLAP::ArgException &e)  // catch any exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
}

