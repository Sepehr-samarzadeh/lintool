#ifndef icommand_h
#define icomand_h
#include <string>

class icommand{

public:
virtual ~icommand() = 0;
virtual void execute(const std::string_view args) = 0;

};



#endif