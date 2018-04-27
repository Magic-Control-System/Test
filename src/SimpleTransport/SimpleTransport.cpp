#include <iostream>
#include <string>
#include <TransportLibrary\TransportCLass.h>

int main(int argc, char** argv)
{
	TransportClass app;
	return app.run(argc, argv);
	std::cout << argv[0] << std::endl;
	system("pause");
}