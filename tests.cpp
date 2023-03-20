#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

#include <ChessFigure.h>

TEST_CASE("Test Rook Class") {
  Rook r("A1");
  CHECK_THROWS_WITH(r.Move("B2"), "Invalid Move !!!");
  r.Move("A3");
}

TEST_CASE("Test Knight Class") {
  Knight k("B1");
  CHECK_THROWS_WITH(k.Move("B2"), "Invalid Move !!!");
  CHECK_THROWS_WITH(k.Move("C1"), "Invalid Move !!!");
  k.Move("D2");
}

TEST_CASE("Test Bishop Class") {
  Bishop b("C1");
  CHECK_THROWS_WITH(b.Move("C2"), "Invalid Move !!!");
  CHECK_THROWS_WITH(b.Move("D1"), "Invalid Move !!!");
  b.Move("E3");
}

TEST_CASE("Test Pawn Class") {
  Pawn p("A2");
  CHECK_THROWS_WITH(p.Move("B2"), "Invalid Move !!!");
  CHECK_THROWS_WITH(p.Move("A1"), "Invalid Move !!!");
  p.Move("A3");
}

TEST_CASE("Test King Class") {
  King k("E1");
  CHECK_THROWS_WITH(k.Move("I1"), "Out of range Move !!!");
  CHECK_THROWS_WITH(k.Move("F2"), "Invalid Move !!!");
  k.Move("E2");
  k.Move("D2");
}

TEST_CASE("Test Queen Class") {
  Queen q("D1");
  CHECK_THROWS_WITH(q.Move("D9"), "Out of range Move !!!");
  CHECK_THROWS_WITH(q.Move("B2"), "Invalid Move !!!");
  q.Move("D4");
}