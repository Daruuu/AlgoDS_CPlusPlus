#include <gtest/gtest.h>

TEST(MyTest, SumaBasica)
{
	int a = 2;
	int b = 3;
	//EXPECT_EQ(a + b, 5);
	EXPECT_EQ(a + b, 4);
}

int main(int ac, char **av)
{
	testing::InitGoogleTest(&ac, av);

	return (RUN_ALL_TESTS());
}
