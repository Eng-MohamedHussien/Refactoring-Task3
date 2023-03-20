#include "ChessFigure.h"
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

ChessFigure::ChessFigure(const std::string &coord) : currentCoord(coord) {}

bool inRangeMove(const std::string &nextCoord) {
  return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' &&
         nextCoord[1] <= '8';
}

bool isValidRookMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  return !(
      (nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) ||
      ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])));
}

bool isValidKnightMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return (dx == 1 && dy == 2 || dx == 2 && dy == 1);
}

bool isValidBishopMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return dx == dy;
}

bool isValidKingMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return dx <= 1 && dy <= 1;
}

bool isValidQueenMove(const std::string &currentCoord,
                      const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);

  return dx == dy || nextCoord[0] == currentCoord[0] ||
         nextCoord[1] == currentCoord[1];
}

bool isValidPawnMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dy = abs(nextCoord[1] - currentCoord[1]);
  return !(nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] ||
           (dy != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')));
}

void Rook::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidRookMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}

void Knight::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidKnightMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}

void Bishop::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidBishopMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}

void Pawn::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidPawnMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}

void King::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidKingMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}

void Queen::Move(const std::string &nextCoord) {
  assert(inRangeMove(nextCoord));
  assert(isValidQueenMove(currentCoord, nextCoord));
  currentCoord = nextCoord;
}