#include "p1.h"

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
   	FILE *inputfileptr, *outputfileptr;
   	char readChar;

	char infilenamecharp[inputfilename.size()+1]; 
	char outfilenamecharp[outputfilename.size()+1]; 
	inputfilename.copy(infilenamecharp,inputfilename.size()+1);
	infilenamecharp[inputfilename.size()] = '\0';
	outputfilename.copy(outfilenamecharp,outputfilename.size()+1);
	outfilenamecharp[outputfilename.size()] = '\0';
   	inputfileptr = fopen(infilenamecharp, "r");
   	if (inputfileptr == NULL) {
      		puts("cannot open this file");
      		exit(1);
   	}
 
   	outputfileptr = fopen(outfilenamecharp, "w");
   	if (outputfileptr == NULL) {
      		puts("Not able to open this file");
      		fclose(inputfileptr);
      		exit(1);
   	}
 
   	do {
      		readChar = fgetc(inputfileptr);
		if(lowerName)
			readChar = tolower(readChar);
		if(upperName)
      			readChar = toupper(readChar);
      		fputc(readChar, outputfileptr);
   	} while (readChar != EOF);
 
   	fclose(inputfileptr);
   	fclose(outputfileptr);
	std::cout<<"File copy completed\n";
	} catch (TCLAP::ArgException &e)  // catch any exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
}

