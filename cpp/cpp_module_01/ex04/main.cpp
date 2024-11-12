#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);

	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	if (s1 == "")
		return (1);

	std::ifstream	file(argv[1], std::ios::in | std::ios::binary);

	if (!file)
	{
		std::cerr << "cannot open file\n";
		return (1);
	}

	file.seekg(0, std::ios::end);
	size_t	size = file.tellg();
	file.seekg(0, std::ios::beg);

	char	*buffer = new char[size];

	if (!file.read(buffer, size))
		std::cout << "cannot read\n";
	file.close();

	std::string	fileContents(buffer, size);
	delete []buffer;

	int t = 0;
	size_t	pos = fileContents.find(s1, t);

	while (pos != std::string::npos)
	{
		fileContents.erase(pos, s1.size());
		fileContents.insert(pos, s2);
		t += s2.size();
		pos = fileContents.find(s1, t);
	}

	std::string	ostring(argv[1]);
	ostring += ".replace";
	std::ofstream	outfile(ostring.c_str(), std::ios::out);
	outfile.write(fileContents.c_str(), fileContents.size());

	return (0);
}