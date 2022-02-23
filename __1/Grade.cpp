#include "Grade.h"

Grade::Grade() : subject(""), value(0)
{
}

Grade::Grade(std::string subject, int value) : subject(subject), value(value)
{
}
