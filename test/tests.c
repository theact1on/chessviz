
#include "ctest.h"

CTEST(suite, test1)
{
    ASSERT_STR("foo", "foo");
}

CTEST(suite, test2)
{
    ASSERT_EQUAL(1, 2);
}

CTEST(suite, test_dbl)
{
    ASSERT_DBL_NEAR(0.0001, 0.00011);
    ASSERT_DBL_NEAR_TOL(0.0001, 0.00011, 1e-5);
}