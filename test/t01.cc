#include "gtest/gtest.h"

#include "context.hpp"

template< bool trivial_value >
class TrivialImplementation :
  public Persistency :: Context<  TrivialImplementation< trivial_value >  >
{
  friend class Persistency ::
    Context<  TrivialImplementation< trivial_value >  >;

  private:
  bool _commit()
  {
    return trivial_value;
  }
};

TEST ( TrivialImplementation , Normal )
{
  TrivialImplementation< true > true_impl;
  EXPECT_EQ ( true_impl.commit(), true );

  TrivialImplementation< false > false_impl;
  EXPECT_EQ ( false_impl.commit(), false );
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
