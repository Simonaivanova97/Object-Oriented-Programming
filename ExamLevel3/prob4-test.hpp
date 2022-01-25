#ifndef prob4_test_hpp
#define prob4_test_hpp

#include <stdio.h>
#include "UnitTestFramework.hpp"

TEST_CASE("PowerSpec", PowerSpec_DefalultSpecs)
{
  const PowerSpec ps;
  Assert::AreEqual(ps.getACDC(), "AC");
  Assert::AreEqual(ps.getVoltage(), 230);
  Assert::AreEqual(ps.getAmps(), 1);
}

TEST_CASE("PowerSpec", PowerSpec_ClassKeepsAssignedData)
{
  const PowerSpec ps("DC", 12, 2);
  Assert::AreEqual(ps.getACDC(), "DC");
  Assert::AreEqual(ps.getVoltage(), 12);
  Assert::AreEqual(ps.getAmps(), 2);
}

TEST_CASE("PowerSpec", PowerSpec_InvalidValuesShouldDefault)
{
  const PowerSpec ps1("WAT", 12, 5);

  Assert::AreEqual(ps1.getACDC(), "AC");
  Assert::AreEqual(ps1.getVoltage(), 230);
  Assert::AreEqual(ps1.getAmps(), 1);

  const PowerSpec ps2("AC", -12, 5);

  Assert::AreEqual(ps2.getACDC(), "AC");
  Assert::AreEqual(ps2.getVoltage(), 230);
  Assert::AreEqual(ps2.getAmps(), 1);

  const PowerSpec ps3("DC", 12, -5);

  Assert::AreEqual(ps3.getACDC(), "AC");
  Assert::AreEqual(ps3.getVoltage(), 230);
  Assert::AreEqual(ps3.getAmps(), 1);
}

TEST_CASE("PowerSpec", PowerSpec_PowerIsCorrect)
{
  const PowerSpec ps("DC", 12, 2);
  Assert::AreEqual(ps.getPower(), 24);
}

TEST_CASE("PowerSpec", PowerSpec_ComparisonsWork)
{
  const PowerSpec ps1("AC", 230, 5);
  const PowerSpec ps2("AC", 110, 3);
  const PowerSpec ps3("DC", 12, 2);
  const PowerSpec ps4("DC", 12, 1);

  Assert::AreComparisonOperatorsStrict(ps1);
  Assert::AreComparisonOperatorsStrict(ps2);
  Assert::AreComparisonOperatorsStrict(ps3);
  Assert::AreComparisonOperatorsStrict(ps4);

  Assert::AreComparisonOperatorsStrictForDifferingElements(ps2, ps1);
  Assert::AreComparisonOperatorsStrictForDifferingElements(ps4, ps3);

  Assert::IsFalse(ps1 < ps3);
  Assert::IsFalse(ps1 > ps3);
  Assert::IsFalse(ps1 <= ps3);
  Assert::IsFalse(ps1 >= ps3);

  Assert::IsFalse(ps2 < ps3);
  Assert::IsFalse(ps2 > ps3);
  Assert::IsFalse(ps2 <= ps3);
  Assert::IsFalse(ps2 >= ps3);

  Assert::IsFalse(ps1 < ps4);
  Assert::IsFalse(ps1 > ps4);
  Assert::IsFalse(ps1 <= ps4);
  Assert::IsFalse(ps1 >= ps4);

  Assert::IsFalse(ps2 < ps4);
  Assert::IsFalse(ps2 > ps4);
  Assert::IsFalse(ps2 <= ps4);
  Assert::IsFalse(ps2 >= ps4);
}

TEST_CASE("Transformer", Transformer_DefaultValues)
{
  const Transformer t;
  const PowerSpec zero("DC", 0, 0);

  Assert::IsTrue(!strcmp(t.getBrand(), "") || !strcmp(t.getBrand(), "Unknown"));
  Assert::AreEqual(t.getInSpec(), zero);
  Assert::AreEqual(t.getOutSpec(), zero);
}

TEST_CASE("Transformer", Transformer_ClassKeepsAssignedData)
{
  const PowerSpec ps1("AC", 230, 5);
  const PowerSpec ps2("DC", 12, 1);
  const Transformer t("MuchPower", ps1, ps2);

  Assert::AreEqual(t.getBrand(), "MuchPower");
  Assert::AreEqual(t.getInSpec(), ps1);
  Assert::AreEqual(t.getOutSpec(), ps2);
}

TEST_CASE("Transformer", Transformer_InvalidOutSpecEqualsInSpec)
{
  const PowerSpec ps1("AC", 230, 5);
  const PowerSpec ps2("DC", 12, 1);
  const Transformer t("MuchPower", ps2, ps1);

  Assert::AreEqual(t.getBrand(), "MuchPower");
  Assert::AreEqual(t.getInSpec(), ps2);
  Assert::AreEqual(t.getOutSpec(), ps1);
}

TEST_CASE("Transformer", Transformer_RegularConstructorCopiesBrand)
{
  // cannot really guarantee, but still better than nothing
  char Brand[] = "MuchPower";

  const Transformer t(Brand, PowerSpec("AC", 230, 5), PowerSpec("DC", 12, 1));
  Brand[1] = 'i';

  Assert::AreNotEqual(
                      reinterpret_cast<intptr_t>(t.getBrand()),
                      reinterpret_cast<intptr_t>(Brand)
                      );
}

TEST_CASE("Transformer", Transformer_CopyConstructorCopiesBrand)
{
  // cannot really guarantee, but still better than nothing
  char Brand[] = "MuchPower";

  Transformer const * t1 = new Transformer(Brand, PowerSpec("AC", 230, 5), PowerSpec("DC", 12, 1));
  const Transformer t2 = *t1;

  Assert::AreNotEqual(
                      reinterpret_cast<intptr_t>(t1->getBrand()),
                      reinterpret_cast<intptr_t>(t2.getBrand())
                      );

  delete t1;

  Assert::AreEqual(
           reinterpret_cast<const char*>(Brand),
           reinterpret_cast<const char*>(t2.getBrand())
           );
}

TEST_CASE("Transformer", Transformer_CopyConstructorCopiesPowerSpecs)
{
  char Brand[] = "MuchPower";

  const Transformer t1(Brand, PowerSpec("AC", 230, 5), PowerSpec("DC", 12, 1));
  const Transformer t2 = t1;

  Assert::AreEqual(t1.getInSpec(), t2.getInSpec());
  Assert::AreEqual(t1.getOutSpec(), t2.getOutSpec());
}

TEST_CASE("Transformer", Transformer_AssignmentOperatorCopiesBrand)
{
  // cannot really guarantee, but still better than nothing
  char Brand[] = "MuchPower";

  Transformer const * t1 = new Transformer(Brand, PowerSpec("AC", 230, 5), PowerSpec("DC", 12, 1));
  Transformer t2;
  t2 = *t1;

  Assert::AreNotEqual(
                      reinterpret_cast<intptr_t>(t1->getBrand()),
                      reinterpret_cast<intptr_t>(t2.getBrand())
                      );

  delete t1;

  Assert::AreEqual(
           reinterpret_cast<const char*>(Brand),
           reinterpret_cast<const char*>(t2.getBrand())
           );
}

TEST_CASE("Transformer", Transformer_AssignmentOperatorCopiesPowerSpecs)
{
  char Brand[] = "MuchPower";

  const Transformer t1(Brand, PowerSpec("AC", 230, 5), PowerSpec("DC", 12, 1));
  Transformer t2;
  t2 = t1;

  Assert::AreEqual(t1.getInSpec(), t2.getInSpec());
  Assert::AreEqual(t1.getOutSpec(), t2.getOutSpec());
}

TEST_CASE("Transformer", Transformer_ComposeWorks)
{
  const PowerSpec ps1("AC", 230, 5);
  const PowerSpec ps2("AC", 110, 10);
  const PowerSpec ps3("DC", 12, 1);

  const Transformer t1("MuchPower", ps1, ps2);
  const Transformer t2("SoElectrical", ps2, ps3);

  const Transformer t3=(t1*t2);
  Assert::AreEqual(t3.getBrand(), "MuchPower-SoElectrical");
  Assert::AreEqual(t3.getInSpec(), ps1);
  Assert::AreEqual(t3.getOutSpec(), ps3);

  const Transformer t4=(t2*t1);
  Assert::AreEqual(t2.getBrand(), t4.getBrand());
  Assert::AreEqual(t2.getInSpec(), t4.getInSpec());
  Assert::AreEqual(t2.getOutSpec(), t4.getOutSpec());
}

#endif /* prob4_test_hpp */
