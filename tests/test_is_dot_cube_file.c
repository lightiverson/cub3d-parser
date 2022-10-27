#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../tokenize.h"
#include "../file_to_str.h"

Test(is_dot_cub_file, mapname_cub)
{
	bool b = is_dot_cub_file("mapname.cub");
	cr_assert(b);
}

Test(is_dot_cub_file, mapname_cubb)
{
	bool b = is_dot_cub_file("mapname.cubb");
	cr_assert(not(b));
}

Test(is_dot_cub_file, mapname_ccub)
{
	bool b = is_dot_cub_file("mapname.ccub");
	cr_assert(not(b));
}

Test(is_dot_cub_file, mapname_cu)
{
	bool b = is_dot_cub_file("mapname.cu");
	cr_assert(not(b));
}

Test(is_dot_cub_file, m)
{
	bool b = is_dot_cub_file("m");
	cr_assert(not(b));
}

Test(is_dot_cub_file, space)
{
	bool b = is_dot_cub_file(" ");
	cr_assert(not(b));
}

Test(is_dot_cub_file, empty)
{
	bool b = is_dot_cub_file("\0");
	cr_assert(not(b));
}
