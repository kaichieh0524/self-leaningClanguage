#include "miracl.h"
#include <tchar.h>
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])

{

	int i;

	big x, y, z;

	miracl* mip = mirsys(1000, 16);

	x = mirvar(0);

	y = mirvar(0);

	z = mirvar(0);



	bigbits(100, x);

	bigbits(100, y);

	bigbits(100, z);

	add(x, y, z);

	cotnum(z, stdout);

	return 0;

}

