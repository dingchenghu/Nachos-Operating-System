#include "syscall.h"

int main()
{
	int result;

	Exec("../test/testp6_joinTwice", 0, 0, 0);
	Exec("../test/array", 0, 0, 1);
	result = Join(3); //the exit status of process #2 is passed to result

	Exit(result);
}
