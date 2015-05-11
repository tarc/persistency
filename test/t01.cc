#include "gtest/gtest.h"

#include "context.hpp"

class FalseImpl : public Persistency::Context< FalseImpl >
{
	friend class Persistency::Context< FalseImpl >;
	private:
		bool _commit()
		{
			return false;
		}
};

TEST ( Include , Normal )
{
	FalseImpl false_impl;
	EXPECT_EQ ( false_impl.commit(), false );
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
